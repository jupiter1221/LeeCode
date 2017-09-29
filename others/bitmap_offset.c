#include <stdio.h>
unsigned int bitmap[4];

void set_btimatp(int offset) {
   char *bits = (char *)bitmap;
   printf("bits = 0x%p, &bitmap = %p\n",bits,bitmap);
   int byte_off = offset/8;
   int bits_off = offset%8;
   printf("offset = %d, byte_off = %d, bits_off = %d\n",offset,byte_off,bits_off);
   *(bits + byte_off) = *(bits + byte_off) | (1 << bits_off);
}
void printf_bitmap() {
	int i = 0;
	for(i = 0; i < 4; i++) 
		printf(" %u ",bitmap[i]);		
	printf(" \n");		
}
int main(void) {
	int input = 0;
	printf("input offset:");
	scanf("%d",&input);
	printf_bitmap();
	set_btimatp(input);
	printf_bitmap();
}

