#include "../include/task.h"

void printList(const List *list); 
void addTask (List *list);

int main() {
  List my_list = {
      .all_elements = 4,
      .tasks = {
        {
          .ID = 100,
          .TaskName = "Выучить основы структур в Си",
          .Time = 119,
          .isComplete = true
        },
        {
          .ID = 101,
          .TaskName = "Настроить Makefile и .gitignore",
          .Time = 44,
          .isComplete = true
        },
        {
          .ID = 102,
          .TaskName = "Написать функцию вывода списка на экран",
          .Time = 29,
          .isComplete = false
        },
        {
          .ID = 103,
          .TaskName = "Помыть посуду",
          .Time = 15,
          .isComplete = false
        }
      }
  };

  int variant;

  do {
    printf("\tВЕДИТЕ\n 1 - получить список задач\n 2 - добавить задачу\n 0 - выйти\n--> ");
    scanf("%d", &variant); 
  
    switch (variant) {
      case 1:
        printList(&my_list);
        break;  
      case 2:
        addTask(&my_list);
        break;
      case 0: 
        break; 
    }

  } while (variant != 0);

  return 0;
}

void printList(const List *list){
  printf("=== СПИСОК ЗАДАЧ ===\n");
  printf("Всего задач созданно: %d\n", list->all_elements);
  for(int i = 0; i < list->all_elements; i++){
    printf("[%-5s] ID: %-10d\t | %-10s \t | Время: %-10d \n", 
           list->tasks[i].isComplete ? "X" : " ",
           list->tasks[i].ID,
           list->tasks[i].TaskName,
           list->tasks[i].Time);
  }
}

void addTask (List *list){
  
  // создаем указатель на новую таску
  Task_S *new_task = &list->tasks[list->all_elements];  

  // Проверка на максимальное количество тасок 
  if (list->all_elements > MAX_ELEMENTS) {
    printf("Создано максиальное количество задач !");
    return; 
  }

  // получаем динамически id: берем id последней таски и доавляем к нему 1
  // если это первый элемент, то ему автоматически ставться id 100
  if (list->all_elements == 0) {
    new_task->ID = 100; 
  }
  else {
  new_task->ID = list->tasks[list->all_elements - 1].ID + 1;
  }

  //  Добавляем то что задача не выполнена
  new_task->isComplete = false; 

  // Пользователь вводит имя задачи и мы добавляем его в новую таску 
  printf("Название задачи: ");
  scanf(" %[^\n]", &new_task->TaskName);
  
  // Пользователь вводит крайний срок задачи и мы добавляем его в новую таску 
  printf("Время задачи: ");
  scanf("%d", &new_task->Time);
  
  // Увеличиваем счетчик элементов 
  list->all_elements++; 
}

