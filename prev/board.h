#pragma once//�浹�� �Ͼ�� �ʵ���

struct lineStack {//struct lineStack ����ü ����
 struct card *head;//������ ī���� �ּ�
 struct card *tail;//�� �Ʒ� ī���� �ּ�
 int count;//�� ī�� ����
};
struct homecell {//struct homecell ����ü ����
 struct card *head;//�� ���� ī���� �ּ�
 struct card *tail;//�� �Ʒ� ī���� �ּ�
 int count;//�� ī�� ����
};
//board.h
int check_color(struct card* a,struct card* b);
int check_line(struct lineStack a[],struct card *free[],int index,int num);
void free_memory(struct homecell homecells[]);
void add_info(char repeat[][13],char * read);
int check_repeat(char repeat[][13]);

//�ش� .c �ҽ����Ͽ� ���ǵǾ��ִ� �Լ����� ����. ������ .c���Ͽ� �ּ�ó�� �� ���ҽ��ϴ�.