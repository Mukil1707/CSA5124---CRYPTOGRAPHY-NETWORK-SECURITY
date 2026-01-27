#include <stdio.h>
int power(int a, int b, int m)
{
	int r = 1;
	for(int i = 1; i <= b; i++)
    	r = (r * a) % m;
	return r;
}
int main()
{
	int p = 23, q = 11, g = 2;
	int x = 3;             	
	int y;                 	
	int h = 9;             	
	int k = 6;
	int r, s;
	y = power(g, x, p);
	r = power(g, k, p) % q;
	s = (h + x * r) % q;
    printf("Public Key y = %d\n", y);
    printf("Signature (r, s) = (%d, %d)\n", r, s);
	int v = (power(g, h, p) * power(y, r, p)) % p % q;
	if(v == r)
        printf("Signature Verified\n");
	else
        printf("Signature Not Verified\n");
	return 0;
}
