#include <wc/types/int.h>
#include <wc/math/mathi.h>

/**
 * @fn			Digit dgl(const I64 x, const U8 n, const U8 base)
 * @brief 		Get the nth digit
 * @param x		The number
 * @param n		The digit number
 * @param base 	The base
 * @return Digit	
 */
Digit dgl(const I64 x, const U8 n, const U8 base) {
	return abl( x / pwq(base,n) % base );
}