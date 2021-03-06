#ifndef WC_TYPES_H
#define WC_TYPES_H

/* Include data model information*/
#include <wc/sys/damo.h>
#include <wc/sys/lang.h>

#if !defined(DATA_MODEL)
#define DATA_MODEL DM_NULL
#endif

#if		defined(LG_C)	/* Follows ISO C standard */

#if LG_C >= VR_C99

#ifndef DEF__BOOL
#define DEF__BOOL		1
#endif


#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	1
#endif

#endif	/* LG_C >= VR_C99 */

#ifndef DEF_VOID
#define DEF_VOID		1
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		0
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif

#elif	defined(LG_CPP)	/* Follows ISO C++ standard */

#if LG_CPP >= VR_CPP11
#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	1
#endif
#endif

#ifndef DEF_VOID
#define DEF_VOID		1
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		1
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif

#else					/* Follows another standard */

#ifndef DEF_VOID
#define DEF_VOID		0
#endif

#ifndef DEF_BOOL
#define DEF_BOOL		0
#endif

#ifndef DEF__BOOL
#define DEF__BOOL		0
#endif

#ifndef DEF_LONG_LONG
#define DEF_LONG_LONG	0
#endif
#endif

/* Fixed-size integer types */
typedef char				ch, Ch, CH;

#ifndef NO_FIXED_TYPES

#if	DATA_MODEL == DM_LP32
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef long				i32,	I32;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned long		u32,	U32;
typedef U32					_Ptr;			/* Pointer type (experimental)	*/

#define CHB	8
#define SHB	16
#define INB	16
#define LOB 32
#define PTB	32								/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_ILP32
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef U32					_Ptr;			/* Pointer type (experimental)	*/

#define CHB	8
#define SHB	16
#define INB	32
#define LOB 32
#define PTB	32								/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_LLP64
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef U64					_Ptr;			/* Pointer type (experimental) */

#define CHB	8
#define SHB	16
#define INB	32
#define PTB	64								/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_LP64
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef long				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned long		u64,	U64;
typedef U64					_Ptr;			/* Pointer type (experimental) */

#define CHB	8
#define SHB	16
#define INB	32
#define LOB 64
#define PTB	64								/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_ILP64
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef int					i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned int		u64,	U64;
typedef U64					_Ptr;			/* Pointer type (experimental) */

#define CHB	8
#define SHB	16
#define INB	64
#define LOB 64
#define PTB	64								/* Pointer size (experimental) */

#elif	DATA_MODEL == DM_SILP64
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef short				i32,	I32;
typedef short				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned short		u32,	U32;
typedef unsigned short		u64,	U64;
typedef U64					_Ptr;			/* Pointer type (experimental) */

#define CHB	8
#define SHB	64
#define INB	64
#define LOB 64
#define PTB	64								/* Pointer size (experimental) */

#else
typedef signed char			i8,		I8;
typedef short				i16,	I16;
typedef int					i32,	I32;
typedef long				i64,	I64;
typedef unsigned char		u8,		U8;
typedef unsigned short		u16,	U16;
typedef unsigned int		u32,	U32;
typedef unsigned long		u64,	U64;
typedef U64					_Ptr;			/* Pointer type (experimental) */

#define CHB	8
#define SHB	16
#define INB	32
#define LOB 64
#define PTB	64								/* Pointer size (experimental) */

#endif

#endif /* Fixed-size integer types */


/* Void type */
#if DEF_VOID == 1
typedef void				vo, VO;
#else
typedef char				vo, VO;
#endif /* Void type */

/* Boolean type */
#if		DEF_BOOL == 1
typedef bool				bl, BL;
#elif	DEF__BOOL == 1
typedef _Bool				bl, BL;
#else
typedef char				bl, BL;
#endif /* Boolean type */

/* Long long integer type */
#if		DEF_LONG_LONG == 1

#if		(DATA_MODEL == DM_LP32) || (DATA_MODEL == DM_ILP32)
#define NO_I64 0
typedef long long			i64, I64;
typedef unsigned long long	u64, U64;
#endif

#else	/* Long long integer type */

#if		(DATA_MODEL == DM_LLP64)
typedef long long			i64, I64;
typedef unsigned long long	u64, U64;
#endif

#endif	/* Long long integer type */

/* Floating point types */
typedef float				f32, F32;
typedef double				f64, F64;

/* Limits and sizes */

#define	I8B		8
#define	I16B	16
#define	I32B	32

#define I8N		(I8)	0x80
#define I16N	(I16)	0x8000
#define I32N	(I32)	0x80000000

#define I8X		(I8)	0x7F
#define I16X	(I16)	0x7FFF
#define I32X	(I32)	0x7FFFFFFF

#define U8N		(U8)	0
#define U16N	(U16)	0
#define U32N	(U32)	0

#define U8X		(U8)	0xFF
#define U16X	(U16)	0xFFFF
#define U32X	(U32)	0xFFFFFFFF

#if NO_I64	/* Abnormal behavior */
#define I64B	32
#define I64N	(I64)	0x80000000
#define I64X	(I64)	0x7FFFFFFF
#define U64N	(U64)	0
#define U64X	(U64)	0xFFFFFFFF
#else		/* Optimal behavior */
#define I64B	64
#define I64N	(I64)	0x8000000000000000
#define I64X	(I64)	0x7FFFFFFFFFFFFFFF
#define U64N	(U64)	0
#define U64X	(U64)	0xFFFFFFFFFFFFFFFF
#endif		/* NO_I64 */

#endif