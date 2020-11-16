#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void stat();
void stack();
void ehd();

const int arraySize = 100000;


int main(void) {
  int i = 0;

  long start = clock();
  for (i = 0; i < arraySize; i++){
    stat();
  }
  long stop = clock();
  long ellapsed = stop - start;
  double statT = (double)ellapsed/(CLOCKS_PER_SEC * 1e9);

  printf("The static function took %ld nanoseconds\n", ellapsed);

/*--------------------------------------------------------*/

  long start2 = clock();
  for (i = 0; i < arraySize; i++){
    stack();
  }
  long stop2 = clock();
  long ellapsed2 = stop2 - start2;
  double stackT = (double)ellapsed2/(CLOCKS_PER_SEC * 1e9);

  printf("The stack dynamic function took %ld nanoseconds\n", ellapsed2);

/*--------------------------------------------------------*/

  long start3 = clock();
  for (i = 0; i < arraySize; i++){
    ehd();
  }
  long stop3 = clock();
  long ellapsed3 = stop3 - start3;
  double ehdT = (double)ellapsed3/(CLOCKS_PER_SEC * 1e9);

  printf("The explicit heap-dynamic function took %ld nanoseconds\n", ellapsed3);
  return 0;
}

void stat(){
  static int arrStatic[arraySize];
}

void stack(){
  int arrStack[arraySize];
}

void ehd(){
  int *arrEHD = (int *) malloc(arraySize * sizeof(int));
}






















