#include "noop.loop.impl.hpp"

#include "win32.app.impl.hpp"

namespace saucer::modules
{
    void loop::impl::iteration()
    {
        m_parent->native<false>()->iteration();
    }
} // namespace saucer::modules
