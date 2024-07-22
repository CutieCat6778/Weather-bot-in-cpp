#include "utils.h"
#include <cstdlib>
#include <dpp/cluster.h>
#include <dpp/snowflake.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Choice::Choice(const std::string &name, const std::string &value)
    : name(name), value(value) {}

Option::Option(const std::string &name, const std::string &description,
               bool required, const std::string &type)
    : name(name), description(description), required(required), type(type) {}

void Option::addChoice(const Choice &choice) { choices.push_back(choice); }

Command::Command() : timeout(0) {}

Command::Command(const std::string &name, const std::string &description,
                 int timeout, const std::vector<std::string> &permission)
    : name(name), description(description), timeout(timeout),
      permission(permission) {}

void Command::addOption(const Option &option) { options.push_back(option); }

void load_env(const std::string &filepath) {
  std::ifstream file(filepath);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filepath << std::endl;
    std::exit(1);
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty()) {
      continue;
    }

    std::istringstream ss(line);
    std::string key;
    if (std::getline(ss, key, '=')) {
      std::string value;
      if (std::getline(ss, value)) {
        setenv(key.c_str(), value.c_str(), 1);
      }
    }
  }

  file.close();
}

Command parse_command(const std::string &name, const json &j) {
  if (!j.contains("name") || !j.contains("description") ||
      !j.contains("timeout") || !j.contains("permission")) {
    throw std::invalid_argument("JSON object is missing required fields.");
  }

  Command command(j["name"].get<std::string>(),
                  j["description"].get<std::string>(), j["timeout"].get<int>(),
                  j["permission"].get<std::vector<std::string>>());

  if (j.contains("options")) {
    for (const auto &optionJson : j["options"]) {
      Option option(optionJson["name"].get<std::string>(),
                    optionJson["description"].get<std::string>(),
                    optionJson["required"].get<bool>(),
                    optionJson["type"].get<std::string>());

      if (optionJson.contains("choices")) {
        for (const auto &choiceJson : optionJson["choices"]) {
          Choice choice(choiceJson["name"].get<std::string>(),
                        choiceJson["value"].get<std::string>());
          option.choices.push_back(choice);
        }
      }

      command.options.push_back(option);
    }
  }

  return command;
}

std::map<std::string, Command> load_commands(const BetterCluster &cluster) {
  dpp::cluster &bot = cluster.get_cluster();
  json j = read_commands_config();
  std::map<std::string, Command> commands;
  for (const auto &commandJson : j["commands"]) {
      std::cout << "Command: " << commandJson["name"].get<std::string>() << std::endl;
    Command command =
        parse_command(commandJson["name"].get<std::string>(), commandJson);
    commands[command.name] = command;
    dpp::slashcommand newcommand(command.name, command.description, bot.me.id);
    for (const auto &option : command.options) {
      if (option.type == "string") {
        dpp::command_option newoption(dpp::co_string, option.name,
                                      option.description, option.required);
        if (option.choices.size() > 0) {
          for (const auto &choice : option.choices) {
            newoption.add_choice(
                dpp::command_option_choice(choice.name, choice.value));
          }
        }
        newcommand.add_option(newoption);
      } else if (option.type == "int") {
        dpp::command_option newoption(dpp::co_integer, option.name,
                                      option.description, option.required);
      } else if (option.type == "double") {
        dpp::command_option newoption(dpp::co_number, option.name,
                                      option.description, option.required);
      } else if (option.type == "bool") {
        dpp::command_option newoption(dpp::co_boolean, option.name,
                                      option.description, option.required);
      }
    }
    bot.guild_command_create(newcommand, 1264600811812688006,
                             [&bot, &commands](const dpp::confirmation_callback_t &event) {
                               if (event.is_error()) {
                                 std::cout << "Error creating command: "
                                           << event.http_info.body << std::endl;
                               } else {
                                std::cout << "Command created: "
                                           << event.http_info.body << std::endl;
                                json j = json::parse(event.http_info.body);
                                std::string command_name = j["name"].get<std::string>();
                                std::string command_id = j["id"].get<std::string>();
                                commands[command_name].id = dpp::snowflake(command_id);
                               }
                             });
  }

  return commands;
}

json read_commands_config() {
  // Open the JSON file
  std::ifstream jsonFile("data/commands_info.json");

  if (!jsonFile.is_open()) {
    std::cerr << "Unable to open the file" << std::endl;
    exit(1);
  }

  // Parse the JSON fileS
  json jsonData;
  jsonFile >> jsonData;

  // Close the file
  jsonFile.close();

  return jsonData;
}
