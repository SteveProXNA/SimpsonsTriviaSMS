#ifndef _TEST3_SCREEN_H_
#define _TEST3_SCREEN_H_

extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_bases_screen_count;
extern unsigned char screen_test3_screen_delay;

void screen_test3_screen_init()
{
	screen_test3_screen_delay = 50;
}

void screen_test3_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("TEST3", 0, 1);

	screen_bases_screen_init();

	//answer_value = engine_quiz_manager_answer(question_value);
	//answer_index = answer_value - 1;		// Zero based index

	// TODO remove
	/*engine_font_manager_draw_data(question_index, 20, 0);
	engine_font_manager_draw_data(question_value, 20, 1);
	engine_font_manager_draw_data(answer_value, 20, 2);*/
	engine_font_manager_draw_data(select_choice, 20, 0);

	// TEST right or wrong!
	if( select_choice == answer_index )
	{
		engine_font_manager_draw_text("RIGHT", 25, 0);
	}
	else
	{
		engine_font_manager_draw_text("WRONG", 25, 0);
	}
	// TODO remove
}

void screen_test3_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_test3_screen_delay)
	{
		question_index++;
		if (question_index >= question_long)
		{
			*screen_type = SCREEN_TYPE_TEST5;
			return;
		}

		//TODO
		engine_font_manager_draw_data(question_index, 20, 0);

		*screen_type = SCREEN_TYPE_TEST2;
		//*screen_type = SCREEN_TYPE_TEST3;
		return;
	}

	*screen_type = SCREEN_TYPE_TEST3;
}

#endif//_TEST3_SCREEN_H_