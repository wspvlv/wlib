#ifndef WC_TYPES_H
#define WC_TYPES_H



/***
 *      ___                  _               _              
 *     |_ _|  _ __     ___  | |  _   _    __| |   ___   ___ 
 *      | |  | '_ \   / __| | | | | | |  / _` |  / _ \ / __|
 *      | |  | | | | | (__  | | | |_| | | (_| | |  __/ \__ \
 *     |___| |_| |_|  \___| |_|  \__,_|  \__,_|  \___| |___/
 *                                                          
 */
#include <wc/sys/damo.h>
#include <wc/sys/lang.h>
#if (WL_LG_C>=WL_VR_C99 || defined(WL_LG_CPP)) && WL_USE_STDINT
#	include <stdint.h>
#endif



/***
 *      __  __                                     
 *     |  \/  |   __ _    ___   _ __    ___    ___ 
 *     | |\/| |  / _` |  / __| | '__|  / _ \  / __|
 *     | |  | | | (_| | | (__  | |    | (_) | \__ \
 *     |_|  |_|  \__,_|  \___| |_|     \___/  |___/
 *                                                 
 */
#if !WL_PREFIX
#	define I8	wl_I8
#	define I16	wl_I16
#	define I32	wl_I32
#	define I64	wl_I64
#	define i8	wl_i8
#	define i16	wl_i16
#	define i32	wl_i32
#	define i64	wl_i64
#	define U8	wl_U8
#	define U16	wl_U16
#	define U32	wl_U32
#	define U64	wl_U64
#	define u8	wl_u8
#	define u16	wl_u16
#	define u32	wl_u32
#	define u64	wl_u64
#	define IMax	wl_IMax
#	define imax	wl_imax
#	define UMax	wl_UMax
#	define umax	wl_umax
#	define Vo	wl_Vo
#	define Bl	wl_Bl
#	define Ch	wl_Ch
#	define Pt	wl_Pt
#	define Fl	wl_Fl
#	define Db	wl_Db
#	define Ld	wl_Ld
#	define vo	wl_vo
#	define bl	wl_bl
#	define ch	wl_ch
#	define pt	wl_pt
#	define fl	wl_fl
#	define db	wl_db
#	define ld	wl_ld
#	define CHB	WL_CHB
#	define SCB	WL_SCB
#	define SHB	WL_SHB
#	define INB	WL_INB
#	define LOB	WL_LOB
#	define LLB	WL_LLB
#	define I8B	WL_I8B
#	define I16B	WL_I16B
#	define I32B	WL_I32B
#	define I64B	WL_I64B
#	define IMB	WL_IMB
#	define UCB	WL_UCB
#	define USB	WL_USB
#	define UIB	WL_UIB
#	define ULB	WL_ULB
#	define ULLB	WL_ULLB
#	define U8B	WL_U8B
#	define U16B	WL_U16B
#	define U32B	WL_U32B
#	define U64B	WL_U64B
#	define UMB	WL_UMB
#	define PTB	WL_PTB
#	define CHN	WL_CHN
#	define SCN	WL_SCN
#	define SHN	WL_SHN
#	define INN	WL_INN
#	define LON	WL_LON
#	define LLN	WL_LLN
#	define I8N	WL_I8N
#	define I16N	WL_I16N
#	define I32N	WL_I32N
#	define I64N	WL_I64N
#	define IMN	WL_IMN
#	define UCN	WL_UCN
#	define USN	WL_USN
#	define UIN	WL_UIN
#	define ULN	WL_ULN
#	define ULLN	WL_ULLN
#	define U8N	WL_U8N
#	define U16N	WL_U16N
#	define U32N	WL_U32N
#	define U64N	WL_U64N
#	define UMN	WL_UMN
#	define PTN	WL_PTN
#	define CHX	WL_CHX
#	define SCX	WL_SCX
#	define SHX	WL_SHX
#	define INX	WL_INX
#	define LOX	WL_LOX
#	define LLX	WL_LLX
#	define I8X	WL_I8X
#	define I16X	WL_I16X
#	define I32X	WL_I32X
#	define I64X	WL_I64X
#	define IMX	WL_IMX
#	define UCX	WL_UCX
#	define USX	WL_USX
#	define UIX	WL_UIX
#	define ULX	WL_ULX
#	define ULLX	WL_ULLX
#	define U8X	WL_U8X
#	define U16X	WL_U16X
#	define U32X	WL_U32X
#	define U64X	WL_U64X
#	define UMX	WL_UMX
#	define PTX	WL_PTX
#	define BLB	WL_BLB
#	ifndef FALSE
#		define FALSE WL_FALSE
#	endif
#	ifndef TRUE
#		define TRUE WL_TRUE
#	endif
#	ifndef NULL
#		define NULL WL_NULL
#	endif
#endif

