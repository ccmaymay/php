#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_randist.h>

int main(int argc, char **argv) {
  gsl_rng_env_setup();
  gsl_rng *r = gsl_rng_alloc(gsl_rng_default);

  const size_t n = 5000;

  double *mat = malloc(n * n * sizeof(double));
  if (mat == NULL) {
    fprintf(stderr, "bad allocation\n");
    exit(1);
  }

  FILE *mat_f = fopen("mat", "w");
  for (size_t i = 0; i < n; ++i) {
    fprintf(mat_f, "%.6f", gsl_ran_gaussian(r, 1));
    for (size_t j = 1; j < n; ++j)
      fprintf(mat_f, " %.6f", gsl_ran_gaussian(r, 1));
    fprintf(mat_f, "\n");
  }
  fclose(mat_f);

  free(mat);
  gsl_rng_free(r);

  return 0;
}
