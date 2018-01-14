#include "board.h"
#include "card.h"
#include "log.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>
//�ʿ��� ���� ����
void line_home(struct lineStack from[],int ind1,struct homecell to[],int ind2)//���ν��ÿ��� Ȩ���� �����̴� �Լ�
{
	struct card * temp;

	if(to[ind2].count==0){//���� �ش� Ȩ���� ����ִٸ�
		to[ind2].head=from[ind1].head;
		to[ind2].tail=from[ind1].head;
		//�ش� Ȩ���� ���ϰ� ��尡 �� �� ���ν����� ��带 ����Ű����
	}
	else{//�ش� Ȩ���� ������� �ʴٸ�
		
		to[ind2].head->next=from[ind1].head;//�ش� Ȩ���� ��尡 next�� ���ν����� ��带 ����Ű����
		to[ind2].head=from[ind1].head;//�ش� Ȩ���� ��尡 ���ν����� ��带 ����Ű����
	}
	(to[ind2].count)++;//�ش� Ȩ���� ī��Ʈ 1 ����

	if(from[ind1].count>1){//���� ���ν����� ī�尡 �Ѱ� �̻� �����ִٸ�
	for(temp=from[ind1].tail;temp->next->next!=0;temp=temp->next);
	temp->next=NULL;//������ ���ν����� ����� �ٷ� �� ī�带 ����Ű���� �Ѵ�.
	from[ind1].head=temp;//�ش� ���ν����� ���ο� ���� ������ ��带 ����Ű�� ī��� �Ѵ�.
	}
	else{//���� ���ν����� 1���� ī�常 �����־��ٸ�
		from[ind1].head=NULL;
		from[ind1].tail=NULL;//�ش� ���ν����� ���� ���� �� �� NULL
	}
	
	(from[ind1].count)--;//�ش� ���ν����� ī��Ʈ ����

	printf("Moving is successful\n");//�̵����� ���

}
void free_home(struct card *freecells[],int ind1,struct homecell to[],int ind2)//���������� Ȩ���� �����̴� �Լ�
{
	
	if(to[ind2].count==0){//���� �ش� Ȩ���� ����ִٸ�
		to[ind2].head=freecells[ind1];
		to[ind2].tail=freecells[ind1];//�ش� Ȩ���� ���ϰ� ��尡 �Ѵ� �ش� �������� ����Ű����
	}
	else{//�ش� Ȩ���� ������� �ʴٸ�
		to[ind2].head->next=freecells[ind1];//Ȩ���� ��尡 next�� �������� ����Ű�� �ϰ�
		to[ind2].head=freecells[ind1];//Ȩ���� ��带 �ش� �������� ����
	}
	(to[ind2].count)++;//�ش� Ȩ���� ī��Ʈ 1 ����

	freecells[ind1]=NULL;//�ش� ������ ���ʱ�ȭ

	printf("Moving is successful\n");//�̵� ���� ���
}
void free_line(struct card *freecells[],int ind1,struct lineStack to[],int ind2)//���������� ���ν������� ī���̵�
{
	if(to[ind2].count==0){//���� �ش� ���ν����̶� ����ִٸ�
		to[ind2].head=freecells[ind1];
		to[ind2].tail=freecells[ind1];//�ش� ���ν����� ���� ������ �� �� �������� ������ ����Ű����
	}
	else{//�ش� ���ν����� ������� �ʴٸ�
		to[ind2].head->next=freecells[ind1];
		to[ind2].head=freecells[ind1];//�������� �ִ� ������ ���ο� �����μ� ���ν��ÿ� �߰�.
	}
	(to[ind2].count)++;//���ν����� ī��Ʈ 1 ����

	freecells[ind1]=NULL;//������ �� �ʱ�ȭ

	printf("Moving is successful\n");//�̵� ���� ���
}
void line_free(struct lineStack from[],int ind,struct card* freecells[],int ind2)//���ν��ÿ��� �������� �̵�
{
	struct card * temp;

	freecells[ind2]=from[ind].head;//�ش� �������� ���ν����� ��带 ����Ű����

	if(from[ind].count>1){//���� �ش� ���ν��ÿ� 1���̻��� ī�尡 �����ִٸ�

	for(temp=from[ind].tail;temp->next->next!=0;temp=temp->next);
	temp->next=NULL;
	from[ind].head=temp;//�ش� ���ν����� ��带 ����Ű�� ��带 ���� �����Ѵ�.
	}
	else{//�ش� ���ν��ÿ� 1���� ī�常 �����ִٸ�
		from[ind].tail=NULL;
		from[ind].head=NULL;//�ش� ���ν����� ���� ������ �� �ʱ�ȭ
	}
	
	(from[ind].count)--;//�ش� ���ν����� ī��Ʈ 1 ����
	
	printf("Moving is successful\n");//�̵� ���� ���
}
void free_free(struct card* freecells[],int ind1,int ind2)//�������� �������� �̵�
{
	freecells[ind2]=freecells[ind1];//���� �������� source�������� ����Ű���� �Ѵ�.
	freecells[ind1]=NULL;//source�������� �� �ʱ�ȭ.

	printf("Moving is successful\n");//�̵� ���� ���
}
void line_line(struct lineStack lineStacks[],int from,int to,int amt)//���ν��ÿ��� ���ν������� �̵�
{
	struct card* temp;
	int i;

	if(lineStacks[from].count>amt){//���ν��ÿ� �����ִ� ī���� ������ �����̰� ���� ī���� �������� ���� ��

		temp=lineStacks[from].tail;
		for(i=0;i<lineStacks[from].count-amt-1;i++)
			temp=temp->next;//������ �����̰� ���� ī��(��)�� ����Ű���� �Ѵ�.

		if(lineStacks[to].count==0){//���� ���� ���ν����� ����ִٸ�
			lineStacks[to].tail=temp->next;
			lineStacks[to].head=lineStacks[from].head;
		}
		else{//���� ���� ���ν����� ������� �ʴٸ�
			lineStacks[to].head->next=temp->next;
			lineStacks[to].head=lineStacks[from].head;
		}
		lineStacks[to].count+=amt;//���� ���ν��ÿ� ������ ī���� ������ŭ ī��Ʈ�� �����Ͽ��ش�.

		temp->next=NULL;//source���ν��ÿ��� ������ ī����� ���̻� ����Ű�� �ʵ��� NULL�� ����Ű���� �Ѵ�.
		lineStacks[from].head=temp;//source���� ������ ���ο� �ҽ��� ������ ī��(��)�� �ٷ� �� ī��� �Ѵ�.
		lineStacks[from].count-=amt;//source���ν��ÿ��� ������ ī���� ������ŭ count�� ���ش�.

	}

	else{//���� �����̰� ���� ī��� source���ν��ÿ� �����ִ� ī���� ������ ���� ��
		temp=lineStacks[from].tail;
		lineStacks[to].head->next=temp;
		lineStacks[to].head=lineStacks[from].head;//�ش� ī��(��)�� ������ ���� ���ν��ÿ� �̾��ش�.
		lineStacks[to].count+=amt;//������ ī���� ������ŭ ī��Ʈ�� ���������ش�.

		lineStacks[from].tail=NULL;
		lineStacks[from].head=NULL;//�ҽ� ���ν����� ���� ������ ���ʱ�ȭ���ش�.
		lineStacks[from].count-=amt;//������ ī���� ������ŭ �ҽ� ���ν��ÿ��� ���ش�.
	}
	printf("Moving is successful\n");//�̵� ���� ���
}

