#pragma once
#include <dpp/appcommand.h>
#include <dpp/snowflake.h>
#include <fstream>
#include <iostream>
#include "dpp/cluster.h"

using json = dpp::json;

class Choice {
public:
    std::string name;
    std::string value;

    Choice(const std::string& name, const std::string& value);
};

class Option {
public:
    std::string name;
    std::string description;
    std::vector<Choice> choices;
    bool required;
    std::string type;

    Option(const std::string& name, const std::string& description, bool required, const std::string& type);
    void addChoice(const Choice& choice);
};

class Command {
public:
    std::string name;
    std::string description;
    std::vector<Option> options;
    int timeout;
    std::vector<std::string> permission;
    dpp::snowflake id;

    Command();
    Command(const std::string& name, const std::string& description, int timeout, const std::vector<std::string>& permission);
    void addOption(const Option& option);
};

class BetterCluster {
public:
    // Constructor that takes a reference to a dpp::cluster object
    BetterCluster(dpp::cluster& cluster)
        : cluster(cluster) {}

    // Getter for the commands map
    std::map<std::string, Command> get_commands() const {
        return commands;
    }

    // Setter for the commands map
    void set_commands(const std::map<std::string, Command>& new_commands) {
        commands = new_commands;
    }

    // Getter for the cluster (returns a reference)
    dpp::cluster& get_cluster() const {
        return cluster;
    }

private:
    // Store a reference to dpp::cluster instead of a copy
    dpp::cluster& cluster;
    std::map<std::string, Command> commands;
};

json read_commands_config();
Command parse_command(const std::string& command, const json& json);
std::map<std::string, Command> load_commands(const BetterCluster& cluster);
void load_env(const std::string& filepath);
