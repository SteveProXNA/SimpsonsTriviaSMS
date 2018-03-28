#ifndef _TEST5_SCREEN_H_
#define _TEST5_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;
extern unsigned char screen_test5_screen_delay;

void screen_test5_screen_init()
{
	screen_test5_screen_delay = 100;
}

void screen_test5_screen_load()
{
	unsigned char idx = 0;

	engine_select_manager_clear();

	screen_bases_screen_init();
	engine_font_manager_draw_text(LOCALE_BLANK, 0, 1);
	engine_font_manager_draw_text("TEST5", 0, 1);
}

void screen_test5_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_TEST5;
}

#endif//_TEST5_SCREEN_H_