#include "noop.loop.impl.hpp"

#include "cocoa.app.impl.hpp"

namespace saucer::modules
{
    void loop::impl::iteration()
    {
        m_parent->native<false>()->iteration();
    }
} // namespace saucer::modules
