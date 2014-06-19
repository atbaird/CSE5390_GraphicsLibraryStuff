#include "Animation.h"


#ifndef CHAO_H
#define CHAO_H

class Chao {
public:
	Chao();
	~Chao();
	void testSprites(clock_t);
	void update(clock_t);
	void drawTest();
private:
	vector<Animation> animations;
};

#endif