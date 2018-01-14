#include "board.h"
#include "card.h"
#include "log.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>
//필요한 변수 선언
void line_home(struct lineStack from[],int ind1,struct homecell to[],int ind2)//라인스택에서 홈셀로 움직이는 함수
{
	struct card * temp;

	if(to[ind2].count==0){//만일 해당 홈셀이 비어있다면
		to[ind2].head=from[ind1].head;
		to[ind2].tail=from[ind1].head;
		//해당 홈셀의 테일과 헤드가 둘 다 라인스택의 헤드를 가르키도록
	}
	else{//해당 홈셀이 비어있지 않다면
		
		to[ind2].head->next=from[ind1].head;//해당 홈셀의 헤드가 next로 라인스택의 헤드를 가르키도록
		to[ind2].head=from[ind1].head;//해당 홈셀의 헤드가 라인스택의 헤드를 가르키도록
	}
	(to[ind2].count)++;//해당 홈셀의 카운트 1 증가

	if(from[ind1].count>1){//만일 라인스택의 카드가 한개 이상 남아있다면
	for(temp=from[ind1].tail;temp->next->next!=0;temp=temp->next);
	temp->next=NULL;//템프가 라인스택의 헤드의 바로 전 카드를 가르키도록 한다.
	from[ind1].head=temp;//해당 라인스택의 새로운 헤드는 기존의 헤드를 가르키던 카드로 한다.
	}
	else{//만일 라인스택의 1장의 카드만 남아있었다면
		from[ind1].head=NULL;
		from[ind1].tail=NULL;//해당 라인스택의 헤드와 테일 둘 다 NULL
	}
	
	(from[ind1].count)--;//해당 라인스택의 카운트 감소

	printf("Moving is successful\n");//이동성공 출력

}
void free_home(struct card *freecells[],int ind1,struct homecell to[],int ind2)//프리셀에서 홈셀로 움직이는 함수
{
	
	if(to[ind2].count==0){//만일 해당 홈셀이 비어있다면
		to[ind2].head=freecells[ind1];
		to[ind2].tail=freecells[ind1];//해당 홈셀의 테일과 헤드가 둘다 해당 프리셀을 가르키도록
	}
	else{//해당 홈셀이 비어있지 않다면
		to[ind2].head->next=freecells[ind1];//홈셀의 헤드가 next로 프리셀을 가르키게 하고
		to[ind2].head=freecells[ind1];//홈셀의 헤드를 해당 프리셀로 지정
	}
	(to[ind2].count)++;//해당 홈셀의 카운트 1 증가

	freecells[ind1]=NULL;//해당 프리셀 널초기화

	printf("Moving is successful\n");//이동 성공 출력
}
void free_line(struct card *freecells[],int ind1,struct lineStack to[],int ind2)//프리셀에서 라인스택으로 카드이동
{
	if(to[ind2].count==0){//만일 해당 라인스택이라 비어있다면
		to[ind2].head=freecells[ind1];
		to[ind2].tail=freecells[ind1];//해당 라인스택의 헤드와 테일이 둘 다 프리셀의 정보를 가르키도록
	}
	else{//해당 라인스택이 비어있지 않다면
		to[ind2].head->next=freecells[ind1];
		to[ind2].head=freecells[ind1];//프리셀에 있는 정보를 새로운 정보로서 라인스택에 추가.
	}
	(to[ind2].count)++;//라인스택의 카운트 1 증가

	freecells[ind1]=NULL;//프리셀 널 초기화

	printf("Moving is successful\n");//이동 성공 출력
}
void line_free(struct lineStack from[],int ind,struct card* freecells[],int ind2)//라인스택에서 프리셀로 이동
{
	struct card * temp;

	freecells[ind2]=from[ind].head;//해당 프리셀이 라인스택의 헤드를 가르키도록

	if(from[ind].count>1){//만일 해당 라인스택에 1개이상의 카드가 남아있다면

	for(temp=from[ind].tail;temp->next->next!=0;temp=temp->next);
	temp->next=NULL;
	from[ind].head=temp;//해당 라인스택의 헤드를 가르키던 노드를 헤드로 지정한다.
	}
	else{//해당 라인스택에 1개의 카드만 남아있다면
		from[ind].tail=NULL;
		from[ind].head=NULL;//해당 라인스택의 헤드와 테일을 널 초기화
	}
	
	(from[ind].count)--;//해당 라인스택의 카운트 1 감소
	
	printf("Moving is successful\n");//이동 성공 출력
}
void free_free(struct card* freecells[],int ind1,int ind2)//프리셀로 프리셀로 이동
{
	freecells[ind2]=freecells[ind1];//목적 프리셀이 source프리셀을 가르키도록 한다.
	freecells[ind1]=NULL;//source프리셀을 널 초기화.

	printf("Moving is successful\n");//이동 성공 출력
}
void line_line(struct lineStack lineStacks[],int from,int to,int amt)//라인스택에서 라인스택으로 이동
{
	struct card* temp;
	int i;

	if(lineStacks[from].count>amt){//라인스택에 남아있는 카드의 개수가 움직이고 싶은 카드의 개수보다 많을 시

		temp=lineStacks[from].tail;
		for(i=0;i<lineStacks[from].count-amt-1;i++)
			temp=temp->next;//템프가 움직이고 싶은 카드(들)을 가르키도록 한다.

		if(lineStacks[to].count==0){//만일 목적 라인스택이 비어있다면
			lineStacks[to].tail=temp->next;
			lineStacks[to].head=lineStacks[from].head;
		}
		else{//만일 목적 라인스택이 비어있지 않다면
			lineStacks[to].head->next=temp->next;
			lineStacks[to].head=lineStacks[from].head;
		}
		lineStacks[to].count+=amt;//목적 라인스택에 움직인 카드의 개수만큼 카운트를 증가하여준다.

		temp->next=NULL;//source라인스택에서 움직인 카드들을 더이상 가르키지 않도록 NULL을 가르키도록 한다.
		lineStacks[from].head=temp;//source라인 스택의 새로운 소스는 움직인 카드(들)의 바로 전 카드로 한다.
		lineStacks[from].count-=amt;//source라인스택에서 움직인 카드의 개수만큼 count를 뺴준다.

	}

	else{//만일 움직이고 싶은 카드와 source라인스택에 남아있는 카드의 개수가 같을 때
		temp=lineStacks[from].tail;
		lineStacks[to].head->next=temp;
		lineStacks[to].head=lineStacks[from].head;//해당 카드(들)의 정보를 목적 라인스택에 이어준다.
		lineStacks[to].count+=amt;//움직인 카드의 개수만큼 카운트를 증가시켜준다.

		lineStacks[from].tail=NULL;
		lineStacks[from].head=NULL;//소스 라인스택의 헤드와 테일을 널초기화해준다.
		lineStacks[from].count-=amt;//움직인 카드의 개수만큼 소스 라인스택에서 빼준다.
	}
	printf("Moving is successful\n");//이동 성공 출력
}

