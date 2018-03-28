#ifndef __MAIN__
#define __MAIN__

#include <stdbool.h>
#include <stdlib.h>
#include "..\lib\SMSlib.h"
#include "..\lib\PSGlib.h"
#include "gfx.h"
#include "psg.h"

#include "banks\bank2.h"
#include "banks\bank3.h"
#include "banks\bank4.h"
#include "banks\bank5.h"
#include "banks\bank6.h"
#include "banks\bank7.h"

#include "engine\global_manager.h"
#include "engine\locale_manager.h"
#include "engine\enum_manager.h"
#include "engine\hack_manager.h"
#include "engine\content_manager.h"
#include "engine\image_manager.h"
#include "engine\font_manager.h"
#include "engine\quiz_manager.h"
#include "engine\random_manager.h"
#include "engine\sprite_manager.h"
#include "engine\select_manager.h"
#include "engine\score_manager.h"
#include "engine\audio_manager.h"
#include "engine\input_manager.h"
#include "engine\debug_manager.h"
#include "engine\asm_manager.h"

#include "screen\bases_screen.h"
#include "screen\splash_screen.h"
#include "screen\title_screen.h"
#include "screen\intro_screen.h"
#include "screen\diff_screen.h"
#include "screen\long_screen.h"
#include "screen\level_screen.h"
#include "screen\number_screen.h"
#include "screen\ready_screen.h"
#include "screen\play_screen.h"
#include "screen\quiz_screen.h"
#include "screen\score_screen.h"
#include "screen\over_screen.h"
#include "screen\credit_screen.h"

#include "screen\test1_screen.h"
#include "screen\test2_screen.h"
#include "screen\test3_screen.h"
#include "screen\test4_screen.h"
#include "screen\test5_screen.h"

//_QUIZ_MANAGER_H_
unsigned char quiz_questions[MAX_QUESTIONS];
unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];
unsigned char option_height[MAX_OPTIONS];
unsigned char question_index, question_long, question_count;
unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
unsigned char answer_index, answer_value;

//_SCORE_MANAGER_H_
unsigned char score_player;

//_SELECT_MANAGER_H_
unsigned char diff_select, long_select, quiz_select;
unsigned char select_choice, select_height;
unsigned char select_option[MAX_OPTIONS];
unsigned char select_high_option[MAX_OPTIONS];
unsigned char select_text_option[MAX_OPTIONS][3];
unsigned char select_diff_option[MAX_OPTIONS][6];

//_BASES_SCREEN_H_
unsigned int screen_bases_screen_timer;
unsigned char screen_bases_screen_count;

//_SPLASH_SCREEN_H_
unsigned char screen_splash_screen_delay;

//_INTRO_SCREEN_H_
unsigned char screen_intro_screen_delay;
unsigned char cheat_count, local_cheat;

//_DIFF_SCREEN_H_
unsigned char screen_diff_screen_delay, screen_diff_screen_state;

//_LONG_SCREEN_H_
unsigned char screen_long_screen_delay, screen_long_screen_state; 

// _READY_SCREEN_H_
unsigned int screen_bases_screen_timer2;
unsigned int screen_ready_screen_delay;
unsigned char screen_ready_screen_delay2, screen_ready_screen_dots;

//_PLAY_SCREEN_H_
unsigned char screen_cheat_screen_delay;

//_QUIZ_SCREEN_H_
unsigned char screen_quiz_screen_delay, screen_quiz_screen_state;

// _OVER_SCREEN_H_
unsigned char screen_over_screen_delay1;
unsigned int screen_over_screen_delay2; 


//_TEST_SCREEN_H_
unsigned char screen_test1_screen_delay;
unsigned char screen_test2_screen_delay;
unsigned char screen_test3_screen_delay;
unsigned char screen_test4_screen_delay;
unsigned char screen_test5_screen_delay;


#endif//__MAIN__