#include "func_screen.h"
#include "../engine/actor_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../devkit/_sms_manager.h"

static unsigned char index = 0;
static void draw_screen( unsigned char index );

void screen_func_screen_load()
{
	engine_actor_manager_init();
	draw_screen( index );
}

void screen_func_screen_update( unsigned char *screen_type )
{
	unsigned char input = engine_input_manager_hold_right();
	if( input )
	{
		if( index >= MAX_ACTORS - 1 )
		{
			index = 0;
		}
		else
		{
			index++;
		}
		draw_screen( index );
	}
	else
	{
		input = engine_input_manager_hold_left();
		if( input )
		{
			if( index <= 0 )
			{
				index = MAX_ACTORS - 1;
			}
			else
			{
				index--;
			}
			draw_screen( index );
		}
	}

	*screen_type = screen_type_func;
}

static void draw_screen( unsigned char index )
{
	devkit_SMS_displayOff();
	engine_actor_manager_draw( index );
	devkit_SMS_displayOn();
}