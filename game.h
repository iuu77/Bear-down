#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 79



#include<time.h>
#include<stdlib.h>
#include<stdio.h>

//ÉùÃ÷
void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char ret);
void PritBoard(char board[ROWS][COLS], int rows, int cols);
void SitMine(char board[ROWS][COLS], int row, int col);
void Is_Mine(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int Num_Mine(char board[ROWS][COLS], int y, int x);