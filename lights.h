// lights.h - Handling of LEDS
//
// Adapted from code provided by the FastLED library by Alison N. Norman

#ifndef INCLUDED_LIGHTS
#define INCLUDED_LIGHTS

#include "FastLED.h"

#define NUM_STRANDS 7
#define NUM_LEDS    7
#define MAX_BRIGHTNESS 255
#define BRIGHTNESS  64   //MAX is 255.  Colors may be more vibrant at lower brightness values
#define LED_TYPE    WS2811

#define UPDATES_PER_SECOND 100

extern CRGB leds[NUM_STRANDS+1][NUM_LEDS+1];
//extern const int led_pins[NUM_STRANDS];

void leds_init();
void leds_scroll();
void leds_off();
void test_leds();


#endif // INCLUDED_LIGHTS
