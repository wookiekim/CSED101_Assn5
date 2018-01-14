#include <stdio.h>
#include <string.h>
#include "card.h"
#include "board.h"
//필요한 헤더파일들을 include하여줍니다.
void set_board(struct lineStack lineStacks[],FILE* infile,char repeat[][13])//파일에서 카드정보를/ 읽어와 배치합니다.
{
	int i,j,no;
	char read[4];//필요한 변수들과 문자열을 선언합니다.

	for(i=0;i<4;i++){//4번동안
		fscanf(infile,"%d",&no);//파일에서 숫자를 받아옵니다. (이는 lineStack의 인덱스)
		if(!(no < 5 && no > 0))//만일 파일에서 읽어온 숫자가 0과 5사이에 없다면
			continue;//반복문으로 돌아간다.

		for(j=0;j<7;j++){//7번동안
			fscanf(infile,"%s",read);//파일에서 카드정보를 읽어옵니다.
			if(strlen(read)>1){//읽어온 정보가 1 character보다 많을 시 (정상적인 카드라면 최소 2)
				add_info(repeat,read);//해당 정보를 중복방지를 위해 배열에 저장
				set_card(lineStacks,read,i);//해당 정보를 저장하고 있는 struct card형 구조체 만들기
			}else break;//만일 읽어온 정보가 1글자라면 반복문을 탈출합니다.
		}
	}

	for(i=4;i<8;i++){//4번동안
		fscanf(infile,"%d",&no);//파일에서 숫자를 받아옵니다. (이는 lineStack의 인덱스)
		if(!(no < 9 && no > 4))//만일 파일에서 읽어온 숫자가 4과 9사이에 없다면
			continue;//반복문으로 돌아간다.

		for(j=0;j<6;j++){//7번동안
			fscanf(infile,"%s",read);//파일에서 카드정보를 읽어옵니다.
			if(strlen(read)>1){//읽어온 정보가 1 character보다 많을 시 (정상적인 카드라면 최소 2)
				add_info(repeat,read);//해당 정보를 중복방지를 위해 배열에 저장
				set_card(lineStacks,read,i);//해당 정보를 저장하고 있는 struct card형 구조체 만들기
			}else break;//만일 읽어온 정보가 1글자라면 반복문을 탈출합니다.
		}
	}

}
int check_file(char *argv[])//입력된 인자가 올바른지 확인
{
	if(!strcmp(argv[1],"file"))//만일 argv[1]에 저장되어있는 문자열이 file이 맞을시
		return 1;//1 반환
	else return 0;//아니라면 0 반환
}