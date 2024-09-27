#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char to_upper (char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	
	return c;
}

int main(int argc, char **argv)
{
	char test = 'a';
	
	char test2 = to_upper(test);
	
	printf ("Test: %c\n", test2);
	
	char *string = "Camello";
	printf ("String: %s\n", string);
	
	char *upper_string;
	int length = strlen(string);
	upper_string = (char*)malloc ((length + 1) * sizeof(char));

	if (string[7] == '\0') printf("Yes!\n");
	
	int i;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (islower(string[i]))
		{
			upper_string[i] = to_upper(string[i]);			
			printf ("String: %c\n", upper_string[i]);
		}
	}
	if (upper_string[7] == '\0') printf("Yes!\n");
	
	int len = strlen(upper_string);
	printf ("Length: %d\n", len);
	
	return 0;
}