//target�� 1
void case1_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location �� 1
	int index2,i;
	struct card* temp;
	printf("Please enter the index: ");//�ε��� �Է� �䱸
	scanf("%d",&index2);//����ڿ��Լ� �ε��� �Է¹ޱ�
	if(lineStacks[index2-1].count==0){//���� �ش� �ε����� ���ν����� ����ִٸ� 
		log_line(lineStacks,index+1,index2,num_card,t,l);//�α� �ۼ�
		line_line(lineStacks,index,index2-1,num_card);	//�̵�
		print_board(lineStacks,freecells,homecells);//������ �� ���
	}
	else{//���� �ش� �ε����� ���ν����� ������� �ʴٸ�
		temp=lineStacks[index].tail;
		for(i=0;i<lineStacks[index].count-num_card;i++)
			temp=temp->next;//������ �����̰� ���� ī��(��)�� ����Ű����
		if(check_color(temp,lineStacks[index2-1].head)){//���� �ٸ��� Ȯ��
			if((temp->number)+1==(lineStacks[index2-1].head->number)){//���ڰ� 1 �������� Ȯ��
				log_line(lineStacks,index+1,index2,num_card,t,l);//�α� �ۼ�
				line_line(lineStacks,index,index2-1,num_card);//�̵�
				print_board(lineStacks,freecells,homecells);//������ �� ���
			}
			else printf("Error : Illegal Moving\n");//���ڰ� 1 ���̰� �ƴ� ��
		}
		else printf("Error : Illegal Moving\n");//���� ���� ��
	}
}
void case1_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location�� 2
	int index2;
	printf("Please enter the index: ");//�ε��� �Է� �䱸 ���� ���
	scanf("%d",&index2);//����ڿ��Լ� �ε��� �Է¹���
	if(freecells[index2-1]==0 && num_card==1){//�ش� �������� ����ְ�, �����̰� ���� ī���� ������ 1�Ͻ�
		log_line(lineStacks,index+1,index2,num_card,t,l);//�α� �ۼ�
		line_free(lineStacks,index,freecells,index2-1);//�̵�
		print_board(lineStacks,freecells,homecells);//������ �� ���
	}
	else printf("Error : Illegal Moving\n");//�������� ������� �ʰų�, 1���̻��� ī�带 �����̰� ���� �� �����޼��� ���
}
void case1_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l)
{//location�� 3�� ��
	int index2;
	printf("Please enter the index: ");//�Է¿䱸���� ���
	scanf("%d",&index2);//����ڿ��Լ� �ε��� �Է¹ޱ�
	if(homecells[index2-1].count==0){//���� Ȩ���� ����ִٸ�
		if(lineStacks[index].head->number==1 && num_card==1){//�����̰� ���� ī�尡 1���̰�, A�Ͻ� 
			log_line(lineStacks,index+1,index2,num_card,t,l);//�α��ۼ�
			line_home(lineStacks,index,homecells,index2-1);//�̵�
			print_board(lineStacks,freecells,homecells);//������ �� ���
		}
		else printf("Error : Illegal Moving\n");//�����̰� ���� ī�尡 1�� �̻��̰ų� A�� �ƴ� �� 
	}
	else{//���� Ȩ���� ������� �ʴٸ�
		if(lineStacks[index].head->suit==homecells[index2-1].head->suit){//��Ʈ�� ������ Ȯ��
			if((lineStacks[index].head->number)==(homecells[index2-1].head->number)+1){//�����̰� ���� ī��� Ȩ���� �� �� ī�尡 1 �������� Ȯ��
				log_line(lineStacks,index+1,index2,num_card,t,l);//�α��ۼ�
				line_home(lineStacks,index,homecells,index2-1);//�̵�
				print_board(lineStacks,freecells,homecells);//������ �� ���
			}
			else printf("Error : Illegal Moving\n");//ī��� Ȩ���� ���� ī���� �� ���̰� 1 �� �ƴ� ��
		}
		else printf("Error : Illegal Moving\n");//��Ʈ�� �ٸ� ��
	}
}

