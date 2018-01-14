#pragma once//충돌이 일어나지 않도록

struct lineStack {//struct lineStack 구조체 선언
 struct card *head;//맨위의 카드의 주소
 struct card *tail;//맨 아래 카드의 주소
 int count;//총 카드 개수
};
struct homecell {//struct homecell 구조체 선언
 struct card *head;//맨 위의 카드의 주소
 struct card *tail;//맨 아래 카드의 주소
 int count;//총 카드 개수
};
//board.h
int check_color(struct card* a,struct card* b);
int check_line(struct lineStack a[],struct card *free[],int index,int num);
void free_memory(struct homecell homecells[]);
void add_info(char repeat[][13],char * read);
int check_repeat(char repeat[][13]);

//해당 .c 소스파일에 정의되어있는 함수들을 선언. 설명은 .c파일에 주석처리 해 놓았습니다.