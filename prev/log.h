#pragma once
//�浹����
void start_log();
void end_log();
void log_line(struct lineStack lineStacks[],int index,int index2,int num_card,int t,int l);
void log_free(struct card *freecells[],int index,int index2,int t,int l);
//�Լ� ����. �Լ��� ���� ������ .c���Ͽ� �ּ�ó�� �� ���ҽ��ϴ�.