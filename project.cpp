//project.cpp - Put your project code here!

#include "lights.h"
#include "project.h"
#include "tests.h"

//potentiometer range is between ~30 and ~1000
//if you want to print then you need to add serial.begin(9600); to your setup() in grid_framework
void print_range(){
  int input_pin = A0;
  int val = analogRead(input_pin); 
  
  Serial.print("val= ");
  Serial.print(val);
  Serial.print("\n");
}

//change the color of the lights based on the input from the potentiometer
void change_colors(){
  int input_pin = A0;
  int val = analogRead(input_pin);
  //hue only goes from 0 to 255 so we need to adjust the value
  int hue = val%255;
  //Serial.println(hue);

  for ( int x = 0; x < NUM_STRANDS + 1; ++x )
     for (int y = 0; y < NUM_LEDS + 1; ++y)
        leds[x][y] = CHSV(hue,255,255);
  FastLED.show();
}


void switch_between_lights(){
  int input_pin = A0;
  int val = analogRead(input_pin); 
  int divisor = 1000/7; //evenly divide strands into this number 1000/7 = 143
  print_range();
  CRGB color = CRGB::Blue;
  //do different things depending on range
  if (val>=(divisor * 0) && val <(divisor * 1)) {
    light_strand(0, color);
  } else if (val>=(divisor * 1) && val <(divisor * 2)){
    light_strand(1, color);
  }else if (val>=(divisor * 2) && val <(divisor * 3)){
    light_strand(2, color);
  }else if (val>=(divisor * 3) && val <(divisor * 4)){
    light_strand(3, color);
  }else if (val>=(divisor * 4) && val <(divisor * 5)){
    light_strand(4, color);
  }else if (val>=(divisor * 5) && val <(divisor * 6)){
    light_strand(5, color);
  }else if (val>=(divisor * 6) && val <(divisor * 7)){
    light_strand(6, color);
  }
  
}

//turns lights on and off
void lights_on_and_off(){
  int input_pin = A0;
  int val = analogRead(input_pin); 
  if (val < 1000/2) {
    leds_off();
  } else {
    blink_all_lights();
  }
}

//light the given strand to the given color
void light_strand(int strand, CRGB color){
  //turn off the previous lights 
  if(leds[strand][0] != color){
    leds_off();
  }
  for(int i=0; i < NUM_LEDS; i++){
    leds[strand][i] = color;
  }
  FastLED.setBrightness(200);
  FastLED.show();
}
