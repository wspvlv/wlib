#ifndef WC_ARRAY_H
#define WC_ARRAY_H



#include <wc/core.h>
#include <wc/types.h>



#if !WL_PREFIX
#	define ano			wl_ano
#	define aas			wl_aas
#	define ant			wl_ant
#	define anot			wl_anot
#	define aor			wl_aor
#	define aan			wl_aan
#	define aand			wl_aand
#	define axr			wl_axr
#	define axor			wl_axor
#	define anr			wl_anr
#	define anor			wl_anor
#	define ann			wl_ann
#	define anand		wl_anand
#	define anx			wl_anx
#	define anxor		wl_anxor

#	define anol			wl_anol
#	define antl			wl_antl
#	define anotl		wl_anotl
#	define aorl			wl_aorl
#	define aanl			wl_aanl
#	define aandl		wl_aandl
#	define axrl			wl_axrl
#	define axorl		wl_axorl
#	define anrl			wl_anrl
#	define anorl		wl_anorl
#	define annl			wl_annl
#	define anandl		wl_anandl
#	define anxl			wl_anxl
#	define anxorl		wl_anxorl

#	define aeq			wl_aeq
#	define anq			wl_anq

#	define ASF_OFFSET	WL_ASF_OFFSET
#	define ASF_NORMAL	WL_ASF_NORMAL
#	define ASF_REVERSED	WL_ASF_REVERSED
#	define ASF_PTRDIFF	WL_ASF_PTRDIFF
#	define ASF_COUNT	WL_ASF_COUNT

#	define Af			wl_Af
#	define As			wl_As
#	define Asf			wl_Asf

#	define afa			wl_afa
#	define afb			wl_afb
#	define afl			wl_afl
#	define asb			wl_asb
#	define asa			wl_asa

#	if	WL_ALIASES
#		define acompl	wl_acompl
#	endif
#endif

#if	WL_ALIASES
#	define wl_acompl	wl_ant
#endif



#define AFADECL1(NAME)	const void* NAME(const void* _a, const void* b, As size)
#define AFADECL2(NAME)	const void* NAME(const void* _a, const void* b, const void* c, As size)

#if	WL_OPTIMIZE_SPEED != 2
	/*
	*	ARRAY BITWISE FUNCTIONS
	*/
	/* Array Bitwise No Operation [r = a] */
#	define wl_ano(r,a,size)			wl_afa((r),	(a),	WL_NULL,	WL_AF_NO,			(size))
	
	/* Array Bitwise NOT [a = ~b] */
#	define wl_ant(r,a,size)			wl_afa((r),	(a),	WL_NULL,	WL_AF_NT,			(size))
	
	/* Array Bitwise OR [r = a|b] */
#	define wl_aor(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_OR,			(size))
	
	/* Array Bitwise AND [r = a&b] */
#	define wl_aan(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_AN,			(size))
	
	/* Array Bitwise XOR [r = a^b] */
#	define wl_axr(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_XR,			(size))

	/* Array Bitwise NOR [r = ~(a|b)] */
#	define wl_anr(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_NR,			(size))

	/* Array Bitwise NAND [r = ~(a&b)] */
#	define wl_ann(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_NN,			(size))

	/* Array Bitwise NXOR [r = ~(a^b)] */
#	define wl_anx(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_AF_NX,			(size))
#endif

#define wl_anos(r,a,size)		wl_afa((r),	(a),	WL_NULL,	WL_I8N|WL_AF_NO,	(size))
#define wl_ants(r,a,size)		wl_afa((r),	(a),	WL_NULL,	WL_I8N|WL_AF_NT,	(size))
#define wl_aors(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_OR,	(size))
#define wl_aans(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_AN,	(size))
#define wl_axrs(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_XR,	(size))
#define wl_anrs(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_NR,	(size))
#define wl_anns(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_NN,	(size))
#define wl_anxs(r,a,b,size)		wl_afa((r),	(a),	(b),		WL_I8N|WL_AF_NX,	(size))

/* Array Assign [a = b] */
#define wl_aas					wl_ano
#define wl_aass					wl_anos
/* Array Copy & Paste */
#define wl_acp					wl_aass

/* Aliases */
#define wl_anot					wl_ant
#define wl_aand					wl_aan
#define wl_axor					wl_axr
#define wl_anand				wl_ann
#define wl_anor					wl_anr
#define wl_anxor				wl_anx
#define wl_anots				wl_ants
#define wl_aands				wl_aans
#define wl_axors				wl_axrs
#define wl_anands				wl_anns
#define wl_anors				wl_anrs
#define wl_anxors				wl_anxs

/*
 *	ARRAY LOGICAL FUNCTIONS
 */
