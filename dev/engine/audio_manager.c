#include "audio_manager.h"
#include "global_manager.h"
#include "hack_manager.h"
#include "sound_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank15.h"
#include "../psg.h"
#include <stdlib.h>

// IMPORTANT disable compiler warning 110
#ifdef _CONSOLE
#else
#pragma disable_warning 196
#endif

#define music_psg				music_psg
#define finish_psg				finish_psg

#define sfx_cheat_psg			sfx_cheat_psg
#define sfx_right_psg			sfx_right_psg
#define sfx_wrong_psg			sfx_wrong_psg

// Private helper functions.
static void play_music( unsigned char *music, unsigned char bank );
static void play_sound( unsigned char *sfx );

static unsigned char prevRight, currRight;
static unsigned char prevWrong, currWrong;

void engine_audio_manager_init()
{
	prevRight = 0; 	currRight = 0;
	prevWrong = 0; 	currWrong = 0;
}

void engine_audio_manager_start_music()
{
	play_music( ( unsigned char* ) music_psg, music_psg_bank );
}

void engine_audio_manager_finish_music()
{
	play_music( ( unsigned char* ) finish_psg, finish_psg_bank );
}

void engine_audio_manager_stop_music()
{
	devkit_PSGStop();
}


void engine_audio_manager_sound_right()
{
	play_sound( ( unsigned char* ) sfx_right_psg );
}
void engine_audio_manager_sound_wrong()
{
	play_sound( ( unsigned char* ) sfx_wrong_psg );
}
void engine_audio_manager_sound_cheat()
{
	play_sound( ( unsigned char* ) sfx_cheat_psg );
}
void engine_audio_manager_sound_woohoo()
{
	while( 1 )
	{
		currRight = rand() % MAX_RIGHT;
		if( currRight != prevRight )
		{
			break;
		}
	}

	engine_sound_manager_play( currRight );
	prevRight = currRight;
}
void engine_audio_manager_sound_doh()
{
	while( 1 )
	{
		currWrong = rand() % MAX_WRONG;
		if( currWrong != prevWrong )
		{
			break;
		}
	}

	engine_sound_manager_play( currWrong + MAX_RIGHT );
	prevWrong = currWrong;
}

static void play_music( unsigned char *music, unsigned char bank )
{
	if( !hacker_music )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	devkit_PSGPlayNoRepeat( music );
}

static void play_sound( unsigned char *sfx )
{
	if( !hacker_sound )
	{
		return;
	}

	devkit_PSGSFXPlay( sfx, devkit_SFX_CHANNEL2() );
}