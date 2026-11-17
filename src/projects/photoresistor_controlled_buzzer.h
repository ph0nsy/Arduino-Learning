#pragma once
#include <projects/project.h>

#include <buzzer.h>

struct PhotoresistorBuzzer_Project : Project {

    // Depending on local, real life parameters
    const float photo2sound = 900/350;

    virtual void SetUp() override {
        pins.put("photoresistor", Pin(A0, INPUT));
        pins.put("buzzer", Pin(8, OUTPUT));
        
        initPins();
    };

    virtual void Loop() override {
        int voltage = analogRead(pins.get("photoresistor").m_number);
        int processedTime = (voltage - 150) * photo2sound + 100;
        Serial.println(processedTime);
        buzz_Active(pins.get("buzzer").m_number, processedTime);
    };
};