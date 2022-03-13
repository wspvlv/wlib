#ifndef WL_CHAR_H
#define WL_CHAR_H



/***
 *      __  __                                     
 *     |  \/  |   __ _    ___   _ __    ___    ___ 
 *     | |\/| |  / _` |  / __| | '__|  / _ \  / __|
 *     | |  | | | (_| | | (__  | |    | (_) | \__ \
 *     |_|  |_|  \__,_|  \___| |_|     \___/  |___/
 *                                                 
 */
#if !WL_PREFIX
#	define NUL		WL_NUL
#	define SOH		WL_SOH
#	define STX		WL_STX
#	define ETX		WL_ETX
#	define EOT		WL_EOT
#	define ENQ		WL_ENQ
#	define ACK		WL_ACK
#	define BEL		WL_BEL
#	define BS		WL_BS
#	define HT		WL_HT
#	define LF		WL_LF
#	define VT		WL_VT
#	define FF		WL_FF
#	define CR		WL_CR
#	define SO		WL_SO
#	define SI		WL_SI
#	define DLE		WL_DLE
#	define DC1		WL_DC1
#	define DC2		WL_DC2
#	define DC3		WL_DC3
#	define DC4		WL_DC4
#	define NAK		WL_NAK
#	define SYN		WL_SYN
#	define ETB		WL_ETB
#	define CAN		WL_CAN
#	define EM		WL_EM
#	define SUB		WL_SUB
#	define ESC		WL_ESC
#	define FS		WL_FS
#	define GS		WL_GS
#	define RS		WL_RS
#	define US		WL_US
#	define DEL		WL_DEL
#	define cilc		wl_cilc
#	define cius		wl_cius
#	define cic		wl_cic
#	define cid		wl_cid
#	define cis		wl_cis
#	define ciw		wl_ciw
#	define cie		wl_cie
#	define cia		wl_cia
#	define cil		wl_cil
#	define c2l		wl_c2l
#	define c2u		wl_c2u
#	define c2d		wl_c2d
#	define d2c		wl_d2c
#endif

/*********************
 * Control Character *
 *********************/
/**
 * \def		WL_NUL
 * \brief	Null (x00)
 */
#define WL_NUL	'\000'
/**
 * \def		WL_SOH
 * \brief	Start of Heading (x01)
 */
#define WL_SOH	'\001'
/**
 * \def		WL_STX
 * \brief	Start of Text (x02)
 */
#define WL_STX	'\002'
/**
 * \def		WL_ETX
 * \brief	End of Text (x03)
 */
#define WL_ETX	'\003'
/**
 * \def		WL_EOT
 * \brief	End of Transmission (x04)
 */
#define WL_EOT	'\004'
/**
 * \def		WL_ENQ
 * \brief	Enquiry (x05)
 */
#define WL_ENQ	'\005'
/**
 * \def		WL_ACK
 * \brief	Acknowledge (x06)
 */
#define WL_ACK	'\006'
/**
 * \def		WL_BEL
 * \brief	Bell (x07)
 */
#define WL_BEL	'\007'
/**
 * \def		WL_BS
 * \brief	Backspace (x08)
 */
#define WL_BS	'\010'
/**
 * \def		WL_HT
 * \brief	Horizontal Tabulation (x09)
 */
#define WL_HT	'\011'
/**
 * \def		WL_LF
 * \brief	New Line (x0A)
 */
#define WL_LF	'\012'
/**
 * \def		WL_VT
 * \brief	Vertical Tabulation (x0B)
 */
#define WL_VT	'\013'
/**
 * \def		WL_FF
 * \brief	Form Feed (x0C)
 */
#define WL_FF	'\014'
/**
 * \def		WL_CR
 * \brief	Carriage Return (x0D)
 */
#define WL_CR	'\015'
/**
 * \def		WL_SO
 * \brief	Shift Out (x0E)
 */
#define WL_SO	'\016'
/**
 * \def		WL_SI
 * \brief	Shift In (x0F)
 */
#define WL_SI	'\017'
/**
 * \def		WL_DLE
 * \brief	Data Link Escape (x10)
 */
