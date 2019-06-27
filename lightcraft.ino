


#include "FastLED.h"
#include "lights.h"
#include "tests.h"
#include "project.h"

CRGB leds[NUM_STRANDS+1][NUM_LEDS+1];



void setup()
{
  //when Serial is in use, the first strand of lights will not work because the output for pin 1 is in use by Serial
  //Serial.begin(9600);
  
  delay( 3000 ); // power-up safety delay
  
  leds_init();

  test_leds();
 
  leds_off(); 
}

void loop()
{ 
  
//  blink_light_0_0_example();
  //blink_lights_0_0_and_2_4();
  //blink_all_lights();
  //blink_alternating_lights();
  //fade_brightness();
  //chase();
  //chase_two_colors_with_scroll();
  //switch_between_lights();
  change_colors();
  //print_range();
    
  //add other functions you would like to execute here!
  
    
}
