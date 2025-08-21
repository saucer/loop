#include "noop.loop.impl.hpp"

namespace saucer::modules
{
    using impl = loop::impl;

    impl::impl() = default;

    void impl::init_platform() {}

    impl::~impl() = default;

    void impl::run() const
    {
        parent->run([](auto &&...) -> coco::stray { return {}; });
    }

    void impl::quit() const
    {
        parent->quit();
    }
} // namespace saucer::modules
