#ifndef _CONTENT_MANAGER_H_
#define _CONTENT_MANAGER_H_

#define FONT_TILES		0
#define SIMPSONS_TILES	96
#define GRAPHICS_TILES	112

void engine_content_manager_splash()
{
	SMS_mapROMBank(6);
	SMS_loadPSGaidencompressedTiles(splash__tiles__psgcompr, GRAPHICS_TILES);
	SMS_loadSTMcompressedTileMap(0, 0, splash__tilemap__stmcompr);
	SMS_loadBGPalette(splash__palette__bin);
}

void engine_content_manager_title()
{
	SMS_mapROMBank(6);
	SMS_loadPSGaidencompressedTiles(simpsons__tiles__psgcompr, SIMPSONS_TILES);
	SMS_loadSTMcompressedTileMap(0, 0, simpsons__tilemap__stmcompr);
	SMS_loadBGPalette(simpsons__palette__bin);
}

void engine_content_manager_load_font()
{
	// Font tiles.
	SMS_loadPSGaidencompressedTiles(font__tiles__psgcompr, FONT_TILES);
	SMS_loadBGPalette(font__palette__bin);
}

void engine_content_manager_load_sprites()
{
	// Sprite tiles.
	SMS_loadPSGaidencompressedTiles(select__tiles__psgcompr, SPRITE_TILES);
	SMS_loadPSGaidencompressedTiles(right__tiles__psgcompr, SPRITE_TILES + 16);
	SMS_loadPSGaidencompressedTiles(wrong__tiles__psgcompr, SPRITE_TILES + 32);
	SMS_loadSpritePalette(wrong__palette__bin);
}

void engine_content_manager_load_maggie()
{
	SMS_mapROMBank(7);
	SMS_loadPSGaidencompressedTiles(maggie__tiles__psgcompr, GRAPHICS_TILES);
	SMS_loadSTMcompressedTileMap(0, 0, maggie__tilemap__stmcompr);
	SMS_loadBGPalette(maggie__palette__bin);
}

#endif//_CONTENT_MANAGER_H_