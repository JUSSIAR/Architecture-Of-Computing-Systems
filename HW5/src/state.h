#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>

const static size_t kSize = 40;

class State {
    std::vector<size_t> bad;
    std::vector<size_t> good;
    std::mutex mutex;

public:
    State() {
        for (size_t i = 0; i < kSize; ++i) {
            good.push_back(i);
        }
    }

    void fixRandomBad(size_t number) {
        mutex.lock();

        std::cout << "Gardener ";
        std::cout << std::to_string(number);
        std::cout << "\t:\t";
        if (bad.empty()) {
            std::cout << "the flowerbed is fine\n";
            mutex.unlock();
            return;
        }
        good.push_back(getRandomFlower(bad));
        std::cout << "fix flower number ";
        std::cout << std::to_string(good.back()) << '\n';

        mutex.unlock();
    }

    void killRandomFlower() {
        mutex.lock();

        std::cout << "Killer\t:\t";
        if (good.empty()) {
            std::cout << "garden is fully killed\n";
            mutex.unlock();
            return;
        }
        bad.push_back(getRandomFlower(good));
        std::cout << "killed flower number ";
        std::cout << std::to_string(bad.back()) << '\n';

        mutex.unlock();
    }
    
private:
    size_t getRandomFlower(std::vector<size_t>& arr) {
        std::random_shuffle(arr.begin(), arr.end());
        size_t flower = arr.back();
        arr.pop_back();
        return flower;
    }
};