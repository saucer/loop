#include "loop.impl.hpp"

namespace saucer::modules
{
    loop::loop(saucer::application &application) : m_impl(std::make_unique<impl>())
    {
        m_impl->parent = std::addressof(application);
        m_impl->init_platform();
    }

    loop::~loop() = default;

    saucer::application *loop::application()
    {
        return m_impl->parent;
    }

    void loop::run()
    {
        m_impl->run();
    }

    void loop::iteration()
    {
        m_impl->iteration();
    }

    void loop::quit()
    {
        m_impl->quit();
    }
} // namespace saucer::modules
