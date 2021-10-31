#include "sound_manager.h"
#include "hack_manager.h"
#include "sample_manager.h"
#include "../devkit/_sms_manager.h"
#include "../object/sound_object.h"

const unsigned char psgInit[] =
{
	0x9F, 0xBF, 0xDF, 0xFF, 0x81, 0x00, 0xA1, 0x00, 0x00, 0xC1, 0x00
};

void engine_sound_manager_init()
{
	engine_sample_manager_init( psgInit );
}

void engine_sound_manager_play( unsigned char index )
{
	const unsigned char *data;
	unsigned char bank;

	data = sound_sample_data[ index ];
	bank = sound_sample_bank[ index ];

	if( !hacker_sound )
	{
		return;
	}

	devkit_SMS_mapROMBank( bank );
	engine_sample_manager_play( data );
}