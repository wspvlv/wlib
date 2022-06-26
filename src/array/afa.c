#include <wc/array.h>



#ifndef mal
#	include <stdlib.h>
#	define mal(n)	calloc(n,1)
#endif



/* Enumerator for */
enum _Af {
	_AF_NO,	/* No operation */
	_AF_NT,	/* NOT */
	_AF_AN,	/* AND */
	_AF_OR,	/* OR */
	_AF_XR,	/* XOR */
	_AF_NN,	/* NAND */
	_AF_NR,	/* NOR */
	_AF_NX	/* NXOR */
};

/*
 *	Assigns `n` bits of `b` to `a`, preserving the remaining bits of `a`
 */
#if WL_CONF_OPTIMIZE&4 == WL_OPTIMIZE_MEMORY
/* Here doesn't use memory */
#	define _ASSIGN_SUBWORD(arr1,arr2,N)	\
		((arr1) = ((arr2)&(((UMax)1<<N) - 1)) + ((arr1)&(UMX>>N<<N))));
#else
/* Here we use memory, but it's faster */
#	define _ASSIGN_SUBWORD(arr1,arr2,N)	{		\
		const UMax m = ((UMax)1<<N) - 1;	\
		((arr1) = ((arr2)&m) + ((arr1)&~m));			\
	}
#endif

/*
 *	Assigns all bytes of `EXP` to `r`, where `EXP` is a expression.
 *	Firstly, assigns in chunks of `sizeof(UMax)`, for the remaining bits uses
 *	`_ASSIGN_SUBWORD()`
 * 	Method:
 * 		1.	Copy bytes till next alignment
 * 		2.	Copy bytes one word at a time
 * 		3.	Copy the remaining bytes (less than word bytes)
 */
#define _AFA1(EXP)												\
	{															\
		const Sz rem = (Pt)arr1%UMB;							\
		if (unlikely(rem>0)) {									\
			_ASSIGN_SUBWORD(*_res, (EXP), CHB*rem);				\
			len -= rem;											\
			_res = (UMax*)((char*)_res + rem);					\
			arr1 = (UMax*)((char*)arr1 + rem);					\
		}														\
	}															\
																\
	while (len >= sizeof(UMax)) {								\
		*_res = (EXP);											\
		_res++; arr1++; len -= sizeof(UMax);					\
	}															\
																\
	if (likely(len))	_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);

#define _AFA2(EXP)												\
	{															\
		const Sz rem = (Pt)arr1%UMB;							\
		if (unlikely(rem>0)) {									\
			_ASSIGN_SUBWORD(*_res, (EXP), CHB*rem);				\
			len -= rem;											\
			_res = (UMax*)((char*)_res + rem);					\
			arr1 = (UMax*)((char*)arr1 + rem);					\
			arr2 = (UMax*)((char*)arr2 + rem);					\
		}														\
	}															\
																\
	while (len >= sizeof(UMax)) {								\
		*_res = (EXP);											\
		_res++; arr1++; arr2++; len -= sizeof(UMax);			\
	}															\
																\
	if (likely(len))	_ASSIGN_SUBWORD(*_res, (EXP), CHB*len);

/*
 *	ADD GCC ATTRIBUTES!!!
 */
/**
 * \brief 
 * \fn		const char* _afa(const UMax* arr1, const UMax* arr2, Sz len, UMax* restrict const res, const _Af func)
 * \param	arr1 
 * \param	arr2 
 * \param	count 
 * \param	res 
 * \return	char* 
 * 
 * Future improvements:
 * 	- Page coping
 */
const UMax* _afa(
	const	UMax*					arr1,
	const	UMax*					arr2,
			Sz						len,
			UMax*	restrict const	res,
	const	_Af						func
) {
	/* Store the base of the operands */
/* 	const	UMax* const _arr1 = arr1;
			UMax* const _arr2 = arr2; */

	/* An operant cannot be nullptr and length has to be larger than 0 */
	if (likely(arr1 != NULL && len > 0)) {
		UMax* _res = res;

		/* If `res` is NULL, it should be allocated by the algorithm */
		if (likely(_res == NULL)) _res = mal(len);
		/* Allocation could fail */
		if (likely(_res != NULL)) {
			/* First, check for _AF_NO */
			if (likely(func==_AF_NO)) {
				_AFA1(*arr1);
				return _res;
			}
			/* Second, check for _AF_NT */
			else if (unlikely(func==_AF_NT)) {
				_AFA1(~*arr1);
				return _res;
			}
			/* Then do other functions */
			else if (unlikely(arr2!=NULL)) {
				switch (func) {
					case _AF_AN: _AFA2(*arr1 & *arr2);		return _res;
					case _AF_OR: _AFA2(*arr1 | *arr2);		return _res;
					case _AF_XR: _AFA2(*arr1 ^ *arr2);		return _res;
					case _AF_NN: _AFA2(~(*arr1 & *arr2));	return _res;
					case _AF_NR: _AFA2(~(*arr1 | *arr2));	return _res;
					case _AF_NX: _AFA2(~(*arr1 ^ *arr2));	return _res;
					default:;
				}
			}
		}
	}

	/* If the flow of the function ends up here, there was an error */
	return NULL;
}
