#pragma once
#include <projects/project.h>

#include <led.h>
#include <potentiometer.h>

struct PotentiometerLED_Project : Project {

    virtual void SetUp() override {
        Project::SetUp();
        pins.put("potentiometer", Pin(A2, INPUT));
        pins.put("led", Pin(6, INPUT));
        
        initPins();
    };

    virtual void Loop() override {
        
        float Pot_val = analogRead(pins.get("potentiometer").m_number);
        float LED_val = POT2CLR * Pot_val;

        Serial.println(Pot_val);
        Serial.println(LED_val);

        analogWrite(pins.get("led").m_number, LED_val);
        
        delay(DELAY);
    };
};