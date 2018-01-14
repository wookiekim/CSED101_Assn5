#include <stdio.h>
#include "board.h"
#include "card.h"
//�ʿ��� ��������� include�Ͽ��ݴϴ�.
void log_line(struct lineStack lineStacks[],int index,int index2,int num_card,int t,int l)//���ν��ÿ��� �����϶��� �α��ۼ�
{
	FILE * outfile;//���ϰ�� ����
	struct card* temp;
	int i;
	//�ʿ��� ���� ����
	outfile=fopen("log.txt","a");//log.txt�� ���� ���� ���ϴ�.

	fprintf(outfile,"%d %d %d ",t,index,num_card);//�α׿� ī���̵��� ���� ������ �Է��մϴ�.

	temp=lineStacks[index-1].tail;//�α׿� �̵��� ī���� ������ ��� �Է��մϴ�.
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

	fprintf(outfile,"%d %d\n",l,index2);//�α׿� ī���̵��� ���� �߰��� ������ �Է��մϴ�.

	fclose(outfile);//outfile���ϰ�θ� �ݾ��ݴϴ�.

}
void log_free(struct card *freecells[],int index,int index2,int t,int l)//���������� �����϶��� �α��ۼ�
{
	FILE * outfile;//outfile���ϰ�� ����

	outfile=fopen("log.txt","a");//log.txt�� ���� ���� ���ϴ�.

	fprintf(outfile,"%d %d %c",t,index,freecells[index-1]->suit);//ī���� �̵������� ���Ͽ� �Է��մϴ�.

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
	//�����̴� ī���� ������ ���Ͽ� �Է��մϴ�.
	fprintf(outfile,"%d %d\n",l,index2);//ī���� �߰����� �̵������� ���Ͽ� �Է��մϴ�.

	fclose(outfile);//outfile���ϰ�θ� �ݾ��ݴϴ�.
}
void start_log()//�α� ����
{
	FILE* outfile;//outfile ���ϰ�� ����
	outfile=fopen("log.txt","w");//log.txt�� ������������ ���ϴ�.
	fprintf(outfile,"Start\n");//Start�Է�
	fclose(outfile);//���ϰ�� �ݱ�
}
void end_log()//�α� ��ħ
{
	FILE* outfile;//outfile ���ϰ�� ����
	outfile=fopen("log.txt","a");//log.txt�� ������������ ���ϴ�.
	fprintf(outfile,"Win\n");//Win�Է�
	fclose(outfile);//���ϰ�� �ݱ�
}