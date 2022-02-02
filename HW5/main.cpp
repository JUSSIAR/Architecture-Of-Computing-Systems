#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "src/state.h"
#include "src/generator.h"
#include "src/reader.h"

int main(int argc, char* argv[]) {
    State state;
    size_t troubles = 0;

    if (argc == 2 && std::string(argv[1]) == "-g") {
        troubles = Generator::generate();
    }
    if (argc == 3 && std::string(argv[1]) == "-f") {
        troubles = Reader::reader(argv[2]);
    }

    if (troubles == 0) {
        std::cerr << "wrong args\n";
        return 0;
    }

    std::cout << "Total bad actions: " << troubles << "\n\n\n";

    std::thread gardener1([&]() {
       while (troubles) {
           state.fixRandomBad(1);
           std::this_thread::sleep_for(std::chrono::milliseconds(400));
       }
    });

    std::thread gardener2([&]() {
        while (troubles) {
            state.fixRandomBad(2);
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
    });

    std::thread killer([&]() {
        while (troubles) {
            state.killRandomFlower();
            --troubles;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    });

    gardener1.join();
    gardener2.join();
    killer.join();

    return 0;
}