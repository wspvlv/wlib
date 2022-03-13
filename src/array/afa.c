#include <wc/array.h>
#include <wc/error.h>



#if !defined(WL_MAL_IMPLIMENTED)
#	include <stdlib.h>
#	undef mal
#	define mal malloc
#	undef mfr
#	define mfr free
#endif



/* Shortcut for properly assigning selected bits of the value, where `m` is the
 * bitmask, where the value of the bit determines if it is going to be assigned
 * from `b` to `a`
 */
#if WL_OPTIMIZE_MEMORY >= 1
#	define _ASV(a,b)	\
		((a) = ((b)&(((UMax)1<<size) - 1)) + ((a)&(UMX>>size<<size))))
#else
#	define _ASV(a,b) 						\
		const UMax m = ((UMax)1<<size) - 1;	\
		((a) = ((b)&m) + ((a)&~m))
#endif
/* Abbreviation for `sizeof(UMax)` */
#define SM	(sizeof(UMax))
/* Pointer add assignment */
#define PADA(a,b) (a = (const void*)((Pt)a+(Pt)b))

#if WL_AFA_SIMPLE
#	define A	*((U8*)a)
#	define B	*((U8*)b)
#	define C	*((U8*)c)

#	define AFATEMP1(_ASVARG_A, _ASVARG_B)						\
		for (; size; PADA(a,1), PADA(b,1), size--)				\
			(_ASVARG_A) = (_ASVARG_B);
#	define AFATEMP2(_ASVARG_A, _ASVARG_B)						\
		for (; size; PADA(a,1), PADA(b,1), PADA(c,1), size--)	\
			(_ASVARG_A) = (_ASVARG_B);
#else
#	define A	*((UMax*)a)
#	define B	*((UMax*)b)
#	define C	*((UMax*)c)

#	define AFATEMP1(_ASVARG_A, _ASVARG_B)						\
		for (; size >= SM; PADA(a,SM), PADA(b,SM), size -= SM)	\
			(_ASVARG_A) = (_ASVARG_B);							\
		if (size<<=3) {											\
			_ASV((_ASVARG_A), (_ASVARG_B));						\
		}
#	define AFATEMP2(_ASVARG_A, _ASVARG_B)									\
		for (; size >= SM; PADA(a,SM), PADA(b,SM), PADA(c,SM), size -= SM)	\
			(_ASVARG_A) = (_ASVARG_B);										\
		if (size<<=3) {														\
			_ASV((_ASVARG_A), (_ASVARG_B));									\
		}
#endif

