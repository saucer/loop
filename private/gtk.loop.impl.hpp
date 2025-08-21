#pragma once

#include "loop.impl.hpp"

namespace saucer::modules
{
    struct loop::impl::native
    {
        bool should_quit{false};
        bool initialized{false};

      public:
        std::size_t on_quit;
        std::size_t on_activate;
    };
} // namespace saucer::modules
