#include <stdio.h>
#include <string.h>
#include <time.h>

#define SECONDS	(1 * CLOCKS_PER_SEC)

/*char *istrstr (char *str, const char *substr)
{
	typedef uint32_t IP;
	IP *isrc = (IP *) src;
	IP *isubstr = (IP *) substr;
	
	for (; ; isrc++) {
		
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
}*/

char *str_str(const char *str, const char *substr)
{
	const char *a = str, *b = substr;
	
	for ( ; ; )
	{
		if ( !*b )
			return (char *) str;
		if ( !*a )
			return NULL;
		if (*a++ != *b++) {
			a = ++str;
			b = substr;
		}
	}
	
	return NULL;
}

char *strstr1(const char *str, const char *substring)
{
  const char *a, *b = substring;

  if ( !*b ) return (char *) str;
  for ( ; *str ; str++) {
    if (*str != *b) continue;
    a = str;
    for (;;) {
      if ( !*b ) return (char *) str;
      if (*a++ != *b++) break;
    }
    b = substring;
  }
  return NULL;
}

char *string_str(const char *str, const char *substr)
{
	size_t len_str, len_substr;
	
	len_substr = strlen(substr);
	if (!len_substr)
		return (char *)str;
	
	len_str = strlen(str);
	while (len_str >= len_substr) {
		len_str--;
		if (!memcmp(str, substr, len_substr)) {
			return (char *)str;
		}
		str++;
	}
	
	return NULL;
}

int main(int argc, char **argv)
{
	const char *original = "He knows and understans people's concerns and will work to"
					 " achieve a fairer, greener Stroud that works for everyone.";
					 
	const char *needle = "greener";
	char *result;
	
	clock_t end_time;
	long loops;

	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		result = string_str(original, needle);
		loops++;
	}
	
	if (result != NULL) {
		printf ("Substring found.\n");
	} else {
		printf ("Substring not found.\n");
	}
	printf("string_str Loops: %ld\n", loops);
	
	
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		result = strstr(original, needle);
		loops++;
	}
	
	if (result != NULL) {
		printf ("Substring found.\n");
	} else {
		printf ("Substring not found.\n");
	}
	printf("strstr Loops: %ld\n", loops);
	
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		result = str_str(original, needle);
		loops++;
	}
	
	if (result != NULL) {
		printf ("Substring found.\n");
	} else {
		printf ("Substring not found.\n");
	}
	printf("str_str Loops: %ld\n", loops);
	
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		result = strstr1(original, needle);
		loops++;
	}
	
	if (result != NULL) {
		printf ("Substring found.\n");
	} else {
		printf ("Substring not found.\n");
	}
	printf("strstr1 Loops: %ld\n", loops);
		
	return 0;
}

