#include "diff_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/select_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdlib.h>

static unsigned char screen_diff_screen_delay;
static unsigned char screen_diff_screen_state;

void screen_diff_screen_init()
{
	screen_diff_screen_delay = NORMAL_DELAY;
}

void screen_diff_screen_load()
{
	screen_bases_screen_init();
	screen_diff_screen_state = select_type_before;

	engine_font_manager_text( LOCALE_BLANK5, 2, 13 );
	engine_font_manager_text( LOCALE_BLANK5, 2, 14 );

	engine_select_manager_base();
	engine_font_manager_text( LOCALE_DIFFICULTY, 2, 6 );
	engine_select_manager_load_diff();
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	rand();

	if( select_type_before == screen_diff_screen_state )
	{
		engine_select_manager_draw_select();
		input = engine_input_manager_hold_up();
		if( input )
		{
			diff_select = engine_select_manager_move_up( diff_select );
		}
		input = engine_input_manager_hold_down();
		if( input )
		{
			diff_select = engine_select_manager_move_down( diff_select );
		}
		// IMPORTANT - don't allow to go back here as invalidates cheat mode!
		//input = engine_input_manager_hold_fire2( curr_joypad1, prev_joypad1 );
		//if(input)
		//{
		//	*screen_type = SCREEN_TYPE_INTRO;
		//	return;
		//}
		input = engine_input_manager_hold_fire1();
		if( input )
		{
			engine_audio_manager_sound_right();
			screen_diff_screen_state = select_type_after;
		}
	}

	if( select_type_after == screen_diff_screen_state )
	{
		engine_select_manager_draw_right();

		screen_bases_screen_timer++;
		if( screen_bases_screen_timer >= screen_diff_screen_delay )
		{
			*screen_type = screen_type_long;
			return;
		}
	}

	*screen_type = screen_type_diff;
}
