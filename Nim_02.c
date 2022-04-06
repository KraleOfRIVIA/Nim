// Структура данных и вывод игрового поля
// - структуры  player and field 
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <locale.h>
int gameover=0; // Условие начала и конца игры 
int kol_kuci; // Кол-во куч спичек 
struct player
{
    int gamers; // кол-во игроков 
    int movepl; // кол-во ходов всего
}pl;
struct Field
{
    int kuci[]; // кол-во куч
}fi;

void setup() // Настройки игры 
{
    pl.movepl = 1; 
    pl.gamers;
    printf("Игра началась!\n");
    printf("Задайте параметры\n");
    printf("Сколько куч?: \n");
    scanf_s("%i", &kol_kuci);

    for (int i = 0; i < kol_kuci; i++)
    {
        printf("Сколько спичек в куче № %i :", i+1);
        scanf_s("%i", &fi.kuci[i]);
    }
    printf("Сколько игроков?: ");
    scanf_s("%i",& pl.gamers);
}

void print_field() // Вывод информации 
{
    system("cls"); // Очистка поля 
    for (int i=0; i < kol_kuci; i++) 
    {
        printf("\nКуча № %i  : %i\n", i+1, fi.kuci[i]);
    }
}
void gamelogic() // Игровая логика при игре с игроками 
{
    int cor = 0; // Переменная для подсчета пустых куч 
    int number; // Номер кучи 
    int count; // Кол-во отнимаемых спичек 
    int i;
    for (i = 1;gameover==0; pl.movepl++ && i++)
    {
        if (i > pl.gamers)
        {
            i = 1; 
        }
        
        print_field();
        printf("\nХод игрока №%i\n",i);
        printf("Введите номер кучи\n");
        scanf_s("%i", &number);
        if (fi.kuci[number - 1] == 0)
        {
            while (fi.kuci[number - 1] == 0)
            {
                printf("Эту кучу нельзя выбрать, выберите другую: ");
                scanf_s("%i", &number);
            }
        }
        printf("Сколько отнять?\n");
        scanf_s("%i", &count);
        if (count > fi.kuci[number - 1])
        {
            while (count > fi.kuci[number - 1])
            {
                printf("Слишком много!\n Введите заново");
                scanf_s("%i", &count);
            }
        }
        fi.kuci[number - 1] -= count;
        if (fi.kuci[number - 1] == 0)
            cor += 1;
        if (cor == kol_kuci)
            gameover = 1;
        printf("Ходов совершено %i \n", pl.movepl);
        print_field();
    }
    printf("\nПроиграл игрок №%i\n", i-1);
}
void game_s_pc() // Игровая логика при игре с компьютером 
{
    pl.movepl = 1;
    int cor = 0;
    int number=0;
    int count=0;
    int i;
    int number_pc=0; // Отдельные переменные для компьютера 
    int count_pc;
    for (i = 1; gameover == 0; pl.movepl++ && i++)
    {
        if (pl.movepl % 2 != 0)
        {
            print_field();
            printf("\nХод игрока \n");
            printf("Введите номер кучи\n");
            scanf_s("%i", &number);
            if (fi.kuci[number - 1] == 0)
            {
                while (fi.kuci[number - 1] == 0)
                {
                    printf("Эту кучу нельзя выбрать, выберите другую: ");
                    scanf_s("%i", &number);
                }
            }
            printf("Сколько отнять?\n");
            scanf_s("%i", &count);
            if (count > fi.kuci[number - 1])
            {
                while (count > fi.kuci[number - 1])
                {
                    printf("Слишком много!\n Введите заново");
                    scanf_s("%i", &count);
                }
            }
        }
        if (pl.movepl % 2 == 0) 
        {
            printf("Ход компьютера\n");
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
        printf("Ходов совершено %i \n", pl.movepl);
        print_field();
    }
    printf("\nПроиграл игрок №%i\n", i - 1);

}
int main()
{
    setlocale(LC_ALL, "Russian");
    setup();
    //gamelogic();

    game_s_pc();
    return 1;
}
