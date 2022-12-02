#pragma once
#include <Adafruit_NeoPixel.h>
#define LED_PIN 12
// Pinout esp32Cam
//      5V                -----------        3.3V
//     GND                ----- -----        GPIO 16
// GPIO 12 SD DATA2       ---- O ----        GPIO 0 - connect 2 GND = flashing mode
// GPIO 13 SD DATA3       ----- -----        GND
// GPIO 15 SD CMD         -----------        3.3V/5V - Power OUT
// GPIO 14 SD CLK         -----------        GPIO 3 RX
// GPIO  2 SD DATA0       -----------        GPIO 1 TX
// GPIO  4 SD DATA1 flash -esp32-cam-        GND

#define LED_COUNT 12

Adafruit_NeoPixel ledRing(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<ledRing.numPixels(); i++) { // For each pixel in strip...
    ledRing.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    ledRing.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void setupLED() {
    ledRing.begin();
    ledRing.show();
    ledRing.setBrightness(255);
    log_v("setupLED");
}

void light(boolean mode) {
    if (mode) {
        colorWipe(ledRing.Color(255,255,255),100);
        log_v("light ON");
    } else {
        colorWipe(ledRing.Color(0,0,0),100);
        log_v("light OFF");
    }
}

void brightness(int bnValue) {
    double base100;
    base100=(bnValue/255)*100;
    log_i("LEDbrightness=%d", (int)base100);
    //ledRing.setBrightness((int)base100);
    colorWipe(ledRing.Color((uint32_t)bnValue,(uint32_t)bnValue,(uint32_t)bnValue),50);
}

