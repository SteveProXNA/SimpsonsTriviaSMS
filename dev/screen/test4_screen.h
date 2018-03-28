#ifndef _TEST4_SCREEN_H_
#define _TEST4_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_test4_screen_delay;

void screen_test4_screen_init()
{
	screen_test4_screen_delay = 100;
}

void screen_test4_screen_load()
{
	screen_bases_screen_init();
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("TEST4", 0, 1);


	/*engine_select_manager_load_long();
	engine_select_manager_base();*/
}

void screen_test4_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	//unsigned char input = 0;
	//engine_select_manager_draw_select();

	//input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	//if( input )
	//{
	//	long_select = engine_select_manager_move_up( long_select );
	//}
	//input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	//if (input)
	//{
	//	long_select = engine_select_manager_move_down( long_select );
	//}

	//// Set the number of questions.
	//input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
	//if (input)
	//{
	//	question_long = select_long_option[ long_select ];
	//	engine_font_manager_draw_data( long_select, 25, 5 );
	//	engine_font_manager_draw_data( question_long, 25, 7 );

	//	*screen_type = SCREEN_TYPE_TEST5;
	//	return;
	//}

	*screen_type = SCREEN_TYPE_TEST4;
}

#endif//_TEST4_SCREEN_H_