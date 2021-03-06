#pragma once

#include <ArduboyTones.h>

const uint16_t intro_theme[] PROGMEM = {
  NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85,
  NOTE_CS4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,428, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85,
  NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_CS4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,428,
  NOTE_C4,171, NOTE_REST,171, NOTE_C4,171, NOTE_REST,171, NOTE_CS4,342, NOTE_REST,428, NOTE_C4,85, NOTE_REST,85,
  NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_CS4,85, NOTE_REST,85,
  NOTE_C4,85, NOTE_REST,428, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85,
  NOTE_C4,85, NOTE_REST,85, NOTE_CS4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,428, NOTE_C4,85, NOTE_REST,85,
  NOTE_CS4,85, NOTE_REST,85, NOTE_D4,85, NOTE_REST,85, NOTE_CS4,85, NOTE_REST,85, NOTE_C4,85,
  TONES_END
};

const uint16_t wave_start[] PROGMEM = {
  NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85, NOTE_C4,85, NOTE_REST,85,
  NOTE_CS4,85, NOTE_REST,85, NOTE_C4,85, TONES_END
};

const uint16_t wave_success[] PROGMEM = {
  NOTE_FS5,498, NOTE_REST,144, NOTE_FS5,34, NOTE_REST,72, NOTE_FS5,34, NOTE_REST,72, NOTE_FS5,177,
  NOTE_REST,108, NOTE_FS5,105, NOTE_REST,36, NOTE_FS5,70, NOTE_REST,72, NOTE_GS5,105, NOTE_REST,36, NOTE_AS5,105,
  NOTE_REST,36, NOTE_B5,1034, NOTE_REST,251, NOTE_B5,105, NOTE_REST,36, NOTE_CS6,70, NOTE_REST,72, NOTE_DS6,70,
  NOTE_REST,72, NOTE_F6,605, NOTE_REST,36, NOTE_F6,34, NOTE_REST,72, NOTE_F6,34, NOTE_REST,72, NOTE_F6,34,
  NOTE_REST,179, NOTE_CS6,177, NOTE_REST,36, NOTE_F6,70, NOTE_REST,72, NOTE_FS6,117, NOTE_REST,24, NOTE_GS6,105,
  NOTE_REST,36, NOTE_FS6,1641,
  TONES_END
};

const uint16_t end_of_game[] PROGMEM = {
  NOTE_C3,342, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85,
  NOTE_C3,342, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85, NOTE_CS3,85, NOTE_REST,85,
  NOTE_C3,342,
  TONES_END
};

const uint16_t player_fires_bullet[] PROGMEM = {
  NOTE_C5,50, NOTE_C3,100, NOTE_C2,200,
  TONES_END
};

const uint16_t enemy_fires_bullet[] PROGMEM = {
  NOTE_F3,22, NOTE_F3,22, NOTE_F3,22,
  TONES_END
};

const uint16_t player_hit_by_alien[] PROGMEM = {
  NOTE_F3,3, NOTE_D4,4, NOTE_A4,4, NOTE_E3,1, 
  TONES_END
};

const uint16_t player_hit_by_bullet[] PROGMEM = {
  NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  TONES_END
};

const uint16_t bullets_collide[] PROGMEM = {
  NOTE_A3,9, TONES_END
};

const uint16_t player_explosion[] PROGMEM = {
  NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, 
  TONES_END
};

const uint16_t enemy_explosion[] PROGMEM = {
  NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_A3,9, NOTE_D3,10, NOTE_C3,6, NOTE_F3,10, 
  NOTE_B3, 9, NOTE_E3, 10, 
  TONES_END
};


const uint16_t double_up[] PROGMEM = {
  NOTE_C3,40, NOTE_REST,20,
  NOTE_C4,40, NOTE_REST,20,
  NOTE_C5,40, NOTE_REST,20,
  TONES_END
};

const uint16_t formation_launch_1[] PROGMEM = {
  NOTE_B3, 9, NOTE_E3, 10, TONES_END
};

const uint16_t formation_launch_2[] PROGMEM = {
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, 
  TONES_END
};

const uint16_t formation_launch_3[] PROGMEM = {
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, TONES_END
};

const uint16_t formation_launch_4[] PROGMEM = {
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, NOTE_REST, 30, 
  NOTE_B3, 9, NOTE_E3, 10, TONES_END
};

const uint16_t blib[] PROGMEM = {
  NOTE_C3, 40, NOTE_REST, 500, TONES_END
};


const uint16_t *formation_launch[] = { formation_launch_1, formation_launch_2, formation_launch_3, formation_launch_4 };