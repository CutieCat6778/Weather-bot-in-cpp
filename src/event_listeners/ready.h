#pragma once

#include <dpp/cluster.h>
#include "../utils/utils.h"

namespace ready_listener {
    void on_ready(BetterCluster& cluster, const dpp::ready_t& event);
}