/*
 * Type support checking
 */
#if		defined(WL_LG_CPP)

#	ifndef WL_TYPE_VOID
#		define WL_TYPE_VOID				1
#	endif	
#	ifndef WL_TYPE_BOOL
#		define WL_TYPE_BOOL				1
#	endif

#	if WL_LG_C>=WL_VR_C11
		/* Long long type support check */
#		ifndef WL_TYPE_LONG_LONG
#			define WL_TYPE_LONG_LONG	1
#		endif
#	endif

#elif	defined(WL_LG_C)

#	if WL_LG_C>=WL_VR_ANSI
		/* Void type support check */
#		ifndef WL_TYPE_VOID
#			define WL_TYPE_VOID			1
#		endif
#	endif

#	if WL_LG_C>=WL_VR_C99
		/* Long long type support check */
#		ifndef WL_TYPE_LONG_LONG
#			define WL_TYPE_LONG_LONG	1
#		endif
		/* _Bool type support check */
#		ifndef WL_TYPE__BOOL
#			define WL_TYPE__BOOL		1
#		endif
#	endif

#endif

/****************************
 *	1.5. Type width macros	*
 ****************************/
/*  If were allowed to use <limits.h>, define CHB through CHAR_BIT */
#if defined(WL_USE_LIMITS)

#	include <limits.h>

/* Char bits */
#	ifndef CHB 
#		define CHB CHAR_BIT
#	endif
#	ifndef SCB 
#		define CHB CHAR_BIT
#	endif
#	ifndef UCB 
#		define CHB CHAR_BIT
#	endif

#	if WL_LG_C >= WL_VR_C23
	/* To be done */
#	endif

#endif

/* If we are not, or, we're working with a pre-C23 standard, define through
 * data models
 */
#if !(defined(WL_USE_LIMITS) && WL_LG_C>=WL_VR_C23)

#	if WL_DM==WL_DM_SILP64
		/* [SHB] */
#		ifndef WL_SHB
#			define WL_SHB	64
#		endif
		/* [USB] */
#		ifndef WL_USB
#			define WL_USB	64
#		endif
#	endif

#	if WL_DM>=WL_DM_ILP64
		/* [INB] */
#		ifndef WL_INB
#			define WL_INB	64
#		endif
		/* [UIB] */
#		ifndef WL_UIB
#			define WL_UIB	64
#		endif
#	endif

#	if WL_DM>=WL_DM_LP64
		/* [LOB] */
#		ifndef WL_LOB
#			define WL_LOB	64
#		endif
		/* [ULB] */
#		ifndef WL_ULB
#			define WL_ULB	64
#		endif
#	endif

#	if WL_DM>=WL_DM_LLP64
		/* [LLB] */
#		ifndef WL_LLB
#			define WL_LLB	64
#		endif
		/* [ULLB] */
#		ifndef WL_ULLB
#			define WL_ULLB	64
#		endif
		/* [PTB] */
#		ifndef WL_PTB
#			define WL_PTB	64
#		endif
#	endif

#	if WL_DM>=WL_DM_ILP32
		/* [INB] */
#		ifndef WL_INB
#			define WL_INB	32
#		endif
		/* [UIB] */
#		ifndef WL_UIB
#			define WL_UIB	32
#		endif
#	endif

#	if WL_DM>=WL_DM_LP32

		/* [CHB] */
#		ifndef WL_CHB
#			define WL_CHB	8
#		endif
		/* [SCB] */
#		ifndef WL_SCB
#			define WL_SCB	8
#		endif
		/* [UCB] */
#		ifndef WL_UCB
#			define WL_UCB	8
#		endif
		/* [SHB] */
#		ifndef WL_SHB
#			define WL_SHB	16
#		endif
		/* [USB] */
#		ifndef WL_USB
#			define WL_USB	16
#		endif
		/* [INB] */
#		ifndef WL_INB
#			define WL_INB	16
#		endif
		/* [UIB] */
#		ifndef WL_UIB
#			define WL_UIB	16
#		endif
		/* [LOB] */
