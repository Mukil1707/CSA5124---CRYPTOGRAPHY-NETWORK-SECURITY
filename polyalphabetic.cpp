#include <stdio.h>
#include <string.h>
int main() {
	char text[100], key[100];
	int i;
 
	printf("Enter plaintext (UPPERCASE): ");
    scanf("%s", text);
	printf("Enter key (UPPERCASE): ");
    scanf("%s", key);
    printf("Encrypted text: ");
	for (i = 0; text[i] != '\0'; i++) {
    	char c = ((text[i] - 'A') + (key[i % strlen(key)] - 'A')) % 26 + 'A';
        printf("%c", c);
	}
	return 0;
}
