#include "Q_S.h"

link* Q_make()// 새로운 Q를 생성한다. 원형큐로 만들어서 <-tail(큐)  ->head(head)
{
	link *head,*tail;

	head=(link*)malloc(sizeof(link));
	tail=(link*)malloc(sizeof(link));

	head->next=tail;
	head->prev=NULL;
	tail->next=head;
	tail->prev=head;
	head->check=0;
	tail->check=0;

	
	return tail;

}

//----------------------------------------------------------------------------------------------------------------//

link* Q_make_add(link*tail,int num)//링크 리스트를 생성한다 원하는 만큼;
{
	link *node;
	
	while(num>0)
	{
		node=(link*)malloc(sizeof(link));
		node->check='n';
		node->next=tail;
		tail->prev->next=node;
		node->prev=tail->prev;	
		tail->prev=node;
		num--;
	}
	tail=node->next;
	return tail;

}

//----------------------------------------------------------------------------------------------------------------//

link* Q_make_findQ(link *tail,int num)// 큐으로 번지를 찾는다. 진행 방향 <-
{
	link *node;		
	for(node=tail;num>0;num--)
	{	
		if(node->prev->check==0)
		{
			fputs("링크 리스트의 범위를 벗어났습니다.",stdout);
			break;
			
		}
		else
		node=node->prev;
	}
	return node;
}

//--------------------------------------------------------------------------------------------------------------//


link* Q_make_findS(link *head,int num)// 스텍으로 번지를 찾는다. ->
{
	link *node;

	for(node=head->next;num>0;num--)
	{	
		
		if(node->next->check==0)
		{
			fputs("링크 리스트의 범위를 벗어났습니다.",stdout);
			break;
		}
		else
		node=node->next;
		
	}
	return node;
}

//--------------------------------------------------------------------------------------------------------------//

link* Q_make_short(link* head) // tail 의 주소만 넣어주면 head의 주소로 찾아가서 가장 단거리를 출력한다.
{
	link *node,*remove;
	link *save;
	if(head->check!=0)
		printf("--------주소의 tail 부분이 아닙니다.--------");
	
	for(save=head->prev;save->prev!=0; save=save->prev)
	{
		
		for(node=save->prev; node->prev!=0; node=node->prev)
		{
			if((save->miro_x==node->miro_x)&&(save->miro_y==node->miro_y))
				for(remove=node->prev; remove->next!=save; node=remove->next)
				{
					node->next->prev=node->prev;
					node->prev->next=node->next;
					free(node);
				}		
		}
		if(save->check==0)
		{	
			node=save;
			remove=node;
			for(node=node->prev; remove->prev->check!=0; node=remove->prev)
			{
				node->next->prev=node->prev;
				node->prev->next=node->next;
				free(node);
				
			}
			save=remove;
		}
	}
	
	
	return head;
}

//---------------------------------------------------------------------------------------------------------------//

void Q_remove(link *head) //  head와tail을 남겨둔채 구성된 링크 리스트를 모두 지운다.
{
	link *node =head;
	
	for(node=node->prev;node->prev!=0;node=node->prev)
	{	
		head=node->next;
		free(head); 
	}
	free(node);

}

//--------------------------------------------------------------------------------------------------------------//