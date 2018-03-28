#ifndef _READY_SCREEN_H_
#define _READY_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned int screen_bases_screen_timer2;
extern unsigned int screen_ready_screen_delay;
extern unsigned char screen_ready_screen_delay2, screen_ready_screen_dots;
extern unsigned char question_index, question_value, question_long, question_count;

void screen_ready_screen_init()
{
	screen_ready_screen_delay = TITLE_DELAY * 3;
	screen_ready_screen_delay2 = NORMAL_DELAY;
}

void screen_ready_screen_load()
{
	screen_bases_screen_init();

	// Clear space.
	engine_select_manager_clear();

	engine_font_manager_draw_text( LOCALE_DIFFICULTY, 2, 6 );
	engine_font_manager_draw_text( LOCALE_ARROW_LEFT, 1, 7 );
	engine_font_manager_draw_text( select_diff_option[diff_select], 2, 7 );

	engine_font_manager_draw_text( LOCALE_QUESTIONS, 2, 11 );
	engine_font_manager_draw_text( LOCALE_ARROW_LEFT, 1, 12 );
	engine_font_manager_draw_data( question_long, 4, 12 );

	engine_font_manager_draw_text( LOCALE_GET, 2, 17 );
	engine_font_manager_draw_text( LOCALE_READY, 2, 18 );

	// Initialize all relevant variables before quiz starts...
	question_index = 0;
	question_value = 0;
	question_count = 0;
	engine_score_manager_init();

	screen_bases_screen_timer2 = 0;
	screen_ready_screen_dots = 0;
}

void screen_ready_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	unsigned char level = 0;

	rand();
	input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
	if( input )
	{
		*screen_type = SCREEN_TYPE_LONG;
		return;
	}
	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1 );
	if( input )
	{
		level = 1;
	}

	// Moving dots "animation".
	screen_bases_screen_timer2++;
	if ( screen_bases_screen_timer2 >= screen_ready_screen_delay2 )
	{
		screen_ready_screen_dots++;
		if( screen_ready_screen_dots > 3 )
		{
			engine_font_manager_draw_text( LOCALE_READY, 2, 18 );
			screen_ready_screen_dots = 0;
		}
		else
		{
			engine_font_manager_draw_text( LOCALE_DOT, DOTS_X + screen_ready_screen_dots, DOTS_Y );
		}

		screen_bases_screen_timer2 = 0;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_ready_screen_delay )
	{
		level = 1;
	}

	if ( level )
	{
		engine_select_manager_clear();
		engine_audio_manager_stop_music();

		*screen_type = SCREEN_TYPE_LEVEL;
		return;
	}

	*screen_type = SCREEN_TYPE_READY;
}

#endif//_READY_SCREEN_H_