#		ifndef WL_LOB
#			define WL_LOB	32
#		endif
		/* [ULB] */
#		ifndef WL_ULB
#			define WL_ULB	32
#		endif
		/* [LLB] */
#		ifndef WL_LLB
#			define WL_LLB	32
#		endif
		/* [ULLB] */
#		ifndef WL_ULLB
#			define WL_ULLB	32
#		endif
		/* [PTB] */
#		ifndef WL_PTB
#			define WL_PTB	32
#		endif
#	endif

#endif

/* [BLB] 
 * Always 8-bits of most systems
 */
#ifndef WL_BLB
#	define WL_BLB	8
#endif
/* [I8B] */
#ifndef WL_I8B
#	define WL_I8B	8
#endif
/* [I16B] */
#ifndef WL_I16B
#	define WL_I16B	16
#endif
/* [I32B] */
#ifndef WL_I32B
#	define WL_I32B	32
#endif
/* [I64B] */
#ifndef WL_I64B
	/* In LP32, ILP32 and LLP32 (without `long long` type availible),
	 * `wl_U64` and `wl_I64` will be 32-bits
	 */
#	if	WL_DM<=WL_DM_ILP32 || (!WL_TYPE_LONG_LONG && WL_DM==WL_DM_LLP32)
#		define WL_I64B	32
#	else
#		define WL_I64B	64
#	endif
#endif
/* [U8B] */
#ifndef WL_U8B
#	define WL_U8B	WL_I8B
#endif
/* [U16B] */
#ifndef WL_U16B
#	define WL_U16B	WL_I16B
#endif
/* [U32B] */
#ifndef WL_U32B
#	define WL_U32B	WL_I32B
#endif
/* [U64B] */
#ifndef WL_U64B
#	define WL_U64B	WL_I64B
#endif

/****************************
 *	1.5. Type width macros	*
 ****************************/
/* [U8N] */
#ifndef WL_U8N
#	define WL_U8N	((wl_U8)0)
#endif
/* [U16N] */
#ifndef WL_U16N
#	define WL_U16N	((wl_U16)0)
#endif
/* [U32N] */
#ifndef WL_U32N
#	define WL_U32N	((wl_U32)0)
#endif
/* [U64N] */
#ifndef WL_U64N
#	define WL_U64N	((wl_U64)0)
#endif
/* [U8X] */
#ifndef WL_U8X
#	define WL_U8X	((wl_U8)0xFF)
#endif
/* [U16X] */
#ifndef WL_U16X
#	define WL_U16X	((wl_U16)0xFFFF)
#endif
/* [U32X] */
#ifndef WL_U32X
#	define WL_U32X	((wl_U32)0xFFFFFFFF)
#endif
/* [U64X] */
#ifndef WL_U64X
#	if	WL_U64B==32
#		define WL_U64X	((wl_U64)0xFFFFFFFF)
#	else
#		define WL_U64X	((wl_U64)0xFFFFFFFFFFFFFFFF)
#	endif
#endif

/* [I8N] */
#ifndef WL_I8N
#	define WL_I8N	((wl_I8)-0x80)
#endif
/* [I16N] */
#ifndef WL_I16N
#	define WL_I16N	((wl_I16)-0x8000)
#endif
/* [I32N] */
#ifndef WL_I32N
#	define WL_I32N	((wl_I32)-0x80000000)
#endif
/* [I64N] */
#ifndef WL_I64N
#	if	WL_I64B==32
#		define WL_I64N	((wl_I64)-0x80000000)
#	else
#		define WL_I64N	((wl_I64)-0x8000000000000000)
#	endif
#endif
/* [I8X] */
#ifndef WL_I8X
#	define WL_I8X	((wl_U8)0x7F)
#endif
/* [I16X] */
#ifndef WL_I16X
#	define WL_I16X	((wl_U16)0x7FFF)
#endif
/* [I32X] */
#ifndef WL_I32X
#	define WL_I32X	((wl_U32)0x7FFFFFFF)
#endif
/* [I64X] */
#ifndef WL_I64N
#	if	WL_I64B==32
#		define WL_I64N	((wl_I64)0x7FFFFFFF)
#	else
#		define WL_I64N	((wl_I64)0x7FFFFFFFFFFFFFFF)
#	endif
#endif

