#ifndef WL_STRING_H
#define WL_STRING_H



#include <wl/core.h>
#include <wl/types.h>



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



/* String length */
EXTERN wl_U16 wl_sl(const char* restrict const string);



#endif
