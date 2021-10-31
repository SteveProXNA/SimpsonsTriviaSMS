#include "main.h"

void main(void)
{
	// Global variables.
	static bool global_pause;
	unsigned char open_screen_type;

	devkit_SMS_init();
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();

	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_useFirstHalfTilesforSprites_True();

	engine_content_manager_load_font();
	engine_content_manager_load_sprites();

	// Initialize.
	engine_hack_manager_init();
	engine_hack_manager_invert();

	engine_actor_manager_init();
	engine_audio_manager_init();
	engine_quiz_manager_init();
	engine_score_manager_init();
	engine_select_manager_init();
	engine_sound_manager_init();

	open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_title;
	engine_screen_manager_init( open_screen_type );

	devkit_SMS_displayOn();
	for (;;)
	{
		if( devkit_SMS_queryPauseRequested() )
		{
			devkit_SMS_resetPauseRequest();
			global_pause = !global_pause;
			if( global_pause )
			{
				devkit_PSGSilenceChannels();
			}
			else
			{
				devkit_PSGRestoreVolumes();
			}
		}

		if( global_pause )
		{
			continue;
		}

		devkit_SMS_initSprites();
		engine_input_manager_update();

		engine_screen_manager_update();

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();
		devkit_SMS_copySpritestoSAT();

		devkit_PSGFrame();
		devkit_PSGSFXFrame();
	}
}
