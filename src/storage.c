#include "storage.h"
#include <stdio.h>


//Сохранение чек-листа в файл
void storage_save(List *list, const char *filename) {
  FILE *f = fopen(filename, "w");

    if (f == NULL) { // Обязательная проверка, если вдруг fopen вернет NULL. Иначе программа крашнется
      printf("Что-то пошло не так. Мы не можем открыть файл\n");
      return;
    }
  
  //Закидываем чек-лист в файл
  for (int i = 0; i < list->all_elements; i++) {
    fprintf(f, "%d\t%s\t%d\t%d\n", list->tasks[i].ID, list->tasks[i].TaskName, list->tasks[i].Time, list->tasks[i].isComplete);
  }

  fclose(f);
}


//Загрузка чек-листа в файл
void storage_load(List *list, const char *filename) {
  FILE *f = fopen(filename, "r");
  
  if (f == NULL) { //Проверка на наличие файл
    list->all_elements = 0; //Если файла нет, то присваиваем 0 и скипаем
    return;
  }
  
  //Закидываем файл в чек-лист
  int tempComplete;
  int i = 0;
  while (fscanf(f, "%d\t%s\t%d\t%d\n", &list->tasks[i].ID, list->tasks[i].TaskName, &list->tasks[i].Time, &tempComplete) == 4) {
    list->tasks[i].isComplete = tempComplete; //Компилятор жалуется, что берем %d для типа Bool(isComplete), т.к. bool - 1байт, а int(%d) - 4 байта это может привезти к траблам. Поэтому вводим temp переменную
    i++;
  }
  list->all_elements = i;

  fclose(f);
}