//target이 1
void case1_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location 이 1
	int index2,i;
	struct card* temp;
	printf("Please enter the index: ");//인덱스 입력 요구
	scanf("%d",&index2);//사용자에게서 인덱스 입력받기
	if(lineStacks[index2-1].count==0){//만일 해당 인덱스의 라인스택이 비어있다면 
		log_line(lineStacks,index+1,index2,num_card,t,l);//로그 작성
		line_line(lineStacks,index,index2-1,num_card);	//이동
		print_board(lineStacks,freecells,homecells);//프리셀 판 출력
	}
	else{//만일 해당 인덱스의 라인스택이 비어있지 않다면
		temp=lineStacks[index].tail;
		for(i=0;i<lineStacks[index].count-num_card;i++)
			temp=temp->next;//템프가 움직이고 싶은 카드(들)을 가르키도록
		if(check_color(temp,lineStacks[index2-1].head)){//색이 다른지 확인
			if((temp->number)+1==(lineStacks[index2-1].head->number)){//숫자가 1 차이인지 확인
				log_line(lineStacks,index+1,index2,num_card,t,l);//로그 작성
				line_line(lineStacks,index,index2-1,num_card);//이동
				print_board(lineStacks,freecells,homecells);//프리셀 판 출력
			}
			else printf("Error : Illegal Moving\n");//숫자가 1 차이가 아닐 시
		}
		else printf("Error : Illegal Moving\n");//색이 같을 시
	}
}
void case1_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location이 2
	int index2;
	printf("Please enter the index: ");//인덱스 입력 요구 문구 출력
	scanf("%d",&index2);//사용자에게서 인덱스 입력받음
	if(freecells[index2-1]==0 && num_card==1){//해당 프리셀이 비어있고, 움직이고 싶은 카드의 개수가 1일시
		log_line(lineStacks,index+1,index2,num_card,t,l);//로그 작성
		line_free(lineStacks,index,freecells,index2-1);//이동
		print_board(lineStacks,freecells,homecells);//프리셀 판 출력
	}
	else printf("Error : Illegal Moving\n");//프리셀이 비어있지 않거나, 1개이상의 카드를 움직이고 싶을 떄 오류메세지 출력
}
void case1_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location이 3일 시
	int index2;
	printf("Please enter the index: ");//입력요구문구 출력
	scanf("%d",&index2);//사용자에게서 인덱스 입력받기
	if(homecells[index2-1].count==0){//만일 홈셀이 비어있다면
		if(lineStacks[index].head->number==1 && num_card==1){//움직이고 싶은 카드가 1장이고, A일시 
			log_line(lineStacks,index+1,index2,num_card,t,l);//로그작성
			line_home(lineStacks,index,homecells,index2-1);//이동
			print_board(lineStacks,freecells,homecells);//프리셀 판 출력
		}
		else printf("Error : Illegal Moving\n");//움직이고 싶은 카드가 1장 이상이거나 A가 아닐 시 
	}
	else{//만일 홈셀이 비어있지 않다면
		if(lineStacks[index].head->suit==homecells[index2-1].head->suit){//수트가 같은지 확인
			if((lineStacks[index].head->number)==(homecells[index2-1].head->number)+1){//움직이고 싶은 카드와 홈셀의 맨 위 카드가 1 차이인지 확인
				log_line(lineStacks,index+1,index2,num_card,t,l);//로그작성
				line_home(lineStacks,index,homecells,index2-1);//이동
				print_board(lineStacks,freecells,homecells);//프리셀 판 출력
			}
			else printf("Error : Illegal Moving\n");//카드와 홈셀의 맨위 카드의 값 차이가 1 이 아닐 시
		}
		else printf("Error : Illegal Moving\n");//수트가 다를 시
	}
}

