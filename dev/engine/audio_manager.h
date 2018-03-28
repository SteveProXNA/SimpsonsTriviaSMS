#ifndef _AUDIO_MANAGER_H_
#define _AUDIO_MANAGER_H_

void engine_audio_manager_start_music()
{
	if( hacker_music )
	{
		PSGPlayNoRepeat( MUSIC_PSG );
	}
}

void engine_audio_manager_finish_music()
{
	if( hacker_music )
	{
		PSGPlayNoRepeat( FINISH_PSG );
	}
}

void engine_audio_manager_stop_music()
{
	if( hacker_music )
	{
		PSGStop();
	}
}

void engine_audio_manager_sound_right()
{
	if( hacker_sound )
	{
		PSGSFXPlay( SOUND1_PSG, SFX_CHANNEL2 );
	}
}

void engine_audio_manager_sound_wrong()
{
	if( hacker_sound )
	{
		PSGSFXPlay( SOUND2_PSG, SFX_CHANNEL2 );
	}
}

void engine_audio_manager_sound_cheat()
{
	if( hacker_sound )
	{
		PSGSFXPlay( SOUND3_PSG, SFX_CHANNEL2 );
	}
}

#endif//_AUDIO_MANAGER_H_