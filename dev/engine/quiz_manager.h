#ifndef _QUIZ_MANAGER_H_
#define _QUIZ_MANAGER_H_

#define QUIZ_X	2
#define QUIZ_Y	5

#define TITLE_X	23
#define TITLE_Y	3

#define OPTN_X	4
#define OPTA_Y	9
#define OPTB_Y	13
#define OPTC_Y	17
#define OPTD_Y	21

#define QUIZ_BANK	2

extern unsigned char diff_select;
extern unsigned char quiz_questions[MAX_QUESTIONS];
extern unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];
extern unsigned char option_height[MAX_OPTIONS];
extern unsigned char select_diff_option[MAX_OPTIONS][6];
extern unsigned char question_value, answer_index, answer_value, question_long;
extern unsigned char local_cheat;

// Private helper method.
static void engine_quiz_manager_diff( unsigned char x, unsigned char y );

void engine_quiz_manager_init()
{
	option_height[0] = OPTA_Y;
	option_height[1] = OPTB_Y;
	option_height[2] = OPTC_Y;
	option_height[3] = OPTD_Y;
}

void engine_quiz_manager_base()
{
	engine_font_manager_draw_text( LOCALE_QUESTION, QUIZ_X, TITLE_Y );
	if( hacker_extra )
	{
		// Display total number of questions.
		engine_font_manager_draw_text( LOCALE_FSLASH_SYM, QUIZ_X + 13, TITLE_Y );
		engine_font_manager_draw_data_ZERO( question_long, QUIZ_X + 16, TITLE_Y );
	}
}

void engine_quiz_manager_base2()
{
	engine_quiz_manager_diff( 26, TITLE_Y - 1 );
}

void engine_quiz_manager_base3( unsigned char y )
{
	engine_quiz_manager_diff( 24, y );
}

void engine_quiz_manager_bank( unsigned char b )
{
	SMS_mapROMBank(b);
}

void engine_quiz_manager_answer( unsigned char q )
{
	if( DIFF_TYPE_EASY == diff_select )
	{
		answer_value = bank2_soln[q];
	}
	else if( DIFF_TYPE_NORM == diff_select )
	{
		answer_value = bank3_soln[q];
	}
	else if( DIFF_TYPE_HARD == diff_select )
	{
		answer_value = bank4_soln[q];
	}
	else if( DIFF_TYPE_ARGH == diff_select )
	{
		answer_value = bank5_soln[q];
	}

	answer_value -= 1;		// Zero based index
	answer_index = quiz_options[q][answer_value];
}

void engine_quiz_manager_cheat( unsigned char ans )
{
	unsigned char idx, cheat_Y;

	for( idx = 0; idx < MAX_OPTIONS; idx++)
	{
		cheat_Y = option_height[idx];
		engine_font_manager_draw_text( LOCALE_ARROW_SPACE, QUIZ_X-1, cheat_Y );
	}

	if( local_cheat )
	{
		cheat_Y = option_height[ans];
		engine_font_manager_draw_text( LOCALE_ARROW_LEFT, QUIZ_X-1, cheat_Y );
	}
}
void engine_quiz_manager_cheat2( unsigned char ans, unsigned char flag )
{
	unsigned char cheat_Y;
	if( local_cheat )
	{
		cheat_Y = option_height[ans];
		if ( !flag )
		{
			engine_font_manager_draw_text( LOCALE_ARROW_LEFT, QUIZ_X - 1, cheat_Y );
		}
		else
		{
			engine_font_manager_draw_text( LOCALE_ARROW_SPACE, QUIZ_X - 1, cheat_Y );
		}
	}
}

