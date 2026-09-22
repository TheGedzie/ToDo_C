#pragma once // Защита от повторного импорта
#include <stdbool.h>
#include <stdio.h>

//Пока что максимально количество элементов - 100
#define MAX_ELEMENTS 100

typedef struct {
  int ID; 
  char TaskName[255];
  int Time; 
  bool isComplete;
} Task_S;

typedef struct {
  Task_S tasks[MAX_ELEMENTS]; // Потом нужно будет сделать массив динамическим (см. темы malloc free sizeof)
  int all_elements;
} List;


