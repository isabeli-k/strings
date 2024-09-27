#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXSIZE 101

// Find string length using for loop
int for_slength(char *string) {
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		count++;
	}
	return count;
}

// Find string length using while loop

int while_slength(char *string) {
	int count = 0;
	while (*string != '\0') {
		count++;
		string++;
	}
	return count;
}

// Find string length using pointers
int ptr_slength(char *string) {
	char *str;
	for (str = string; *str != '\0'; str++);
	return str - string;
}

int main(int argc, char **argv)
{
	char text[MAXSIZE] = {0};
	
	printf ("Enter string: ");
	fgets(text, MAXSIZE, stdin);
	
	time_t begin, end;
	time(&begin);
	
	for (int i = 0; i < 100000000; i++) {
		for_slength(text);
	}
	
	printf ("For loop: %d\n", for_slength(text));
	
	time(&end);
	time_t elapsed = end - begin;
	printf ("Time measured for loop: %ld seconds.\n", elapsed);
	
	begin = 0, end = 0, elapsed = 0;
	time(&begin);
	
	for (int i = 0; i < 100000000; i++) {
		while_slength(text);
	}
	printf ("While loop: %d\n", while_slength(text));
	
	time(&end);
	elapsed = end - begin;
	printf ("Time measured while loop: %ld seconds.\n", elapsed);
	
	begin = 0, end = 0, elapsed = 0;
	time(&begin);
	
	for (int i = 0; i < 100000000; i++) {
		ptr_slength(text);
	}
	printf ("Pointers: %d\n", ptr_slength(text));
	
	time(&end);
	elapsed = end - begin;
	printf ("Time measured pointers: %ld seconds.\n", elapsed);
	
	begin = 0, end = 0, elapsed = 0;
	time(&begin);
	int len = 0;
	
	for (int i = 0; i < 100000000; i++) {
		len = strlen(text);
	}
	printf ("Strlen: %d\n", len);
	
	time(&end);
	elapsed = end - begin;
	printf ("Time measured strlen: %ld seconds.\n", elapsed);
	
	return 0;
}

