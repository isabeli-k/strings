#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define MAXSIZE (1024 * 1024)

// Function using for loop
inline char *for_scopy (char *str, char *string)
{	
	for (int i = 0; string[i] != '\0'; i++)
	{
		str[i] = string[i];
	}
	
	str = '\0';
	
	return str;
}

// Function using while loop
inline char *while_scopy (char *str, char *string)
{
	while (*string != '\0')
	{
		*str = *string;
		string++;
		str++;
	}
	
	*str = '\0';
	
	return str;
}

// Function using pointers
inline char *ptr_scopy (char *str, char *string)
{
	char *tmp = str;
	while ( (*str++ = *string++) );
	
	return tmp;
}

size_t ptr_slength(char *string) {
	char *str;
	for (str = string; *str++ != '\0'; );
	return str - string - 1;
}

size_t istrlen (char *str)
{
	typedef uint32_t IP;
	IP *istr = (IP *) str;
	IP *istart = istr;

	for (; ; istr++) {
		#if 1
		IP mask = 0xff;
		for (int i = 0; i < sizeof(IP); i++) {
			if ((*istr & mask) == 0) {
				return (istr - istart) * sizeof(IP) + i;
			}
			mask <<= 8;
		}
		#else
		for (int i = 0; i < sizeof(IP); i++) {
			if ( (*istr & (0xff << (i << 3))) == 0 ) {
				return (istr - istart) * sizeof(IP) + i;
			}
		}
		#endif
	}

	puts("we never get here");
	return 0;
}


#if 0
char *istrcpy (char *dest, const char *src)
{
	typedef uint32_t IP;
	IP *isrc = (IP *) src;
	IP *idest = (IP *) dest;

	for (; ; idest++, isrc++) {
		
		// Check the 4 chars held in *isrc
		IP mask = 0xff;
		for (int i = 0; i < sizeof(IP); i++) {
			if ((*isrc & mask) == 0) {
				#if 0
				#else
				dest = (char *) idest;
				src = (char *) isrc;
				while (i--) {
					*dest++ = *src++;
				}
				#endif

				return dest;
			}
			mask <<= 8;
		}
		// None of the 4 chars in *isrc are '\0'
		*idest = *isrc;
	}

	puts("we never get here");
	return NULL;
}
#else
char *istrcpy (char *dest, const char *src)
{
	typedef uint32_t IP;
	IP *isrc = (IP *) src;
	IP *idest = (IP *) dest;
	
	for (; ; idest++, isrc++) {
		
		// Check the 4 chars held in *isrc
		IP mask = 0xff;
		for (int i = 0; i < sizeof(IP); i++) {
			if ((*isrc & mask) == 0) {
				#if 0
				#else
				dest = (char *) idest;
				src = (char *) isrc;
				while (i--) {
					*dest++ = *src++;
				}
				#endif

				return dest;
			}
			mask <<= 8;
		}
		// None of the 4 chars in *isrc are '\0'
		*idest = *isrc;
	}

	puts("we never get here");
	return NULL;
}
#endif
// 12 34 37 79  12 34 37 79   55 00 37 79

// Function using pointers
inline char *OLDptr_scopy (char *dest, char *src)
{
	size_t len = istrlen(src);
	memcpy(dest, src, len);
	
	return dest;
}

int main(int argc, char **argv)
{
	#define SECONDS	(1 * CLOCKS_PER_SEC)
	char *text = calloc(MAXSIZE + 1, sizeof(char));
	memset (text, 'i', MAXSIZE);
	text[MAXSIZE] = '\0';
	
	char *text_copy = calloc(MAXSIZE + 1, sizeof(char));
	
	printf("%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
		istrlen("a"), istrlen("ab"), istrlen("abc"), istrlen("abcd"),
		istrlen("abcde"), istrlen("abcdef"), istrlen("abcdefg"), istrlen("abcdefgh"),
		istrlen("123456789"), istrlen("1234567890"), istrlen("12345678901"), istrlen("123456789012")
	);

	clock_t end_time;
	long loops;

	#if 0
	long len;
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		len = strlen(text);
		loops++;
	}
	printf("strlen Loops: %ld len: %ld\n", loops, len);

	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		len = istrlen(text);
		loops++;
	}
	printf("istrlen Loops: %ld len: %ld\n", loops, len);

	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		len = ptr_slength(text);
		loops++;
	}
	printf("ptr_slength Loops: %ld len: %ld\n", loops, len);
	exit(0);
	#endif 
	
	/*
	while (clock() <= end_time)
	{
		for_scopy(text_copy, text);
		loops++;
	}
	
	printf("Num of loops - for: %ld\n", loops);
	
	len = strlen(text_copy);
	printf ("Length: %ld\n", len);
	
	end_time = clock() + (3 * CLOCKS_PER_SEC), len = 0, loops = 0;
	
	while (clock() <= end_time)
	{
		while_scopy(text_copy, text);
		loops++;
	}
	
	printf("Num of loops - while: %ld\n", loops);
	
	len = strlen(text_copy);
	printf ("Length: %ld\n", len);

	*/

	end_time = clock() + SECONDS, loops = 0;
	while (clock() <= end_time)
	{
		ptr_scopy(text_copy, text);
		loops++;
	}
	printf("ptr_scopy loops %ld len %ld strcmp %d\n", loops, strlen(text_copy), strcmp(text_copy, text));

	end_time = clock() + SECONDS, loops = 0;
	while (clock() <= end_time)
	{
		istrcpy(text_copy, text);
		loops++;
	}
	printf("istrcpy loops %ld len %ld strcmp %d\n", loops, strlen(text_copy), strcmp(text_copy, text));
	
	end_time = clock() + SECONDS, loops = 0;
	while (clock() <= end_time)
	{
		strcpy (text_copy, text);
		loops++;
	}
	printf("strcpy loops %ld len %ld strcmp %d\n", loops, strlen(text_copy), strcmp(text_copy, text));
	
	return 0;
}

