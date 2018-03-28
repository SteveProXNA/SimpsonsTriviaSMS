#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

// Screen type.
#define SCREEN_TYPE_NONE	0
#define SCREEN_TYPE_SPLASH	1
#define SCREEN_TYPE_TITLE	2
#define SCREEN_TYPE_INTRO	3
#define SCREEN_TYPE_LEVEL	4
#define SCREEN_TYPE_NUMBER	5
#define SCREEN_TYPE_READY	6
#define SCREEN_TYPE_PLAY	7
#define SCREEN_TYPE_QUIZ	8
#define SCREEN_TYPE_SCORE	9
#define SCREEN_TYPE_OVER	10
#define SCREEN_TYPE_CREDIT	11
#define SCREEN_TYPE_TEST1	12
#define SCREEN_TYPE_TEST2	13
#define SCREEN_TYPE_TEST3	14
#define SCREEN_TYPE_TEST4	15
#define SCREEN_TYPE_TEST5	16
#define SCREEN_TYPE_DIFF	17
#define SCREEN_TYPE_LONG	18

enum
{
	screen_type_none,	// 0
	screen_type_splash,	// 1
	screen_type_title,	// 2
	screen_type_intro,	// 3
	screen_type_level,	// 4
	screen_type_number,	// 5
	screen_type_ready,	// 6
	screen_type_play,	// 7
	screen_type_quiz,	// 8
	screen_type_score,	// 9
	screen_type_over,	// 10
	screen_type_credit,	// 11
	screen_type_test1,	// 12
	screen_type_test2,	// 13
	screen_type_test3,	// 14
	screen_type_test4,	// 15
	screen_type_test5,	// 16
	screen_type_diff,	// 17
	screen_type_long,	// 18
} enum_curr_screen_type, enum_next_screen_type;


// TODO - not used so can remove
// Select type.
#define ANSWER_TYPE_NONE	0
#define ANSWER_TYPE_RIGHT	1
#define ANSWER_TYPE_WRONG	2

enum
{
	answer_type_none,	// 0
	answer_type_right,	// 1
	answer_type_wrong,	// 2
} enum_answer_type;
// TODO - not used so can remove


// Each select screen has 2x states
#define SELECT_TYPE_BEFORE	0
#define SELECT_TYPE_AFTER	1

enum
{
	select_type_before,	// 0
	select_type_after,	// 1
} enum_select_type;


// Difficulty type.
#define DIFF_TYPE_EASY		0
#define DIFF_TYPE_NORM		1
#define DIFF_TYPE_HARD		2
#define DIFF_TYPE_ARGH		3

enum
{
	diff_type_easy,	// 0
	diff_type_norm,	// 1
	diff_type_hard,	// 2
	diff_type_argh,	// 3
} enum_difficulty_type;


// Random type.
#define RAND_TYPE_RANDOM		0
#define RAND_TYPE_NORMAL		1
#define RAND_TYPE_MIXED			2

enum
{
	rand_type_random,	// 0
	rand_type_normal,	// 1
	rand_type_mixed,	// 2
} enum_select_answer_type;

#endif//_ENUM_MANAGER_H_