#define WL_DLE	'\020'
/**
 * \def		WL_DC1
 * \brief	Device Control 1 (x11)
 */
#define WL_DC1	'\021'
/**
 * \def		WL_DC2
 * \brief	Device Control 2 (x12)
 */
#define WL_DC2	'\021'
/**
 * \def		WL_DC3
 * \brief	Device Control 3 (x13)
 */
#define WL_DC3	'\021'
/**
 * \def		WL_DC4
 * \brief	Device Control 4 (x14)
 */
#define WL_DC4	'\021'
/**
 * \def		WL_NAK
 * \brief	Negative Acknowledge (x15)
 */
#define WL_NAK	'\025'
/**
 * \def		WL_SYN
 * \brief	Synchronous Idle (x16)
 */
#define WL_SYN	'\026'
/**
 * \def		WL_ETB
 * \brief	End of Transmission Block (x17)
 */
#define WL_ETB	'\027'
/**
 * \def		WL_CAN
 * \brief	Cancel (x18)
 */
#define WL_CAN	'\030'
/**
 * \def		WL_EM
 * \brief	End of Medium (x19)
 */
#define WL_EM	'\031'
/**
 * \def		WL_SUB
 * \brief	Substitute (x1A)
 */
#define WL_SUB	'\032'
/**
 * \def		WL_ESC
 * \brief	Escape (x1B)
 */
#define WL_ESC	'\033'
/**
 * \def		WL_FS
 * \brief	File Separator (x1C)
 */
#define WL_FS	'\034'
/**
 * \def		WL_GS
 * \brief	Group Separator (x1D)
 */
#define WL_GS	'\035'
/**
 * \def		WL_RS
 * \brief	Record Separator (x1E)
 */
#define WL_RS	'\036'
/**
 * \def		WL_US
 * \brief	Unit Separator (x1F)
 */
#define WL_US	'\037'
/**
 * \def		WL_DEL
 * \brief	Delete (x7F)
 */
#define WL_DEL	'\177'

/*************
 * Functions *
 *************/
/**
 * \brief	Is Lowercase Letter
 * \def		wl_cill(a)
 * \param	a	character
 * \return	True, if character is a lowercase letter, false, otherwise
 */
#define wl_cill(a) ((a) >= 'a' && (a) <= 'z')					/* Is Lowercase Character	*/
/**
 * \brief	Is Uppercase Letter
 * \def		wl_ciul(a)
 * \param	a	character
 * \return	True, if character is an uppercase letter, false otherwise
 */
#define wl_ciul(a) ((a) >= 'A' && (a) <= 'Z')					/* Is Uppercase Character	*/
/**
 * \brief	Is Contol Character
 * \def		wl_cic(a)
 * \param	a	character
 * \return	True, if character is a control character, false otherwise
 */
#define wl_cic(a) ((a) < ' ' || (a) == WL_DEL)					/* Is Contol Character		*/
/**
 * \brief	Is Digit Character
 * \def		wl_cid(a)
 * \param	a	character
 * \return	True, if character is a decimal digit character, false otherwise
 */
#define wl_cid(a) ((a) >= '0' && (a) <= '9')					/* Is Digit Character		*/
/**
 * \brief	Is Symbol Character
 * \def		wl_cis(a)
 * \param	a	character
 * \return	True, if character is a symbol character, false otherwise
 */
#define wl_cis(a)												/* Is Symbol Character		*/\
	((a) >= '!' && (a) <= '/' || (a) >= ':' && (a) <= '@' || (a) >= '[' && (a) <= '`' || (a) >= '{' && (a) <= '~')
/**
 * \brief	Is Whitespace Character
 * \def		wl_ciw(a)
 * \param	a	character
 * \return	True, if character is a whitespace character, false otherwise
 */
#define wl_ciw(a) ((a) >= WL_HT && (a) <= WL_CR || (a) == ' ')	/* Is Whitespace Character	*/
/**
 * \brief	Is Ext. ASCII Character
 * \def		wl_cie(a)
 * \param	a	character
 * \return	True, if character from extended character set, false otherwise
 */
