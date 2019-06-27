// lights.cpp - Lights buffer handling
//
// Adapted from code by John Graham-Cumming by Alison N. Norman
//

#include "lights.h"

//Initilizes light strands with FastLED library
void leds_init()
{  
   FastLED.addLeds<LED_TYPE, 8, RGB>(leds[8], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 7, RGB>(leds[0], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 6, RGB>(leds[1], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 5, RGB>(leds[2], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 4, RGB>(leds[3], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 3, RGB>(leds[4], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 2, RGB>(leds[5], NUM_LEDS).setCorrection( TypicalLEDStrip );
   FastLED.addLeds<LED_TYPE, 1, RGB>(leds[6], NUM_LEDS).setCorrection( TypicalLEDStrip );


   FastLED.setBrightness(  BRIGHTNESS );  //sets the brightness for the strand of LEDs.  Default is 64, max is 255.
  
}

// leds_init: Initializes leds to all pixels off and mirrors
// that to the actual display
void leds_off()
{
  for ( int x = 0; x < NUM_STRANDS + 1; ++x )
     for (int y = 0; y < NUM_LEDS + 1; ++y)
        leds[x][y] = CRGB::Black;

  FastLED.show();
}

// leds_scroll: scroll the leds left one column
void leds_scroll()
{

  for ( int x = 1; x < NUM_STRANDS + 1; ++x )
   for (int y = 0; y < NUM_LEDS; ++y )
     leds[x-1][y] = leds[x][y];
     
  FastLED.show();
}

void test_leds()
{
  for(int j = 0; j < 5; j++)
  {
    
    for ( int x = 0; x < NUM_STRANDS + 1; ++x )
      for (int y = 0; y < NUM_LEDS + 1; ++y )
      {
         if((x+y)%2==0)
            leds[x][y]=CRGB::SteelBlue;
         else
            leds[x][y]=CRGB::PaleVioletRed;
       }
   FastLED.delay(500);
   for ( int x = 0; x < NUM_STRANDS + 1; ++x )
      for (int y = 0; y < NUM_LEDS + 1; ++y )
      {
         if((x+y)%2==0)
            leds[x][y]=CRGB::PaleVioletRed;
         else
            leds[x][y]=CRGB::SteelBlue;
      }
    FastLED.delay(700);
  }
}
