#ifndef WL_MEMORY_H
#define WL_MEMORY_H	1



#include <wl/config.h>



#if !WL_CONF_PREFIX
#	define mal	wl_mal
#	define mfr	wl_mfr
#endif



#include <stdlib.h>
#define wl_mal	malloc
#define wl_mfr	free



#endif
