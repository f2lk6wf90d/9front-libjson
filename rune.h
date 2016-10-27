typedef unsigned int Rune;	/* 32 bits */

typedef unsigned char		uchar;
typedef unsigned short	ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;


enum
{
	UTFmax		= 4,		/* maximum bytes per rune */
	Runesync	= 0x80,		/* cannot represent part of a UTF sequence (<) */
	Runeself	= 0x80,		/* rune and UTF sequences are the same (<) */
	Runeerror	= 0xFFFD,	/* decoding error in UTF */
	Runemax = 0x10FFFF	/* maximum rune value */
};

int chartorune(Rune *rune, char *str);
int runetochar(char *str, Rune *rune);
