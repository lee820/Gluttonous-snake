// tanChiShe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tcsChess.h"
#include "tcsBenti.h"



int main()
{
	tcsChess chess;
	chess.showChess();
	tcsBenti benti;
	benti.attachToChess(&chess);
	benti.start();
	system("pause");
	return 0;
}

