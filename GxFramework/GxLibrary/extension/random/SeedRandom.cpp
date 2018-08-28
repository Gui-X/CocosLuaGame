#include "SeedRandom.h"

static SeedRandom * s_shareSeedRandomManager1 = nullptr;
static SeedRandom * s_shareSeedRandomManager2 = nullptr;

SeedRandom::SeedRandom()
{
	this->IA = 16807;
	this->IM = 2147483647;
	this->IQ = 127773;
	this->IR = 2836;
	this->m_z[0] = 0;
	this->m_z[1] = 0;
	this->m_z[2] = 0;
	this->m_z[3] = 0;
}

SeedRandom::~SeedRandom(void)
{
}

bool SeedRandom::init()
{
	return true;
}

SeedRandom * SeedRandom::getInstance(int index)
{
	if (index == 1)
	{
		if (!s_shareSeedRandomManager1)
		{
			s_shareSeedRandomManager1 = new SeedRandom();
		}

		return s_shareSeedRandomManager1;
	}
	if (index == 2)
	{
		if (!s_shareSeedRandomManager2)
		{
			s_shareSeedRandomManager2 = new SeedRandom();
		}

		return s_shareSeedRandomManager2;
	}

}

void SeedRandom::destroy()
{
	if (s_shareSeedRandomManager1 != NULL)
	{
		delete s_shareSeedRandomManager1;
		s_shareSeedRandomManager1 = NULL;
	}
	if (s_shareSeedRandomManager2 != NULL)
	{
		delete s_shareSeedRandomManager2;
		s_shareSeedRandomManager2 = NULL;
	}
}

void SeedRandom::Reset(int seed)
{
	double k;
	double iSeed = seed;
	if (iSeed <= 0) iSeed = 1;

	int a = 9 / 10;

	k = floor(iSeed / this->IQ);
	iSeed = floor(this->IA * (iSeed - k * this->IQ) - this->IR * k);
	if (iSeed < 0) iSeed += this->IM;
	if (iSeed < 2) this->m_z[0] = (int)(iSeed + 2);
	else this->m_z[0] = (int)iSeed;

	k = floor((iSeed) / this->IQ);
	iSeed = this->IA * (iSeed - k * this->IQ) - this->IR * k;
	if (iSeed < 0) iSeed += this->IM;
	if (iSeed < 8) this->m_z[1] = (int)(iSeed + 8);
	else this->m_z[1] = (int)iSeed;

	k = floor((iSeed) / this->IQ);
	iSeed = this->IA * (iSeed - k * this->IQ) - this->IR * k;
	if (iSeed < 0) iSeed += this->IM;
	if (iSeed < 16) this->m_z[2] = (int)(iSeed + 16);
	else this->m_z[2] = (int)iSeed;

	k = floor((iSeed) / this->IQ);
	iSeed = this->IA * (iSeed - k * this->IQ) - this->IR * k;
	if (iSeed < 0) iSeed += this->IM;
	if (iSeed < 128) this->m_z[3] = (int)(iSeed + 128);
	else this->m_z[3] = (int)iSeed;

}

long SeedRandom::Value()
{
	//log("start %d,%d,%d,%d", m_z[0], m_z[1], m_z[2], m_z[3]);

	int b;

	b = (unsigned)((unsigned)((this->m_z[0] << 6) ^ this->m_z[0]) >> 13) >> 0;
	this->m_z[0] = (int)((unsigned)(((this->m_z[0] & 4294967294l) << 18) ^ b) >> 0);

	b = (unsigned)((unsigned)((this->m_z[1] << 2) ^ this->m_z[1]) >> 27) >> 0;
	this->m_z[1] = (int)((unsigned)(((this->m_z[1] & 4294967288L) << 2) ^ b) >> 0);

	b = (unsigned)((unsigned)((this->m_z[2] << 13) ^ this->m_z[2]) >> 21) >> 0;
	this->m_z[2] = (int)((unsigned)(((this->m_z[2] & 4294967280L) << 7) ^ b) >> 0);

	b = (unsigned)((unsigned)((this->m_z[3] << 3) ^ this->m_z[3]) >> 12) >> 0;
	this->m_z[3] = (int)((unsigned)(((this->m_z[3] & 4294967168L) << 13) ^ b) >> 0);

	//log("end  %d,%d,%d,%d", m_z[0], m_z[1], m_z[2], m_z[3]);

	long ret = (unsigned)(this->m_z[0] ^ this->m_z[1] ^ this->m_z[2] ^ this->m_z[3]) >> 1;

	return ret;
}

int SeedRandom::Value1(int iMin, int iMax)
{
	long fb = 0x7fffffff;
	long fz = this->Value();


	double d = fz / (float)fb;
	double e = (iMax - iMin) * d;
	int ret = (int)floor(iMin + e);
	//log("     get  %d", ret);

	return ret;

}

