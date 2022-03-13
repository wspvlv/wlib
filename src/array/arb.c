#include <wc/array.h>


/* Array Replace Bit */
/* Replace all occurances of byte `b` with `r` in array `a` */
void arb(
	const void* restrict const a,
	const As sa,
	const char b,
	const char r,
	const Asf flags
) {
	Pt z;
	/* ASF_COUNT will replace all needles */
	if (flags&ASF_COUNT)
		while (( z = asb(a,sa,b,0) )) {
			*(char*)z = r; z++;
 		}
	/* ASF_REVERSE will replace the last needle, and ASF_NORMAL the first */
	else if (( z = asb(a,sa,b,flags&WL_ASF_REVERSED) )) *(char*)z = r;
}
