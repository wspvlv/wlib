#include <wc/array.h>
#include <wc/error.h>



#if UMB>=64
/* Value of `UMax`, where all individual bytes are `0x01` */
#	define _LOW		0x0101010101010101
/* Value of `UMax`, where all individual bytes are `0x80` */
#	define _HIGH	0x8080808080808080
#else
/* Value of `UMax`, where all individual bytes are `0x01` */
#	define _LOW		0x01010101
/* Value of `UMax`, where all individual bytes are `0x08` */
#	define _HIGH	0x80808080
#endif
/* Whether there's a byte that has a value of `0x00` */
#define _HASZERO(X)  (((X)-_LOW) & ~(X) & _HIGH)



/**
 * \brief 
 * 
 * \param a 
 * \param sa 
 * \param b 
 * \param flags 
 * \return Pt 
 */
Pt asb(
	const void* restrict const	a,
	As							sa,
	const char					b,
	const Asf					flags
) {
	/* If `a` is not NULL and `sa` > 0 */
	if (a) {
		const char* p = (const char*)((Pt)a + (sa-1)*(flags&WL_ASF_REVERSED) );

#		if WL_OPTIMIZE_SIZE >= 1
			const char m = b*_LOW;
#		endif

		/* If size is set, search for the needle(s) until the search flag 
		 * condition is met or size != 0 
		 */
		if (sa) {
			/* If WL_ASF_COUNT is set */
			if (flags&WL_ASF_COUNT) {
				As c = 0;	/* Counter */
#				if !WL_ASB_SIMPLE
#					if WL_OPTIMIZE_SIZE == 0
						const char m = b*_LOW;
#					endif
					/* Do match finding until `c` is at the next alignment */
					for (; (Pt)p&(sizeof(UMax)-1) && sa; p++, sa--) {
						if (*(char*)p == b) c++;
					}

					for (; sa>=sizeof(UMax); ) {
						if (_HASZERO(*p^m)) {
							const char* const q = p+8;
							for (; p<q; p++, sa--) {
								if (*p==b) c++;
							}
						}
						else {
							p+=sizeof(UMax);
							sa-=sizeof(UMax);
						}
					}
#				endif
				/* Loops until a match is found or we are at the beggining of 
				* the array
				*/
				for (; sa && *p != b; p++, sa--);

				return c;
			}

			/* If WL_ASF_REVERSED is set */
			if (flags&WL_ASF_REVERSED) {
#				if !WL_ASB_SIMPLE
					/* Do match finding until `c` is at the previous alignment */
					for (; (Pt)p&(sizeof(UMax)-1) && sa && *(char*)p != b; p--, 
					sa--);
					/* If there still bytes remaining and the next byte isn't a 
					* match 
					*/
					if (sa && *p != b) {
#						if WL_OPTIMIZE_SIZE == 0
							const char m = b*_LOW;
#						endif
						/* Now that `a` is aligned. We check the value of the size
						* of alignment for the presence of a byte that has a `b`
						* character. If there isn't one, increment `a` to the 
						* next alignment, if there is one or more, go to the next
						* step.
						*/
						for (p-=sizeof(UMax); !_HASZERO(*p^m) && sa>=sizeof(UMax); 
						p-=sizeof(UMax), sa-=sizeof(UMax));
					}
					/* Now we do know that there is a matching byte somewhere in 
					* this alignment, check each byte in it, if it's a match, 
					* return.
					*/
#				endif
				/* Loops until a match is found or we are at the beggining of 
				* the array
				*/
				for (; sa && *p != b; p--, sa--);
			}
			/* Else WL_ASF_NORMAL is set */
			else {
#				if !WL_ASB_SIMPLE
					/* Do match finding until `c` is at the next alignment */
					for (; (Pt)p&(sizeof(UMax)-1) && sa && *(char*)p != b; p++, 
					sa--);
					/* If there still bytes remaining and the next byte isn't a 
					* match 
					*/
					if (sa && *p != b) {
#						if WL_OPTIMIZE_SIZE == 0
							const char m = b*_LOW;
#						endif
						/* Now that `a` is aligned. We check the value of the size
						* of alignment for the presence of a byte that has a `b`
						* character. If there isn't one, increment `a` to the 
						* next alignment, if there is one or more, go to the next
						* step.
						*/
						for (; !_HASZERO(*p^m) && sa>=sizeof(UMax); 
						p+=sizeof(UMax), sa-=sizeof(UMax));
					}
					/* Now we do know that there is a matching byte somewhere in 
					* this alignment, check each byte in it, if it's a match, 
					* return.
					*/
#				endif
				/* Loops until a match is found or we are at the beggining of 
				* the array
				*/
				for (; sa && *p != b; p++, sa--);
			}

			/* Returns the address where or the offset at which (depending on 
			* the WL_ASB_PTRDIFF flag) a match was found, or returns NULL if
			* we looped through the entire array and didn't find any matches
			*/
			return (Pt)p - (Pt)a*!!(flags&WL_ASF_PTRDIFF);
		}

		/* If size was not set, search for the needle until a match is found.
		 * Here flags WL_ASF_REVERSE and WL_ASF_COUNT, are inapplicable
		 */
		if (!(flags&(WL_ASF_REVERSED|WL_ASF_COUNT))) {
#			if !WL_ASB_SIMPLE
				for (; (Pt)p&(sizeof(UMax)-1) && *(char*)p != b; p++);
				if (*p != b) {
#					if WL_OPTIMIZE_SIZE == 0
						const char m = b*_LOW;
#					endif
					for (; !_HASZERO(*p^m); p+=sizeof(UMax) );
				}
#			endif
				for (; *p != b; p++);

			/* Returns the address where or the offset at which (depending on 
			* the WL_ASB_PTRDIFF flag) a match was found, or returns NULL if
			* we looped through the entire array and didn't find any matches
			*/
			return (Pt)p - (Pt)a*!!(flags&WL_ASF_PTRDIFF);
		}



	}
	/* Error checkin' */
	err(afl,ERNULL);
	return 0;
}
