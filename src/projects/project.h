#pragma once
#include <Arduino.h>

#define DELAY 500

#include <pin.h>
#include <hashmap.h>

struct Project {
    uint8_t maxPins = 8;
    Map<Pin> pins;

    Project() = default;

    Map<Pin> getPins() { return pins; };
    void initPins() {
        for(size_t i = 0; i < pins.size; i++) {
            pinMode(
            ((Pin)pins.buckets[i]).m_number, 
            ((Pin)pins.buckets[i]).m_mode
            );
        } 
    }

    virtual void SetUp() { pins = init<Pin>(maxPins); };
    virtual void Loop();
};
