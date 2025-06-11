#pragma once

#include <saucer/app.hpp>

namespace saucer::modules
{
    class loop
    {
        friend class traits<application>;
        struct impl;

      private:
        std::unique_ptr<impl> m_impl;
        saucer::application *m_parent;

      public:
        loop(saucer::application *parent);

      public:
        ~loop();

      protected:
        bool on_quit();

      public:
        [[nodiscard]] saucer::application *application();

      public:
        void run();
        void iteration();

      public:
        void quit();
    };
} // namespace saucer::modules
