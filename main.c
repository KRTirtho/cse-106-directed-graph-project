#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void directed(int n) {
  int **matrix = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % 2;
    }
  }

  clock_t start_t = clock();

  int id = 0;
  int od = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 1) {
        od++;
      }
      if (matrix[j][i] == 1) {
        id++;
      }
    }
  }

  printf("In degrees: %d\n", id);
  printf("Out degrees: %d\n", od);

  clock_t end_t = clock();

  double elapsed_ms = (double)(end_t - start_t) / CLOCKS_PER_SEC;

  printf("Calculation Time: %fms\n", elapsed_ms * 1000);

  for (int i; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  time_t t;

  srand((unsigned)time(&t));

  int n;

  printf("Number of vertices: ");
  scanf("%d", &n);

  directed(n);
}