void engine_quiz_manager_load(unsigned char qi, unsigned char qv, unsigned char opt1, unsigned char opt2, unsigned char opt3, unsigned char opt4)
{
	unsigned char opt1_Y, opt2_Y, opt3_Y, opt4_Y;
	unsigned char bank;

	opt1_Y = option_height[opt1];
	opt2_Y = option_height[opt2];
	opt3_Y = option_height[opt3];
	opt4_Y = option_height[opt4];

	// Number.
	engine_font_manager_draw_data_ZERO( qi + 1, QUIZ_X + 12, TITLE_Y );
	qv = qv * 1;

	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );

	if( DIFF_TYPE_EASY == diff_select )
	{
		// Question.
		engine_font_manager_draw_text( bank2_quiz_line1[qv], QUIZ_X, QUIZ_Y + 0 );
		engine_font_manager_draw_text( bank2_quiz_line2[qv], QUIZ_X, QUIZ_Y + 1 );
		engine_font_manager_draw_text( bank2_quiz_line3[qv], QUIZ_X, QUIZ_Y + 2 );

		// Option A.
		engine_font_manager_draw_text( bank2_opt1_line1[qv], OPTN_X, opt1_Y + 0 );
		engine_font_manager_draw_text( bank2_opt1_line2[qv], OPTN_X, opt1_Y + 1 );
		engine_font_manager_draw_text( bank2_opt1_line3[qv], OPTN_X, opt1_Y + 2 );

		// Option B.
		engine_font_manager_draw_text( bank2_opt2_line1[qv], OPTN_X, opt2_Y + 0 );
		engine_font_manager_draw_text( bank2_opt2_line2[qv], OPTN_X, opt2_Y + 1 );
		engine_font_manager_draw_text( bank2_opt2_line3[qv], OPTN_X, opt2_Y + 2 );

		// Option C.
		engine_font_manager_draw_text( bank2_opt3_line1[qv], OPTN_X, opt3_Y + 0 );
		engine_font_manager_draw_text( bank2_opt3_line2[qv], OPTN_X, opt3_Y + 1 );
		engine_font_manager_draw_text( bank2_opt3_line3[qv], OPTN_X, opt3_Y + 2 );

		// Option D.
		engine_font_manager_draw_text( bank2_opt4_line1[qv], OPTN_X, opt4_Y + 0 );
		engine_font_manager_draw_text( bank2_opt4_line2[qv], OPTN_X, opt4_Y + 1 );
		engine_font_manager_draw_text( bank2_opt4_line3[qv], OPTN_X, opt4_Y + 2 );
	}
	else if( DIFF_TYPE_NORM == diff_select )
	{
		// Question.
		engine_font_manager_draw_text( bank3_quiz_line1[qv], QUIZ_X, QUIZ_Y + 0 );
		engine_font_manager_draw_text( bank3_quiz_line2[qv], QUIZ_X, QUIZ_Y + 1 );
		engine_font_manager_draw_text( bank3_quiz_line3[qv], QUIZ_X, QUIZ_Y + 2 );

		// Option A.
		engine_font_manager_draw_text( bank3_opt1_line1[qv], OPTN_X, opt1_Y + 0 );
		engine_font_manager_draw_text( bank3_opt1_line2[qv], OPTN_X, opt1_Y + 1 );
		engine_font_manager_draw_text( bank3_opt1_line3[qv], OPTN_X, opt1_Y + 2 );

		// Option B.
		engine_font_manager_draw_text( bank3_opt2_line1[qv], OPTN_X, opt2_Y + 0 );
		engine_font_manager_draw_text( bank3_opt2_line2[qv], OPTN_X, opt2_Y + 1 );
		engine_font_manager_draw_text( bank3_opt2_line3[qv], OPTN_X, opt2_Y + 2 );

		// Option C.
		engine_font_manager_draw_text( bank3_opt3_line1[qv], OPTN_X, opt3_Y + 0 );
		engine_font_manager_draw_text( bank3_opt3_line2[qv], OPTN_X, opt3_Y + 1 );
		engine_font_manager_draw_text( bank3_opt3_line3[qv], OPTN_X, opt3_Y + 2 );

		// Option D.
		engine_font_manager_draw_text( bank3_opt4_line1[qv], OPTN_X, opt4_Y + 0 );
		engine_font_manager_draw_text( bank3_opt4_line2[qv], OPTN_X, opt4_Y + 1 );
		engine_font_manager_draw_text( bank3_opt4_line3[qv], OPTN_X, opt4_Y + 2 );
	}
	else if( DIFF_TYPE_HARD == diff_select )
	{
		// Question.
		engine_font_manager_draw_text( bank4_quiz_line1[qv], QUIZ_X, QUIZ_Y + 0 );
		engine_font_manager_draw_text( bank4_quiz_line2[qv], QUIZ_X, QUIZ_Y + 1 );
		engine_font_manager_draw_text( bank4_quiz_line3[qv], QUIZ_X, QUIZ_Y + 2 );

		// Option A.
		engine_font_manager_draw_text( bank4_opt1_line1[qv], OPTN_X, opt1_Y + 0 );
		engine_font_manager_draw_text( bank4_opt1_line2[qv], OPTN_X, opt1_Y + 1 );
		engine_font_manager_draw_text( bank4_opt1_line3[qv], OPTN_X, opt1_Y + 2 );

		// Option B.
		engine_font_manager_draw_text( bank4_opt2_line1[qv], OPTN_X, opt2_Y + 0 );
		engine_font_manager_draw_text( bank4_opt2_line2[qv], OPTN_X, opt2_Y + 1 );
		engine_font_manager_draw_text( bank4_opt2_line3[qv], OPTN_X, opt2_Y + 2 );

		// Option C.
		engine_font_manager_draw_text( bank4_opt3_line1[qv], OPTN_X, opt3_Y + 0 );
		engine_font_manager_draw_text( bank4_opt3_line2[qv], OPTN_X, opt3_Y + 1 );
		engine_font_manager_draw_text( bank4_opt3_line3[qv], OPTN_X, opt3_Y + 2 );

		// Option D.
		engine_font_manager_draw_text( bank4_opt4_line1[qv], OPTN_X, opt4_Y + 0 );
		engine_font_manager_draw_text( bank4_opt4_line2[qv], OPTN_X, opt4_Y + 1 );
		engine_font_manager_draw_text( bank4_opt4_line3[qv], OPTN_X, opt4_Y + 2 );
	}
	else if( DIFF_TYPE_ARGH == diff_select )
	{
		// Question.
		engine_font_manager_draw_text( bank5_quiz_line1[qv], QUIZ_X, QUIZ_Y + 0 );
		engine_font_manager_draw_text( bank5_quiz_line2[qv], QUIZ_X, QUIZ_Y + 1 );
		engine_font_manager_draw_text( bank5_quiz_line3[qv], QUIZ_X, QUIZ_Y + 2 );

		// Option A.
		engine_font_manager_draw_text( bank5_opt1_line1[qv], OPTN_X, opt1_Y + 0 );
		engine_font_manager_draw_text( bank5_opt1_line2[qv], OPTN_X, opt1_Y + 1 );
		engine_font_manager_draw_text( bank5_opt1_line3[qv], OPTN_X, opt1_Y + 2 );

		// Option B.
		engine_font_manager_draw_text( bank5_opt2_line1[qv], OPTN_X, opt2_Y + 0 );
		engine_font_manager_draw_text( bank5_opt2_line2[qv], OPTN_X, opt2_Y + 1 );
		engine_font_manager_draw_text( bank5_opt2_line3[qv], OPTN_X, opt2_Y + 2 );

		// Option C.
		engine_font_manager_draw_text( bank5_opt3_line1[qv], OPTN_X, opt3_Y + 0 );
		engine_font_manager_draw_text( bank5_opt3_line2[qv], OPTN_X, opt3_Y + 1 );
		engine_font_manager_draw_text( bank5_opt3_line3[qv], OPTN_X, opt3_Y + 2 );

		// Option D.
		engine_font_manager_draw_text( bank5_opt4_line1[qv], OPTN_X, opt4_Y + 0 );
		engine_font_manager_draw_text( bank5_opt4_line2[qv], OPTN_X, opt4_Y + 1 );
		engine_font_manager_draw_text( bank5_opt4_line3[qv], OPTN_X, opt4_Y + 2 );
	}
}

void engine_quiz_manager_diff( unsigned char x, unsigned char y )
{
	if( !hacker_extra )
	{
		return;
	}

	// Display difficulty level for quiz.
	engine_font_manager_draw_text( LOCALE_SQUARE_LEFT, x + 0, y );
	engine_font_manager_draw_text( LOCALE_SQUARE_RIGHT, x + 5, y );
	engine_font_manager_draw_text( select_diff_option[diff_select], x + 1, y );
}

#endif//_QUIZ_MANAGER_H_