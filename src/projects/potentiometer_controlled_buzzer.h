#pragma once
#include <projects/project.h>

#include <buzzer.h>
#include <potentiometer.h>

struct PotentiometerBuzzer_Project : Project {

    // Depending on local, real life parameters
    const float photo2sound = 900/350;

    virtual void SetUp() override {
        pins.put("potentiometer", Pin(A0, INPUT));
        pins.put("buzzer", Pin(8, OUTPUT));
        
        initPins();
    };

    virtual void Loop() override {
        int frequencyDelay = analogRead(pins.get("potentiometer").m_number) * POT2BUZZ + MIN_BUZZ;
        buzz_Active(pins.get("buzzer").m_number, frequencyDelay);
    };
};