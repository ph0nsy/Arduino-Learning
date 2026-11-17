#define MAX_VOLTAGE 5.f
#define BAUD_RATE 9600  // Baud Rate (bits/sec)

// Function declarations:

// Global variable declarations:

//#include <projects/led_counter.h>
//CounterLED_Project project;

//#include <projects/potentiometer_controlled_led.h>
//PotentiometerLED_Project project;

//#include <projects/rgb_led.h>
//RGB_LED_Project project;

//#include <projects/potentiometer_controlled_buzzer.h>
//PotentiometerBuzzer_Project project;

//#include <projects/photoresistor_controlled_buzzer.h>
//PhotoresistorBuzzer_Project project;

//#include <projects/pushbutton_controlled_led.h>
//PushbuttonLED_Project project;

#include <projects/pushbuttons_dimmable_led.h>
Pushbuttons_LR_LED_Project project;

// Runs once, before anything else
void setup() {
  Serial.begin(BAUD_RATE); 
  project.SetUp();
}

// Runs repeatedly
void loop() {
  
  project.Loop();

  /**
   * Arduino Input Cheatsheet

  while (Serial.available() == 0) { }
  Serial.println(Serial.parseInt());
  
  while (Serial.available() == 0) { }
  Serial.println(Serial.readString());
  
  while (Serial.available() == 0) { }
  Serial.println(Serial.readStringUntil('\n'));

  while (Serial.available() == 0) { }
  Serial.println(Serial.parseFloat());

   */
}

// Function definitions: