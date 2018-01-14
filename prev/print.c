#include <stdio.h>
#include "board.h"
#include "card.h"
//�ʿ��� ��������� include�Ͽ��ݴϴ�.
void print_board(struct lineStack lineStacks[],struct card *freecells[],struct homecell homecells[])//������ �� ���
{
	int i,j;
	struct card* temp;
	//�ʿ��� ���� ����
	printf("\n[Homecell]\n");//Ȩ�� ���
	for(i=0;i<4;i++){
		printf("%d",i+1);
		if(homecells[i].count==0)
			printf("[-]\n"); //����ִ� ĭ�̶�� [-]���
		else{//�ƴϸ� �ش� homecell�� ����Ǿ��ִ� ī�������� ��� ���
			for(temp=homecells[i].tail;temp!=NULL;temp=temp->next){
				switch(temp->suit){
				case 'S':
					printf("[��",temp->suit);
					break;
				case 'H':
					printf("[��",temp->suit);
					break;
				case 'D':
					printf("[��",temp->suit);
					break;
				case 'C' :
					printf("[��",temp->suit);
					break;
				}
				if(temp->number!=1 && temp->number!=11 && temp->number!=12 && temp->number!=13)
					printf("%2d]",temp->number);
				else if(temp->number==1)
					printf("%2c]",'A');
				else if(temp->number==11)
					printf("%2c]",'J');
				else if(temp->number==12)
					printf("%2c]",'Q');
				else if(temp->number==13)
					printf("%2c]",'K');
			}
			printf("\n");
		}
		}
		printf("[Freecell]");//������ ���
		for(i=0;i<4;i++){

			if(freecells[i]!=0){//��ĭ�� �ƴ϶�� �ش� �������� �ִ� ī�������� ���
				switch(freecells[i]->suit){
				case 'S':
					printf("[��",freecells[i]->suit);
					break;
				case 'H':
					printf("[��",freecells[i]->suit);
					break;
				case 'D':
					printf("[��",freecells[i]->suit);
					break;
				case 'C' :
					printf("[��",freecells[i]->suit);
					break;
				}
				if(freecells[i]->number!=1 && freecells[i]->number!=11 && freecells[i]->number!=12 && freecells[i]->number!=13)
					printf("%2d]",freecells[i]->number);
				else if(freecells[i]->number==1)
					printf("%2c]",'A');
				else if(freecells[i]->number==11)
					printf("%2c]",'J');
				else if(freecells[i]->number==12)
					printf("%2c]",'Q');
				else if(freecells[i]->number==13)
					printf("%2c]",'K');
			}
			else printf("[-]");//����ִٸ� [-]���
		}

		printf("\n[Line Stack]\n");//���ν��� ���

		for(i=0;i<8;i++){
			printf("%d ",i+1);
			if(lineStacks[i].count==0)
				printf("[-]\n");//�ش� ���ν����� ����ִٸ� [-]���
			else{//�Ⱥ���ִٸ� �ش� ���ν��ÿ� ����Ǿ��ִ� ī������ ��� ���
			for(temp=lineStacks[i].tail;temp!=NULL;temp=temp->next){
				switch(temp->suit){
				case 'S':
					printf("[��",temp->suit);
					break;
				case 'H':
					printf("[��",temp->suit);
					break;
				case 'D':
					printf("[��",temp->suit);
					break;
				case 'C' :
					printf("[��",temp->suit);
					break;
				}
				if(temp->number!=1 && temp->number!=11 && temp->number!=12 && temp->number!=13)
					printf("%2d]",temp->number);
				else if(temp->number==1)
					printf("%2c]",'A');
				else if(temp->number==11)
					printf("%2c]",'J');
				else if(temp->number==12)
					printf("%2c]",'Q');
				else if(temp->number==13)
					printf("%2c]",'K');
			}
			printf("\n");
			}
		}
		printf("\n");
}
void print_free(struct card*freecells[4],int index)//���õ� �������� ī�带 ����մϴ�.
{
	printf("Selected Card :");
//���õ� �������� ����Ű�� ī���� ������ ����մϴ�.
	switch(freecells[index]->suit){
	case 'S':
		printf("[��",freecells[index]->suit);
		break;
	case 'H':
		printf("[��",freecells[index]->suit);
		break;
	case 'D':
		printf("[��",freecells[index]->suit);
		break;
	case 'C' :
		printf("[��",freecells[index]->suit);
		break;
	}
	if(freecells[index]->number!=1 && freecells[index]->number!=11 && freecells[index]->number!=12 && freecells[index]->number!=13)
		printf("%2d]",freecells[index]->number);
	else if(freecells[index]->number==1)
		printf("%2c]",'A');
	else if(freecells[index]->number==11)
		printf("%2c]",'J');
	else if(freecells[index]->number==12)
		printf("%2c]",'Q');
	else if(freecells[index]->number==13)
		printf("%2c]",'K');
	printf("\n");
}
void print_line(struct lineStack lineStacks[],int index,int num_card)//���ν��ÿ��� ���õ� ī��(��)�� ������ ���
{
	struct card* temp;
	int i;
	printf("Selected Card:");
	//���ν��ÿ��� ���õ� ī��(��)�� ������ ��� ����մϴ�.
					temp=lineStacks[index].tail;
					for(i=0;i<lineStacks[index].count-num_card;i++)
						temp=temp->next;

					for(i=0;i<num_card;i++,temp=temp->next){
						switch(temp->suit){
						case 'S':
							printf("[��",temp->suit);
							break;
						case 'H':
							printf("[��",temp->suit);
							break;
						case 'D':
							printf("[��",temp->suit);
							break;
						case 'C' :
							printf("[��",temp->suit);
							break;
						}
						if(temp->number!=1 && temp->number!=11 && temp->number!=12 && temp->number!=13)
							printf("%2d]",temp->number);
						else if(temp->number==1)
							printf("%2c]",'A');
						else if(temp->number==11)
							printf("%2c]",'J');
						else if(temp->number==12)
							printf("%2c]",'Q');
						else if(temp->number==13)
							printf("%2c]",'K');
					}printf("\n");
}