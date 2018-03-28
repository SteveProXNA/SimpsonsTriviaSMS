#ifndef _TEST1_SCREEN_H_
#define _TEST1_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_test1_screen_delay;

extern unsigned char question_index, question_value, question_long, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

void screen_test1_screen_init()
{
	screen_test1_screen_delay = 25;
	question_value = 0;
}

// Ready
void screen_test1_screen_load()
{
	unsigned char bank;

	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("TEST1", 0, 1);

	screen_bases_screen_init();

	question_index = 0;

	rand();


	engine_random_manager_init();
	if( hacker_debug )
	{
		engine_debug_manager_init();
	}


	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );


	engine_random_manager_load();
	engine_select_manager_load_quiz();



	//engine_random_manager_load_random();
	//engine_random_manager_load_normal();

	if( hacker_debug )
	{
		engine_debug_manager_load();
	}

	//engine_debug_manager_quest4();


	// TODO remove
	if( hacker_debug )
	{
		engine_debug_manager_quest(0);
	}

	//engine_quiz_manager_answer(0);
}

void screen_test1_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_test1_screen_delay)
	{
		//*screen_type = SCREEN_TYPE_TEST1;
		*screen_type = SCREEN_TYPE_TEST2;
	}
}

#endif//_TEST1_SCREEN_H_