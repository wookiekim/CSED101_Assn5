#pragma once//�浹�� �Ͼ�� �ʵ��� ����

struct card {//struct card ����
int number;//ī���� ���ڸ� �����ϴ� ����
char suit;//ī���� ����� �����ϴ� ����
struct card *next;//���� ī���� �ּҰ��� �����ϴ� ����
};

void set_card(struct lineStack lineStacks[],char read[], int index);//ī�������� �о���� �Լ� ����