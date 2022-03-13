#include <wc/array.h>
#include <wc/error.h>



/**
 * \brief Array Fill 
 * \fn	const void* afl(
 *		const void* restrict const a,
 *		const As sa,
 *		const void* restrict const b,
 *		const As sb
 *	)
 * \param a		array to be filled
 * \param sa	size of `*a` in bytes
 * \param b		array to fill with
 * \param sb	size of `*b` in bytes
 * \returns const void*
 * 
 * Repeatedly fills `*a` with `*b`
 * # Rules
 * `a` != `NULL`
 * `b` != `NULL`
 * `sa` > 0
 * # Special case
 * If `sb` = 0, returns `a` but does nothing.
 */
const void* afl(
	const void* restrict const	a,
	const As					sa,
	const void* restrict const	b,
	const As					sb
) {
	/* 1. Check that `a` and `b` are valid pointers, and that `sa` > 0 */
	if (a && b && sa) {
		/* 2. Check that `sb` is more than zero */
		if (sb) {
			const As d = sa-(sa%sb);

			/* 3. Assign `sb` bytes of `*b` to `*a`, until there's less than
			 * `sb` bytes remaining unassigned
			 */
			As i = 0;
			for (i = 0; i<d; i+=sb) aas((Vo*)((Pt)a+i), b, sb);
			
			/* 4. Assign the remaining bytes */
			aas((Vo*)((Pt)a+i), b, sa-d);
		}
		/* If `sb` is zero, do nothing */

		return a;
	}
#if WL_ERROR
	/* Error checkin' */
	if (sa)	err(afb,ERNULL);
	else	err(afb,ERZERO);
#endif
	/* Otherwise just return NULL */
	return NULL;
}
