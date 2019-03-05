#include <inttypes.h>
#include <string.h>

#include "rand48_r.h"

uint64_t __rand48_step(unsigned short *xi, unsigned short *lc)
{
	uint64_t a, x;
	x = xi[0] | (xi[1]+0U)<<16 | (xi[2]+0ULL)<<32;
	a = lc[0] | (lc[1]+0U)<<16 | (lc[2]+0ULL)<<32;
	x = a*x + lc[3];
	xi[0] = x;
	xi[1] = x>>16;
	xi[2] = x>>32;
	return x & 0xffffffffffffull;
}


int jrand48_r(unsigned short s[3], struct drand48_data *buffer, long *result)
{
	*result = (int32_t)(__rand48_step(s, buffer->__x+3) >> 16);
	return 0;
}

int mrand48_r(struct drand48_data *buffer,long *result)
{
	*result = jrand48_r(buffer->__x,buffer,result);
	return 0;
}

int erand48_r(unsigned short s[3], struct drand48_data *buffer, double *result)
{
	union {
		uint64_t u;
		double f;
	} x = { 0x3ff0000000000000ULL | __rand48_step(s, buffer->__x+3)<<4 };
	*result = x.f - 1.0;
	return 0;
}

int drand48_r(struct drand48_data *buffer, double *result)
{
	return erand48_r(buffer->__x, buffer, result);
}

int nrand48_r(unsigned short s[3], struct drand48_data *buffer, long *result)
{
	*result = __rand48_step(s, buffer->__x+3) >> 17;
	return 0;
}

int lrand48_r(struct drand48_data *buffer, long int *result)
{
	return nrand48_r(buffer->__x, buffer, result);
}
int srand48_r(long s, struct drand48_data *buffer)
{
	return seed48_r((unsigned short [3]){0x330e, s, s>>16}, buffer);
}

int seed48_r(unsigned short *s, struct drand48_data *buffer)
{
	memcpy(buffer->__old_x, buffer->__x, sizeof buffer->__x);
	memcpy(buffer->__x, s, sizeof buffer->__x);
	buffer->__c = 0;
	buffer->__init = 1;
	buffer->__a = 0;
	return 0;
}

