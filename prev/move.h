#pragma once
//�浹 ����
void line_home(struct lineStack from[],int ind1,struct homecell to[],int ind2);
void free_home(struct card *freecells[],int ind1,struct homecell to[],int ind2);
void free_line(struct card *freecells[],int ind1,struct lineStack to[],int ind2);
void line_free(struct lineStack from[],int ind,struct card* freecells[],int ind2);
void free_free(struct card* freecells[],int ind1,int ind2);
void line_line(struct lineStack lineStacks[],int from,int to,int amt);

void case1_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l);
void case1_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l);
void case1_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int num_card,int t,int l);

void case2_1(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l);
void case2_2(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l);
void case2_3(struct card* freecells[],struct lineStack lineStacks[],struct homecell homecells[],int index,int t,int l);

//�Լ� ����. �Լ��� ���� ������ .c���Ͽ� �ּ�ó�� �� ���ҽ��ϴ�.