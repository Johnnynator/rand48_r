#ifndef RAND48_R_H
#define RAND48_R_H
#ifdef __cplusplus
extern "C" {
#endif

struct drand48_data {
  unsigned short __x[3];
  unsigned short __old_x[3];
  unsigned short __c;
  unsigned short __init;
  long long __a;
};

int drand48_r(struct drand48_data*, double*);
int erand48_r(unsigned short [3], struct drand48_data*, double*);
int lrand48_r(struct drand48_data*, long int*);
int nrand48_r(unsigned short [3], struct drand48_data*, long*);
int mrand48_r(struct drand48_data*,long *result);
int jrand48_r(unsigned short[3], struct drand48_data*, long*);
int srand48_r(long, struct drand48_data*);
int seed48_r(unsigned short*, struct drand48_data*);
#ifdef __cplusplus
}
#endif
#endif
