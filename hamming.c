#include <stdio.h>

unsigned int stringToInt(const char *s) {

        unsigned int sum = 0;
        while (*s >= '0' && *s <= '9'){
                sum = sum * 10 + (*s - '0');
                s++;
        }
        return sum;
}

int length (unsigned int n, unsigned int base) {

	int counter = 0;	

	if (n == 0) return 1;

	while (n > 0) {
		n /= base;
		counter++; 
	}
	
	return counter; 
}

int main (int argc, char *argv[]) {

	if (argc != 4) return 1;

	unsigned int first = stringToInt(argv[1]);
	unsigned int second = stringToInt(argv[2]);
	unsigned int base = stringToInt(argv[3]);
	
	int count = 0;

	int x = length(first, base);	
	int y = length(second, base);

	int diff = (x > y) ? y : x;
	int larger = (x > y) ? x : y;
		
	for (int i=0; i < diff; i++) {
		
		unsigned int digit = first % base;
		unsigned int digit2 = second % base;
 
		if (digit != digit2) {
			count++;
		}
		
		first /= base;
		second /= base;
	
	}
	
	printf("%d\n", count + larger - diff);
	return 0;
}
