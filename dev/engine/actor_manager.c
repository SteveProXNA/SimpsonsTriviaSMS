#include "actor_manager.h"
#include "../engine/global_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank6.h"
#include "../banks/bank7.h"
#include "../banks/bank8.h"
#include "../banks/bank9.h"
#include <stdlib.h>

#define ACTOR_TILES_OFFSET	128
#define ACTOR_TILES_TOTALS	4
#define ACTOR_TILES_BANKED	2

static void( *draw_method[ MAX_ACTORS ] )( );
static void draw_impl( unsigned char n, const unsigned char *tileset, const unsigned char *tilemap, const unsigned char *palette );

static void draw_actor00(); static void draw_actor01(); static void draw_actor02(); static void draw_actor03();
static void draw_actor04(); static void draw_actor05(); static void draw_actor06(); static void draw_actor07();
static void draw_actor08(); static void draw_actor09(); static void draw_actor10(); static void draw_actor11();
static void draw_actor12(); static void draw_actor13(); static void draw_actor14(); static void draw_actor15();

static unsigned char prevActor;
static unsigned char currActor;

void engine_actor_manager_init()
{
	draw_method[ 0 ] = draw_actor00;
	draw_method[ 1 ] = draw_actor01;
	draw_method[ 2 ] = draw_actor02;
	draw_method[ 3 ] = draw_actor03;
	draw_method[ 4 ] = draw_actor04;
	draw_method[ 5 ] = draw_actor05;
	draw_method[ 6 ] = draw_actor06;
	draw_method[ 7 ] = draw_actor07;
	draw_method[ 8 ] = draw_actor08;
	draw_method[ 9 ] = draw_actor09;
	draw_method[ 10 ] = draw_actor10;
	draw_method[ 11 ] = draw_actor11;
	draw_method[ 12 ] = draw_actor12;
	draw_method[ 13 ] = draw_actor13;
	draw_method[ 14 ] = draw_actor14;
	draw_method[ 15 ] = draw_actor15;

	prevActor = 0;
	currActor = 0;
}

void engine_actor_manager_load()
{
	while( 1 )
	{
		currActor = rand() % MAX_ACTORS;
		if( currActor != prevActor )
		{
			break;
		}
	}

	draw_method[ currActor ]();
	prevActor = currActor;
}

void engine_actor_manager_draw( unsigned char index )
{
	draw_method[ index ]();
}

static void draw_impl( unsigned char n, const unsigned char *tileset, const unsigned char *tilemap, const unsigned char *palette )
{
	devkit_SMS_mapROMBank( n );
	devkit_SMS_loadPSGaidencompressedTiles( tileset, ACTOR_TILES_OFFSET );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) tilemap );
	devkit_SMS_loadBGPalette( ( void * ) palette );
}

static void draw_actor00()
{
	draw_impl( actor00__tiles__psgcompr_bank, actor00__tiles__psgcompr, actor00__tilemap__stmcompr, actor00__palette__bin );
}
static void draw_actor01()
{
	draw_impl( actor01__tiles__psgcompr_bank, actor01__tiles__psgcompr, actor01__tilemap__stmcompr, actor01__palette__bin );
}
static void draw_actor02()
{
	draw_impl( actor02__tiles__psgcompr_bank, actor02__tiles__psgcompr, actor02__tilemap__stmcompr, actor02__palette__bin );
}
static void draw_actor03()
{
	draw_impl( actor03__tiles__psgcompr_bank, actor03__tiles__psgcompr, actor03__tilemap__stmcompr, actor03__palette__bin );
}
static void draw_actor04()
{
	draw_impl( actor04__tiles__psgcompr_bank, actor04__tiles__psgcompr, actor04__tilemap__stmcompr, actor04__palette__bin );
}
static void draw_actor05()
{
	draw_impl( actor05__tiles__psgcompr_bank, actor05__tiles__psgcompr, actor05__tilemap__stmcompr, actor05__palette__bin );
}
static void draw_actor06()
{
	draw_impl( actor06__tiles__psgcompr_bank, actor06__tiles__psgcompr, actor06__tilemap__stmcompr, actor06__palette__bin );
}
static void draw_actor07()
{
	draw_impl( actor07__tiles__psgcompr_bank, actor07__tiles__psgcompr, actor07__tilemap__stmcompr, actor07__palette__bin );
}

static void draw_actor08()
{
	draw_impl( actor08__tiles__psgcompr_bank, actor08__tiles__psgcompr, actor08__tilemap__stmcompr, actor08__palette__bin );
}
static void draw_actor09()
{
	draw_impl( actor09__tiles__psgcompr_bank, actor09__tiles__psgcompr, actor09__tilemap__stmcompr, actor09__palette__bin );
}
static void draw_actor10()
{
	draw_impl( actor10__tiles__psgcompr_bank, actor10__tiles__psgcompr, actor10__tilemap__stmcompr, actor10__palette__bin );
}
static void draw_actor11()
{
	draw_impl( actor11__tiles__psgcompr_bank, actor11__tiles__psgcompr, actor11__tilemap__stmcompr, actor11__palette__bin );
}
static void draw_actor12()
{
	draw_impl( actor12__tiles__psgcompr_bank, actor12__tiles__psgcompr, actor12__tilemap__stmcompr, actor12__palette__bin );
}
static void draw_actor13()
{
	draw_impl( actor13__tiles__psgcompr_bank, actor13__tiles__psgcompr, actor13__tilemap__stmcompr, actor13__palette__bin );
}
static void draw_actor14()
{
	draw_impl( actor14__tiles__psgcompr_bank, actor14__tiles__psgcompr, actor14__tilemap__stmcompr, actor14__palette__bin );
}
static void draw_actor15()
{
	draw_impl( actor15__tiles__psgcompr_bank, actor15__tiles__psgcompr, actor15__tilemap__stmcompr, actor15__palette__bin );
}
