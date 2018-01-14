#pragma once//충돌이 일어나지 않도록 선언

struct card {//struct card 선언
int number;//카드의 숫자를 저장하는 변수
char suit;//카드의 모양을 저장하는 변수
struct card *next;//다음 카드의 주소값을 저장하는 변수
};

void set_card(struct lineStack lineStacks[],char read[], int index);//카드정보를 읽어오는 함수 선언