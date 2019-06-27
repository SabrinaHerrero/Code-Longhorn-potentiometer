//tests.cpp - learn how to control the lights here!
//by Alison N. Norman

#include "tests.h"

//blink the light closest to the controller
void blink_light_0_0_example()
{
  leds[0][0]=CRGB::White; //defined in colors (pixeltypes.h), sets led 0,0 to white in strand

  FastLED.delay(1000); //pauses the program for the specified number of milliseconds
                       //do this to display the current light settings for a particular amount of time
                       //calls show, which mirrors the values in leds to the strand

  leds[0][0]=CRGB::Black; //Black turns the led off

  FastLED.delay(1000);

}

//Function to blink light (0,0) and (2,4) 
void blink_lights_0_0_and_2_4()
{
  int x = 0;
  while (x<20){
    leds[0][0]=CRGB::White;
    leds[2][4]=CRGB::White;
    FastLED.delay(1000);
    leds[0][0]=CRGB::Black;
    leds[2][4]=CRGB::Black;
    FastLED.delay(1000);
    x++;
  }
}

//Function to blink all lights
void blink_all_lights()
{
  for ( int x = 0; x < NUM_STRANDS + 1; ++x )
     for (int y = 0; y < NUM_LEDS + 1; ++y)
        leds[x][y] = CRGB::Blue;

  FastLED.delay(1000);
}

//Function to blink alternating lights
void blink_alternating_lights()
{


}


//Function to fade the brightness of all
void fade_brightness()
{
  //first give each a color
   for ( int x = 0; x < NUM_STRANDS; ++x )
    for (int y = 0; y < NUM_LEDS; ++y )
    {
      leds[x][y].r=random(255);   //random is in the Arduino library.  Sends back a random number between 0 and its argument, inclusive.
      leds[x][y].g=random(255);   //One way to set the color of the LEDs to a custom color.
      leds[x][y].b=random(255);
    }
  //then do brightness
  //for()
  //{
  //  FastLED.setBrightness(brightness);
  //  FastLED.delay(50);
  //}
}


void chase()
{

}


void chase_two_colors_with_scroll()
{
  
}
