#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

// Screen type.
#define SCREEN_TYPE_NONE	0
#define SCREEN_TYPE_SPLASH	1
#define SCREEN_TYPE_TITLE	2
#define SCREEN_TYPE_INTRO	3
#define SCREEN_TYPE_DIFF	4
#define SCREEN_TYPE_LONG	5
#define SCREEN_TYPE_READY	6
#define SCREEN_TYPE_LEVEL	7
#define SCREEN_TYPE_NUMBER	8
#define SCREEN_TYPE_PLAY	9
#define SCREEN_TYPE_QUIZ	10
#define SCREEN_TYPE_SCORE	11
#define SCREEN_TYPE_OVER	12

enum
{
	screen_type_none,	// 0
	screen_type_splash,	// 1
	screen_type_title,	// 2
	screen_type_intro,	// 3
	screen_type_diff,	// 4
	screen_type_long,	// 5
	screen_type_ready,	// 6
	screen_type_level,	// 7
	screen_type_number,	// 8
	screen_type_play,	// 9
	screen_type_quiz,	// 10
	screen_type_score,	// 11
	screen_type_over,	// 12

} enum_curr_screen_type, enum_next_screen_type;


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