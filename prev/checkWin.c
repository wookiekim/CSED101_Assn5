#include "board.h"
#include "card.h"
//�ʿ��� ������ϵ��� include�Ͽ��ݴϴ�.
int check_win(struct lineStack lineStacks[],struct card *freecells[])//��������� Ȯ���մϴ�.
{
	int i,j;

	for(i=0;i<8;i++)
		if(lineStacks[i].count!=0)//���� �ش� linestack�� ������� �ʴٸ� �ݺ��� Ż��
			break;
	for(j=0;j<4;j++)
		if(freecells[i]!=0)//���� �ش� �������� ������� �ʴٸ� �ݺ��� Ż��
			break;

	if(i==8 && j==4)//���� ��� �ݺ����� Ż������ �ʰ� ���Ҵٸ�
		return 0;//0 ��ȯ 
	else
		return 1;//�ƴ϶�� 1 ��ȯ
}
