#include <stdio.h>
#include <stdlib.h>


int getValue() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t' && c != '\r' && c != '\v' && c != '\f')				
			return c;

	}
	return EOF;
}

typedef struct {
	char *data;
	unsigned int len;
	unsigned int cap;
}SString;

void alterChar(SString *cur, int ch, int isQuoted){
	while (ch != EOF) {

		if (isQuoted && ch == '"') break;
		if (!isQuoted && (ch == ' ' || ch == '\n' || ch == '\t' || 
                          ch == '\r' || ch == '\v' || ch == '\f')) break;

		if (cur->len == cur->cap){
			cur->cap *= 2;
			cur->data = realloc(cur->data, cur->cap * sizeof(char));
		}
		cur->data[cur->len++] = ch;
		ch = getchar();
	}
}

int main () {
	
	SString strings[4];
	for (int i = 0; i < 4; i++) {
		strings[i].cap = 4;
		strings[i].len = 0;
		strings[i].data = malloc(4 * sizeof(char));
	}
	
	int cmd;

	while ((cmd = getValue()) != EOF) {
		
		if (cmd == 'q') break;

		if (cmd == 'c') {

		int targetValue = getValue() - 'a';
		int firstEle = getValue() - 'a';
		int secondEle = getValue() - 'a';
		
		unsigned newLen = strings[firstEle].len + strings[secondEle].len;
		unsigned newCap = strings[targetValue].cap;
		while (newCap < newLen) newCap *= 2;
	
		char *newData = malloc(newCap * sizeof(char));

		for (int i=0; i < strings[firstEle].len; i++) {
			newData[i] = strings[firstEle].data[i];
		}
		for (int i=0; i < strings[secondEle].len; i++) {
			newData[strings[firstEle].len + i] = strings[secondEle].data[i];
		}
		
		free (strings[targetValue].data);
		strings[targetValue].data = newData;
		strings[targetValue].len = newLen;
		strings[targetValue].cap = newCap;

		} else {
			int index = getValue() - 'a';
			SString *cur = &strings[index];
				
			if (cmd == 'r' || cmd == 'a'){
				if (cmd == 'r') cur->len = 0;
				int ch = getValue();

				if (ch == '"') {
					alterChar(cur, getchar(), 1);					
				}else{
					alterChar(cur, ch, 0);
				}
				
			} 
			else if (cmd == 'p'){
				for (int i=0; i < cur->len; i++) {
					printf("%c", cur->data[i]);
				}
				printf("\n");
			}
			else if (cmd == 'd'){
				printf("String: \"");
				for (int i=0; i < cur->len; i++) {
					printf("%c", cur->data[i]);
				}
				printf("\"\nLength: %u\nCapacity: %u\n", cur->len, cur->cap);
			}

		}
	}
	for (int i = 0; i < 4; i++) {
		free(strings[i].data);
	}
	return 0;
}
