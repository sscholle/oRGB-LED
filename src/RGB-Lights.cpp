/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/
#include <Arduino.h>

const uint8_t GREEN_LED = 9;
const uint8_t RED_LED = 10;
const uint8_t BLUE_LED = 11;


uint8_t SAME_COLOR_ITERATIONS = 12;
uint8_t GENERAL_DELAY = 4;
uint8_t MAX_BRIGHTNESS = 64;
uint8_t MIN_BRIGHTNESS = 4;


uint8_t G_BRIGHT = MIN_BRIGHTNESS;
uint8_t G_FADEAMNT = 1;

uint8_t R_BRIGHT = MIN_BRIGHTNESS;
uint8_t R_FADEAMNT = 2;

uint8_t B_BRIGHT = MIN_BRIGHTNESS;
uint8_t B_FADEAMNT = 3;

void writeRed(uint8_t br){
  analogWrite(RED_LED, br);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, 0);
}

void writeGreen(uint8_t br){
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, br);
  analogWrite(BLUE_LED, 0);
}

void writeBlue(uint8_t br){
  analogWrite(RED_LED, 0);
  analogWrite(GREEN_LED, 0);
  analogWrite(BLUE_LED, br);
}

void iterateCurrentColor(int iterations){
  for(int x = 0; x < iterations; x++){
    writeGreen(G_BRIGHT);
    delay(GENERAL_DELAY);
    writeRed(R_BRIGHT);
    delay(GENERAL_DELAY);
    writeBlue(B_BRIGHT);
    delay(GENERAL_DELAY);
  }
}

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // change the brightness for next time through the loop:
  G_BRIGHT = G_BRIGHT + G_FADEAMNT;
  R_BRIGHT = R_BRIGHT + R_FADEAMNT;
  B_BRIGHT = B_BRIGHT + B_FADEAMNT;

  // reverse the direction of the fading at the ends of the fade:
  if (G_BRIGHT < MIN_BRIGHTNESS || G_BRIGHT > MAX_BRIGHTNESS) {
    G_FADEAMNT = -G_FADEAMNT;
    G_BRIGHT = G_BRIGHT + G_FADEAMNT;
  }
  if (R_BRIGHT < MIN_BRIGHTNESS || R_BRIGHT > MAX_BRIGHTNESS) {
    R_FADEAMNT = -R_FADEAMNT;
    R_BRIGHT = R_BRIGHT + R_FADEAMNT;
  }
    if (B_BRIGHT < MIN_BRIGHTNESS || B_BRIGHT > MAX_BRIGHTNESS) {
    B_FADEAMNT = -B_FADEAMNT;
    B_BRIGHT = B_BRIGHT + B_FADEAMNT;
  }

  iterateCurrentColor(SAME_COLOR_ITERATIONS);
}



