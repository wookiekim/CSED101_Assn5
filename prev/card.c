#include "board.h"
#include "card.h"
#include <string.h>
#include <stdlib.h>
//필요한 헤더파일들을 include하여줍니다.
void set_card(struct lineStack lineStacks[],char read[],int index)//카드정보를 읽어오는 함수
{
	struct card* temp;//포인터형 struct card 변수 선언
	temp=(struct card*)malloc(sizeof(struct card));//temp에 동적할당

	temp->suit=read[0];//템프가 가르키는 suit에 read[0]에 있는 문자를 넣어줍니다.

	if(strlen(read)==2){//만일 read의 길이가 2일때
		if(read[1]>49 && read[1]<58)//만일 read[1]에 저장되어있는 캐릭터 값이 49와 58 사이라면 (캐릭터형 2부터 9)
			temp->number=read[1]-48;//temp가 가르키는 number에 실제 2부터 9를 넣어줍니다.
		else if(read[1]=='A')//만일 read[1]에 저장되어있는 값이 A일시
			temp->number=1;//temp가 가르키는 number에 1 저장
		else if(read[1]=='J')//만일 read[1]에 저장되어있는 값이 J일시
			temp->number=11;//temp가 가르키는 number에 11 저장
		else if(read[1]=='Q')//만일 read[1]에 저장되어있는 값이 Q일시
			temp->number=12;//temp가 가르키는 number에 12저장
		else if(read[1]=='K')//만일 read[1]에 저장되어있는 값이 K일시
			temp->number=13;//temp가 가르키는 number에 13저장
	}
	else if(strlen(read)==3)//만일 read의 길이가 3일때
		temp->number=10;//temp가 가르키는 number에 10저장

	if(lineStacks[index].count==0){//해당 lineStack이 비어있을 때
		temp->next=0;//temp 의 next가 아무것도 가르키지 않도록
		lineStacks[index].head=temp;//해당 라인스택의 헤드를 템프로
		lineStacks[index].tail=temp;//해당 라인스택의 테일을 템프로
	}
	else{//해당 linestack이 비어있지 않을 떄
		temp->next=0;//temp의 next가 아무것도 가르키지 않도록
		lineStacks[index].head->next=temp;//기존에 있던 해당 라인스택의 헤드가 템프를 next로 가르키도록
		lineStacks[index].head=temp;//해당 라인스택의 헤드를 템프로
	}
	(lineStacks[index].count)++;//해당 라인스택에 count 1증가
}