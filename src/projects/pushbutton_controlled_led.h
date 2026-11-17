#pragma once
#include <projects/project.h>

#include <led.h>

struct PushbuttonLED_Project : Project {

    bool current_press = false, button_state = false;
    LED led = 0;
    
    virtual void SetUp() override {
        Project::SetUp();
        pins.put("button", Pin(12, INPUT));
        pins.put("led", Pin(8, OUTPUT));
        
        initPins();
    };

    virtual void Loop() override {
        current_press = !digitalRead(pins.get("button").m_number);
        if(button_state && !current_press){ led.toggleLED(); }
        button_state = current_press;
        digitalWrite(pins.get("led").m_number, led.getState_Digital());
    };
};