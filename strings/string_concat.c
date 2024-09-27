#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Concatenate strings using while loop
/*char *while_scat(char *str2, char *str1)
{
	while (*(++str1));
	
	while (*(str1++) = *(str2++));
	
	return str1;
}*/

// Concatenate strings using pointers

int main(int argc, char **argv)
{
	char str1[MAX], str2[MAX];
    char * s1 = str1;
    char * s2 = str2;

    /* Input two strings from user */
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    /* Move till the end of str1 */
    while(*(++s1));

    /* Copy str2 to str1 */
    while(*(s1++) = *(s2++));

    printf("Concatenated string = %s", str1);

    return 0;
}

