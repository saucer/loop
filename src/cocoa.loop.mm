#include "noop.loop.impl.hpp"

#include <saucer/cocoa.app.impl.hpp>

namespace saucer::modules
{
    void loop::impl::iteration() const
    {
        parent->native<false>()->platform->iteration();
    }
} // namespace saucer::modules
