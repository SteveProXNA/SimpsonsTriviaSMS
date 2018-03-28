#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

// Private helper methods.
static unsigned char engine_input_manager_hold(unsigned int data, unsigned int curr_joypad1, unsigned int prev_joypad1);
static unsigned char engine_input_manager_move(unsigned int data, unsigned int curr_joypad1);


// Public methods HOLD.
unsigned char engine_input_manager_hold_up(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_UP, curr_joypad1, prev_joypad1);
}
unsigned char engine_input_manager_hold_down(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_DOWN, curr_joypad1, prev_joypad1);
}
unsigned char engine_input_manager_hold_left(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_LEFT, curr_joypad1, prev_joypad1);
}
unsigned char engine_input_manager_hold_right(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_RIGHT, curr_joypad1, prev_joypad1);
}
unsigned char engine_input_manager_hold_fire1(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_1, curr_joypad1, prev_joypad1);
}
unsigned char engine_input_manager_hold_fire2(unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	return engine_input_manager_hold(PORT_A_KEY_2, curr_joypad1, prev_joypad1);
}

// Public methods MOVE.
unsigned char engine_input_manager_move_up(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_UP, curr_joypad1);
}
unsigned char engine_input_manager_move_down(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_DOWN, curr_joypad1);
}
unsigned char engine_input_manager_move_left(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_LEFT, curr_joypad1);
}
unsigned char engine_input_manager_move_right(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_RIGHT, curr_joypad1);
}
unsigned char engine_input_manager_move_fire1(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_1, curr_joypad1);
}
unsigned char engine_input_manager_move_fire2(unsigned int curr_joypad1)
{
	return engine_input_manager_move(PORT_A_KEY_2, curr_joypad1);
}


static unsigned char engine_input_manager_hold(unsigned int data, unsigned int curr_joypad1, unsigned int prev_joypad1)
{
	unsigned char input = 0;
	if (curr_joypad1 & data && !(prev_joypad1 & data))
	{
		input = 1;
	}

	return input;
}
static unsigned char engine_input_manager_move(unsigned int data, unsigned int curr_joypad1)
{
	unsigned char input = 0;
	if (curr_joypad1 & data)
	{
		input = 1;
	}

	return input;
}

#endif//_INPUT_MANAGER_H_