#ifndef WC_ERROR_H
#define WC_ERROR_H



#if !WL_PREFIX
#	define ERNULL	WL_ERNULL
#	define ERZERO	WL_ERZERO
#	define ERFUNC	WL_ERFUNC
#	define WRNULL	WL_WRNULL
#	define WRZERO	WL_WRZERO

#	define err		wl_err
#	define wrn		wl_wrn
#endif



#define WL_ERNULL	"Null agrument"
#define WL_ERZERO	"Zero agrument"
#define WL_ERFUNC	"Invalid `func` value"
#define WL_WRNULL	"Null agrument, allocating"
#define WL_WRZERO	"Zero agrument, assuming infinity"



#if WL_ERROR
#	include <stdio.h>
#	define wl_err(SRC, MSG)	printf("%s: %s\n", #SRC, MSG)
#	define wl_wrn(SRC, MSG)	printf("%s: %s\n", #SRC, MSG)
#else
#	define wl_err(SRC, MSG)
#	define wl_wrn(SRC, MSG)
#endif

#endif
