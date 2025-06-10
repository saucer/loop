#include "noop.loop.impl.hpp"

#include "win32.app.impl.hpp"

namespace saucer::modules
{
    loop::loop(saucer::application *parent) : m_impl(std::make_unique<impl>()), m_parent(parent) {}

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

    bool loop::on_quit() // NOLINT(*-static)
    {
        return false;
    }
} // namespace saucer::modules