//target�� 2
void case2_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location�� 1
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//�ε��� �Է¹ޱ�

	if(lineStacks[index2-1].count==0){//���� �ش� ���ν����� ����ִٸ�
		log_free(freecells,index+1,index2,t,l);//�α��ۼ�
		free_line(freecells,index,lineStacks,index2-1);//�̵�
		print_board(lineStacks,freecells,homecells);//������ �� ���
	}
	else{//�ش� ���ν����� ������� �ʴٸ�
		if(check_color(freecells[index],lineStacks[index2-1].head)){//���� �ٸ��� Ȯ��
			if((freecells[index]->number)+1==(lineStacks[index2-1].head->number)){//ī���� �� ���̰� 1�� �´��� Ȯ��
				log_free(freecells,index+1,index2,t,l);//�α��ۼ�
				free_line(freecells,index,lineStacks,index2-1);//�̵�
				print_board(lineStacks,freecells,homecells);}//������ �� ���
			else printf("Error : Illegal Moving\n");//ī���� �� ���̰� 1�� �ƴ� ��
		}
		else printf("Error : Illegal Moving\n");//���� ���� ��
	}
}
void case2_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location�� 2�� �� 
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//index�Է¹ޱ� 
	if(freecells[index2-1]==0){//�ش� �������� ����ִٸ�
		log_free(freecells,index+1,index2,t,l);//�α��ۼ�
		free_free(freecells,index,index2-1);//�̵�
		print_board(lineStacks,freecells,homecells);//������ �� ���
	}
	else printf("Error : Illegal Moving\n");//�������� ������� �ʴٸ�
}
void case2_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l)
{//location�� 3�Ͻ�
	int index2;

	printf("Please enter the index: ");
	scanf("%d",&index2);//����ڿ��Լ� index�Է¹ޱ�
	if(homecells[index2-1].count==0){//�ش� Ȩ���� ����ִٸ�
		if(freecells[index]->number==1){//�����̷��� ī�尡 A�� �´ٸ�
			log_free(freecells,index+1,index2,t,l);//�α��ۼ�
			free_home(freecells,index,homecells,index2-1);//�̵�	
			print_board(lineStacks,freecells,homecells);//������ �� ���
		}
		else printf("Error : Illegal Moving\n");//�����̷��� ī�尡 A�� �ƴ� ��
	}
	else{
		if(freecells[index]->suit==homecells[index2-1].head->suit){//��Ʈ�� ������ Ȯ��
			if((freecells[index]->number)==(homecells[index2-1].head->number)+1){//ī����� ���� ���̰� 1�� �´��� Ȯ��
				log_free(freecells,index+1,index2,t,l);//�α��ۼ�
				free_home(freecells,index,homecells,index2-1);//�̵�
				print_board(lineStacks,freecells,homecells);}//������ �� ���
			else printf("Error : Illegal Moving\n");//ī����� ���� ���̰� 1�� �ƴ� ��
		}
		else printf("Error : Illegal Moving\n");//��Ʈ�� �ٸ� ��
	}
}