/* [UCN] */
#ifndef WL_UCN
#	define WL_UCN	((unsigned char)0)
#endif
/* [USN] */
#ifndef WL_USN
#	define WL_USN	((unsigned short)0)
#endif
/* [UIN] */
#ifndef WL_UIN
#	define WL_UIN	((unsigned int)0)
#endif
/* [ULN] */
#ifndef WL_ULN
#	define WL_ULN	((unsigned long)0)
#endif
/* [ULLN] */
#ifndef WL_ULLN
#	if TYPE_LONG_LONG
#		define WL_ULLN	((unsigned long long)0)
#	else
#		define WL_ULLN	((unsigned long)0)
#	endif
#endif
/* [UCX] */
#ifndef WL_UCX
#	define WL_UCX	((unsigned char)WL_U8X)
#endif
/* [USX] */
#ifndef WL_USX
#	define WL_USX	((unsigned short)WL_U16X)
#endif
/* [UIX] */
#ifndef WL_UIX
#	if WL_UIB==16
#		define WL_UIX	((unsigned int)WL_U16X)
#	elif WL_UIB>=32
#		define WL_UIX	((unsigned int)WL_U32X)
#	endif
#endif
/* [ULX] */
#ifndef WL_ULX
#	if WL_ULB==32
#		define WL_ULX	((unsigned int)WL_U32X)
#	else
#		define WL_ULX	((unsigned int)WL_U64X)
#	endif
#endif
/* [ULLX] */
#ifndef WL_ULLX
#	if WL_ULLB==32
#		define WL_ULX	((unsigned int)WL_U32X)
#	else
#		define WL_ULX	((unsigned int)WL_U64X)
#	endif
#endif

/* [SCN] */
#ifndef WL_SCN
#	define WL_SCN	((signed char)WL_I8N)
#endif
/* [SHN] */
#ifndef WL_SHN
#	define WL_SHN	((short)WL_I16N)
#endif
/* [INN] */
#ifndef WL_INN
#	if WL_INB==16
#		define WL_INN	((unsigned int)WL_I16N)
#	elif WL_INB>=32
#		define WL_INN	((unsigned int)WL_I32N)
#	endif
#endif
/* [LON] */
#ifndef WL_LON
#	if WL_LOB==32
#		define WL_LON	((unsigned int)WL_I32N)
#	else
#		define WL_LON	((unsigned int)WL_I64N)
#	endif
#endif
/* [LLN] */
#ifndef WL_LLN
#	if WL_LLB==32
#		define WL_LLN	((unsigned int)WL_I32N)
#	else
#		define WL_LLN	((unsigned int)WL_I64N)
#	endif
#endif
/* [SCX] */
#ifndef WL_SCX
#	define WL_SCX	((signed char)WL_I8X)
#endif
/* [SHX] */
#ifndef WL_SHX
#	define WL_SHX	((short)WL_I16X)
#endif
/* [IXX] */
#ifndef WL_IXX
#	if WL_IXB==16
#		define WL_IXX	((unsigned int)WL_I16X)
#	elif WL_IXB>=32
#		define WL_IXX	((unsigned int)WL_I32X)
#	endif
#endif
/* [LOX] */
#ifndef WL_LOX
#	if WL_LOB==32
#		define WL_LOX	((unsigned int)WL_I32X)
#	else
#		define WL_LOX	((unsigned int)WL_I64X)
#	endif
#endif
/* [LLX] */
#ifndef WL_LLX
#	if WL_LLB==32
#		define WL_LLX	((unsigned int)WL_I32X)
#	else
#		define WL_LLX	((unsigned int)WL_I64X)
#	endif
#endif

/* [IMax] */
#ifndef WL_IMB
#	define WL_IMB	WL_I64B
#endif
#ifndef WL_IMN
#	define WL_IMN	WL_I64N
#endif
#ifndef WL_IMX
#	define WL_IMX	WL_I64X
#endif
/* [UMax] */
#ifndef WL_UMB
#	define WL_UMB	WL_U64B
#endif
#ifndef WL_UMN
#	define WL_UMN	WL_U64N
#endif
#ifndef WL_UMX
#	define WL_UMX	WL_U64X
#endif

/* [TRUE] */
#ifndef WL_TRUE
#	define WL_TRUE	1
#endif
/* [FALSE] */
#ifndef WL_FALSE
#	define WL_FALSE	0
#endif
/* [NULL] */
#ifndef WL_NULL
#	define WL_NULL	((void*)0)
#endif



