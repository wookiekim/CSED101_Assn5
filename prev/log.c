#include <stdio.h>
#include "board.h"
#include "card.h"
//필요한 헤더파일을 include하여줍니다.
void log_line(struct lineStack lineStacks[],int index,int index2,int num_card,int t,int l)//라인스택에서 움직일때의 로그작성
{
	FILE * outfile;//파일경로 선언
	struct card* temp;
	int i;
	//필요한 변수 선언
	outfile=fopen("log.txt","a");//log.txt를 수정 모드로 엽니다.

	fprintf(outfile,"%d %d %d ",t,index,num_card);//로그에 카드이동에 대한 정보를 입력합니다.

	temp=lineStacks[index-1].tail;//로그에 이동한 카드의 정보를 모두 입력합니다.
	for(i=0;i<lineStacks[index-1].count-num_card;i++)
		temp=temp->next;

	for(i=0;i<num_card;i++,temp=temp->next){
		fprintf(outfile,"%c",temp->suit);
		if(temp->number!=1 && temp->number!=11 && temp->number!=12 && temp->number!=13)
			fprintf(outfile,"%d ",temp->number);
		else if(temp->number==1)
			fprintf(outfile,"%c ",'A');
		else if(temp->number==11)
			fprintf(outfile,"%c ",'J');
		else if(temp->number==12)
			fprintf(outfile,"%c ",'Q');
		else if(temp->number==13)
			fprintf(outfile,"%c ",'K');
	}

	fprintf(outfile,"%d %d\n",l,index2);//로그에 카드이동에 대한 추가적 정보를 입력합니다.

	fclose(outfile);//outfile파일경로를 닫아줍니다.

}
void log_free(struct card *freecells[],int index,int index2,int t,int l)//프리셀에서 움직일때의 로그작성
{
	FILE * outfile;//outfile파일경로 선언

	outfile=fopen("log.txt","a");//log.txt를 수정 모드로 엽니다.

	fprintf(outfile,"%d %d %c",t,index,freecells[index-1]->suit);//카드의 이동정보를 파일에 입력합니다.

	if(freecells[index-1]->number!=1 && freecells[index-1]->number!=11 && freecells[index-1]->number!=12 && freecells[index-1]->number!=13)
		fprintf(outfile,"%d ",freecells[index-1]->number);
	else if(freecells[index-1]->number==1)
		fprintf(outfile,"%c ",'A');
	else if(freecells[index-1]->number==11)
		fprintf(outfile,"%c ",'J');
	else if(freecells[index-1]->number==12)
		fprintf(outfile,"%c ",'Q');
	else if(freecells[index-1]->number==13)
		fprintf(outfile,"%c",'K');
	//움직이는 카드의 정보를 파일에 입력합니다.
	fprintf(outfile,"%d %d\n",l,index2);//카드의 추가적인 이동정보를 파일에 입력합니다.

	fclose(outfile);//outfile파일경로를 닫아줍니다.
}
void start_log()//로그 시작
{
	FILE* outfile;//outfile 파일경로 선언
	outfile=fopen("log.txt","w");//log.txt를 쓰기전용으로 엽니다.
	fprintf(outfile,"Start\n");//Start입력
	fclose(outfile);//파일경로 닫기
}
void end_log()//로그 마침
{
	FILE* outfile;//outfile 파일경로 선언
	outfile=fopen("log.txt","a");//log.txt를 수정전용으로 엽니다.
	fprintf(outfile,"Win\n");//Win입력
	fclose(outfile);//파일경로 닫기
}