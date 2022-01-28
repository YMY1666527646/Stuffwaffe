#pragma once

#if defined(_WIN32)
    #include <Windows.h>
    #include <TlHelp32.h>
    #include <Psapi.h>
#elif defined(__linux__)
    // TODO: Linux support
    #error "Not Supported Operating System"
#else
    #error "Not Supported Operating System"
#endif

#include <iostream>
#include <fstream>
#include <ostream>
#include <thread>
#include <chrono>
#include <future>
#include <string>
#include <string_view>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <array>

#include "Offsets.hpp"
#include "Math.hpp"

namespace sw {
    struct Status {
        bool process = false;
        bool game = false;
        bool bunnyhop = false;
        bool noflash = false;
        bool skinchanger = false;
        bool glow = false;
    };
};

class App {
public:
    App() = default;
    virtual ~App() = default;

    virtual int Init();
};