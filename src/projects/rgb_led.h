#pragma once
#include <projects/project.h>

#include <led.h>

struct RGB_LED_Project : Project {

    uint8_t maxPins = 8;
    String msg[3] = {"R: "," - G: "," - B: "};
    LED_RGB led = LED_RGB(RGB());
    
    virtual void SetUp() override {
        Project::SetUp();
        pins.put("R", Pin(A0, INPUT));
        pins.put("G", Pin(A1, INPUT));
        pins.put("B", Pin(A2, OUTPUT));
        
        initPins();
    };

    virtual void Loop() override {
        Serial.print(msg[0]);
        while (Serial.available() == 0) { }
        led.setColorChannel(eColorChannel::RED, Serial.parseInt());
        Serial.print(led.getChannel(eColorChannel::RED));
        analogWrite(pins.get("R").m_number, led.getChannel(eColorChannel::RED));
        
        Serial.print(msg[1]);
        while (Serial.available() == 0) { }
        led.setColorChannel(eColorChannel::GREEN, Serial.parseInt());
        Serial.print(led.getChannel(eColorChannel::GREEN));
        analogWrite(pins.get("G").m_number, led.getChannel(eColorChannel::GREEN));

        Serial.print(msg[2]);
        while (Serial.available() == 0) { }
        led.setColorChannel(eColorChannel::BLUE, Serial.parseInt());
        Serial.println(led.getChannel(eColorChannel::BLUE));
        analogWrite(pins.get("B").m_number, led.getChannel(eColorChannel::BLUE));
    };
};