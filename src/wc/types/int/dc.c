#include <wc/types/char.h>
#include <wc/types/int.h>

/**
 * \fn		char dc(const Digit x, const U8 base)
 * \brief	Digit to Char
 * \param	x		Digit
 * \param	base	base
 * \return	char
 * Converts a number into a character representation of a digit
 * If `x` exceeds the base, character DEL is returned
 * Table (0--96):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 * The last two characters are SPACE and DEL respectively
 */
char dc(const Dg x, const U8 base) {
	/* This code executes the chunk of code commented out below, but three times faster */
	if (x>base)	return DEL;
	else if(x == 94) return ' ';
	else if(x == 95) return DEL;
	else return
		x 
		+ '0' 
		+ (x>9)		* ('0'-'A'-10) 
		+ (x>35)	* ('A'-'a'-36)
		+ (x>61)	* ('a'-'!'-62)
		+ (x>76)	* ('!'-':'-77)
		+ (x>83)	* (':'-'['-84)
		+ (x>89)	* ('['-'{'-90)
		+ (x>95)	* ('{'-161-96)
		+ (x>190)	* (161-191)
		+ (x>223)	* (128);
	
	/*if (x > base)	return DEL;
	if (x <= 9)		return x+'0';
	if (x <= 35)	return x-10+'A';
	if (x <= 61)	return x-36+'a';
	if (x <= 76)	return x-62+'!';
	if (x <= 83)	return x-77+':';
	if (x <= 89)	return x-84+'[';
	if (x <  94)	return x-90+'{';
	if (x == 94)	return ' ';
	if (x == 95)	return DEL;
	if (x <= 190)	return x-96+161;
	if (x <= 223)	return x-191;
	else			return x-191+128;*/
}