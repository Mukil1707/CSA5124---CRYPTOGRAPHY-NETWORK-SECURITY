#include <stdio.h>
#include <string.h>
void encrypt(char msg[], int key) {
	for(int i = 0; i < strlen(msg); i++)
    	msg[i] += key;
}
void decrypt(char msg[], int key) {
	for(int i = 0; i < strlen(msg); i++)
    	msg[i] -= key;
}
int simpleHash(char msg[]) {
	int sum = 0;
	for(int i = 0; i < strlen(msg); i++)
    	sum += msg[i];
	return sum;
}
int main() {
	char message[100];
	int key = 3;
	printf("Enter message: ");
	fgets(message, sizeof(message), stdin);
	message[strcspn(message, "\n")] = '\0';
	int signature = simpleHash(message);  
	encrypt(message, key);            	
    printf("\nEncrypted Message: %s", message);
    printf("\nSignature: %d\n", signature);
	decrypt(message, key);            	
    printf("Decrypted Message: %s\n", message);
    if(simpleHash(message) == signature)
        printf("Signature Verified!\n");
	else
        printf("Signature Verification Failed!\n");
	return 0;
}
