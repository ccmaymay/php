#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv) {
  size_t n = 0;

  FILE *mat_f = fopen("mat", "r");
  while (! feof(mat_f))
    if (fgetc(mat_f) == '\n')
      ++n;

  double *mat = malloc(n * n * sizeof(double));
  if (mat == NULL) {
    fprintf(stderr, "bad allocation\n");
    exit(1);
  }

  fseek(mat_f, 0, SEEK_SET);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (fscanf(mat_f, "%lf", mat + j + i*n) != 1) {
        fprintf(stderr, "bad scan\n");
        exit(1);
      }
    }
  }
  fclose(mat_f);

  double norm = 0;

  time_t start = time(NULL);

  /* compute frobenius norm of mat */
  const size_t num_entries = n * n;
  for (size_t k = 0; k < num_entries; ++k)
    norm += mat[k] * mat[k];
  norm = sqrt(norm);

  time_t end = time(NULL);

  fprintf(stdout, "norm: %.3f\n", norm);
  fprintf(stdout, "elapsed time: %.3f\n", difftime(end, start));

  free(mat);

  return 0;
}
