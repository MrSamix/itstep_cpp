#pragma once
#include <iostream>

class Remote;

class TV {
    const size_t maxChannel;
    const size_t maxVolume;
    bool status;
    size_t channel;
    size_t volume;

public:

    TV(size_t channel = 1, size_t volume = 1, bool status = false, size_t maxChannel = 100, size_t maxVolume = 100);

    void power();
    void nextChannel();
    void prevChannel();
    void incVolume();
    void decVolume();
    void printInfo() const;

    friend class Remote;
};
