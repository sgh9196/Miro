#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define mx 16  // �̷��� ���� ũ�⸦ ���� 
#define my 16  // �̷��� ���� ũ�⸦ ����
#define wall '@'//�̷��� �� 
#define way ' '	// �̷��� �� 
#define find '.'


typedef struct link{
 
struct link *next;
struct link *prev;

char check;
int miro_x;
int miro_y;

}link;
//-----------------------------------------------------------------//-----------------------------------








//-----------------------------------------------------------------//-------------------------------------


link* Q_make();							// ���� ���� ��ũ�� ����Ʈ�� �����.

link* Q_make_add(link *tail,int num);	// tail�� �ּҰ��� �Ѱܹ޾Ƽ� num�� ����ŭ ��ũ�� �����Ѵ�.

link* Q_make_findQ(link *tail,int num);	// num �� ����ŭ�� �ּҸ� ��ȯ�Ѵ�.Q

link* Q_make_findS(link *head,int num); // num �� ����ŭ�� �ּҸ� ��ȯ�Ѵ�.����.

link* Q_make_short(link* head);         // ���� �ܰŸ��� ã�´�.

void Q_remove(link *head); // head�� tail�� ������ ����Ʈ�� ��� �����.



//----------------------------------------------------------------// �ȱ��.


void map_out(char (*map)[mx]); // ���� ����Ѵ�.

void find_state(char (*map)[mx],link *tail);// ���� ������ ã�´�.

void miro_way_find(link *tail, char (*move)[mx],int x, int y);// ������ ���ϴ� ��ġ���� ���� ã���� �ֵ��� 4���� �μ��� �Է¹���

int miro_check(char (*check)[mx],link *addr_check,int cx,int cy); //�Լ����� �Լ��� ���δ�.

void miro_map_cpy(char (*a)[mx],char (*b)[mx]);// 2���� �迭�� �������ش�.

void miro_way_completionQ(link *tail,char (*moving)[mx]);//�ϼ��� �� (�ִܰŸ��� ã�Ƽ� �ٽ� �ʿ� �ѷ��ش�.)

link* map_re_find(link *tail);// ���� ������ �ٽ� ã�� ���� ª������ ã�´�.
