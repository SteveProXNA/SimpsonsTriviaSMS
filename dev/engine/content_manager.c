#include "content_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank6.h"
#include "../banks/bank7.h"
#include "../banks/bank14.h"
#include "../gfx.h"

#define FONT_TILES			0
#define SIMPSONS_TILES		96
#define GRAPHICS_TILES		112

void engine_content_manager_load_font()
{
	// Font tiles.
	devkit_SMS_loadPSGaidencompressedTiles( font__tiles__psgcompr, FONT_TILES );
	devkit_SMS_loadBGPalette( ( void * ) font__palette__bin );
}

void engine_content_manager_load_sprites()
{
	devkit_SMS_loadPSGaidencompressedTiles( select__tiles__psgcompr, SPRITE_TILES );
	devkit_SMS_loadPSGaidencompressedTiles( right__tiles__psgcompr, SPRITE_TILES + 16 );
	devkit_SMS_loadPSGaidencompressedTiles( wrong__tiles__psgcompr, SPRITE_TILES + 32 );
	devkit_SMS_loadSpritePalette( ( void * ) wrong__palette__bin );
}

void engine_content_manager_load_sprite_palette( unsigned char color )
{
	devkit_SMS_setSpritePaletteColor( 0, color, color, color );
}

void engine_content_manager_splash()
{
	devkit_SMS_mapROMBank( splash__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( splash__tiles__psgcompr, GRAPHICS_TILES );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) splash__tilemap__stmcompr );
	devkit_SMS_loadBGPalette( ( void * ) splash__palette__bin );
}

void engine_content_manager_title()
{
	devkit_SMS_mapROMBank( simpsons__tiles__psgcompr_bank );
	devkit_SMS_loadPSGaidencompressedTiles( simpsons__tiles__psgcompr, SIMPSONS_TILES );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) simpsons__tilemap__stmcompr );
	devkit_SMS_loadBGPalette( ( void * ) simpsons__palette__bin );
}