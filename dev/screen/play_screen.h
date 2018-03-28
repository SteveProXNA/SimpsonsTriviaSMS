#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_cheat_screen_delay;

extern unsigned char question_index, question_value, question_long, question_count;
extern unsigned char question_value, option1_value, option2_value, option3_value, option4_value;
extern unsigned char answer_index, answer_value;

void screen_play_screen_init()
{
	screen_cheat_screen_delay = TITLE_DELAY * 2/5;
}

void screen_play_screen_load()
{
	engine_quiz_manager_base();
	engine_quiz_manager_base2();
	engine_score_manager_base();

	question_value = quiz_questions[question_index];
	option1_value = quiz_options[question_value][0];
	option2_value = quiz_options[question_value][1];
	option3_value = quiz_options[question_value][2];
	option4_value = quiz_options[question_value][3];

	engine_select_manager_base();
	engine_quiz_manager_load(question_index, question_value, option1_value, option2_value, option3_value, option4_value);

	engine_quiz_manager_answer(question_value);
	engine_quiz_manager_cheat(answer_index);
}

void screen_play_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		*screen_type = SCREEN_TYPE_QUIZ;
		return;
	}

	input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
	if( input )
	{
		*screen_type = SCREEN_TYPE_SCORE;
		return;
	}

	engine_select_manager_draw_select();

	screen_bases_screen_timer++;
	if ( screen_bases_screen_timer >= screen_cheat_screen_delay )
	{
		engine_quiz_manager_cheat2( answer_index, screen_bases_screen_count );
		screen_bases_screen_count = !screen_bases_screen_count;
		screen_bases_screen_timer = 0;
	}

	input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
	if( input )
	{
		quiz_select = engine_select_manager_move_up( quiz_select );
	}
	input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
	if (input)
	{
		quiz_select = engine_select_manager_move_down( quiz_select );
	}

	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_PLAY_SCREEN_H_