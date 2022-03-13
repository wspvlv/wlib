#ifndef WC_STRING_H
#define WC_STRING_H



#include <wc/core.h>
#include <wc/types.h>



#if !WL_PREFIX
#	define Sl		wl_Sl
#	define sl		wl_sl

#	if WL_ALIASES
#		define Lens			wl_Lens
#		define Strlen		wl_Strlen
#		define StringLength	wl_StringLength
#		define lens			wl_lens
#		define strlen		wl_strlen
#		define stringLength	wl_stringLength
#	endif

#endif

#if WL_ALIASES
#	define wl_Lens			wl_Sl
#	define wl_Strlen		wl_Sl
#	define wl_StringLength	wl_Sl
#	define wl_lens			wl_sl
#	define wl_strlen		wl_sl
#	define wl_stringLength	wl_Sl
#endif



/**
 * \brief	String length type
 * \typedef	wl_Sl
 * This type is used as type that for a length of a string. It is useful because
 * any string function will only support strings, which length can be stored
 * using this type.
 */
typedef wl_U16 wl_Sl;



/* String length */
EXTERN wl_Sl wl_sl(const char* restrict const s);



#endif
