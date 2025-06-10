#pragma once

#include <saucer/app.hpp>

namespace saucer::modules
{
    class loop
    {
        struct impl;

      private:
        std::unique_ptr<impl> m_impl;
        saucer::application *m_parent;

      public:
        loop(saucer::application *parent);

      public:
        void run();
        void iteration();

      public:
        void quit();
        bool on_quit();
    };
} // namespace saucer::modules
