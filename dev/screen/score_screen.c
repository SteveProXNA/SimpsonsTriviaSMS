#include "score_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/input_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/score_manager.h"
#include "../engine/select_manager.h"

// IMPORTANT disable compiler warning 4244
#ifdef _CONSOLE
#pragma warning( disable : 4244 ) 
#endif

void screen_score_screen_load()
{
	float percent = 0.0f;
	engine_select_manager_clear2();

	engine_quiz_manager_base3( TITLE_Y + 2 );
	engine_font_manager_text( LOCALE_FIRE2, 2, 21 );
	engine_font_manager_text( LOCALE_FIRE1, 2, 22 );

	engine_font_manager_text( LOCALE_STATISTICS, 8, TITLE_Y );
	engine_font_manager_text( LOCALE_QUIZ_TOTAL, SUMMARY_TEXT_X, 5 );
	engine_font_manager_data_ZERO( question_long, SUMMARY_DATA_X, 6 );

	engine_font_manager_text( LOCALE_QUIZ_SOLVE, SUMMARY_TEXT_X, 9 );
	engine_font_manager_data_ZERO( question_count, SUMMARY_DATA_X, 10 );

	engine_font_manager_text( LOCALE_QUIZ_RIGHT, SUMMARY_TEXT_X, 13 );
	engine_font_manager_data_ZERO( score_player, SUMMARY_DATA_X, 14 );

	// Allow for potential division by zero error.
	engine_font_manager_text( LOCALE_CURR_PERCENT, SUMMARY_TEXT_X, 17 );
	if( question_count == 0 )
	{
		engine_font_manager_data_ZERO( percent, SUMMARY_DATA_X, 18 );
		engine_font_manager_text( LOCALE_PERCENT_SYM, SUMMARY_DATA_X + 1, 18 );
		return;
	}

	percent = ( float ) score_player / ( float ) question_count * 100;
	engine_font_manager_data_ZERO( percent, SUMMARY_DATA_X, 18 );
	engine_font_manager_text( LOCALE_PERCENT_SYM, SUMMARY_DATA_X + 1, 18 );
}

void screen_score_screen_update( unsigned char *screen_type )
{
	unsigned char input = 0;

	input = engine_input_manager_hold_fire2();
	if( input )
	{
		engine_select_manager_clear2();
		*screen_type = screen_type_play;
		return;
	}

	input = engine_input_manager_hold_fire1();
	if( input )
	{
		*screen_type = screen_type_over;
		return;
	}

	*screen_type = screen_type_score;
}
