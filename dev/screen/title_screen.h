#ifndef _TITLE_SCREEN_H_
#define _TITLE_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_intro_screen_delay;

void screen_title_screen_init()
{
	screen_splash_screen_delay = NORMAL_DELAY;
}

void screen_title_screen_load()
{
	screen_bases_screen_init();

	SMS_displayOff();
	engine_content_manager_title();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));

	if( hacker_extra )
	{
		engine_font_manager_draw_text( LOCALE_VERSION, 25, 23 );
	}
	SMS_displayOn();

	engine_audio_manager_start_music();
}

void screen_title_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char test_curr_joypad1 = curr_joypad1;
	unsigned char test_prev_joypad1 = prev_joypad1;

	screen_bases_screen_timer++;
	if (screen_bases_screen_timer >= screen_splash_screen_delay)
	{
		*screen_type = SCREEN_TYPE_INTRO;
	}
}

#endif//_TITLE_SCREEN_H_