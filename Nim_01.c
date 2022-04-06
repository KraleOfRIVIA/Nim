// Структура данных и вывод игрового поля
// - структуры  player and field 
#include <stdio.h>
#include <string.h>

struct player
  {   int gamers; // кол-во игроков 
      int motion; // кол-во ходов всего
  }pl;
struct Field
  {  
     int kuci[2]; // кол-во куч
  }fi;

void print_info()
{ 
  printf("Кол-во игроков %i\n",pl.gamers);
  //printf("Ход игрока %i\n",pl.motion);
}

void print_field()
{
  printf("%i\n",fi.kuci[0]);
  printf("%i\n",fi.kuci[1]);
  printf("%i",fi.kuci[2]);
}
void gamelogic()
{ 
  int number;
  int count;
  int movepl=1;
  printf("Игра началась!\n");
  for(;(fi.kuci[0] && fi.kuci[1] && fi.kuci[2])>0;movepl++ )
  {
    if (movepl % 2 !=0)
      printf("Ход первого игрока\n");
    else 
      printf("Ход второго игрока\n");
    printf("Введите номер кучи\n");
    scanf("%i",&number);
    printf("Сколько отнять?\n");
    scanf("%i",&count);
    fi.kuci[number]-=count;
    pl.motion++;
    printf("Ходов совершено %i",pl.motion);
    print_field();
  }
  if (movepl % 2 !=0)
    printf("Выиграл второй игрок\n");
  else
    printf("Выиграл первый игрок\n");
}
int main()
{
  fi.kuci[0]=2;
  fi.kuci[1]=3;
  fi.kuci[2]=4;
  pl.gamers=2;
  pl.motion=0;
print_info();
gamelogic();
return 1;
}
