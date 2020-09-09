#include "Q_S.h"
		

int main()  
{

	char miro_map[my][mx]={				// 미로의 맵을 만든다.
		{wall,way,wall,'s',wall,wall,wall,wall,wall,wall,way,wall,wall,wall,wall,wall},
		{wall,way,wall,way,way,way,way,way,wall,wall,wall,way,way,wall,wall,wall},
		{wall,way,way,way,wall,wall,way,wall,way,wall,way,wall,way,way,way,way},
		{wall,wall,way,wall,way,way,wall,way,wall,way,wall,wall,way,way,wall,wall},
		{wall,way,way,way,wall,wall,way,way,wall,way,wall,way,wall,way,wall,wall},
		{wall,wall,wall,way,way,wall,way,way,wall,way,wall,way,wall,wall,way,wall},
		{wall,wall,wall,way,wall,wall,way,wall,way,wall,way,way,way,wall,wall,wall},
		{way,wall,way,wall,wall,way,wall,way,way,wall,wall,way,wall,way,wall,wall},
		{wall,wall,wall,wall,wall,wall,way,wall,way,wall,way,way,wall,way,wall,wall},
		{way,wall,way,wall,wall,wall,way,wall,wall,wall,wall,way,wall,way,way,wall},
		{wall,wall,way,wall,wall,way,wall,wall,wall,wall,wall,way,way,wall,way,wall},
		{wall,wall,way,way,way,wall,wall,wall,wall,wall,wall,wall,way,wall,wall,way},
		{wall,way,wall,wall,wall,way,wall,wall,wall,way,wall,way,way,way,wall,way},
		{way,wall,wall,wall,wall,wall,way,wall,wall,way,way,way,way,way,'e',way},
		{way,wall,wall,wall,wall,wall,wall,wall,way,way,wall,wall,wall,way,wall,way},

	};




char miro_map2[my][mx];//  맵을 복사해 놓는다.
int count = (mx*my);

char (*move)[mx]=miro_map;  // 맵의 첫 주소 값을 move 포인터에 다가 저장한다.
link *addr;
//-------------------------------------------------변수선언의 끝 -----------------------------------------------//


miro_map_cpy(miro_map,miro_map2);// 2차원 배열의 복사해준다.
	
addr=Q_make();

addr=Q_make_add(addr,count); // 맵의 x*Y만큼의 원형 연결 리스트를 만든다.

map_out(miro_map); // 미로의 맵을 출력한다.

find_state(miro_map,addr);// 시작 좌표을 찾는다.

printf("\n출발점: x = %d  y = %d  Enter을 누르면 길찾기를 시작합니다...\n",addr->prev->miro_x,addr->prev->miro_y);

getchar();  //-test

miro_way_find(addr,move,addr->prev->miro_x,addr->prev->miro_y);//시작 값과 저장될 링크리스트만 값을 보내어 준다.

addr=Q_make_short(addr); //  최단 거리를 구한다.


//--------------------------------------------------첫번째 길찾기의 끝 --------------------------------//



//-----------------------------------------------역으로 길찾기 시작-------------------------------------//
getchar();

system("cls");

miro_map_cpy(miro_map2,miro_map);//맵을 초기화

map_out(miro_map); // 미로의 맵을 출력한다.(맵을 초기상태로 복원한것을 확인);

miro_way_completionQ(addr,move);//완성시킨 미로의 길이 저장된값과, 포인터 값을 넘겨주면 좀더 짧아진 길을 찍어준다.

map_out(miro_map); // 미로의 맵을 출력한다.

getchar();

addr=map_re_find(addr);// 찾은 길을 더욱 줄여준다.  첫번째--

miro_map_cpy(miro_map2,miro_map);//미로의 맵을 초기화

map_out(miro_map); //(맵을 초기상태로 복원한것을 확인);

getchar(); // 첫번째의 끝

addr=map_re_find(addr);// 찾은 길을 더욱 줄여준다.  두번쨰--

//--------------------------------------------------------두번째 길찾기의 끝 --------------------------//



//----------------------------------------마지막 찾으길을 정리..--------------------------------------//

miro_map_cpy(miro_map2,miro_map);// 2차원 배열의 복사해준다.

map_out(miro_map); // 미로의 맵을 출력한다.

miro_way_completionQ(addr,move);//최종 완성된 길을 찍어준다.

map_out(miro_map); //최종 길을 보여준다

printf("---------------길찾기를 완료하였습니다------------------\n");

getchar();
return 0;

}

//---------------------------------------------------------------
































/*  여기까지는 연습 ..// 라이브러리 파일을 위해서 시험해본다.
{

//-------------------------------------------------------------------------------------
	link *addr;
	link *addr1;
	int number =10;
	int i;

	addr=Q_make(); // tail을 저장할 주소를 할당



	addr=Q_make_add(addr,number); //tail의 주소를 넘겨주면 그 수만큼 증가된다.

//-----------------------------------------------------------------------------------

	for(i=1; i<=number; i++)	// 링크에 스택으로 1부터 10 까지 넣어본다.
	{
		addr1=Q_make_findQ(addr,i);
		
		addr1->miro_x=i;
		addr1->miro_y=i;
	}

//-----------------------------------------------------------------------------------

	addr1=Q_make_findQ(addr,6);
	addr1->miro_x=2;
	addr1->miro_y=2;

//------------------------------------------------------------------------------------

	for(i=1; i<=number; i++)	// 링크에 큐로  1부터 10 까지 출력한다.
	{
	
		
		addr1=Q_make_findQ(addr,i);

		printf("x 출력: %d \n",addr1->miro_x);
			
	}

	getchar();
//------------------------------------------------------------------------------------



	addr=Q_make_short(addr); //  최단 거리를 구한다.


//------------------------------------------------------------------------------------



	for(i=1; i<=number; i++)	// 링크리스트에 스택으로 출력한다.
	{
		addr1=Q_make_findS(addr,i);
		
		printf("변환된 값 = %d    ",addr1->miro_x);
		printf("변환된 값 = %d\n",addr1->miro_y);
	}

//---------------------------------------------------------------------------------------------------
*/