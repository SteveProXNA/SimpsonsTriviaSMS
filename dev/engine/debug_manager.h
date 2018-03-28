#ifndef _DEBUG_MANAGER_H_
#define _DEBUG_MANAGER_H_

extern unsigned char quiz_questions[MAX_QUESTIONS];
extern unsigned char quiz_options[MAX_QUESTIONS][MAX_OPTIONS];

//void engine_debug_manager_clear()
//{
//	unsigned char idx;
//	for(idx = 0; idx < 24; idx++)
//	{
//		engine_font_manager_draw_text(LOCALE_BLANK, 0, idx);
//	}
//}

void engine_debug_manager_init()
{
	unsigned char idx;
	unsigned char delta = 0;

	engine_font_manager_draw_text("QUESTIONS", 0, 0);
	engine_font_manager_draw_text("OPTION A.", 0, 5);
	engine_font_manager_draw_text("OPTION B.", 0, 10);
	engine_font_manager_draw_text("OPTION C.", 0, 15);
	engine_font_manager_draw_text("OPTION D.", 0, 20);

	for(idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		engine_font_manager_draw_data(idx + delta, 5* idx, 1);
		engine_font_manager_draw_data(idx + delta, 5* idx, 6);
		engine_font_manager_draw_data(idx + delta, 5* idx, 11);
		engine_font_manager_draw_data(idx + delta, 5* idx, 16);
		engine_font_manager_draw_data(idx + delta, 5* idx, 21);

		/*engine_font_manager_draw_data(quiz_questions[idx] + delta, 5 * idx, 2);
		engine_font_manager_draw_data(quiz_options[idx][0] + delta, 5 * idx, 7);
		engine_font_manager_draw_data(quiz_options[idx][1] + delta, 5 * idx, 12);
		engine_font_manager_draw_data(quiz_options[idx][2] + delta, 5 * idx, 17);
		engine_font_manager_draw_data(quiz_options[idx][3] + delta, 5 * idx, 22);*/
	}
}

void engine_debug_manager_load()
{
	unsigned char idx;
	unsigned char delta = 0;

	for(idx = 0; idx < MAX_QUESTIONS; idx++)
	{
		engine_font_manager_draw_data(quiz_questions[idx] + delta, 5 * idx, 2);
		engine_font_manager_draw_data(quiz_options[idx][0] + delta, 5 * idx, 7);
		engine_font_manager_draw_data(quiz_options[idx][1] + delta, 5 * idx, 12);
		engine_font_manager_draw_data(quiz_options[idx][2] + delta, 5 * idx, 17);
		engine_font_manager_draw_data(quiz_options[idx][3] + delta, 5 * idx, 22);
	}
}

void engine_debug_manager_quest(unsigned char qi)
{
	unsigned char qv = quiz_questions[qi];

	engine_font_manager_draw_data(qi, 25, 2);
	engine_font_manager_draw_data(qv, 25, 3);

	engine_font_manager_draw_data(quiz_options[qv][0], 25, 5);
	engine_font_manager_draw_data(quiz_options[qv][1], 25, 6);
	engine_font_manager_draw_data(quiz_options[qv][2], 25, 7);
	engine_font_manager_draw_data(quiz_options[qv][3], 25, 8);
}

void engine_debug_manager_quest2(unsigned char qi, unsigned char qv, unsigned char opt1, unsigned char opt2, unsigned char opt3, unsigned char opt4)
{
	engine_font_manager_draw_data(qi, 15, 0);
	engine_font_manager_draw_data(qv, 20, 0);

	engine_font_manager_draw_data(opt1, 24, 15); engine_font_manager_draw_data(opt1+1, 30, 15);
	engine_font_manager_draw_data(opt2, 24, 16); engine_font_manager_draw_data(opt2+1, 30, 16);
	engine_font_manager_draw_data(opt3, 24, 17); engine_font_manager_draw_data(opt3+1, 30, 17);
	engine_font_manager_draw_data(opt4, 24, 18); engine_font_manager_draw_data(opt4+1, 30, 18);
}

void engine_debug_manager_quest3(unsigned char q, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
	engine_font_manager_draw_data(a, 28, 20);
	engine_font_manager_draw_data(b, 28, 21);
	engine_font_manager_draw_data(c, 28, 22);
	engine_font_manager_draw_data(d, 28, 23);

	engine_font_manager_draw_data(quiz_options[q][0], 26, 20); 
	engine_font_manager_draw_data(quiz_options[q][1], 26, 21); 
	engine_font_manager_draw_data(quiz_options[q][2], 26, 22); 
	engine_font_manager_draw_data(quiz_options[q][3], 26, 23); 
}

void engine_debug_manager_quest4()
{
}

#endif//_DEBUG_MANAGER_H_