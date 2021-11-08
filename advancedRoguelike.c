#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void wall(int length)
{
	int i;
	printf("+");
	for(i = 0; i < length; i++)
	{
		printf("-");
	}
	printf("+\n");
}

void vacant(int length)
{
	int i;
	printf("|");
	for(i = 0; i < length; i++)
	{
		printf(".");
	}
	printf("|\n");
}

void occupied(int length, int x)
{
	int i;
	printf("|");
	for(i = 0; i < x; i++)
	{
		printf(".");
	}
	printf("@");
	for(i = 0; i < length-x-1; i++)
	{
		printf(".");
	}
	printf("|\n");
}

void drawRoom(int length, int height, int x, int y)
{
	int i;
	wall(length);
	for(i = 0; i < y; i++)
	{
		vacant(length);
	}
	occupied(length,x);
	for(i = 0; i < height-y-1; i++)
	{
		vacant(length);
	}
	wall(length);
}
int main()
{
	int order, length, height, x = 0, y = 0;
	printf("Please input length and height (divided by spacebar)\n");
	scanf("%d %d", &length, &height);
	drawRoom(length, height, x, y);
	for(;;)
	{
		order = getchar();
		switch(order)
		{ 
			case 119 : 
				if(y == 0)
				{
					drawRoom(length, height, x, y);
					printf("You bump into the wall.\n");
				}
				else
				{
					y = y - 1;
					drawRoom(length, height, x, y);
				}
				break;
			case 115 :
				if(y == height - 1)
				{
					drawRoom(length, height, x, y);
					printf("You bump into the wall.\n");
				}
				else
				{
					y = y + 1;
					drawRoom(length, height, x, y);
				}
				break;
			case 97 :
				if(x == 0)
				{
					drawRoom(length, height, x, y);
					printf("You bump into the wall.\n");
				}
				else
				{
					x = x - 1;
					drawRoom(length, height, x, y);
				}
				break;
			case 100 :
				if(x == length - 1)
				{
					drawRoom(length, height, x, y);
					printf("You bump into the wall.\n");
				}
				else
				{
					x = x + 1;
					drawRoom(length, height, x, y);
				}
				break;
		}
		continue;
	}	
	return 0;
}
