// Структура данных и вывод игрового поля
// - структуры  player and field 
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct player
{
    int gamers; // кол-во игроков 
    int movepl; // кол-во ходов всего
}pl;
struct Field
{
    int kuci[3]; // кол-во куч
}fi;

void print_info()
{
    printf("Кол-во игроков %i\n", pl.gamers);
    //printf("Ход игрока %i\n",pl.motion);
}

void print_field()
{
    printf("Первая %i\n", fi.kuci[0]);
    printf("Вторая  %i\n", fi.kuci[1]);
    printf("Третья %i\n", fi.kuci[2]);
}
void gamelogic()
{
    int number;
    int count;
    pl.movepl = 1;
    printf("Игра началась!\n");
    print_field();
    for (; (fi.kuci[0] || fi.kuci[1] || fi.kuci[2]) > 0; pl.movepl++)
    {
        if (pl.movepl % 2 != 0)
            printf("Ход первого игрока\n");
        else
            printf("Ход второго игрока\n");
        printf("Введите номер кучи\n");
        scanf_s("%i", &number);
        printf("Сколько отнять?\n");
        scanf_s("%i", &count);
        fi.kuci[number - 1] -= count;
        printf("Ходов совершено %i \n", pl.movepl);
        print_field();
    }
    if (pl.movepl % 2 == 0)
        printf("Выиграл второй игрок\n");
    else
        printf("Выиграл первый игрок\n");
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