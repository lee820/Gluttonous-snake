#pragma once
#include "tcsChess.h"
class tcsBenti
{
public:
	tcsBenti();
	~tcsBenti();
	void creatFood();
	void attachToChess(tcsChess *p) { ptChess = p; }
	void start();
private:
	tcsChess * ptChess;
	char tcsZuobiao[2][100];
	int f_x, f_y;
	int head ;
	int tail ;
};

