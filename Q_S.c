#include "Q_S.h"
		

int main()  
{

	char miro_map[my][mx]={				// �̷��� ���� �����.
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




char miro_map2[my][mx];//  ���� ������ ���´�.
int count = (mx*my);

char (*move)[mx]=miro_map;  // ���� ù �ּ� ���� move �����Ϳ� �ٰ� �����Ѵ�.
link *addr;
//-------------------------------------------------���������� �� -----------------------------------------------//


miro_map_cpy(miro_map,miro_map2);// 2���� �迭�� �������ش�.
	
addr=Q_make();

addr=Q_make_add(addr,count); // ���� x*Y��ŭ�� ���� ���� ����Ʈ�� �����.

map_out(miro_map); // �̷��� ���� ����Ѵ�.

find_state(miro_map,addr);// ���� ��ǥ�� ã�´�.

printf("\n�����: x = %d  y = %d  Enter�� ������ ��ã�⸦ �����մϴ�...\n",addr->prev->miro_x,addr->prev->miro_y);

getchar();  //-test

miro_way_find(addr,move,addr->prev->miro_x,addr->prev->miro_y);//���� ���� ����� ��ũ����Ʈ�� ���� ������ �ش�.

addr=Q_make_short(addr); //  �ִ� �Ÿ��� ���Ѵ�.


//--------------------------------------------------ù��° ��ã���� �� --------------------------------//



//-----------------------------------------------������ ��ã�� ����-------------------------------------//
getchar();

system("cls");

miro_map_cpy(miro_map2,miro_map);//���� �ʱ�ȭ

map_out(miro_map); // �̷��� ���� ����Ѵ�.(���� �ʱ���·� �����Ѱ��� Ȯ��);

miro_way_completionQ(addr,move);//�ϼ���Ų �̷��� ���� ����Ȱ���, ������ ���� �Ѱ��ָ� ���� ª���� ���� ����ش�.

map_out(miro_map); // �̷��� ���� ����Ѵ�.

getchar();

addr=map_re_find(addr);// ã�� ���� ���� �ٿ��ش�.  ù��°--

miro_map_cpy(miro_map2,miro_map);//�̷��� ���� �ʱ�ȭ

map_out(miro_map); //(���� �ʱ���·� �����Ѱ��� Ȯ��);

getchar(); // ù��°�� ��

addr=map_re_find(addr);// ã�� ���� ���� �ٿ��ش�.  �ι���--

//--------------------------------------------------------�ι�° ��ã���� �� --------------------------//



//----------------------------------------������ ã������ ����..--------------------------------------//

miro_map_cpy(miro_map2,miro_map);// 2���� �迭�� �������ش�.

map_out(miro_map); // �̷��� ���� ����Ѵ�.

miro_way_completionQ(addr,move);//���� �ϼ��� ���� ����ش�.

map_out(miro_map); //���� ���� �����ش�

printf("---------------��ã�⸦ �Ϸ��Ͽ����ϴ�------------------\n");

getchar();
return 0;

}

//---------------------------------------------------------------
































/*  ��������� ���� ..// ���̺귯�� ������ ���ؼ� �����غ���.
{

//-------------------------------------------------------------------------------------
	link *addr;
	link *addr1;
	int number =10;
	int i;

	addr=Q_make(); // tail�� ������ �ּҸ� �Ҵ�



	addr=Q_make_add(addr,number); //tail�� �ּҸ� �Ѱ��ָ� �� ����ŭ �����ȴ�.

//-----------------------------------------------------------------------------------

	for(i=1; i<=number; i++)	// ��ũ�� �������� 1���� 10 ���� �־��.
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

	for(i=1; i<=number; i++)	// ��ũ�� ť��  1���� 10 ���� ����Ѵ�.
	{
	
		
		addr1=Q_make_findQ(addr,i);

		printf("x ���: %d \n",addr1->miro_x);
			
	}

	getchar();
//------------------------------------------------------------------------------------



	addr=Q_make_short(addr); //  �ִ� �Ÿ��� ���Ѵ�.


//------------------------------------------------------------------------------------



	for(i=1; i<=number; i++)	// ��ũ����Ʈ�� �������� ����Ѵ�.
	{
		addr1=Q_make_findS(addr,i);
		
		printf("��ȯ�� �� = %d    ",addr1->miro_x);
		printf("��ȯ�� �� = %d\n",addr1->miro_y);
	}

//---------------------------------------------------------------------------------------------------
*/