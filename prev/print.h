#pragma once
//�浹 ����
void print_board(struct lineStack lineStacks[],struct card *freecells[],struct homecell homecells[]);
void print_free(struct card*freecells[4],int index);
void print_line(struct lineStack lineStacks[],int index,int num_card);
//�Լ� ����. �Լ��� ������ ,c���Ͽ� �ּ�ó�� �� ���ҽ��ϴ�.