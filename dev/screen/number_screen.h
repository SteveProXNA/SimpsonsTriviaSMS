#ifndef _NUMBER_SCREEN_H_
#define _NUMBER_SCREEN_H_

void screen_number_screen_load()
{
	SMS_displayOff();
	engine_content_manager_load_maggie();
	engine_content_manager_load_sprites();
	SMS_setSpritePaletteColor(0, RGB(3,3,3));
	SMS_displayOn();
}

void screen_number_screen_update(unsigned char *screen_type, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned int test_curr_joypad1 = curr_joypad1;
	unsigned int test_prev_joypad1 = prev_joypad1;

	*screen_type = SCREEN_TYPE_PLAY;
}

#endif//_NUMBER_SCREEN_H_