/* Array Logical No Operation [!!a] or [(Bl)a] */
#define wl_anol(a,size)		wl_afb(a,WL_NULL,size,WL_FALSE)
/* Array Logical NOT [!a] */
#define wl_antl(a,size)		wl_afb(a,WL_NULL,size,WL_TRUE)
/* Array Logical OR [a||b] */
#define wl_aorl(a,b,size)	(wl_anol(a,size)	||	wl_anol(b,size))
/* Array Logical AND [a||b] */
#define wl_aanl(a,b,size)	(wl_anol(a,size)	&&	wl_anol(b,size))
#define wl_aandl			wl_aanl
/* Array Logical XOR */
#define wl_axrl(a,b,size)	(wl_anol(a,size)	^	wl_anol(b,size))
#define wl_axorl			wl_axrl
/* Array Logical NOR */
#define wl_anrl(a,b,size)	(wl_antl(a,size)	&&	wl_antl(b,size))
#define wl_anorl			wl_anrl
/* Array Logical NAND */
#define wl_annl(a,b,size)	(wl_antl(a,size)	||	wl_antl(b,size))
#define wl_anandl			wl_annl
/* Array Logical NXOR */
#define wl_anxl(a,b,size)	(wl_anol(a,size)	^	wl_antl(b,size))
#define wl_anxorl			wl_anxl



/*
 *	ARRAY COMPARISON FUNCTIONS
 */
#if WL_OPTIMIZE_SIZE == 2
/* Array Equal [a==b] */
#define wl_aeq(a,b,size)	wl_antl(wl_axr(NULL,	(a),	(b),	(size)	), (size))
/* Array Not Equal [a!=b] */
#define wl_anq(a,b,size)	wl_anol(wl_axr(NULL,	(a),	(b),	(size)	), (size))
#else
/* Array Equal [a==b] */
#define wl_aeq(a,b,size)	wl_afb(a,b,size,WL_FALSE)
/* Array Not Equal [a!=b] */
#define wl_anq(a,b,size)	wl_afb(a,b,size,WL_TRUE)
#endif



/* Array Functions */
ENUM(wl_Af) {
	WL_AF_NO = 0,	/**< Bitwise no operation */
	WL_AF_NT = 1,	/**< Bitwise NOT */
	WL_AF_AN = 2,	/**< Bitwise AND */
	WL_AF_NN = 3,	/**< Bitwise NAND */
	WL_AF_OR = 4,	/**< Bitwise OR */
	WL_AF_NR = 5,	/**< Bitwise NOR */
	WL_AF_XR = 6,	/**< Bitwise XOR */
	WL_AF_NX = 7	/**< Bitwise NXOR */
};
/* Search Flags */
ENUM(wl_Asf) {
	WL_ASF_OFFSET = 0,		/**< Return the offset from base pointer */
	WL_ASF_NORMAL = 0,		/**< Searching from beginning to end */
	WL_ASF_REVERSED = 1,	/**< Searching from end to beggining */
	WL_ASF_PTRDIFF = 2,		/**< Return pointer difference from the base pointer */
	WL_ASF_COUNT = 4		/**< Return the count of occurrences */
};


/* The maximal size of the array that array functions support. */
typedef	wl_U16	wl_As;
/* 8-bits is enough */
typedef wl_U8	wl_Af, wl_Asf;


#if WL_OPTIMIZE_SPEED == 2
	EXTERN AFADECL1(wl_ano);
	EXTERN AFADECL1(wl_ant);
	EXTERN AFADECL2(wl_aan);
	EXTERN AFADECL2(wl_aor);
	EXTERN AFADECL2(wl_axr);
	EXTERN AFADECL2(wl_ann);
	EXTERN AFADECL2(wl_anr);
	EXTERN AFADECL2(wl_anx);
#endif

/* Array Function Assign */
EXTERN const void* wl_afa(
	const void* a, 
	const void* restrict const b,
	const void* restrict const c,
	const wl_Af func,
	const wl_As size
);

/* Array Function Boolean */
EXTERN wl_Bl wl_afb(const void* a, const void* b, wl_As size, wl_Bl mode);

/* Array Fill */
EXTERN const void* wl_afl(
	const void* restrict const a,
	const wl_As sa,
	const void* restrict const b,
	const wl_As sb
);

/* Array Search Byte */
EXTERN wl_Pt wl_asb(
	const void* restrict const	a,
	wl_As						sa,
	const char					b,
	const wl_Asf				flags
);

/* Array Search Array */
EXTERN wl_Pt wl_asa(
	const void* restrict const	_a,
	wl_As						sa,
	const void*					b,
	wl_As						sb,
	const wl_Asf				flags
);



#endif
