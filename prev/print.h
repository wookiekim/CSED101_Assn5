#pragma once
//충돌 방지
void print_board(struct lineStack lineStacks[],struct card *freecells[],struct homecell homecells[]);
void print_free(struct card*freecells[4],int index);
void print_line(struct lineStack lineStacks[],int index,int num_card);
//함수 선언. 함수의 설명은 ,c파일에 주석처리 해 놓았습니다.