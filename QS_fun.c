#include "Q_S.h"

link* Q_make()// ���ο� Q�� �����Ѵ�. ����ť�� ���� <-tail(ť)  ->head(head)
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

link* Q_make_add(link*tail,int num)//��ũ ����Ʈ�� �����Ѵ� ���ϴ� ��ŭ;
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

link* Q_make_findQ(link *tail,int num)// ť���� ������ ã�´�. ���� ���� <-
{
	link *node;		
	for(node=tail;num>0;num--)
	{	
		if(node->prev->check==0)
		{
			fputs("��ũ ����Ʈ�� ������ ������ϴ�.",stdout);
			break;
			
		}
		else
		node=node->prev;
	}
	return node;
}

//--------------------------------------------------------------------------------------------------------------//


link* Q_make_findS(link *head,int num)// �������� ������ ã�´�. ->
{
	link *node;

	for(node=head->next;num>0;num--)
	{	
		
		if(node->next->check==0)
		{
			fputs("��ũ ����Ʈ�� ������ ������ϴ�.",stdout);
			break;
		}
		else
		node=node->next;
		
	}
	return node;
}

//--------------------------------------------------------------------------------------------------------------//

link* Q_make_short(link* head) // tail �� �ּҸ� �־��ָ� head�� �ּҷ� ã�ư��� ���� �ܰŸ��� ����Ѵ�.
{
	link *node,*remove;
	link *save;
	if(head->check!=0)
		printf("--------�ּ��� tail �κ��� �ƴմϴ�.--------");
	
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

void Q_remove(link *head) //  head��tail�� ���ܵ�ä ������ ��ũ ����Ʈ�� ��� �����.
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