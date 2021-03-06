/* Includes */
#include <wc/types.h>



/* Macros */

#define VP0F		(U32)0x00000000			/* (F32) Bitwise representation of Positive 0 */
#define VP1F		(U32)0x3F800000			/* (F32) Bitwise representation of Positive 1 */
#define VP2F		(U32)0x40000000			/* (F32) Bitwise representation of Positive 2 */
#define VPIF		(U64)0x7F800000			/* (F64) Bitwise representation of Positive Infinity */
#define VPNF		(U64)0x7FFFFFFF			/* (F64) Bitwise representation of Positive NaN */
#define VEF			(U32)0x402DF854			/* (F32) Bitwise representation of Euler's constant */
#define VPF			(U32)0x40490FDBF		/* (F32) Bitwise representation of Pi constant */
#define VTF			(U32)0x40C90FDB			/* (F32) Bitwise representation of Tau constant */

#ifdef CM_MSC
#define NIF			-1e30f*1e30f			/* (F32) Negative Infinity */
#define NNF			NIF*0.0f				/* (F32) Negative NaN */
#define PIF			1e30f*1e30f				/* (F32) Positive Infinity */
#define PNF			PIF*0.0f				/* (F32) Positive NaN */
#else
#define NIF			-1e39f					/* (F32) Negative Infinity */
#define NNF			-0.0f/0.0f				/* (F32) Negative NaN */
#define PIF			1e39f					/* (F32) Positive Infinity */
#define PNF			(0.0f/0.0f)				/* (F32) Positive NaN */
#endif

/* (F32) Natural logarithm of 2 */
#define LN2F		0.693147182464599609375F



/* Declarations */
extern F32 lg2f	(F32 z);		/* (F64) Binary Logarithm */
extern F32 _pwif(F32 x, U64 y);	/* (F32) Integer exponent exponentiation */



/* Function definitions */

/* (F32) Logarithm			*/
F32	lgf(F32	x, F32 z) {
	U32 vx, vz;

	vx = *(U32*)&x;
	vz = *(U32*)&z;

	if (vz & I32N) {
		vz &= I32X;
		if (vz < VP1F) return NNF;
		return PNF;
	}

	if (vz==VP0F)	return NIF;
	if (vz==VP1F)	return 0.0f;
	if (vz == VPIF)	return PIF;
	if (vz > VPIF)	return PNF;
	if (vx==vz)		return 1.0f;
	if (vx == VP2F)	return lg2f(z);
	 
	return lg2f(z) / lg2f(x);
}