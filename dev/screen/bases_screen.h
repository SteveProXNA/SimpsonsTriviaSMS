#ifndef _BASES_SCREEN_H_
#define _BASES_SCREEN_H_

extern unsigned char screen_bases_screen_count;
extern unsigned int screen_bases_screen_timer;

void screen_bases_screen_init()
{
	screen_bases_screen_count = 0;
	screen_bases_screen_timer = 0;
}

#endif//_BASES_SCREEN_H_
