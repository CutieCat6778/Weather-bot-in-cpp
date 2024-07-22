#include "slashcommand.h"

namespace slash_listener {
    void on_slashcommand(BetterCluster &cluster, const dpp::slashcommand_t &event) {
    std::cout << "Slash command created: " << event.command.guild_id << std::endl;
    }
} // namespace slash_listener
