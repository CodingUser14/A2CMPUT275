#include <stdio.h>
#include <stdlib.h>



typedef struct {

	unsigned int pixelR;
	unsigned int pixelG;
	unsigned int pixelB;

}pixel;

void doFlip(unsigned int h,unsigned int w, pixel *matrix) {

    	for (unsigned int i = 0; i < h; i++) {
        	for (unsigned int j = 0; j < w / 2; j++) {
            		pixel temp = matrix[i * w + j];
            		matrix[i * w + j] = matrix[i * w + (w - 1 - j)];
            		matrix[i * w + (w - 1 - j)] = temp;
        	}
    	}
}

void doSepia(unsigned int h,unsigned int w, pixel *matrix, unsigned int m) {
	
	for (unsigned int i=0; i < h; i++){
		for (unsigned int j=0; j < w; j++){
			unsigned int R = matrix[i * w + j].pixelR; 
			unsigned int G = matrix[i * w + j].pixelG;
			unsigned int B = matrix[i * w + j].pixelB;

			unsigned int newR = (unsigned int)(R * 0.393 + G * 0.769 + B * 0.189);
			unsigned int newG = (unsigned int)(R * 0.349 + G * 0.686 + B * 0.168);
			unsigned int newB = (unsigned int)(R * 0.272 + G * 0.534 + B * 0.131);

			if (newR > m) newR = m;
			if (newG > m) newG = m;
			if (newB > m) newB = m;
			
			matrix[i * w + j].pixelR = newR;
			matrix[i * w + j].pixelG = newG;
			matrix[i * w + j].pixelB = newB;
		}
	}	
}

void doPrint(unsigned int h,unsigned int w, pixel *matrix,unsigned int m) {
	printf("P3\n%u %u\n%u\n", w, h, m);

	for (unsigned int i=0; i < h; i++){
		for (unsigned int j=0; j < w; j++){
			printf("%u %u %u", matrix[i * w + j].pixelR, matrix[i * w + j].pixelG, matrix[i * w + j].pixelB);
			if (j != w - 1) printf(" ");	
		}
	printf("\n");
	}
}

int main (int argc, char *argv[]) {

	char lineOne[3];
	unsigned int width, height, maxColor; 

	//Acquire heading values
	scanf("%2s", lineOne);
	scanf("%u %u", &width, &height);
	scanf("%u", &maxColor);
	

	if (lineOne[0] != 'P' || lineOne[1] != '3') return 1; 

	pixel *matrix = malloc(height * width * sizeof(pixel));
	if (!matrix) return 1;
	for (unsigned int i=0; i < height; i++){
		for (unsigned int j=0; j < width; j++){
			scanf("%u %u %u", &matrix[i * width + j].pixelR, &matrix[i * width + j].pixelG, &matrix[i * width + j].pixelB);
		}
	}

	for (unsigned int i=1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'f') doFlip(height, width, matrix);
			else if (argv[i][1] == 's') doSepia(height, width, matrix, maxColor);
		}
	}
	doPrint(height, width, matrix, maxColor);
	free(matrix);
	return 0;
}
