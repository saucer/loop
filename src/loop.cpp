#include "loop.hpp"

namespace saucer::modules
{
    saucer::application *loop::application()
    {
        return m_parent;
    }
} // namespace saucer::modules
