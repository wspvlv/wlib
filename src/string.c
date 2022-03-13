#include <wc/string.h>



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
 * \brief	String length
 * \fn		Sl sl(const char* restrict const s)
 * \param	s	Pointer to string
 * \return	Sl
 */
Sl sl(const char* restrict const s) {
		/* 1. Creates a variable which will store the pointer to a character of 
		* string `s`. The parameter `s` is preserved, in order to calculate
		* the difference in bytes between `s` and `a` at return point.
		*/
		const char* a=s;

#	ifndef WL_SL_SIMPLE
		/* 2. Check, whether pointer `a` is 4-byte (in x86) or 8-byte (in x86-64)
		* aligned, if not, check the character `a` points to for a NUL character
		* if it's NUL, return `a`-`s`, otherwise, increment `a` and repeat this
		* step until `a` is aligned.
		*/
		for (; (Pt)a % sizeof(UMB); a++) if (!a) return a-s;

		/* 3. Now that `a` is aligned. We check the value of the size of alignment
		* for the presence of a byte that has a NUL character. If there isn't
		* one, increment `a` to the next alignment, if there is one or more, go
		* to the next step.
		*/
		for (; !_HASZERO(*(UMax*)a); a += sizeof(UMB)) {}; /* Braces here to 
		suppress "this ‘for’ clause does not guard..." */


		/* 4. Now we do know that, that there is a NUL character somewhere in this
		* alignment, check each character, if it's NUL, return there difference
		* between `s` and `a` &mdash; this is our string length.
		*/
#		if defined(__OPTIMIZE_SIZE__) || defined(PREFER_SIZE_OVER_SPEED)
			for (; *a; a++);
			return a-s;
#		else
#			if UMB >= 64
				if(!a[0]) return a-s;
				if(!a[1]) return a-s+1;
				if(!a[2]) return a-s+2;
				if(!a[3]) return a-s+3;
				if(!a[4]) return a-s+4;
				if(!a[5]) return a-s+5;
				if(!a[6]) return a-s+6;
				return a-s+7;
#			else
				if(!a[0]) return a-s;
				if(!a[1]) return a-s+1;
				if(!a[2]) return a-s+2;
				return a-s+3;
#			endif
#		endif
#	else
		/* A simple lazy implimentation */
		for (; *a; a++);
		return a-s;
#	endif
}
