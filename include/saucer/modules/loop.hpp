#pragma once

#include <saucer/app.hpp>

namespace saucer::modules
{
    struct loop
    {
        struct impl;

      private:
        std::unique_ptr<impl> m_impl;

      public:
        loop(saucer::application &);

      public:
        ~loop();

      public:
        [[nodiscard]] saucer::application *application();

      public:
        void run();
        void iteration();

      public:
        void quit();
    };
} // namespace saucer::modules
