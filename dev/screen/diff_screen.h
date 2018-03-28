#ifndef _DIFF_SCREEN_H_
#define _DIFF_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_diff_screen_delay, screen_diff_screen_state;

void screen_diff_screen_init()
{
	screen_diff_screen_delay = NORMAL_DELAY;
}

void screen_diff_screen_load()
{
	screen_bases_screen_init();
	screen_diff_screen_state = SELECT_TYPE_BEFORE;

	engine_select_manager_clear();
	engine_select_manager_base();

	engine_font_manager_draw_text( LOCALE_DIFFICULTY, 2, 6);
	engine_select_manager_load_diff();
}

void screen_diff_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	rand();

	if( SELECT_TYPE_BEFORE == screen_diff_screen_state )
	{
		engine_select_manager_draw_select();
		input = engine_input_manager_hold_up(curr_joypad1, prev_joypad1);
		if( input )
		{
			diff_select = engine_select_manager_move_up( diff_select );
		}
		input = engine_input_manager_hold_down(curr_joypad1, prev_joypad1);
		if (input)
		{
			diff_select = engine_select_manager_move_down( diff_select );
		}
		// IMPORTANT - don't allow to go back here as invalidates cheat mode!
		//input = engine_input_manager_hold_fire2(curr_joypad1, prev_joypad1);
		//if (input)
		//{
		//	*screen_type = SCREEN_TYPE_INTRO;
		//	return;
		//}
		input = engine_input_manager_hold_fire1(curr_joypad1, prev_joypad1);
		if (input)
		{
			engine_audio_manager_sound_right();
			screen_diff_screen_state = SELECT_TYPE_AFTER;
		}
	}

	if( SELECT_TYPE_AFTER == screen_diff_screen_state )
	{
		engine_select_manager_draw_right();

		screen_bases_screen_timer++;
		if (screen_bases_screen_timer >= screen_diff_screen_delay)
		{
			*screen_type = SCREEN_TYPE_LONG;
			return;
		}
	}

	*screen_type = SCREEN_TYPE_DIFF;
}

#endif//_DIFF_SCREEN_H_