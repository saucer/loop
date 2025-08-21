#include "gtk.loop.impl.hpp"

#include <saucer/gtk.utils.hpp>
#include <saucer/gtk.app.impl.hpp>

namespace saucer::modules
{
    using impl = loop::impl;

    impl::impl() = default;

    void impl::init_platform()
    {
        platform = std::make_unique<native>();

        platform->on_quit = parent->on<saucer::application::event::quit>(
            [this]()
            {
                quit();
                return saucer::policy::block;
            });

        auto callback = [](GtkApplication *, impl *self)
        {
            self->quit();
        };
        platform->on_activate = utils::connect(parent->native<false>()->platform->application.get(), "activate", +callback, this);

        run();
    }

    impl::~impl()
    {
        g_signal_handler_disconnect(parent->native<false>()->platform->application.get(), platform->on_activate);
        parent->off(saucer::application::event::quit, platform->on_quit);
    }

    void impl::run() const
    {
        // https://github.com/GNOME/glib/blob/ce5e11aef4be46594941662a521c7f5e026cfce9/gio/gapplication.c#L2591

        platform->should_quit = false;

        auto *const application = G_APPLICATION(parent->native<false>()->platform->application.get());
        auto *const context     = g_main_context_default();

        if (!g_main_context_acquire(context))
        {
            return;
        }

        if (!platform->initialized) [[unlikely]]
        {
            g_application_register(application, nullptr, nullptr);
            g_application_activate(application);
            platform->initialized = true;
        }

        while (!platform->should_quit)
        {
            g_main_context_iteration(context, true);
        }

        g_main_context_release(context);
    }

    void impl::iteration() const
    {
        if (platform->should_quit)
        {
            return;
        }

        parent->native<false>()->platform->iteration();
    }

    void impl::quit() const
    {
        parent->invoke([this] { platform->should_quit = true; });
    }
} // namespace saucer::modules
