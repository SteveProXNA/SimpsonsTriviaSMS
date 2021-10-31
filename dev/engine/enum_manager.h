#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_diff = 0,
	screen_type_intro = 1,
	screen_type_level = 2,
	screen_type_long = 3,
	screen_type_number = 4,
	screen_type_over = 5,
	screen_type_play = 6,
	screen_type_quiz = 7,
	screen_type_ready = 8,
	screen_type_score = 9,
	screen_type_splash = 10,
	screen_type_title = 11,
	screen_type_none = 12,
	screen_type_test = 13,
	screen_type_func = 14,

} enum_screen_type;

typedef enum tag_enum_answer_type
{
	answer_type_none,	// 0
	answer_type_right,	// 1
	answer_type_wrong,	// 2

} enum_answer_type;

typedef enum tag_enum_select_type
{
	select_type_before,	// 0
	select_type_after,	// 1

} enum_select_type;

typedef enum tag_enum_difficulty_type
{
	diff_type_easy,	// 0
	diff_type_norm,	// 1
	diff_type_hard,	// 2
	diff_type_argh,	// 3

} enum_difficulty_type;

typedef enum tag_enum_select_answer_type
{
	rand_type_random,	// 0
	rand_type_normal,	// 1
	rand_type_mixed,	// 2

} enum_select_answer_type;

#endif//_ENUM_MANAGER_H_
