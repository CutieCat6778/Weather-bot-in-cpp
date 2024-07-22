#include "ready.h"

namespace ready_listener {
    void on_ready(BetterCluster &cluster, const dpp::ready_t &event) {
        std::cout << "Logged in as " << cluster.get_cluster().me.username << "!" << std::endl;
        std::map<std::string, Command> commands = load_commands(cluster);
        std::cout << "Loaded " << commands.size() << " commands!" << std::endl;
        cluster.set_commands(commands);
    }
} // namespace ready_listener
