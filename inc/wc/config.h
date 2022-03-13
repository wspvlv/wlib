#ifndef WC_CONFIG_H
#define WC_CONFIG_H



/**********************************
 *                                *
 *  YOUR CONFIGURATION GOES HERE  *
 *                                *
 **********************************/



/*
 *	STANDARD C LIBRARY INTEGRATION
 */

/* Allow using the Standard C Library */
#ifndef WL_USE_LIBC
#	define WL_USE_LIBC		0
#endif

/* If WL_USE_LIBC is TRUE, allow using all headers, otherwise disallow */

/* Allow including <limits.h> */
#ifndef WL_USE_LIMITS
#	define WL_USE_LIMITS	WL_USE_LIBC
#endif

/* Allow including <stdint.h> */
#ifndef WL_USE_STDINT
#	define WL_USE_STDINT	WL_USE_LIBC
#endif

/* Allow including <stdlib.h> */
#ifndef WL_USE_STDLIB
#	define WL_USE_STDLIB	WL_USE_LIBC
#endif



/*
 *	OPTIMIZATION
 */

/* Optimize implimentation of WLib for maximal execution speed */
#ifndef WL_OPTIMIZE_SPEED
#	if defined(__OPTIMIZE_SPEED__) && __OPTIMIZE_SPEED__ == 0
#		define WL_OPTIMIZE_SPEED	0
#	else
#		define WL_OPTIMIZE_SPEED	1
#	endif
#endif
/* Optimize implimentation of WLib for minimal size of binary files */
#ifndef WL_OPTIMIZE_SIZE
#	if defined(__OPTIMIZE_SIZE__) || defined(PREFER_SIZE_OVER_SPEED)
#		define WL_OPTIMIZE_SIZE		1
#	else
#		define WL_OPTIMIZE_SIZE		0
#	endif
#endif
/* Optimize implimentation of WLib for the least memory (RAM) usage */
#ifndef WL_OPTIMIZE_MEMORY
#	define WL_OPTIMIZE_MEMORY		0
#endif



/*
 *	IMPLIMENTATION OPTIONS
 */
/* Defines identifiers without the `wl_` prefix */
#ifndef WL_PREFIX
#	define WL_PREFIX		0
#endif
/* Defines readable aliases for identifiers*/
#ifndef WL_ALIASES
#	define WL_ALIASES		0
#endif
/* Primitive `sl` implimentation */
#ifndef WL_SL_SIMPLE
#	define WL_SL_SIMPLE		0
#endif
/* Primitive `afa` implimentation */
#ifndef WL_AFA_SIMPLE
#	define WL_AFA_SIMPLE	0
#endif
/* Primitive `afb` implimentation */
#ifndef WL_AFB_SIMPLE
#	define WL_AFB_SIMPLE	0
#endif
/* Primitive `afl` implimentation */
#ifndef WL_AFL_SIMPLE
#	define WL_AFL_SIMPLE	0
#endif
/* Primitive `asb` implimentation */
#ifndef WL_ASB_SIMPLE
#	define WL_ASB_SIMPLE	0
#endif
/* Primitive `asa` implimentation */
#ifndef WL_ASA_SIMPLE
#	define WL_ASA_SIMPLE	0
#endif



/*********************************************************************
 *                                                                   *
 *  ... OR HERE                                                      *
 *  (but use `#undef` before defining to avoid redefinition errors)  *
 *                                                                   *
 *********************************************************************/
/* #undef WL_OPTIMIZE_SPEED
#define WL_OPTIMIZE_SPEED 2 */
#define WL_ERROR	1



#endif
