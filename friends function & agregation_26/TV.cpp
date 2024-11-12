#include "TV.h"

TV::TV(size_t channel, size_t volume, bool status, size_t maxChannel, size_t maxVolume)
    : maxChannel(maxChannel), maxVolume(maxVolume), status(status), channel(channel), volume(volume) {}

void TV::power() {
    status = !status;
}

void TV::nextChannel() {
    if (status) {
        channel = (channel % maxChannel) + 1;
    }
}

void TV::prevChannel() {
    if (status) {
        channel = (channel == 1) ? maxChannel : channel - 1;
    }
}


void TV::incVolume() {
    if (status && volume < maxVolume) {
        ++volume;
    }
}

void TV::decVolume() {
    if (status && volume > 0) {
        --volume;
    }
}

void TV::printInfo() const {
    std::cout << "TV: " << (status ? "ON" : "OFF") << "\n";
    std::cout << "Active Channel: " << channel << "\n";
    std::cout << "Volume: " << volume << "\n";
}