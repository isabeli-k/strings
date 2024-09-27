#include <stdio.h>
#include <string.h>
#include <time.h>

int str_cmp (char *str1, char *str2)
{
	int i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			break;
		
		i++;
	}
	return str1[i] - str2[i];
}

int strptr_cmp (char *str1, char *str2)
{
	while ((*str1 && *str2) && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main(int argc, char **argv)
{
	#define SECONDS	(1 * CLOCKS_PER_SEC)
	
	char *str1 = "Camello";
	char *str2 = "Camello";
	
	clock_t end_time;
	long loops;
	
	int str_cmp_result = 0;
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		str_cmp_result = str_cmp(str1, str2);
		loops++;
	}
	printf ("Str_cmp_result: %ld loops.\n", loops);
	printf ("Str_cmp_result: %d.\n", str_cmp_result);
	
	int strptr_cmp_result = 0;
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		strptr_cmp_result = strptr_cmp(str1, str2);
		loops++;
	}
	printf ("Strptr_cmp_result: %ld loops.\n", loops);	
	printf ("Strptr_cmp_result: %d.\n", strptr_cmp_result);	
	
	int strcmp_result = 0;
	for (loops = 0, end_time = clock() + SECONDS; clock() <= end_time; loops++)
	{
		strcmp_result = strcmp(str1, str2);
		loops++;
	}
	printf ("Strcmp_result: %ld loops.\n", loops);
	printf ("Strcmp_result: %d.\n", strcmp_result);
	
	return 0;
}

