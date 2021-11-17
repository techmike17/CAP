
#include <malloc.h>
#include <stdlib.h>
#include "nbody.h"
#include <mm_malloc.h>
body2* get_memory(int nBodies)
{
	
	body2 *p = _mm_malloc (sizeof(body2),32);
	p->m = (float*)_mm_malloc (sizeof(float)* nBodies,32);
	p->x = (float*)_mm_malloc (sizeof(float)* nBodies,32);	
	p->y = (float*)_mm_malloc (sizeof(float)* nBodies,32);
	p->z = (float*)_mm_malloc (sizeof(float)* nBodies,32);
	p->vx =(float*) _mm_malloc (sizeof(float)* nBodies,32);
	p->vy =(float*) _mm_malloc (sizeof(float)* nBodies,32);
	p->vz =(float*) _mm_malloc (sizeof(float)* nBodies,32);
	return p;
}

void free_memory(body2 *p)
{
	_mm_free(p->m);
	_mm_free(p->x);
	_mm_free(p->y);
	_mm_free(p->z);
	_mm_free(p->vx);
	_mm_free(p->vy);
	_mm_free(p->vz);
	_mm_free(p);
}

void randomizeBodies(body2 *data, int n) {
	for (int i = 0; i < n; i++) {
		data->m[i]  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data->x[i] = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data->y[i]  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data->z[i]  = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;

		data->vx[i] = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data->vy[i] = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
		data->vz[i] = 2.0f * (rand() / (float)RAND_MAX) - 1.0f;
	}
}

