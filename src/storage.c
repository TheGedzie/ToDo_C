#include "storage.h"
#include <stdio.h>

//Сохранение чек-листа в файл
void storage_save(List *list, const char *filename) {
  FILE *f = fopen(filename, "w");
    if (f == NULL) { // Обязательная проверка, если вдруг fopen вернет NULL. Иначе программа крашнется
      printf("Что-то пошло не так. Мы не можем открыть файл\n");
      return;
    }
  for (int i = 0; i < list->all_elements; i++) {
    fprintf(f, "%d\t%s\t%d\t%d\n", list->tasks[i].ID, list->tasks[i].TaskName, list->tasks[i].Time, list->tasks[i].isComplete);
  }
  fclose(f);
}