//target이 2
void case2_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location이 1
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//인덱스 입력받기

	if(lineStacks[index2-1].count==0){//만일 해당 라인스택이 비어있다면
		log_free(freecells,index+1,index2,t,l);//로그작성
		free_line(freecells,index,lineStacks,index2-1);//이동
		print_board(lineStacks,freecells,homecells);//프리셀 판 출력
	}
	else{//해당 라인스택이 비어있지 않다면
		if(check_color(freecells[index],lineStacks[index2-1].head)){//색이 다른지 확인
			if((freecells[index]->number)+1==(lineStacks[index2-1].head->number)){//카드의 값 차이가 1이 맞는지 확인
				log_free(freecells,index+1,index2,t,l);//로그작성
				free_line(freecells,index,lineStacks,index2-1);//이동
				print_board(lineStacks,freecells,homecells);}//프리셀 판 출력
			else printf("Error : Illegal Moving\n");//카드의 값 차이가 1이 아닐 시
		}
		else printf("Error : Illegal Moving\n");//색이 같을 시
	}
}
void case2_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location이 2일 시 
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//index입력받기 
	if(freecells[index2-1]==0){//해당 프리셀이 비어있다면
		log_free(freecells,index+1,index2,t,l);//로그작성
		free_free(freecells,index,index2-1);//이동
		print_board(lineStacks,freecells,homecells);//프리셀 판 출력
	}
	else printf("Error : Illegal Moving\n");//프리셀이 비어있지 않다면
}
void case2_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location이 3일시
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//사용자에게서 index입력받기
	if(homecells[index2-1].count==0){//해당 홈셀이 비어있다면
		if(freecells[index]->number==1){//움직이려는 카드가 A가 맞다면
			log_free(freecells,index+1,index2,t,l);//로그작성
			free_home(freecells,index,homecells,index2-1);//이동	
			print_board(lineStacks,freecells,homecells);//프리셀 판 출력
		}
		else printf("Error : Illegal Moving\n");//움직이려는 카드가 A가 아닐 시
	}
	else{
		if(freecells[index]->suit==homecells[index2-1].head->suit){//수트가 같은지 확인
			if((freecells[index]->number)==(homecells[index2-1].head->number)+1){//카드들의 값의 차이가 1이 맞는지 확인
				log_free(freecells,index+1,index2,t,l);//로그작성
				free_home(freecells,index,homecells,index2-1);//이동
				print_board(lineStacks,freecells,homecells);}//프리셀 판 출력
			else printf("Error : Illegal Moving\n");//카드들의 값의 차이가 1이 아닐 시
		}
		else printf("Error : Illegal Moving\n");//수트가 다를 시
	}
}