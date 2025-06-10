#pragma once

#include "loop.hpp"

namespace saucer::modules
{
    struct loop::impl
    {
        bool should_quit{false};
        bool initialized{false};
    };
} // namespace saucer::modules
