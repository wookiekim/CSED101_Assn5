#include <stdio.h>
#include "board.h"
#include "card.h"
//필요한 헤더파일을 include하여줍니다.
void print_board(struct lineStack lineStacks[],struct card *freecells[],struct homecell homecells[])//프리셀 판 출력
{
	int i,j;
	struct card* temp;
	//필요한 변수 선언
	printf("\n[Homecell]\n");//홈셀 출력
	for(i=0;i<4;i++){
		printf("%d",i+1);
		if(homecells[i].count==0)
			printf("[-]\n"); //비어있는 칸이라면 [-]출력
		else{//아니면 해당 homecell에 저장되어있는 카드정보를 모두 출력
			for(temp=homecells[i].tail;temp!=NULL;temp=temp->next){
				switch(temp->suit){
				case 'S':
					printf("[♠",temp->suit);
					break;
				case 'H':
					printf("[♡",temp->suit);
					break;
				case 'D':
					printf("[◇",temp->suit);
					break;
				case 'C' :
					printf("[♣",temp->suit);
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
		printf("[Freecell]");//프리셀 출력
		for(i=0;i<4;i++){

			if(freecells[i]!=0){//빈칸이 아니라면 해당 프리셀에 있는 카드정보를 출력
				switch(freecells[i]->suit){
				case 'S':
					printf("[♠",freecells[i]->suit);
					break;
				case 'H':
					printf("[♡",freecells[i]->suit);
					break;
				case 'D':
					printf("[◇",freecells[i]->suit);
					break;
				case 'C' :
					printf("[♣",freecells[i]->suit);
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
			else printf("[-]");//비어있다면 [-]출력
		}

		printf("\n[Line Stack]\n");//라인스택 출력

		for(i=0;i<8;i++){
			printf("%d ",i+1);
			if(lineStacks[i].count==0)
				printf("[-]\n");//해당 라인스택이 비어있다면 [-]출력
			else{//안비어있다면 해당 라인스택에 저장되어있는 카드정보 모두 출력
			for(temp=lineStacks[i].tail;temp!=NULL;temp=temp->next){
				switch(temp->suit){
				case 'S':
					printf("[♠",temp->suit);
					break;
				case 'H':
					printf("[♡",temp->suit);
					break;
				case 'D':
					printf("[◇",temp->suit);
					break;
				case 'C' :
					printf("[♣",temp->suit);
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
void print_free(struct card*freecells[4],int index)//선택된 프리셀의 카드를 출력합니다.
{
	printf("Selected Card :");
//선택된 프리셀이 가르키는 카드의 정보를 출력합니다.
	switch(freecells[index]->suit){
	case 'S':
		printf("[♠",freecells[index]->suit);
		break;
	case 'H':
		printf("[♡",freecells[index]->suit);
		break;
	case 'D':
		printf("[◇",freecells[index]->suit);
		break;
	case 'C' :
		printf("[♣",freecells[index]->suit);
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
void print_line(struct lineStack lineStacks[],int index,int num_card)//라인스택에서 선택된 카드(들)의 정보를 출력
{
	struct card* temp;
	int i;
	printf("Selected Card:");
	//라인스택에서 선택된 카드(들)의 정보를 모두 출력합니다.
					temp=lineStacks[index].tail;
					for(i=0;i<lineStacks[index].count-num_card;i++)
						temp=temp->next;

					for(i=0;i<num_card;i++,temp=temp->next){
						switch(temp->suit){
						case 'S':
							printf("[♠",temp->suit);
							break;
						case 'H':
							printf("[♡",temp->suit);
							break;
						case 'D':
							printf("[◇",temp->suit);
							break;
						case 'C' :
							printf("[♣",temp->suit);
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