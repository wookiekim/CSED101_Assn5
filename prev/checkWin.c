#include "board.h"
#include "card.h"
//필요한 헤더파일들을 include하여줍니다.
int check_win(struct lineStack lineStacks[],struct card *freecells[])//우승조건을 확인합니다.
{
	int i,j;

	for(i=0;i<8;i++)
		if(lineStacks[i].count!=0)//만일 해당 linestack이 비어있지 않다면 반복문 탈출
			break;
	for(j=0;j<4;j++)
		if(freecells[i]!=0)//만일 해당 프리셀이 비어있지 않다면 반복문 탈출
			break;

	if(i==8 && j==4)//만일 모든 반복문을 탈출하지 않고 돌았다면
		return 0;//0 반환 
	else
		return 1;//아니라면 1 반환
}
