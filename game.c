#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };//11*11
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');//储存雷的信息
	InitBoard(show, ROWS, COLS, '*');//展示给用户的棋盘
	//布置雷的信息
	SitMine(mine, ROW, COL);
	//打印棋盘
	PritBoard(mine, ROWS, COLS);
	PritBoard(show, ROWS, COLS);
	//玩家扫雷
	Is_Mine(mine, show, ROW, COL);

}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ret;
		}
	}
}

void PritBoard(char board[ROWS][COLS], int rows, int cols)
{
	int i = 0;
	int j = 1;
	for (i; i <= rows - 2; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		printf("%d ", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SitMine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (count<EASY_COUNT)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count++;
		}
	}
}
void Is_Mine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < row * col - EASY_COUNT)
	{
		printf("请输入坐标:>");
		here:
		scanf("%d%d", &x, &y);
		if (x > 0 && x < 10 && y>0 && y < 10)
		{
			if (board[x][y] == '0')
			{
				show[x][y] = Num_Mine(board, y, x) + '0';
				count++;
				PritBoard(show, ROWS, COLS);
			} else
			{
				printf("你被炸死了，游戏结束。\n");
				break;
			}
		}
		else
		{
			printf("输入有误；请重新输入:>");
			goto here;
		}
	}
	if (count >= row * col - EASY_COUNT)
	{
		printf("恭喜你! 你赢了!\n");
	}
}
int Num_Mine(char board[ROWS][COLS], int y, int x) 
{
	int sum = 0;
	sum = board[x - 1][y + 1] + board[x][y + 1] + board[x + 1][y + 1] +
		board[x - 1][y] + board[x + 1][y + 1] +
		board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1] + 8 * '0';
	return sum;
}