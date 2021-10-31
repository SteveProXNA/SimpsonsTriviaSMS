#include "number_screen.h"
#include "../engine/actor_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../devkit/_sms_manager.h"

void screen_number_screen_load()
{
	devkit_SMS_displayOff();
	engine_actor_manager_load();
	engine_content_manager_load_sprites();
	devkit_SMS_displayOn();
}

void screen_number_screen_update( unsigned char *screen_type )
{
	*screen_type = screen_type_play;
}
