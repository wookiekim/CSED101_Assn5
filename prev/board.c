#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "card.h"
//�ʿ��� ������ϵ��� include�Ͽ� �ݴϴ�.
int check_color(struct card *a,struct card *b)//�� ī���� ���� ���Ͽ��ݴϴ�.
{
	if((a->suit=='S' || a->suit=='C') && (b->suit=='H' || b->suit=='D'))///
		return 1;
	else if((b->suit=='S' || b->suit=='C') && (a->suit=='H' || a->suit=='D'))
		return 1;
	else return 0;//���� ���ٸ� 0��, �ٸ��ٸ� 1�� ��ȯ�Ͽ��ݴϴ�.
}
int check_line(struct lineStack a[],struct card *free[],int index,int num)//linestack���� ���õ� ������ ī����� �� ��ġ�� ������ �� �ִ��� Ȯ���Ͽ��ݴϴ�.
{
	struct card* temp;//�������� struct card���� ����
	int fcount=0,lcount=0,i,max;//�ʿ��� ������ ����

	if(a[index].count<num)//���� �ش� ���ν��ÿ� �����ִ� ī�庸�� ���� ī�带 �䱸�Ͽ��� ��
		return 0;//0 ��ȯ

	if(num>1){
		for(i=0;i<4;i++)
			if(free[i]==NULL)
				fcount++;//����ִ� freecell�� ���� fcount�� ����
		for(i=0;i<8;i++)
			if(!a[i].count)
				lcount++;//����ִ� linestack�� ���� lcount�� ����

		max=(fcount+1)*(lcount+1);//�����ϼ� �ִ� ī���� �ִ� ������ ���Ͽ��ݴϴ�.

		if(num>max)//���� �����̰� ���� ī���� ���� �ִ� �������� ���ٸ�
			return 0;//0 ��ȯ

		temp=a[index].tail;
		for(i=0;i<a[index].count-num-1;i++)
			temp=temp->next;//������ �����̰� ���� ù ī�带 ����Ű���� �����Դϴ�

		if(a[index].count>num){//���� �ش� ���ν��ÿ� �����ִ� ī�尡 �����̰� ���� ī�庸�� ������

			for(i=1;i<num;i++,temp=temp->next){//�� ���ķ� �����̰� ���� ������ ī�����
				if(!check_color(temp->next,temp->next->next))//�پ��ִ� ī���� ���� ���ٸ�
					return 0;//0 ��ȯ

				if(temp->next->number!=temp->next->next->number+1)//�پ��ִ� ī���� ���� ���̰� 1�� �ƴ϶��(���� �߿�)
					return 0;//0 ��ȯ
			}
		}

		else{//���� �ش� ���ν��ÿ� �����ִ� ī�尡 �����̰� ���� ī��� ���� �����϶�
			for(i=1;i<num;i++,temp=temp->next){
				if(!check_color(temp,temp->next))//�پ��ִ� ī���� ���� ���ٸ�
					return 0; //0��ȯ

				if(temp->number!=temp->next->number+1)//�پ��ִ� ī���� ���� ���̰� 1�� �ƴ϶�� (�����߿�)
					return 0;//0 ��ȯ
			}
		}
	}

	return 1;//������� ���Ҵٸ� 1 ��ȯ
}
void free_memory(struct homecell homecells[])//�����Ҵ� �� �޸𸮸� Ǯ���ݴϴ�.
{
	struct card* temp1,*temp2;
	int i;
	//�ʿ��� ���� ����
	for(i=0;i<4;i++){//i �� 0 ���� 3���� (4��)
		for(temp1=homecells[i].tail;temp1!=NULL;temp1=temp2){
			temp2=temp1->next;
			free(temp1);//�ش� homecell�� ���鿡 �����Ҵ� �Ǿ��ִ� �޸𸮸� free�Ͽ��ݴϴ�.
		}
	}
}
void add_info(char repeat[][13],char * read)//���� ī���� ������ �迭�� �����ϴ� �Լ��Դϴ�.
{
	int i;//�ʿ��� ���� ����
	switch(read[0]){//read[0]�� ����Ǿ��ִ� ���� ����
		case 'S'://���� S���, �迭�� 0���� �࿡�� ����
			for(i=0;i<13;i++){//�ִ� 13�� �ݺ�
				if((strlen(read)==2 && repeat[0][i]==read[1]) || (strlen(read)==3 && repeat[0][i]=='0'))//�̹� ���� ������ ����Ǿ��ִٸ�
				break;//�ݺ��� Ż��
				else if(repeat[0][i]==0){//ĭ�� ����ִٸ�
					if(strlen(read)==2)//read�� 2���� ���ڰ� ����Ǿ� ���� ��
						repeat[0][i]=read[1];//�ش� �迭ĭ�� read[1]�� ����Ǿ��ִ� ���� ����
					else repeat[0][i]='0';//read�� 2���� ���ڰ� �ƴ� �� (3���� ����) -> �ش� �迭ĭ�� ĳ������ 0 ����
					break;
				}
			}
			break;
		case 'H'://���� H���, ���� ������ �迭�� 1��° �࿡�� ����ȴ�.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[1][i]==read[1]) || (strlen(read)==3 && repeat[1][i]=='0'))
				break;
				else if(repeat[1][i]==0){
					if(strlen(read)==2)
						repeat[1][i]=read[1];
					else repeat[1][i]='0';
					break;
				}
			}
			break;
		case 'D'://���� D���, ���� ������ �迭�� 2��° �࿡�� ����ȴ�.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[2][i]==read[1]) || (strlen(read)==3 && repeat[2][i]=='0'))
				break;
				else if(repeat[2][i]==0){
					if(strlen(read)==2)
						repeat[2][i]=read[1];
					else repeat[2][i]='0';
					break;
				}
			}
			break;
		case 'C'://���� C���, ���� ������ �迭�� 3��° �࿡�� ����ȴ�.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[3][i]==read[1]) || (strlen(read)==3 && repeat[3][i]=='0'))
				break;
				else if(repeat[3][i]==0){
					if(strlen(read)==2)
						repeat[3][i]=read[1];
					else repeat[3][i]='0';
					break;
				}
			}
			break;
	}
}
int check_repeat(char repeat[][13])//�ߺ��� �ִ��� Ȯ���ϴ� �Լ��Դϴ�.
{
	int i,j,count=0;

	for(i=0;i<4;i++)
		for(j=0;j<13;j++)
			if(repeat[i][j]!=0)
				count++;//�迭�� ������� ���� ������ 1�� ���մϴ�.
	if(count==52)//���� 52���� ������ �� �ִٸ�
		return 0;//0 ��ȯ
	else return 1;//52���� ������ ���� �� (�ߺ��� �ְų�, �ʱ������ ���ν��ÿ��� Ʋ�� ���� ī�尡 �ִٸ� ���� ���ִ�) 1��ȯ.
}