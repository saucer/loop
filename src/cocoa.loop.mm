#include "noop.loop.impl.hpp"

#include "cocoa.app.impl.hpp"

namespace saucer::modules
{
    loop::loop(saucer::application *parent) : m_impl(std::make_unique<impl>()), m_parent(parent) {}

    loop::~loop() = default;

    bool loop::on_quit() // NOLINT(*-static)
    {
        return false;
    }

    void loop::run()
    {
        m_parent->run([](auto...) -> coco::stray { return {}; });
    }

    void loop::iteration()
    {
        m_parent->native<false>()->iteration();
    }

    void loop::quit()
    {
        m_parent->quit();
    }
} // namespace saucer::modules
