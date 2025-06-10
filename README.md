<hr>

<div align="center"> 
    <img src="https://raw.githubusercontent.com/saucer/saucer.github.io/master/static/img/logo.png" height="312" />
</div>

<p align="center"> 
    Iterative Loop module for <a href="https://github.com/saucer/saucer">saucer</a>
</p>

---

## 📦 Installation

* Using [CPM](https://github.com/cpm-cmake/CPM.cmake)
  ```cmake
  CPMFindPackage(
    NAME           saucer-loop
    VERSION        1.0.0
    GIT_REPOSITORY "https://github.com/saucer/loop"
  )
  ```

* Using FetchContent
  ```cmake
  include(FetchContent)

  FetchContent_Declare(saucer-loop GIT_REPOSITORY "https://github.com/saucer/loop" GIT_TAG v1.0.0)
  FetchContent_MakeAvailable(saucer-loop)
  ```

Finally, link against target:

```cmake
target_link_libraries(<target> saucer::loop)
```

## 📃 Usage

> [!WARNING]
> This module may replace the default application loop. Therefore, it is recommended to not use or call `application::quit` / `application::finish()`!

```cpp
auto  app    = /*...*/;
auto& loop   = app->add_module<saucer::modules::loop>();
auto webview = /*...*/;

while (/*cond*/)
{
    loop->iteration();
}

// or simply...

loop->run();
```
