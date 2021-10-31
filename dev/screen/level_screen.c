#include "level_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/quiz_manager.h"
#include "../engine/random_manager.h"
#include "../engine/select_manager.h"
#include "../devkit/_sms_manager.h"

void screen_level_screen_load()
{
	unsigned char bank;

	// Process this here just before quiz starts
	// Why?  Otherwise may cause music to "drag"
	engine_random_manager_init();

	bank = diff_select + QUIZ_BANK;
	engine_quiz_manager_bank( bank );

	engine_random_manager_load();
	engine_select_manager_load_quiz();
}

void screen_level_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_number;
}
