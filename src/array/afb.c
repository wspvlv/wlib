#include <wc/array.h>
#include <wc/error.h>



#if !defined(WL_MAL_IMPLIMENTED) || !defined(mal)
#	include <stdlib.h>
#	define mal malloc
#endif



/* Abbreviation for `sizeof(UMax)` */
#define SM	(sizeof(UMax))
/* Pointer add assignment */
#define PADA(a,b) (a = (const void*)((Pt)a+(Pt)b))

#define A	(*((UMax*)a))
#define B	(*((UMax*)b))

#define AFBTEMP(COND)							\
	for (; size >= SM; PADA(a,SM), size -= SM)	\
		if (COND) return func&1;				\
	if (size<<=3) {								\
		const UMax m = ((UMax)1<<size) - 1;		\
		if ((COND)&m) return func&1;			\
	}

Bl afb(const void* a, const void* b, As size, Bl mode) {
	/* 1. `a` cannot be NULL and `size` should be > `0`*/
	if (a&&size) {
		/* If `mode` is true, the functions return value will be negated */

#		if OPTIMIZE_SIZE != 2
			/* 2. If b != NULL, then aeq/anq */
			if (b) {
				/* XOR each byte of `a` and `b`. If at any point 
				* the result of XOR is not zero, the strings aren't equal.
				*/
				for (; size >= SM; PADA(a,SM), size -= SM)
					if (A^B) return !mode;
				if (size<<=3) {
					const UMax m = ((UMax)1<<size) - 1;
					if ((A^B)&m) return !mode;
				}
			}
#		endif
		
		/* If any byte of `a` is not zero, the array is true */
		for (; size >= SM; PADA(a,SM), size -= SM)
			if (A) return !mode;
		if (size<<=3) {
			const UMax m = ((UMax)1<<size) - 1;
			if (A&m) return !mode;
		}

		return mode;
	}
#if WL_ERROR
	/* Error checkin' */
	if (size)	err(afb,ERNULL);
	else		err(afb,ERZERO);
#endif
	return FALSE;
}
