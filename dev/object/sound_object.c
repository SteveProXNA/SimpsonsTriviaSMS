#include "sound_object.h"
#include "../banks/bank10.h"
#include "../banks/bank11.h"
#include "../banks/bank12.h"
#include "../banks/bank13.h"

const unsigned char *sound_sample_data[] =
{
	right01_wav_pcmenc,
	right02_wav_pcmenc,
	right03_wav_pcmenc,
	wrong01_wav_pcmenc,
	wrong02_wav_pcmenc,
	wrong03_wav_pcmenc,
};

const unsigned char sound_sample_bank[] =
{
	right01_wav_pcmenc_bank,
	right02_wav_pcmenc_bank,
	right03_wav_pcmenc_bank,
	wrong01_wav_pcmenc_bank,
	wrong02_wav_pcmenc_bank,
	wrong03_wav_pcmenc_bank,
};