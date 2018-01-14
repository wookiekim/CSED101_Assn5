#include <stdio.h>
#include <string.h>
#include "card.h"
#include "board.h"
//�ʿ��� ������ϵ��� include�Ͽ��ݴϴ�.
void set_board(struct lineStack lineStacks[],FILE* infile,char repeat[][13])//���Ͽ��� ī��������/ �о�� ��ġ�մϴ�.
{
	int i,j,no;
	char read[4];//�ʿ��� ������� ���ڿ��� �����մϴ�.

	for(i=0;i<4;i++){//4������
		fscanf(infile,"%d",&no);//���Ͽ��� ���ڸ� �޾ƿɴϴ�. (�̴� lineStack�� �ε���)
		if(!(no < 5 && no > 0))//���� ���Ͽ��� �о�� ���ڰ� 0�� 5���̿� ���ٸ�
			continue;//�ݺ������� ���ư���.

		for(j=0;j<7;j++){//7������
			fscanf(infile,"%s",read);//���Ͽ��� ī�������� �о�ɴϴ�.
			if(strlen(read)>1){//�о�� ������ 1 character���� ���� �� (�������� ī���� �ּ� 2)
				add_info(repeat,read);//�ش� ������ �ߺ������� ���� �迭�� ����
				set_card(lineStacks,read,i);//�ش� ������ �����ϰ� �ִ� struct card�� ����ü �����
			}else break;//���� �о�� ������ 1���ڶ�� �ݺ����� Ż���մϴ�.
		}
	}

	for(i=4;i<8;i++){//4������
		fscanf(infile,"%d",&no);//���Ͽ��� ���ڸ� �޾ƿɴϴ�. (�̴� lineStack�� �ε���)
		if(!(no < 9 && no > 4))//���� ���Ͽ��� �о�� ���ڰ� 4�� 9���̿� ���ٸ�
			continue;//�ݺ������� ���ư���.

		for(j=0;j<6;j++){//7������
			fscanf(infile,"%s",read);//���Ͽ��� ī�������� �о�ɴϴ�.
			if(strlen(read)>1){//�о�� ������ 1 character���� ���� �� (�������� ī���� �ּ� 2)
				add_info(repeat,read);//�ش� ������ �ߺ������� ���� �迭�� ����
				set_card(lineStacks,read,i);//�ش� ������ �����ϰ� �ִ� struct card�� ����ü �����
			}else break;//���� �о�� ������ 1���ڶ�� �ݺ����� Ż���մϴ�.
		}
	}

}
int check_file(char *argv[])//�Էµ� ���ڰ� �ùٸ��� Ȯ��
{
	if(!strcmp(argv[1],"file"))//���� argv[1]�� ����Ǿ��ִ� ���ڿ��� file�� ������
		return 1;//1 ��ȯ
	else return 0;//�ƴ϶�� 0 ��ȯ
}