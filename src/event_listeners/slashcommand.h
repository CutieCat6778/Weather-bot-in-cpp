#pragma once

#include <dpp/cluster.h>
#include "../utils/utils.h"

namespace slash_listener {
    void on_slashcommand(BetterCluster& cluster, const dpp::slashcommand_t& event);
}
