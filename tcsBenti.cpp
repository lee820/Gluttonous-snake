#include "stdafx.h"
#include "tcsBenti.h"


tcsBenti::tcsBenti()
{
	head = 3;
	tail = 0;
	for (int i = 0; i < 4; i++)
	{
		tcsZuobiao[0][i] = 1;
		tcsZuobiao[1][i] = i + 1;
	}	
}


tcsBenti::~tcsBenti()
{
}

void tcsBenti::creatFood()
{
	
	srand(time(0));	
	do {
		f_x = rand() % 20 + 1;
		f_y = rand() % 20 + 1;
	} while (ptChess->chess[f_x][f_y] != ' ');
		ptChess->chess[f_x][f_y] = '@';
		ptChess->showChess();

}

void tcsBenti::start()
{
	creatFood();
	for (int i = 1; i < 4; i++)
		ptChess->chess[1][i] = '*';
	ptChess->chess[1][4] = '#';
	ptChess->showChess();

	long start ;
	int speed = 500;
	int direction = 77;
	int x, y;
	while (1)
	{
		int timeover = 1;
		start = clock();
		while ((timeover = (clock() - start <= speed)) && !_kbhit());
		if (timeover)
		{
			_getch();
			direction = _getch();
		}
		switch (direction)
		{
		case 72:
			x = tcsZuobiao[0][head] - 1; y = tcsZuobiao[1][head]; break;//上
		case 80:
			x = tcsZuobiao[0][head] + 1; y = tcsZuobiao[1][head]; break;//下
		case 75:
			x = tcsZuobiao[0][head]; y = tcsZuobiao[1][head] - 1; break;//左
		case 77:
			x = tcsZuobiao[0][head]; y = tcsZuobiao[1][head] + 1; break;//右
		default:
			break;
		}
		/*if (direction != 72 || direction != 80 || direction != 75 || direction != 77) {
			cout << "Game over!!!!" << endl;
			cout << direction << endl;
		}*/
		if (x == 0 || x == 22 || y == 0 || y == 22) {
			cout << "Game over!!!" << endl;
			break;
		}
		if (ptChess->chess[x][y] != ' '&&!(x == f_x&&y == f_y)) {
			cout << "Game over!!!" << endl;
			break;
		}
		else
		{
			if (x == f_x&&y == f_y)//吃到食物
			{
				ptChess->chess[x][y] = '#';
				ptChess->chess[tcsZuobiao[0][head]][tcsZuobiao[1][head]] = '*';
				head = (head % 100) + 1;
				tcsZuobiao[0][head] = x;
				tcsZuobiao[1][head] = y;
				creatFood();
				ptChess->showChess();
			}
			else
			{
				ptChess->chess[tcsZuobiao[0][tail]][tcsZuobiao[1][tail]] = ' ';
				tail = (tail % 100) + 1;
				ptChess->chess[tcsZuobiao[0][head]][tcsZuobiao[1][head]] = '*';
				head = (head % 100) + 1;
				tcsZuobiao[0][head] = x;
				tcsZuobiao[1][head] = y;
				ptChess->chess[x][y] = '#';
				ptChess->showChess();
			}
		}
	}
}