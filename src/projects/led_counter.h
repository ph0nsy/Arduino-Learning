#pragma once
#include <projects/project.h>

#define LED_COUNT 4
#define DELAY_NEXT 2000

#include <led.h>

struct CounterLED_Project : Project {

    int count = 0;
    uint8_t ledPins[LED_COUNT] = { 11, 10, 9, 8 };
    LED ledStates[LED_COUNT];

    virtual void SetUp() override {
        for(uint8_t i = 0; i < LED_COUNT; i++) { 
            pinMode(ledPins[i], OUTPUT); 
        }
    };

    virtual void Loop() override {
        count++;
        count = count <= 0 ? 0 : count >= 1 << LED_COUNT ? 0 : count;

        for(uint8_t i = 0; i < LED_COUNT; i++) {
            ledStates[i].setLED((bool)(count & (1 << i)));  // Parse into bit
            digitalWrite(ledPins[i], ledStates[i].getState_Digital());
        }

        delay(DELAY_NEXT);
    };
};