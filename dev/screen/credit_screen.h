#ifndef _CREDIT_SCREEN_H_
#define _CREDIT_SCREEN_H_

void screen_credit_screen_load()
{
	engine_font_manager_draw_text(LOCALE_BLANK, 2, 2);
	engine_font_manager_draw_text("CREDIT", 2, 2);
}

void screen_credit_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char level = 0;
	if ((curr_joypad1 & PORT_A_KEY_1 && !(prev_joypad1 & PORT_A_KEY_1)) ||
		(curr_joypad1 & PORT_A_KEY_2 && !(prev_joypad1 & PORT_A_KEY_2)))
	{
		level = 1;
	}

	if (level)
	{
		*screen_type = SCREEN_TYPE_LEVEL;
	}
}

#endif//_CREDIT_SCREEN_H_