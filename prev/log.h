#pragma once
//충돌방지
void start_log();
void end_log();
void log_line(struct lineStack lineStacks[],int index,int index2,int num_card,int t,int l);
void log_free(struct card *freecells[],int index,int index2,int t,int l);
//함수 선언. 함수에 대한 설명은 .c파일에 주석처리 해 놓았습니다.