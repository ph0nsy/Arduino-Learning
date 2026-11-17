#pragma once
#include <projects/project.h>

#include <led.h>
#include <buzzer.h>

struct Pushbuttons_LR_LED_Project : Project {

    LED led = 0;
    
    virtual void SetUp() override {
        Project::SetUp();
        pins.put("button_L", Pin(13, INPUT));
        pins.put("button_R", Pin(12, INPUT));
        pins.put("led", Pin(11, OUTPUT));
        pins.put("buzzer", Pin(8, OUTPUT));
        
        initPins();
    };

    virtual void Loop() override {
        if(!digitalRead(pins.get("button_L").m_number)){ 
            led.setLED(led.getState_Analog() - LED_GROWTH); 
            if(led.getState_Analog() == 0) {
            buzz_Active(pins.get("buzzer").m_number, MAX_BUZZ);
            }
        }
        if(!digitalRead(pins.get("button_R").m_number)){ 
            led.setLED(led.getState_Analog() + LED_GROWTH); 
            if(led.getState_Analog() == MAX_ANALOG) {
            buzz_Active(pins.get("buzzer").m_number, MAX_BUZZ);
            }
        }
        
        analogWrite(pins.get("led").m_number, led.getState_Analog());
        delay(50);
    };
};