/***
 *      _____                              
 *     |_   _|  _   _   _ __     ___   ___ 
 *       | |   | | | | | '_ \   / _ \ / __|
 *       | |   | |_| | | |_) | |  __/ \__ \
 *       |_|    \__, | | .__/   \___| |___/
 *              |___/  |_|                 
 */

/************************************
 *	1.1. Fixed-size integer types	*
 ************************************/
/* "Alternatively, `WL_USE_STDINT` macro can be defined with any non-zero 
 * value ..."
 */
#if (WL_LG_C>=WL_VR_C99 || defined(WL_LG_CPP)) && WL_USE_STDINT
	typedef 	int8_t				wl_I8,		wl_i8;
	typedef 	int16_t				wl_I16,		wl_i16;
	typedef 	int32_t				wl_I32,		wl_i32;
	typedef 	int64_t				wl_I64,		wl_i64;
	typedef 	uint8_t				wl_U8,		wl_u8;
	typedef 	uint16_t			wl_U16,		wl_u16;
	typedef 	uint32_t			wl_U32,		wl_u32;
	typedef 	uint64_t			wl_U64,		wl_u64;
#else
	/* [I8 & U8]
	* All data models define char as a byte.
	*/
	typedef		signed char			wl_I8, wl_i8;
	typedef		unsigned char		wl_U8, wl_u8;
	/* [I16 & U16]
	* In all data models `short` is 16-bits, except SILP64. On SILP64 there are 
	* no 16-bit type, but we will still define it as `short` as it is big enough
	* to store 16-bits.
	*/
	typedef 	short				wl_I16, wl_i16;
	typedef 	unsigned short		wl_U16, wl_u16;
	/* [I32 & U32]
	 * `int` in LP32 is 16-bit, so it does suit us. We will use long instead.
	 */
#	if WL_DM == WL_DM_LP32
		typedef	long				wl_I32,		wl_i32;
		typedef	unsigned long		wl_U32,		wl_u32;
#	else
		typedef	int					wl_I32,		wl_i32;
		typedef	unsigned int		wl_U32,		wl_u32;
#	endif
	/* [I64 & U64]
	 * `long` in LP32, LLP64, ILP32 is 32-bit, so it does suit us. We will 
	 * use `long long` instead, if supported 
	 */
#	if	(WL_DM==WL_DM_LP32 || WL_DM==WL_DM_LLP64 || WL_DM == WL_DM_ILP32) \
		&& WL_TYPE_LONG_LONG
		typedef	long long			wl_I64,		wl_i64;
		typedef	unsigned long long	wl_U64,		wl_u64;
#	else
		typedef	long				wl_I64,		wl_i64;
		typedef	unsigned long		wl_U64,		wl_u64;
#	endif
#endif

/************************
 *	1.2. Special types	*
 ***********************/
/* "Alternatively, `USE_STDINT` macro can be defined with any non-zero 
 * value ..."
 */
#if (WL_LG_C>=WL_VR_C99 || defined(WL_LG_CPP)) && USE_STDINT
	typedef 	uintptr_t			wl_Pt,		wl_Pt;
	typedef 	intmax_t			wl_IMax,	wl_imax;
	typedef 	uintmax_t			wl_UMax,	wl_umax;
#else
	typedef		wl_I64				wl_IMax,	wl_imax;
	typedef		wl_U64				wl_UMax,	wl_umax;
	/* Pointer type always has the same width as the widest data type */
	typedef 	wl_UMax				wl_Pt, wl_pt;
#endif

/********************************
 *	1.3. Compatibility types	*
 ********************************/
#if !defined(WL_LG_CPP)		/* If C */
/* Void */
#	if WL_LG_C<=WL_VR_K_R_C	/* K&R C */
		typedef	char				wl_Vo,		wl_vo;
#	else					/* Standard C */
		typedef	void				wl_Vo,		wl_vo;
#	endif
/* Boolean */
#	if WL_TYPE__BOOL		/* C99+ */
		typedef	_Bool				wl_Bl,		wl_bl;
#	else					/* Pre-C99 */
		typedef	char				wl_Bl,		wl_bl;
#	endif
#else						/* If C++ */
		typedef	void				wl_Vo,		wl_vo;
		typedef	bool				wl_Bl,		wl_bl;
#endif

/************************
 *	1.4. Alias types	*
 ************************/
typedef			char				wl_Ch,		wl_ch;
typedef			float				wl_Fl,		wl_fl;
typedef			double				wl_Db,		wl_db;
typedef			long double			wl_Ld,		wl_ld;



#endif
