#include "Q_S.h"

//----------------------------------------------------------------------------
void map_out(char (*map)[mx])
{	
	int numx,numy;
	system("cls");
	fputs("\n\t <<------------------�̷� ã�� ��---------------->>\n\n",stdout);
	
	for(numy=0; numy<my; numy++)
	{	
		fputs("\t",stdout);
		for(numx=0; numx<mx; numx++)
		{
			printf("  %c",*(*(map+numy)+numx));
		}
		fputs("\n",stdout);
	}	


}


//----------------------------------------------------------------------------------------
void find_state(char (*map)[mx],link *tail) //������ ��ũ ����Ʈ�� ���� ������ ã�Ƽ� �ִ´�.
{
	link *node; 
	int count1,count2;
	node=Q_make_findQ(tail,1);
	
	for(count1=0;count1<my;count1++)
	{
		for(count2=0;count2<mx;count2++)
		{
			if(*(*(map+count1)+count2)=='s')
			{
				node->miro_x=count2;
				node->miro_y=count1;
				node->check='s';
				break;
			}
		}
		if(*(*(map+count1)+count2)=='s')
			break;
	}
}

//--------------------------------------------------------------------------------------------------------------------------

int miro_check(char (*check)[mx],link *addr_check,int cx,int cy)//check�� �غ��� ���̸� find ���� �ְ� ����ǥ�� �������� ��ȯ
{
	if(*(*(check+cy)+cx)==way||*(*(check+cy)+cx)=='e')
	{	
		if(*(*(check+cy)+cx)=='e')
		{	

			addr_check->miro_x=cx;
			addr_check->miro_y=cy;
			addr_check->check=0;
			return 2;
			
		}
		else if(cx>=0&&cy>=0&&cx<=mx&&cy<=my)	
		{
			*(*(check+cy)+cx)=find;	
			addr_check->miro_x=cx;
			addr_check->miro_y=cy;
			
			addr_check=addr_check->prev;
			
			return 1; // ���������� 1�� ��ȯ 
		}
		else
			addr_check=addr_check->prev;
	}
	
		return 0;	// �ƴϸ� 0�� ��ȯ
	
}

//----------------------------------------------------------------------------------------------------------//

link* miro_return(link *after,link *now, char (*going)[mx])       //(���ư���,���簪,�̵���������)
{
	link *re_node=now;
	after = after->next;
	now = now->next;
	
	
	while(1)		
	{	
		if((after->miro_x==now->miro_x)&&(after->miro_y==now->miro_y))
			break;
		*(*(going+now->miro_y)+now->miro_x)='^';
		now=now->next;
	}
	re_node->miro_x=now->miro_x;
	re_node->miro_y=now->miro_y;

	return re_node;
}

//--------------------------------------------------------------------------------------------------------//

void miro_way_find(link *tail ,char (*moving)[mx],int x,int y)
{
	link *node= tail->prev->prev; // ���� �Է� ���� ���������� ��ġ��  �̵� ��Ų��.
	
	link *cross; // �������� �����ϱ� ���� ��ũ ������
	
	int num=0;
	
	int end=0;
	
	cross=Q_make();// cross�� head�� tail�� �����.
	
	cross=Q_make_add(cross,(mx*my)/2); // ���� x*Y��ŭ�� ���� ���� ����Ʈ�� �����.
	
	cross= cross->prev;
	
	*(*(moving+y)+x)=find; //�������� ���� ã�Ҵٰ� ǥ�����ش�.
	
	while(*(*(moving+y)+x) != 'e')
	{
		
		if(*(*(moving+(y-1))+(x-1))==way || *(*(moving+(y-1))+(x-1))=='e')
			num++;
		if(*(*(moving+(y-1))+x)==way || *(*(moving+(y-1))+x)=='e') 
			num++;
		if(*(*(moving+(y-1))+(x+1))==way || *(*(moving+(y-1))+(x+1))=='e')
			num++;
		if(*(*(moving+y)+(x-1))==way || *(*(moving+y)+(x-1))=='e') 
			num++;
		if(*(*(moving+y)+(x+1))==way || *(*(moving+y)+(x+1))=='e')
			num++;
		if(*(*(moving+(y+1))+(x-1))==way || *(*(moving+y+1)+(x-1))=='e')
			num++;
		if(*(*(moving+(y+1))+x)==way || *(*(moving+y+1)+x)=='e')
			num++;
		if(*(*(moving+(y+1))+(x+1))==way || *(*(moving+y+1)+(x+1))=='e')
			num++;	
		if((num >=2&&x>=0&&y>=0&&y<=my&&x<=mx)&&((x-1>0)&&(y-1>0)&&(x+1<mx)&&(y+1<my)))
		{
			cross->miro_x=x;		//�������� �����ϰ� ��������� �̵��Ѵ�.
			cross->miro_y=y;
			cross= cross->prev;
		}
		num=0;		// num �� ���� �ʱ�ȭ;
		
		//-------------------------------------------------------------------�������� �ƴ��� �����Ͽ���.-----------		
		
		if(end==2||1==(end=miro_check(moving,node,x-1,y-1))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x-1;
			y = y-1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end==2||(1==(end=miro_check(moving,node,x-1,y)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x-1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		else if(end==2||(1==(end=miro_check(moving,node,x-1,y+1)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x-1;
			y = y+1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end==2||(1==(end=miro_check(moving,node,x,y-1)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			y = y-1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end==2||(1==(end=miro_check(moving,node,x,y+1)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			y = y+1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end==2||(1==(end=miro_check(moving,node,x+1,y-1)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x+1;
			y = y-1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end==2||(1==(end=miro_check(moving,node,x+1,y)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x+1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else if(end == 2||(1==(end=miro_check(moving,node,x+1,y+1)))&&x>=0&&y>=0&&y<=my&&x<=mx)
		{	
			node= node->prev;
			x = x+1;
			y = y+1;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		else if(end==2)
		{
			node=node->prev;
			if(end == 2){printf("----------------���� ã�⿡ �����Ͽ����ϴ�.----------------\n");break;}
		}
		
		else// ���� �ڸ��� �ǵ��ư���.
		{	
			*(*(moving+y)+x)='^';
			node=miro_return(cross,node,moving);
			cross=cross->next;
			x = node->miro_x;
			y = node->miro_y;
			node = node->prev;
			
			
		}

	
		
		
		map_out(moving);
		
	}
	getchar();
}

//-----------------------------------------------------------------------------------------------------------
// testetst






























