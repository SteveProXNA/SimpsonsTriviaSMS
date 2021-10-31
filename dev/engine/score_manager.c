#include "score_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "locale_manager.h"

unsigned char score_player;

#define SCORE_X 31
#define SCORE_Y 3


// Private helper method.
static void draw_score();


// Public methods.
void engine_score_manager_init()
{
	score_player = 0;
}
void engine_score_manager_base()
{
	engine_font_manager_text( LOCALE_SCORE, TITLE_X, TITLE_Y );
	draw_score();
}
void engine_score_manager_update()
{
	score_player++;
	draw_score();
}

static void draw_score()
{
	engine_font_manager_data_ZERO( score_player, SCORE_X, SCORE_Y );
}