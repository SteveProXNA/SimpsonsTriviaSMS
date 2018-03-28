#ifndef _INTRO_SCREEN_H_
#define _INTRO_SCREEN_H_

extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_bases_screen_count;
extern unsigned char screen_intro_screen_delay;
extern unsigned char cheat_count, local_cheat;

void screen_intro_screen_init()
{
	screen_intro_screen_delay = NORMAL_DELAY;
}

void screen_intro_screen_load()
{
	local_cheat = 0;
	cheat_count = 0;
	screen_bases_screen_init();

	engine_select_manager_clear();
	engine_font_manager_draw_text( LOCALE_PRESS, 2, 13 );
	engine_font_manager_draw_text( LOCALE_START, 2, 14 );

	if ( hacker_cheat )
	{
		engine_font_manager_draw_text( LOCALE_CHEAT, 25, 10 );
		engine_font_manager_draw_text( LOCALE_MODE, 25, 11 );
		
		engine_audio_manager_sound_cheat();
		local_cheat = 1;
	}
}

void screen_intro_screen_update( unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1 )
{
	unsigned char input = 0;
	rand();

	screen_bases_screen_timer++;
	if ( screen_bases_screen_timer >= screen_intro_screen_delay )
	{
		if( screen_bases_screen_count )
		{
			engine_font_manager_draw_text( LOCALE_PRESS, 2, 13 );
			engine_font_manager_draw_text( LOCALE_START, 2, 14 );
		}
		else
		{
			engine_font_manager_draw_text( LOCALE_BLANK5, 2, 13 );
			engine_font_manager_draw_text( LOCALE_BLANK5, 2, 14 );
		}

		screen_bases_screen_count = !screen_bases_screen_count;
		screen_bases_screen_timer = 0;
	}

	input = engine_input_manager_hold_fire1( curr_joypad1, prev_joypad1);
	if( input )
	{
		*screen_type = SCREEN_TYPE_DIFF;
		return;
	}
	if( engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 ) )
	{
		if ( !hacker_cheat && !local_cheat )
		{
			cheat_count++;
			if( cheat_count >= CHEAT_TOTAL )
			{
				engine_font_manager_draw_text( LOCALE_CHEAT, 25, 10 );
				engine_font_manager_draw_text( LOCALE_MODE, 25, 11 );

				engine_audio_manager_sound_cheat();
				local_cheat = 1;
			}
		}
	}

	*screen_type = SCREEN_TYPE_INTRO;
}

#endif//_INTRO_SCREEN_H_