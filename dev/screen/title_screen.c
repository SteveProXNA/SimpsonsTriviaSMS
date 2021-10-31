#include "title_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/audio_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/global_manager.h"
#include "../engine/locale_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdlib.h>

static unsigned char screen_title_screen_delay;

void screen_title_screen_init()
{
	screen_title_screen_delay = NORMAL_DELAY;
}

void screen_title_screen_load()
{
	screen_bases_screen_init();

	devkit_SMS_displayOff();
	engine_content_manager_load_sprites();

	engine_content_manager_title();
	if( hacker_extra )
	{
		engine_font_manager_text( LOCALE_VERSION, 25, 23 );
	}

	devkit_SMS_displayOn();
	engine_audio_manager_start_music();
}

void screen_title_screen_update( unsigned char *screen_type )
{
	screen_bases_screen_timer++;
	if( screen_bases_screen_timer >= screen_title_screen_delay )
	{
		*screen_type = screen_type_intro;
		return;
	}

	rand();
	*screen_type = screen_type_title;
}
