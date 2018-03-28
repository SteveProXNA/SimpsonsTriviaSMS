#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

#define	HIDE_Y		188

// Private helper method.
static void engine_sprite_manager_draw(unsigned char x, unsigned char y, unsigned char tile);


// Public methods DRAW.
void engine_sprite_manager_draw_select(unsigned char x, unsigned char y)
{
	engine_sprite_manager_draw(x, y, SPRITE_TILES+0);
}
void engine_sprite_manager_draw_right(unsigned char x, unsigned char y)
{
	engine_sprite_manager_draw(x, y, SPRITE_TILES+16);
}
void engine_sprite_manager_draw_wrong(unsigned char x, unsigned char y)
{
	engine_sprite_manager_draw(x, y, SPRITE_TILES+32);
}

// Public methods HIDE.
//void engine_sprite_manager_hide_select()
//{
//	engine_sprite_manager_draw(0, HIDE_Y, SPRITE_TILES+0);
//}
//void engine_sprite_manager_hide_right()
//{
//	engine_sprite_manager_draw(0, HIDE_Y, SPRITE_TILES+16);
//}
//void engine_sprite_manager_hide_wrong()
//{
//	engine_sprite_manager_draw(0, HIDE_Y, SPRITE_TILES+32);
//}


static void engine_sprite_manager_draw(unsigned char x, unsigned char y, unsigned char tile)
{
	SMS_addSprite(x+0, y+0, tile+0);
	SMS_addSprite(x+8, y+0, tile+1);
	SMS_addSprite(x+16, y+0, tile+2);
	SMS_addSprite(x+24, y+0, tile+3);

	SMS_addSprite(x+0, y+8, tile+4);
	SMS_addSprite(x+8, y+8, tile+5);
	SMS_addSprite(x+16, y+8, tile+6);
	SMS_addSprite(x+24, y+8, tile+7);
	
	SMS_addSprite(x+0, y+16, tile+8);
	SMS_addSprite(x+8, y+16, tile+9);
	SMS_addSprite(x+16, y+16, tile+10);
	SMS_addSprite(x+24, y+16, tile+11);

	SMS_addSprite(x+0, y+24, tile+12);
	SMS_addSprite(x+8, y+24, tile+13);
	SMS_addSprite(x+16, y+24, tile+14);
	SMS_addSprite(x+24, y+24, tile+15);
}

#endif//_SPRITE_MANAGER_H_