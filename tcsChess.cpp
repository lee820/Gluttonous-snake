#include "stdafx.h"
#include "tcsChess.h"


tcsChess::tcsChess()
{
	for (int i = 0; i < COL; i++)
		chess[i][0] = chess[i][22] = '|';
	for (int j = 0; j < ROW; j++)
		chess[0][j] = chess[22][j] = '-';
	for (int i = 1; i < ROW-1; i++)
		for (int j = 1; j < COL-1; j++)
			chess[i][j] = ' ';
}


tcsChess::~tcsChess()
{
}

void tcsChess::showChess()
{
	system("cls");
	for (int i = 0; i <ROW ; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << chess[i][j]<<' ';
			
		}
		cout << endl;
	}
}