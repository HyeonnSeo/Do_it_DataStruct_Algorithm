// gcc -o test9-2 test9-2.c LinkedList.c Member.c

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

typedef enum{
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT, RMV_CRNT,
    SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
        "��忡 ����",
        "������ ����",
        "�Ӹ���� ����",
        "������� ����",
        "������ ��� ���",
        "������ ��� ����",
        "��ȣ�� �˻�",
        "�̸����� �˻�",
        "��� ��� ���",
        "��� ��� ����",
    };
    do
    {
        for (i = TERMINATE; i < CLEAR; i++)
        {
            printf("(%2d) %-18.18s ", i + 1, mstring[i]);
            if ((i % 3) == 2)
                putchar('\n');
        }

        printf("(0) ����: ");
        scanf("%d", &ch);
    }while((ch < TERMINATE || ch > CLEAR));
    return (Menu)ch;
}


int main(void)
{
    Menu menu;
    List list;
    Initialize(&list);

    do{
        Member x;
        switch(menu=SelectMenu()){
            case INS_FRONT:
                x=ScanMember("�Ӹ��� ����", MEMBER_NO|MEMBER_NAME);
                InsertFront(&list, &x);
                break;

            case INS_REAR:
                x = ScanMember("������ ����", MEMBER_NO | MEMBER_NAME);
                InserRear(&list, &x);
                break;

            case RMV_FRONT:
                RemoveFront(&list);
                break;

            case RMV_REAR:
                RemoveRear(&list);
                break;

            case PRINT_CRNT:
                PrintLnCurrent(&list);
                break;
            case RMV_CRNT:
                RemoveCurrent(&list);
                break;
            
            case SRCH_NO:
                x=ScanMember("�˻�",MEMBER_NO);
                if(search(&list, &x, MemberNoCmp) != NULL){
                    PrintLnCurrent(&list);
                }
                else
                    puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
                break;

            case SRCH_NAME:
                x=ScanMember("�˻�",MEMBER_NAME);
                if(search(&list, &x, MemberNameCmp) != NULL){
                    PrintLnCurrent(&list);
                }
                else
                    puts("�� �̸��� �����Ͱ� �����ϴ�.");
                break;
            
            case PRINT_ALL:
                Print(&list);
                break;
            
            case CLEAR:
                Clear(&list);
                break;
            }
    }while(menu != TERMINATE);
    Terminate(&list);

    return 0;
}   