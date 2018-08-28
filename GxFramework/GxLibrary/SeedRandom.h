#ifndef __LIBRARY_SEEDRANDOM__
#define __LIBRARY_SEEDRANDOM__

#include "cocos2d.h"

USING_NS_CC;

class  SeedRandom : public Ref
{
public:
	SeedRandom();
	~SeedRandom();
	virtual bool init();
	static SeedRandom * getInstance(int index);

	void Reset(int seed);
	int Value1(int iMin, int iMax);

private:
	int IA;
	int IM;
	int IQ;
	int IR;
	int m_z[4];

	long Value();
	void destroy();
};

#endif // __LIBRARY_SEEDRANDOM__