#if !WL_OPTIMIZE_MEMORY
#	define AFAHEAD1						\
		if (size&&b) {					\
			const char* a;				\
			const Af _func = func&I8X;	\
			if (!_a) {					\
				wrn(afa, WRNULL);		\
				_a = mal(size);			\
			}							\
			a = _a;

#	define AFAHEAD2						\
		if (size&&b&&c) {				\
			const char* a;				\
			const Af _func = func&I8X;	\
			if (!_a) {					\
				wrn(afa, WRNULL);		\
				_a = mal(size);			\
			}							\
			a = _a;
#else
#	define AFAHEAD1						\
		if (size&&b) {					\
			const char* a;				\
			if (!_a) {					\
				wrn(afa, WRNULL);		\
				_a = mal(size);			\
			}							\
			a = _a;

#	define AFAHEAD2						\
		if (size&&b&&c) {				\
			const char* a;				\
			if (!_a) {					\
				wrn(afa, WRNULL);		\
				_a = mal(size);			\
			}							\
			a = _a;
#endif

#define AFAFOOT															\
		if (_a != a && func&I8N) {										\
			const char* const __a = aas(NULL, _a, (const char*)_a-a);	\
			mfr((char*)_a);												\
			return __a;													\
		}																\
	}																	\
	err(afa, ERNULL);													\
	return _a;

#define AFADEF1(NAME, _ASVARG_A, _ASVARG_B)	\
	AFADECL1(NAME) {						\
		AFAHEAD1							\
		AFATEMP1( (_ASVARG_A), (_ASVARG_B))	\
		AFAFOOT								\
	}

#define AFADEF2(NAME, _ASVARG_A, _ASVARG_B)	\
	AFADECL2(NAME) {						\
		AFAHEAD2							\
		AFATEMP2( (_ASVARG_A), (_ASVARG_B))	\
		AFAFOOT								\
	}



#if WL_OPTIMIZE_SPEED == 2
	AFADEF1(ano, A, B)
	AFADEF1(ant, A, ~B)
	AFADEF2(aan, A, B & C)
	AFADEF2(aor, A, B | C)
	AFADEF2(axr, A, B ^ C)
	AFADEF2(ann, A, ~(B & C))
	AFADEF2(anr, A, ~(B | C))
	AFADEF2(anx, A, ~(B ^ C))

	/* This function exists here as a failsafe, 
	 * YOU SHOULD NOT USE THIS FUNCTION IF SPEED IS YOUR PRIORITY 
	 */
	const void* afa(const void* _a, const void* b, const void* c, const	Af func, As size) {
		switch (func) {
			case WL_AF_NO: return ano(_a, b, size);
			case WL_AF_NT: return ant(_a, b, size);
			case WL_AF_AN: return aan(_a, b, c, size);
			case WL_AF_OR: return aor(_a, b, c, size);
			case WL_AF_XR: return axr(_a, b, c, size);
			case WL_AF_NN: return ann(_a, b, c, size);
			case WL_AF_NR: return anr(_a, b, c, size);
			case WL_AF_NX: return anx(_a, b, c, size);
			default: return NULL;
		}
	}
#else
	const void* afa(const void* _a, const void* b, const void* c, const	Af func, As size) {
		AFAHEAD1
#		if WL_OPTIMIZE_MEMORY
#			define _func	func&I8X
#		endif
		/* Method in a nutshell:
		 * 1.	Treat values in chunks of SM bytes
		 * 2.	When there are less than SM bytes remaining, 
		 * 		use selected assignment macro `_ASV`
		 * Notes:
		 * `size<<=3` -- convertion from bytes to bits for `m` shifts
		 * `m` is a bitmask for selected assignment `_ASV`. See the 
		 * comment above `_ASV` for more information.
		 */

		/* All function require `b` != NULL, otherwise, no action will 
		 * performed 
		 */

		/* If the leftmost bit of func is 1, then all operations should be to 
		 * an intermediate buffer first.
		 */


		/* Those functions that require `c`, will only be done if `c` is 
		 * not NULL 
		 */

		if (_func <= WL_AF_NX) {
			if (c)	switch (_func) {
				/* aan() -- Array bitwise AND */
				case WL_AF_AN: AFATEMP2(A, B & C) break;
				/* aor() -- Array bitwise OR */
				case WL_AF_OR: AFATEMP2(A, B | C) break;
				/* axr() -- Array bitwise XOR */
				case WL_AF_XR: AFATEMP2(A, B ^ C) break;
				/* ann() -- Array bitwise NAND */
				case WL_AF_NN: AFATEMP2(A, ~(B & C)) break;
				/* anr() -- Array bitwise NOR */
				case WL_AF_NR: AFATEMP2(A, ~(B | C)) break;
				/* anx() -- Array bitwise NXOR */
				case WL_AF_NX: AFATEMP2(A, ~(B ^ C)) break;
			}
			else switch (_func) {
				/* aas() -- Array assignment */
				case WL_AF_NO: AFATEMP1(A, B) break;
				/* ant() -- Array bitwise NOT */
				case WL_AF_NT: AFATEMP1(A, ~B) break;
				default: err(afa,ERNULL); break;
			}
		}
		else err(afa,ERFUNC);
		AFAFOOT
	}
#endif
