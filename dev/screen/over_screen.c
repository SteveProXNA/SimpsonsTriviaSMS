#include "over_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"
#include "../engine/timer_manager.h"

// IMPORTANT disable compiler warning 4244
#ifdef _CONSOLE
#pragma warning( disable : 4244 ) 
#endif

static unsigned char screen_over_screen_delay1;
static unsigned int screen_over_screen_delay2;

void screen_over_screen_init()
{
	screen_over_screen_delay1 = TITLE_DELAY * 2;
	screen_over_screen_delay2 = TITLE_DELAY * 8;
}

void screen_over_screen_load()
{
	float percent = 0.0f;
	screen_bases_screen_init();

	engine_quiz_manager_base3( TITLE_Y + 2 );
	engine_font_manager_text( LOCALE_OVER_MSG1, 2, 21 );
	engine_font_manager_text( LOCALE_OVER_MSG2, 2, 22 );

	engine_font_manager_text( LOCALE_UNDERLINED, 8, TITLE_Y - 1 );
	engine_font_manager_text( LOCALE_COMPLETION, 8, TITLE_Y + 0 );
	engine_font_manager_text( LOCALE_UNDERLINED, 8, TITLE_Y + 1 );

	engine_font_manager_text( LOCALE_QUIZ_TOTAL, SUMMARY_TEXT_X, 5 );
	engine_font_manager_data_ZERO( question_long, SUMMARY_DATA_X, 6 );

	engine_font_manager_text( LOCALE_QUIZ_SOLVE, SUMMARY_TEXT_X, 9 );
	engine_font_manager_data_ZERO( question_count, SUMMARY_DATA_X, 10 );

	engine_font_manager_text( LOCALE_QUIZ_RIGHT, SUMMARY_TEXT_X, 13 );
	engine_font_manager_data_ZERO( score_player, SUMMARY_DATA_X, 14 );

	engine_font_manager_text( LOCALE_OVER_PERCENT, SUMMARY_TEXT_X, 17 );
	percent = ( float ) score_player / ( float ) question_count * 100;
	engine_font_manager_data_ZERO( percent, SUMMARY_DATA_X, 18 );
	engine_font_manager_text( LOCALE_PERCENT_SYM, SUMMARY_DATA_X + 1, 18 );

	engine_audio_manager_finish_music();
}

void screen_over_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;
	unsigned char level = 0;

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer < screen_over_screen_delay1 )
	{
		return;
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		level = 1;
	}

	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_over_screen_delay2 )
	{
		level = 1;
	}

	if( level )
	{
		*screen_type = screen_type_title;
		return;
	}

	*screen_type = screen_type_over;
}
