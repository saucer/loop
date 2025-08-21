#pragma once

#include "loop.hpp"

namespace saucer::modules
{
    struct loop::impl
    {
        struct native;

      public:
        saucer::application *parent;

      public:
        std::unique_ptr<native> platform;

      public:
        impl();

      public:
        ~impl();

      public:
        void init_platform();

      public:
        void run() const;
        void iteration() const;

      public:
        void quit() const;
    };
} // namespace saucer::modules
