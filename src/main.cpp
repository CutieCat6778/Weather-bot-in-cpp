#include <cstdlib>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>

#include "event_listeners/ready.h"
#include "event_listeners/slashcommand.h"
#include "utils/utils.h"
#include "database/database.h"

int main() {
  load_env("../.env");

  const char *BOT_TOKEN = getenv("BOT_TOKEN");

  dpp::cluster client(BOT_TOKEN);
  BetterCluster cluster(client);
  dpp::cluster& bot = cluster.get_cluster();

  bot.on_log(dpp::utility::cout_logger());

  bot.on_slashcommand([&cluster](const dpp::slashcommand_t& event) {
      slash_listener::on_slashcommand(cluster, event);
  });

  bot.on_ready([&cluster](const dpp::ready_t& event) {
      ready_listener::on_ready(cluster, event);
  });

  bot.start(dpp::st_wait);

  return 0;
}
