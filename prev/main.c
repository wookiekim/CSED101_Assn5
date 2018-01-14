#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "card.h"
#include "move.h"
#include "log.h"
#include "checkWin.h"
#include "print.h"
#include "set.h"
//필요한 헤더파일들과 사용자 지정 헤더파일들을 포함한다.
int main(int argc, char *argv[])//인자를 사용자에게 입력받는다.
{
	struct lineStack lineStacks[8]={0};
	struct card *freecells[4]={0};
	struct homecell homecells[4]={0}; //homecell,freecell 그리고 linestack을 선언 및 초기화해줍니다.
	char repeat[4][13]={0};//중복을 방지하기 위하여 읽어온 카드의 정보를 저장하는 배열입니다.
	FILE * infile;//파일경로를 선언해줍니다.
	int target,index,index1,num_card,location;//필요한 변수들을 선언하여줍니다.

	freopen("check.txt","r",stdin);
	freopen("check2.txt","w",stdout);

	if(!check_file(argv)){//만일 입력받은 인자가 올바르지 않다면
		printf("Error : Invalid command line argument\n");
		return 0;//에러메세지와 함께 프로그램을 종료합니다.
	}
		infile=fopen(argv[2],"r");//3번째 인자를 파일명으로, 읽기형식으로 열어줍니다.

		if(infile==NULL){//만일 파일경로가 비어있다면
			printf("Error : File doesn't exist\n");
			return 0;//파일이 없다는 메세지와 함께 종료합니다.
		}

		set_board(lineStacks,infile,repeat);//파일에서 프리셀 판의 정보를 읽어와 라인스택에 배치합니다.

		if(check_repeat(repeat)){//중복을 확인합니다.
			printf("Error: Invalid input file\n");
			return 0;//중복이 있다면 에러 메세지와 함께 종료합니다.
		}

		print_board(lineStacks,freecells,homecells);//초기 판을 출력합니다.

		start_log();//로그에 입력을 시작합니다.

		while(check_win(lineStacks,freecells)){//우승조건을 만족할때까지

			printf("Please enter the target (Line stack - 1, Freecell - 2): ");//사용자 입력 요구 출력
			scanf("%d",&target);//사용자 입력을 받습니다.
			if(target==2){//2를 입력받을 시

				printf("Please enter the index:");//사용자 입력 요구 출력
				scanf("%d",&index1);//사용자 입력을 받습니다.

				if(freecells[index1-1]!=0){//만일 입력받은 인덱스의 프리셀이 비어있는 것이 아니라면
					
					print_free(freecells,index1-1);//해당 프리셀에 저장되어있는 카드정보를 출력합니다.

					printf("Please enter the location (Line stack-1, Freecell-2, Homecell-3, Cancel-4):");//사용자 입력 요구 출력
					scanf("%d",&location);//사용자 입력을 받습니다.

					switch(location){//입력받은 값에 따라서 다음을 실행합니다.
					case 1://1을 입력받았을 시
						case2_1(freecells,lineStacks,homecells,index1-1,target,location);//해당 함수 실행
						break;

					case 2://2를 입력받았을 시
						case2_2(freecells,lineStacks,homecells,index1-1,target,location);//해당 함수 실행
						break;
					case 3://3을 입력받았을 시
						case2_3(freecells,lineStacks,homecells,index1-1,target,location);//해당 함수 실행
						break;
					case 4://4를 입력받았을 시
						continue;//다시 반복문으로 돌아갑니다.

					}
				}
				else printf("Error : Illegal card selection\n");//만일 입력받은 인덱스의 프리셀이 비어있다면 오류문구를 출력합니다.

			}

			else if(target==1){//입력받은 target이 1이라면

				printf("Please enter the index and a number of cards:");//사용자 요구 출력
				scanf("%d %d",&index,&num_card);//인덱스와 카드 수를 입력받습니다.

				if(!check_line(lineStacks,freecells,index-1,num_card)){//입력받은 인덱스의 입력받은 카드 수만큼이 한번에 움직일 수 없는 뭉큼일때
					printf("Error: Illegal	card selection\n");//오류 문구 출력
					continue;//반복문으로 돌아갑니다.
				}
					print_line(lineStacks,index-1,num_card);//입력받은 인덱스의 입력받은 카드 수만큼의 카드들을 출력합니다.

					printf("Please enter the location (Line stack-1, Freecell-2, Homecell-3, Cancel-4):");//사용자 입력 요구 출력
					scanf("%d",&location);//사용자에게 location값을 입력받습니다.

					switch(location){//입력받은 location의 값에 따라 다음을 실행합니다.
					case 1://입력받은 location의 값이 1일때
						case1_1(freecells,lineStacks,homecells,index-1,num_card,target,location);//해당 함수 실행
						break;
					case 2://입력받은 location의 값이 2일때
						case1_2(freecells,lineStacks,homecells,index-1,num_card,target,location);//해당 함수 실행
						break;
					case 3://입력받은 location의 값이 3일때
						case1_3(freecells,lineStacks,homecells,index-1,num_card,target,location);//해당 함수 실행
						break;
					case 4://입력받은 location의 값이 4일때
						continue;//반복문으로 돌아갑니다.

					}
			}
			else//입력받은 target이 1도 2도 아닐 시
				printf("Invalid target, Please reenter\n");//재입력 요구 문구 출력
		}

	printf("\n\nYou Win!\n\n");//우승해서 while문을 탈출했을 시 우승문구 출력
	fclose(infile);//infile 파일경로를 닫아줍니다.
	end_log();//log작성 완료
	free_memory(homecells);//동적할당 된 메모리들을 free시켜줍니다.
	return 0;//프로그램을 종료합니다.
}
