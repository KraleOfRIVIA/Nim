// ��������� ������ � ����� �������� ����
// - ���������  player and field 
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct player
{
    int gamers; // ���-�� ������� 
    int movepl; // ���-�� ����� �����
}pl;
struct Field
{
    int kuci[3]; // ���-�� ���
}fi;

void print_info()
{
    printf("���-�� ������� %i\n", pl.gamers);
    //printf("��� ������ %i\n",pl.motion);
}

void print_field()
{
    printf("������ %i\n", fi.kuci[0]);
    printf("������  %i\n", fi.kuci[1]);
    printf("������ %i\n", fi.kuci[2]);
}
void gamelogic()
{
    int number;
    int count;
    pl.movepl = 1;
    printf("���� ��������!\n");
    print_field();
    for (; (fi.kuci[0] || fi.kuci[1] || fi.kuci[2]) > 0; pl.movepl++)
    {
        if (pl.movepl % 2 != 0)
            printf("��� ������� ������\n");
        else
            printf("��� ������� ������\n");
        printf("������� ����� ����\n");
        scanf_s("%i", &number);
        printf("������� ������?\n");
        scanf_s("%i", &count);
        fi.kuci[number - 1] -= count;
        printf("����� ��������� %i \n", pl.movepl);
        print_field();
    }
    if (pl.movepl % 2 == 0)
        printf("������� ������ �����\n");
    else
        printf("������� ������ �����\n");
}
int main()
{
    setlocale(LC_ALL, "Russian");
    fi.kuci[0] = 2;
    fi.kuci[1] = 3;
    fi.kuci[2] = 4;
    pl.gamers = 2;
    print_info();
    gamelogic();
    return 1;
}