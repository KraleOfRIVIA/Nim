// ��������� ������ � ����� �������� ����
// - ���������  player and field 
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <locale.h>
int gameover=0;
int kol_kuci;
struct player
{
    int gamers; // ���-�� ������� 
    int movepl; // ���-�� ����� �����
}pl;
struct Field
{
    int kuci[]; // ���-�� ���
}fi;

void setup()
{
    pl.movepl = 1;
    pl.gamers;
    printf("���� ��������!\n");
    printf("������� ���������\n");
    printf("������� ���?: \n");
    scanf_s("%i", &kol_kuci);

    for (int i = 0; i < kol_kuci; i++)
    {
        printf("������� ������ � ���� � %i :", i+1);
        scanf_s("%i", &fi.kuci[i]);
    }
    printf("������� �������?: ");
    scanf_s("%i",& pl.gamers);
}

void print_field()
{
    system("cls");
    for (int i=0; i < kol_kuci; i++) 
    {
        printf("\n���� � %i  : %i\n", i+1, fi.kuci[i]);
    }
}
void gamelogic()
{
    int cor = 0;
    int number;
    int count;
    int i;
    for (i = 1;gameover==0; pl.movepl++ && i++)
    {
        if (i > pl.gamers)
        {
            i = 1; 
        }
        
        print_field();
        printf("\n��� ������ �%i\n",i);
        printf("������� ����� ����\n");
        scanf_s("%i", &number);
        if (fi.kuci[number - 1] == 0)
        {
            while (fi.kuci[number - 1] == 0)
            {
                printf("��� ���� ������ �������, �������� ������: ");
                scanf_s("%i", &number);
            }
        }
        printf("������� ������?\n");
        scanf_s("%i", &count);
        if (count > fi.kuci[number - 1])
        {
            while (count > fi.kuci[number - 1])
            {
                printf("������� �����!\n ������� ������");
                scanf_s("%i", &count);
            }
        }
        fi.kuci[number - 1] -= count;
        if (fi.kuci[number - 1] == 0)
            cor += 1;
        if (cor == kol_kuci)
            gameover = 1;
        printf("����� ��������� %i \n", pl.movepl);
        print_field();
    }
    printf("\n�������� ����� �%i\n", i-1);
}
void game_s_pc()
{
    pl.movepl = 1;
    int cor = 0;
    int number=0;
    int count=0;
    int i;
    int number_pc=0;
    int count_pc;
    for (i = 1; gameover == 0; pl.movepl++ && i++)
    {
        if (pl.movepl % 2 != 0)
        {
            print_field();
            printf("\n��� ������ \n");
            printf("������� ����� ����\n");
            scanf_s("%i", &number);
            if (fi.kuci[number - 1] == 0)
            {
                while (fi.kuci[number - 1] == 0)
                {
                    printf("��� ���� ������ �������, �������� ������: ");
                    scanf_s("%i", &number);
                }
            }
            printf("������� ������?\n");
            scanf_s("%i", &count);
            if (count > fi.kuci[number - 1])
            {
                while (count > fi.kuci[number - 1])
                {
                    printf("������� �����!\n ������� ������");
                    scanf_s("%i", &count);
                }
            }
        }
        if (pl.movepl % 2 == 0) 
        {
            printf("��� ����������\n");
            while (number_pc != kol_kuci) 
            {
                if (fi.kuci[number_pc] > 1)
                {
                    count_pc = fi.kuci[number_pc] - 1;
                    fi.kuci[number_pc] -= count_pc;
                }
                else if (fi.kuci[number_pc] == 1)
                {
                    fi.kuci[number_pc] -= 1;
                }
            }
        }
        fi.kuci[number - 1] -= count;
        if (fi.kuci[number - 1] == 0)
            cor += 1;
        if (cor == kol_kuci)
            gameover = 1;
        printf("����� ��������� %i \n", pl.movepl);
        print_field();
    }
    printf("\n�������� ����� �%i\n", i - 1);

}
int main()
{
    setlocale(LC_ALL, "Russian");
    setup();
    //gamelogic();

    game_s_pc();
    return 1;
}