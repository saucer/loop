#include "gtk.loop.impl.hpp"

#include "gtk.app.impl.hpp"

namespace saucer::modules
{
    loop::loop(saucer::application *parent) : m_impl(std::make_unique<impl>()), m_parent(parent)
    {
        auto *const impl = parent->native<false>();

        auto callback = [](GtkApplication *, loop *self)
        {
            self->quit();
        };
        g_signal_connect(impl->application.get(), "activate", G_CALLBACK(+callback), this);

        run();
    }

    loop::~loop() = default;

    bool loop::on_quit()
    {
        quit();
        return true;
    }

    void loop::run()
    {
        // https://github.com/GNOME/glib/blob/ce5e11aef4be46594941662a521c7f5e026cfce9/gio/gapplication.c#L2591

        m_impl->should_quit = false;

        auto *const impl    = m_parent->native<false>();
        auto *const context = g_main_context_default();

        if (!g_main_context_acquire(context))
        {
            return;
        }

        if (!m_impl->initialized) [[unlikely]]
        {
            g_application_register(G_APPLICATION(impl->application.get()), nullptr, nullptr);
            g_application_activate(G_APPLICATION(impl->application.get()));
            m_impl->initialized = true;
        }

        while (!m_impl->should_quit)
        {
            g_main_context_iteration(context, true);
        }

        g_main_context_release(context);
    }

    void loop::iteration()
    {
        if (m_impl->should_quit)
        {
            return;
        }

        m_parent->native<false>()->iteration();
    }

    void loop::quit()
    {
        if (!m_parent->thread_safe())
        {
            return m_parent->dispatch([this] { return quit(); });
        }

        m_impl->should_quit = true;
    }
} // namespace saucer::modules
