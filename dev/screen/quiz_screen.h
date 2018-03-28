#ifndef _QUIZ_SCREEN_H_
#define _QUIZ_SCREEN_H_

extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_bases_screen_count;
extern unsigned char screen_quiz_screen_delay, screen_quiz_screen_state;

void screen_quiz_screen_init()
{
	screen_quiz_screen_delay = NORMAL_DELAY * 2;
}

void screen_quiz_screen_load()
{
	question_count++;
	screen_bases_screen_init();

	if( quiz_select == answer_index )
	{
		screen_quiz_screen_state = ANSWER_TYPE_RIGHT;
		
	}
	else
	{
		screen_quiz_screen_state = ANSWER_TYPE_WRONG;
	}

	if( ANSWER_TYPE_RIGHT == screen_quiz_screen_state )
	{
		engine_audio_manager_sound_right();
		engine_score_manager_update();
	}
	else
	{
		engine_audio_manager_sound_wrong();
	}
}

void screen_quiz_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	// Logic: display right or wrong sprite for delay.
	// Increment question counter
	// After the delay check this
	// if all questions answered then game over
	// otherwise then resume next question

	unsigned char input = 0;
	unsigned char level = 0;

	if( ANSWER_TYPE_RIGHT == screen_quiz_screen_state )
	{
		engine_select_manager_draw_right();
	}
	else
	{
		engine_select_manager_draw_wrong();
	}

	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1);
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_quiz_screen_delay)
	{
		level = 1;
	}

	if ( level )
	{
		question_index++;
		if ( question_index >= question_long )
		{
			*screen_type = SCREEN_TYPE_OVER;
			return;
		}

		*screen_type = SCREEN_TYPE_PLAY;
		return;
	}

	*screen_type = SCREEN_TYPE_QUIZ;
}

#endif//_QUIZ_SCREEN_H_