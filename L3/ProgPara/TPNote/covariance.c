#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <omp.h>

#define ERROR          1.e-6 // Acceptable precision
#define MAX_VAL        5.      // Random values are [0, MAX_VAL]

// Matrix size
#define N 4000
#define M 1000

#define TYPE float

// Computation kernel (to parallelize)
void covariance_kernel(TYPE data[N][M], TYPE cov[M][M], TYPE mean[M])
{
#pragma omp parallel for
  for (int j = 0; j < M; j++)
  {
    mean[j] = 0.;
    for (int i = 0; i < N; i++)
      mean[j] += data[i][j];
    mean[j] /= N;
  }

#pragma omp parallel for collapse(2)
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      data[i][j] -= mean[j];

#pragma omp parallel for collapse(2)
  for (int i = 0; i < M; i++)
    for (int j = i; j < M; j++)
    {
      cov[i][j] = 0.;
      for (int k = 0; k < N; k++)
        cov[i][j] += data[k][i] * data[k][j];
      cov[i][j] /= (N - 1.);
      cov[j][i] = cov[i][j];
    }
}

// Reference computation kernel (do not touch)
void covariance_reference(TYPE data[N][M], TYPE cov[M][M], TYPE mean[M])
{
  for (int j = 0; j < M; j++)
  {
    mean[j] = 0.;
    for (int i = 0; i < N; i++)
      mean[j] += data[i][j];
    mean[j] /= N;
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      data[i][j] -= mean[j];

  for (int i = 0; i < M; i++)
    for (int j = i; j < M; j++)
    {
      cov[i][j] = 0.;
      for (int k = 0; k < N; k++)
        cov[i][j] += data[k][i] * data[k][j];
      cov[i][j] /= (N - 1.);
      cov[j][i] = cov[i][j];
    }
}

// MAIN
int main()
{
  TYPE (*data)[M]    = malloc(N * M * sizeof(TYPE));
  TYPE (*cov)[M]     = malloc(M * M * sizeof(TYPE));
  TYPE *mean         = malloc(M * sizeof(TYPE));
  TYPE (*data_ref)[M]    = malloc(N * M * sizeof(TYPE));
  TYPE (*cov_ref)[M] = malloc(M * M * sizeof(TYPE));
  TYPE *mean_ref     = malloc(M * sizeof(TYPE));
  double time_reference, time_kernel, speedup;

  // INITIALIZATION
  srand(time(NULL)+getpid());
  for (size_t i = 0; i < N; i++)
    for (size_t j = 0; j < M; j++)
      data[i][j] = data_ref[i][j] = (TYPE)rand()/(RAND_MAX/MAX_VAL);

  // REFERENCE CALL
  time_reference = omp_get_wtime();
  covariance_reference(data_ref, cov_ref, mean_ref);
  time_reference = omp_get_wtime() - time_reference;
  printf("Reference time : %3.5lf s\n", time_reference);

  // KERNEL CALL
  time_kernel = omp_get_wtime();
  covariance_kernel(data, cov, mean);
  time_kernel = omp_get_wtime() - time_kernel;
  printf("Kernel time -- : %3.5lf s\n", time_kernel);

  speedup = time_reference / time_kernel;
  printf("Speedup ------ : %3.5lf\n", speedup);

  // Check if the result differs from the reference
  for (size_t i = 0; i < M; i++) {
    for (size_t j = i; j < M; j++) {
      if (fabs(cov_ref[i][j] - cov[i][j]) > ERROR)
      {
        printf("Bad results :-(((\n");
        exit(1);
      }
    }
  }
  printf("OK results :-)\n");

  free(data);
  free(cov);
  free(mean);
  free(cov_ref);
  free(mean_ref);
  return 0;
}
