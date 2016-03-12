#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

double runif() {
  double u = rand() / (double) RAND_MAX;
  return u == 0 ? 1./(double)RAND_MAX : u;
}

double rnorm() {
  double u = runif(),
         v = runif();
  double r1 = sqrt(-2. * log(u)) * cos(2. * PI * v);
  /* double r2 = sqrt(-2. * log(u)) * sin(2. * PI * v); */
  return r1;
}

int main(int argc, char **argv) {
  double pi = 2 * asin(1);

  const size_t n = 5000;

  double *mat = malloc(n * n * sizeof(double));
  if (mat == NULL) {
    fprintf(stderr, "bad allocation\n");
    exit(1);
  }

  FILE *mat_f = fopen("mat", "w");
  for (size_t i = 0; i < n; ++i) {
    fprintf(mat_f, "%.6f", rnorm());
    for (size_t j = 1; j < n; ++j)
      fprintf(mat_f, " %.6f", rnorm());
    fprintf(mat_f, "\n");
  }
  fclose(mat_f);

  free(mat);

  return 0;
}
