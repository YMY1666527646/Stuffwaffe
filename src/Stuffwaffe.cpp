#include "Stuffwaffe.hpp"
#include "Logger.hpp"
#include "Memory.hpp"
#include "VAC.hpp"
#include "Client.hpp"
#include "Bunnyhop.hpp"
#include "Noflash.hpp"
#include "Skinchanger.hpp"
#include "Glow.hpp"

int App::Init() {
    sw::Logger::Init();
    sw::Memory memory;
    sw::VAC vac(std::make_shared<sw::Memory>(memory));
    sw::Client client(std::make_shared<sw::Memory>(memory));
    sw::Status status;
    status.bunnyhop = true;
    status.noflash = true;
    status.skinchanger = false;
    status.glow = true;
    int connections = 0;

    sw::Logger::Log(std::string_view("client base >> " + std::to_string(memory.GetClient().base)), sw::Color.at(sw::Colors::Red));
    sw::Logger::Log(std::string_view("client size >> " + std::to_string(memory.GetClient().size)), sw::Color.at(sw::Colors::Yellow));
    sw::Logger::Log(std::string_view("engine base >> " + std::to_string(memory.GetEngine().base)), sw::Color.at(sw::Colors::Red));
    sw::Logger::Log(std::string_view("engine size >> " + std::to_string(memory.GetEngine().size)), sw::Color.at(sw::Colors::Yellow));
    sw::Logger::Endl();

    sw::Logger::Log(std::string_view("bunnyhop >> " + std::to_string(status.bunnyhop)), sw::Color.at(sw::Colors::Green));
    sw::Logger::Log(std::string_view("noflash >> " + std::to_string(status.noflash)), sw::Color.at(sw::Colors::Green));
    sw::Logger::Log(std::string_view("skinchanger >> " + std::to_string(status.skinchanger)), sw::Color.at(sw::Colors::Green));
    sw::Logger::Log(std::string_view("glow >> " + std::to_string(status.glow)), sw::Color.at(sw::Colors::Green));
    sw::Logger::Endl();

    sw::Logger::Log("initialization done", sw::Color.at(sw::Colors::Cyan));
    sw::Logger::Endl();

    sw::Player localPlayer = client.GetLocalPlayer();

    for(;;) {
        for(;memory.IsOk();) {
            if(!status.process) {
                status.process = true;
                sw::Logger::Log("process >> true", sw::Color.at(sw::Colors::Blue));
            }

            for(;client.IsGame();) {
                if(!status.game) {
                    status.game = true;
                    sw::Logger::Log("game >> true", sw::Color.at(sw::Colors::Blue));
                }

                auto bunnyhop = std::async(std::launch::async, &sw::Bunnyhop::ThreadedJump, std::make_shared<sw::Client>(client), std::make_shared<sw::Status>(status));
                auto noflash = std::async(std::launch::async, &sw::Noflash::ThreadedHide, std::make_shared<sw::Client>(client), std::make_shared<sw::Status>(status));
                // auto skinchanger = std::async(std::launch::async, &sw::Skinchanger::Skin, std::make_shared<sw::Memory>(memory), std::make_shared<sw::Client>(client));
                auto glow = std::async(std::launch::async, &sw::Glow::ThreadedGlow, std::make_shared<sw::Memory>(memory), std::make_shared<sw::Player>(localPlayer), std::make_shared<sw::Status>(status));

                if(GetAsyncKeyState(VK_DELETE)) {
                    std::exit(1);
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

            status.game = false;
            sw::Logger::Log("game >> false", sw::Color.at(sw::Colors::Blue));
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }

        status.process = false;
        sw::Logger::Log("process >> false", sw::Color.at(sw::Colors::Blue));
        ++connections;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        
        if(connections >= 2) {
            connections = 0;
            memory.~Memory();
            client.~Client();

            new(&memory) sw::Memory();
            new(&client) sw::Client(std::make_shared<sw::Memory>(memory));
        }
    }

    return 1;
}

auto main(int argc, char** argv) -> int {
    App app;
    return app.Init();
}