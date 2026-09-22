#include "../include/task.h"


int main() {
  List my_list = {
      .all_elements = 4,
      .tasks = {
        {
          .ID = 101,
          .TaskName = "Выучить основы структур в Си",
          .Time = 120,
          .isComplete = true
        },
        {
          .ID = 102,
          .TaskName = "Настроить Makefile и .gitignore",
          .Time = 45,
          .isComplete = true
        },
        {
          .ID = 103,
          .TaskName = "Написать функцию вывода списка на экран",
          .Time = 30,
          .isComplete = false
        },
        {
          .ID = 104,
          .TaskName = "Помыть посуду",
          .Time = 15,
          .isComplete = false
        }
      }
  };

  printf("=== СПИСОК ЗАДАЧ ===\n");
  printf("Всего задач созданно: %d\n", my_list.all_elements);
  for(int i = 0; i < my_list.all_elements; i++){
    printf("[%s] ID: %d\t | %s \t\t | Время: %d \n", 
           my_list.tasks[i].isComplete ? "X" : " ",
           my_list.tasks[i].ID,
           my_list.tasks[i].TaskName,
           my_list.tasks[i].Time);
  }
    return 0;
}
