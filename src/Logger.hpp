#pragma once

#include "Stuffwaffe.hpp"

namespace sw {
    enum Colors {
        None,
        White,
        Black,
        Red,
        Yellow,
        Green,
        Blue,
        Magenta,
        Cyan
    };

    const inline std::map<int, std::string_view> Color {
        { Colors::None, "\u001b[0m" },
        { Colors::White, "\u001b[37m" },
        { Colors::Black, "\u001b[30m" },
        { Colors::Red, "\u001b[31m" },
        { Colors::Yellow, "\u001b[33m" },
        { Colors::Green, "\u001b[32m" },
        { Colors::Blue, "\u001b[34m" },
        { Colors::Magenta, "\u001b[35m" },
        { Colors::Cyan, "\u001b[36m" }
    };

    class Logger {
    public:
        Logger() = default;
        virtual ~Logger() = default;

        static void Init();
        static void Log(std::string_view message, std::string_view color);
        static void Endl();
        static void Pause();
    };
};