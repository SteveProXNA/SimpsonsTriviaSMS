#ifndef _SCORE_MANAGER_H_
#define _SCORE_MANAGER_H_

#define SCORE_X 31
#define SCORE_Y 3

extern unsigned char score_player;

// Private helper method.
static void engine_score_manager_draw();


// Public methods.
void engine_score_manager_init()
{
	score_player = 0;
}
void engine_score_manager_base()
{
	engine_font_manager_draw_text(LOCALE_SCORE, TITLE_X, TITLE_Y);
	engine_score_manager_draw();
}
void engine_score_manager_update()
{
	score_player++;
	engine_score_manager_draw();
}

void engine_score_manager_draw()
{
	engine_font_manager_draw_data_ZERO( score_player, SCORE_X, SCORE_Y );
}

#endif//_SCORE_MANAGER_H_