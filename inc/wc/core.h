#ifndef WC_CORE_H
#define WC_CORE_H



#include <wc/sys/lang.h>



#ifdef WL_LG_CPP
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern "C"
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN	EXTERN {
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END	}
#	endif
#	ifndef ENUM
#		define ENUM(NAME)	enum ENUM_##NAME
#	endif
#else
/* Extern compatibility */
#	ifndef EXTERN
#		define EXTERN		extern
#	endif
/* Beginning of a set of external definitions */
#	ifndef C_DECL_BEGIN
#		define C_DECL_BEGIN
#	endif
/* End of a set of external definitions */
#	ifndef C_DECL_END
#		define C_DECL_END	}
#	endif
#	ifndef ENUM
#		define ENUM(NAME)	enum NAME
#	endif
#endif

/* C99 keywords */
/* #if defined(WL_LG_C) && WL_LG_C < WL_VR_C99 || defined(WL_LG_CPP)
#	ifndef INLINE
#		define INLINE
#	endif
#	ifndef RESTRICT
#		define RESTRICT
#	endif
#else
#	ifndef INLINE
#		define INLINE inline
#	endif
#	ifndef RESTRICT
#		define RESTRICT	restrict
#	endif
#endif */

#if defined(WL_LG_C) && WL_LG_C < WL_VR_C99
/* Inline */
#	undef	inline
#	define	inline
/* Restrict */
#	undef	restrict
#	define	restrict
#elif defined(WL_LG_CPP)
/* Restrict */
#	undef	restrict
#	define	restrict
#endif



#endif
