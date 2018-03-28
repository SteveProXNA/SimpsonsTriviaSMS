#include "main.h"

// Global variables.
bool global_pause;

unsigned char hacker_debug;
unsigned char hacker_cheat, hacker_random;
unsigned char hacker_music, hacker_sound;
unsigned char hacker_extra;
unsigned char enum_curr_screen_type, enum_next_screen_type;

void custom_initialize();

void (*load_method[MAX_STATES])();
void (*update_method[MAX_STATES])(unsigned char *screen_type, const unsigned int curr_joypad1, const unsigned int prev_joypad1);

void main( void )
{
	// Must be static to persist values!
	static unsigned int curr_joypad1 = 0;
	static unsigned int prev_joypad1 = 0;

	SMS_init();
	SMS_displayOff();

	engine_asm_manager_clear_VRAM();

	SMS_setSpriteMode(SPRITEMODE_NORMAL);
	SMS_useFirstHalfTilesforSprites(true);

	engine_content_manager_load_font();
	engine_content_manager_load_sprites();

	custom_initialize();

	enum_curr_screen_type = SCREEN_TYPE_NONE;
	enum_next_screen_type = SCREEN_TYPE_SPLASH;

	SMS_displayOn();
	for (;;)
	{
		if( SMS_queryPauseRequested() )
		{
			SMS_resetPauseRequest();
			global_pause = !global_pause;
			if( global_pause )
			{
				if( hacker_debug )
				{
					engine_font_manager_draw_text(LOCALE_PAUSED, 13, 12);
				}
				PSGSilenceChannels();
			}
			else
			{
				if( hacker_debug )
				{
					engine_font_manager_draw_text(LOCALE_RESUME, 13, 12);
				}
				PSGRestoreVolumes();
			}
		}

		if (global_pause)
		{
			continue;
		}

		if (enum_curr_screen_type != enum_next_screen_type)
		{
			enum_curr_screen_type = enum_next_screen_type;
			load_method[enum_curr_screen_type]();
		}

		SMS_initSprites();

		curr_joypad1 = SMS_getKeysStatus();
		update_method[enum_curr_screen_type](&enum_next_screen_type, curr_joypad1, prev_joypad1);

		SMS_finalizeSprites();
		SMS_waitForVBlank();
		SMS_copySpritestoSAT();

		PSGFrame();
		PSGSFXFrame();

		prev_joypad1 = curr_joypad1;
	}
}

void custom_initialize()
{
	// Set load methods
	load_method[screen_type_splash] = screen_splash_screen_load;
	load_method[screen_type_title] = screen_title_screen_load;
	load_method[screen_type_intro] = screen_intro_screen_load;
	load_method[screen_type_level] = screen_level_screen_load;
	load_method[screen_type_number] = screen_number_screen_load;
	load_method[screen_type_ready] = screen_ready_screen_load;
	load_method[screen_type_play] = screen_play_screen_load;
	load_method[screen_type_quiz] = screen_quiz_screen_load;
	load_method[screen_type_score] = screen_score_screen_load;
	load_method[screen_type_over] = screen_over_screen_load;
	load_method[screen_type_credit] = screen_credit_screen_load;
	load_method[screen_type_diff] = screen_diff_screen_load;
	load_method[screen_type_long] = screen_long_screen_load;

	// TODO - delete
	load_method[screen_type_test1] = screen_test1_screen_load;
	load_method[screen_type_test2] = screen_test2_screen_load;
	load_method[screen_type_test3] = screen_test3_screen_load;
	load_method[screen_type_test4] = screen_test4_screen_load;
	load_method[screen_type_test5] = screen_test5_screen_load;
	// TODO - delete

	// Set update methods
	update_method[screen_type_splash] = screen_splash_screen_update;
	update_method[screen_type_title] = screen_title_screen_update;
	update_method[screen_type_intro] = screen_intro_screen_update;
	update_method[screen_type_level] = screen_level_screen_update;
	update_method[screen_type_number] = screen_number_screen_update;
	update_method[screen_type_ready] = screen_ready_screen_update;
	update_method[screen_type_play] = screen_play_screen_update;
	update_method[screen_type_quiz] = screen_quiz_screen_update;
	update_method[screen_type_score] = screen_score_screen_update;
	update_method[screen_type_over] = screen_over_screen_update;
	update_method[screen_type_credit] = screen_credit_screen_update;
	update_method[screen_type_diff] = screen_diff_screen_update;
	update_method[screen_type_long] = screen_long_screen_update;


	// TODO - delete
	update_method[screen_type_test1] = screen_test1_screen_update;
	update_method[screen_type_test2] = screen_test2_screen_update;
	update_method[screen_type_test3] = screen_test3_screen_update;
	update_method[screen_type_test4] = screen_test4_screen_update;
	update_method[screen_type_test5] = screen_test5_screen_update;
	// TODO - delete


	engine_hack_manager_init();
	engine_hack_manager_invert();


	// Initialize other managers.
	engine_quiz_manager_init();
	engine_score_manager_init();
	engine_select_manager_init();

	// Initialize screens.
	screen_bases_screen_init();
	screen_splash_screen_init();
	screen_title_screen_init();
	screen_intro_screen_init();
	screen_ready_screen_init();
	screen_diff_screen_init();
	screen_long_screen_init();
	screen_play_screen_init();
	screen_quiz_screen_init();
	screen_over_screen_init();


	// TODO - delete
	screen_test1_screen_init();
	screen_test2_screen_init();
	screen_test3_screen_init();
	screen_test4_screen_init();
	screen_test5_screen_init();
	// TODO - delete
}

SMS_EMBED_SEGA_ROM_HEADER(9999, 0);
SMS_EMBED_SDSC_HEADER(1, 0, 2018, 3, 27, "StevePro Studios", "Simpsons Trivia", "Simpsons Trivia game for the SMS Power! 2018 Competition");