#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "card.h"
//필요한 헤더파일들을 include하여 줍니다.
int check_color(struct card *a,struct card *b)//두 카드의 색을 비교하여줍니다.
{
	if((a->suit=='S' || a->suit=='C') && (b->suit=='H' || b->suit=='D'))///
		return 1;
	else if((b->suit=='S' || b->suit=='C') && (a->suit=='H' || a->suit=='D'))
		return 1;
	else return 0;//색이 같다면 0을, 다르다면 1을 반환하여줍니다.
}
int check_line(struct lineStack a[],struct card *free[],int index,int num)//linestack에서 선택된 개수의 카드들이 한 뭉치로 움직일 수 있는지 확인하여줍니다.
{
	struct card* temp;//포인터형 struct card변수 선언
	int fcount=0,lcount=0,i,max;//필요한 변수들 선언

	if(a[index].count<num)//만일 해당 라인스택에 남아있는 카드보다 많은 카드를 요구하였을 시
		return 0;//0 반환

	if(num>1){
		for(i=0;i<4;i++)
			if(free[i]==NULL)
				fcount++;//비어있는 freecell의 값을 fcount에 저장
		for(i=0;i<8;i++)
			if(!a[i].count)
				lcount++;//비어있는 linestack의 값을 lcount에 저장

		max=(fcount+1)*(lcount+1);//움직일수 있는 카드의 최대 개수를 정하여줍니다.

		if(num>max)//만일 움직이고 싶은 카드의 수가 최대 개수보다 많다면
			return 0;//0 반환

		temp=a[index].tail;
		for(i=0;i<a[index].count-num-1;i++)
			temp=temp->next;//템프를 움직이고 싶은 첫 카드를 가르키도록 움직입니다

		if(a[index].count>num){//만일 해당 라인스택에 남아있는 카드가 움직이고 싶은 카드보다 많을때

			for(i=1;i<num;i++,temp=temp->next){//그 이후로 움직이고 싶은 마지막 카드까지
				if(!check_color(temp->next,temp->next->next))//붙어있는 카드의 색이 같다면
					return 0;//0 반환

				if(temp->next->number!=temp->next->next->number+1)//붙어있는 카드의 수의 차이가 1이 아니라면(순서 중요)
					return 0;//0 반환
			}
		}

		else{//만일 해당 라인스택에 남아있는 카드가 움직이고 싶은 카드와 같은 개수일때
			for(i=1;i<num;i++,temp=temp->next){
				if(!check_color(temp,temp->next))//붙어있는 카드의 색이 같다면
					return 0; //0반환

				if(temp->number!=temp->next->number+1)//붙어있는 카드의 수의 차이가 1이 아니라면 (순서중요)
					return 0;//0 반환
			}
		}
	}

	return 1;//여기까지 돌았다면 1 반환
}
void free_memory(struct homecell homecells[])//동적할당 된 메모리를 풀어줍니다.
{
	struct card* temp1,*temp2;
	int i;
	//필요한 변수 선언
	for(i=0;i<4;i++){//i 가 0 부터 3까지 (4번)
		for(temp1=homecells[i].tail;temp1!=NULL;temp1=temp2){
			temp2=temp1->next;
			free(temp1);//해당 homecell의 노드들에 동적할당 되어있는 메모리를 free하여줍니다.
		}
	}
}
void add_info(char repeat[][13],char * read)//읽은 카드의 정보를 배열에 저장하는 함수입니다.
{
	int i;//필요한 변수 선언
	switch(read[0]){//read[0]에 저장되어있는 값에 따라서
		case 'S'://만일 S라면, 배열의 0번쨰 행에서 실행
			for(i=0;i<13;i++){//최대 13번 반복
				if((strlen(read)==2 && repeat[0][i]==read[1]) || (strlen(read)==3 && repeat[0][i]=='0'))//이미 같은 정보가 저장되어있다면
				break;//반복문 탈출
				else if(repeat[0][i]==0){//칸이 비어있다면
					if(strlen(read)==2)//read에 2개의 문자가 저장되어 있을 시
						repeat[0][i]=read[1];//해당 배열칸에 read[1]에 저장되어있는 정보 저장
					else repeat[0][i]='0';//read에 2개의 문자가 아닐 시 (3개의 문자) -> 해당 배열칸에 캐릭터형 0 저장
					break;
				}
			}
			break;
		case 'H'://만일 H라면, 위와 같지만 배열의 1번째 행에서 실행된다.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[1][i]==read[1]) || (strlen(read)==3 && repeat[1][i]=='0'))
				break;
				else if(repeat[1][i]==0){
					if(strlen(read)==2)
						repeat[1][i]=read[1];
					else repeat[1][i]='0';
					break;
				}
			}
			break;
		case 'D'://만일 D라면, 위와 같지만 배열의 2번째 행에서 실행된다.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[2][i]==read[1]) || (strlen(read)==3 && repeat[2][i]=='0'))
				break;
				else if(repeat[2][i]==0){
					if(strlen(read)==2)
						repeat[2][i]=read[1];
					else repeat[2][i]='0';
					break;
				}
			}
			break;
		case 'C'://만일 C라면, 위와 같지만 배열의 3번째 행에서 실행된다.
			for(i=0;i<13;i++){
				if((strlen(read)==2 && repeat[3][i]==read[1]) || (strlen(read)==3 && repeat[3][i]=='0'))
				break;
				else if(repeat[3][i]==0){
					if(strlen(read)==2)
						repeat[3][i]=read[1];
					else repeat[3][i]='0';
					break;
				}
			}
			break;
	}
}
int check_repeat(char repeat[][13])//중복이 있는지 확인하는 함수입니다.
{
	int i,j,count=0;

	for(i=0;i<4;i++)
		for(j=0;j<13;j++)
			if(repeat[i][j]!=0)
				count++;//배열이 비어있지 않을 때마다 1을 더합니다.
	if(count==52)//만일 52개의 정보가 다 있다면
		return 0;//0 반환
	else return 1;//52개의 정보가 없을 시 (중복이 있거나, 초기상태의 라인스택에서 틀린 양의 카드가 있다면 적게 들어가있다) 1반환.
}