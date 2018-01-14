#include "board.h"
#include "card.h"
#include <string.h>
#include <stdlib.h>
//�ʿ��� ������ϵ��� include�Ͽ��ݴϴ�.
void set_card(struct lineStack lineStacks[],char read[],int index)//ī�������� �о���� �Լ�
{
	struct card* temp;//�������� struct card ���� ����
	temp=(struct card*)malloc(sizeof(struct card));//temp�� �����Ҵ�

	temp->suit=read[0];//������ ����Ű�� suit�� read[0]�� �ִ� ���ڸ� �־��ݴϴ�.

	if(strlen(read)==2){//���� read�� ���̰� 2�϶�
		if(read[1]>49 && read[1]<58)//���� read[1]�� ����Ǿ��ִ� ĳ���� ���� 49�� 58 ���̶�� (ĳ������ 2���� 9)
			temp->number=read[1]-48;//temp�� ����Ű�� number�� ���� 2���� 9�� �־��ݴϴ�.
		else if(read[1]=='A')//���� read[1]�� ����Ǿ��ִ� ���� A�Ͻ�
			temp->number=1;//temp�� ����Ű�� number�� 1 ����
		else if(read[1]=='J')//���� read[1]�� ����Ǿ��ִ� ���� J�Ͻ�
			temp->number=11;//temp�� ����Ű�� number�� 11 ����
		else if(read[1]=='Q')//���� read[1]�� ����Ǿ��ִ� ���� Q�Ͻ�
			temp->number=12;//temp�� ����Ű�� number�� 12����
		else if(read[1]=='K')//���� read[1]�� ����Ǿ��ִ� ���� K�Ͻ�
			temp->number=13;//temp�� ����Ű�� number�� 13����
	}
	else if(strlen(read)==3)//���� read�� ���̰� 3�϶�
		temp->number=10;//temp�� ����Ű�� number�� 10����

	if(lineStacks[index].count==0){//�ش� lineStack�� ������� ��
		temp->next=0;//temp �� next�� �ƹ��͵� ����Ű�� �ʵ���
		lineStacks[index].head=temp;//�ش� ���ν����� ��带 ������
		lineStacks[index].tail=temp;//�ش� ���ν����� ������ ������
	}
	else{//�ش� linestack�� ������� ���� ��
		temp->next=0;//temp�� next�� �ƹ��͵� ����Ű�� �ʵ���
		lineStacks[index].head->next=temp;//������ �ִ� �ش� ���ν����� ��尡 ������ next�� ����Ű����
		lineStacks[index].head=temp;//�ش� ���ν����� ��带 ������
	}
	(lineStacks[index].count)++;//�ش� ���ν��ÿ� count 1����
}