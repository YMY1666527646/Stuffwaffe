#include "Logger.hpp"

namespace sw {
    void Logger::Init() {
        #if defined(_WIN32)
        std::system("setlocal");
        #endif
    }

    void Logger::Log(std::string_view message, std::string_view color) {
        std::cout << Color.at(Colors::Magenta) << " < Stuffwaffe > " << color << " >> " << message << "\n";
    }

    void Logger::Endl() {
        std::cout << "\n";
    }

    void Logger::Pause() {
        std::cin.get();
    }
};