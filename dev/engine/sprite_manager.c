#include "sprite_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"

// Private helper method.
static void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned int tile );

// Public methods DRAW.
void engine_sprite_manager_draw_select( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, SPRITE_TILES + 0 );
}
void engine_sprite_manager_draw_right( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, SPRITE_TILES + 16 );
}
void engine_sprite_manager_draw_wrong( unsigned char x, unsigned char y )
{
	engine_sprite_manager_draw( x, y, SPRITE_TILES + 32 );
}

static void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned int tile )
{
	devkit_SMS_addSprite( x + 0, y + 0, tile + 0 );
	devkit_SMS_addSprite( x + 8, y + 0, tile + 1 );
	devkit_SMS_addSprite( x + 16, y + 0, tile + 2 );
	devkit_SMS_addSprite( x + 24, y + 0, tile + 3 );

	devkit_SMS_addSprite( x + 0, y + 8, tile + 4 );
	devkit_SMS_addSprite( x + 8, y + 8, tile + 5 );
	devkit_SMS_addSprite( x + 16, y + 8, tile + 6 );
	devkit_SMS_addSprite( x + 24, y + 8, tile + 7 );

	devkit_SMS_addSprite( x + 0, y + 16, tile + 8 );
	devkit_SMS_addSprite( x + 8, y + 16, tile + 9 );
	devkit_SMS_addSprite( x + 16, y + 16, tile + 10 );
	devkit_SMS_addSprite( x + 24, y + 16, tile + 11 );

	devkit_SMS_addSprite( x + 0, y + 24, tile + 12 );
	devkit_SMS_addSprite( x + 8, y + 24, tile + 13 );
	devkit_SMS_addSprite( x + 16, y + 24, tile + 14 );
	devkit_SMS_addSprite( x + 24, y + 24, tile + 15 );
}