#define wl_cie(a) ((a) > WL_DEL)								/* Is Ext. ASCII Character	*/
/**
 * \brief	Is Alphanumeric Character
 * \def		wl_cia(a)
 * \param	a	character
 * \return	True, if character is an alphanumeric character, false otherwise
 */
#define wl_cia(a) (wl_cil(a) || wl_cid(a))						/* Is Alphanumeric Character*/
/**
 * \brief	Is Letter Character
 * \def		wl_cil(a)
 * \param	a	character
 * \return	True, if character is a letter, false otherwise
 */
#define wl_cil(a) (wl_cill(a) || wl_ciul(a))					/* Is Letter Character		*/
/**
 * \brief	Character To Lowercase
 * \def		wl_c2l(a)
 * \param	a	character
 * \return	\a a or its modified value
 * If the character is uppercase, changes its case and returns it, otherwise returns \a
 */
#define wl_c2l(a) ((a) - wl_ciul(a)*32)
/**
 * \brief	Character To Uppercase
 * \def		wl_c2u(a)
 * \param	a	character
 * \return	\a a or its modified value
 * If the character is lowercase, changes its case and returns it, otherwise returns \a
 */
#define wl_c2u(a) ((a) + wl_cill(a)*32)
/**
 * \def		wl_c2d(chr, base)
 * \brief	char to wl_Digit
 * \param	x		Digit
 * \return	wl_Digit
 * Converts a charcter representing a digit to a digit
 * If result exceeds the base, character 255 is returned
 * Table (0—95):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 *                             ↑ ↑
 *                         SPACE DEL
 */
#define wl_c2d(x) 	(								\
		(x)	+ 62*((wl_U8)(x)==' ')					\
			- 32*((wl_U8)(x)==127)					\
			+ 96*((wl_U8)(x)<' ')					\
			+ 29*((wl_U8)(x)<'0'&&(wl_U8)(x)>=' ')	\
			- 48*((wl_U8)(x)<':'&&(wl_U8)(x)>='0')	\
			+ 19*((wl_U8)(x)<'A'&&(wl_U8)(x)>=':')	\
			- 55*((wl_U8)(x)<'['&&(wl_U8)(x)>='A')	\
			- 7	*((wl_U8)(x)<'a'&&(wl_U8)(x)>='[')	\
			- 61*((wl_U8)(x)<'{'&&(wl_U8)(x)>='a')	\
			- 33*((wl_U8)(x)<127&&(wl_U8)(x)>='{')	\
	)
/**
 * \def		wl_d2c(chr, base)
 * \brief	wl_Digit to char
 * \param	x		Digit
 * \return	char
 * Converts a digit to charcter representing a digit
 * If result exceeds the base, character 255 is returned
 * Table (0—95):
 * 0 1 2 3 4 5 6 7 8 9 A B C D E F
 * G H I J K L M N O P Q R S T U V
 * W X Y Z a b c d e f g h i j k l
 * m n o p q r s t u v w x y z ! "
 * # $ % & ' ( ) * + , - . / : ; <
 * = > ? @ [ \ ] ^ _ ` { | } ~   
 *                             ↑ ↑
 *                         SPACE DEL
 */
#define wl_d2c(x) (									\
		(x)	- 62*((wl_U8)(x)==94)					\
			+ 32*((wl_U8)(x)==95)					\
			- 96*((wl_U8)(x)>96&&(wl_U8)(x)<=127)	\
			- 29*((wl_U8)(x)<=76&&(wl_U8)(x)>=62)	\
			+ 48*((wl_U8)(x)<=9&&(wl_U8)(x)>=0)		\
			- 19*((wl_U8)(x)<83&&(wl_U8)(x)>=77)	\
			+ 55*((wl_U8)(x)<=35&&(wl_U8)(x)>=10)	\
			+ 7	*((wl_U8)(x)<89&&(wl_U8)(x)>=84)	\
			+ 61*((wl_U8)(x)<61&&(wl_U8)(x)>=36)	\
			+ 33*((wl_U8)(x)<93&&(wl_U8)(x)>=90)	\
	)


#endif
