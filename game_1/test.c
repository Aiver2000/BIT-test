#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***********************************************\n");
	printf("****************   1.PLAY     *****************\n");
	printf("****************   2.EXIT     *****************\n");
	printf("***********************************************\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL]; //数据的存储---二维数组
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);


		//电脑下棋
		ComputerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf(" 你赢了 \n");
	else if (ret == '#')
		printf(" 你输了 \n");
	else if (ret == 'Q')
		printf(" 平局 \n");
	DisplayBoard(board, ROW, COL);


}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
				break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择!\n");
			break;
		}

	} while (input);
	return 0;
}
