#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fa;
	FILE *fb;
	FILE *fout;
	char name1[] = "fA.txt";
	char name2[] = "fB.txt";
	fa = fopen(name1, "r");
	fb = fopen(name2, "r");
	fout = fopen("fc.txt", "w");
	
	char *buffer[256];
	
	int colA=0;
	int colB=0;
	float val=0;
	int count=0;
	
	fscanf(fa, "%d", &colA);
	fscanf(fb, "%d", &colB);
	
	while(fscanf(fa, "%f", &val)!=EOF) {
		count++;
	}
	int rowA=count/colA;
	count=0;
	
	while(fscanf(fb, "%f", &val)!=EOF) {
		count++;
	}
	int rowB=count/colB;
	count=0;
	
	if (colA!=rowB) {
		printf("ERROR");
		return -1;
	}

	fseek(fa, 0, SEEK_SET);
	fseek(fb, 0, SEEK_SET);
	
	fscanf(fa, "%d", &colA);
	fscanf(fb, "%d", &colB);
	
	float massiveA[rowA][colA];
	float massiveB[rowB][colB];

	for (int i=0; i<rowA; i++) {
		for (int j=0; j<colA; j++) {
			fscanf(fa, "%f", &massiveA[i][j]);
		}
	}
	
	for (int i=0; i<rowB; i++) {
		for (int j=0; j<colB; j++) {
			fscanf(fb, "%f", &massiveB[i][j]);
		}
		printf("\n");
	}
	
	for (int row = 0; row < rowA; ++row){
		for (int col = 0; col < colB; ++col){
			float mult = 0;
			for (int el = 0; el < rowB; ++el)
				mult += massiveA[row][el] * massiveB[el][col];
			fprintf(fout, "%.2f\t", mult);
		}
		fprintf(fout, "\n");
	}
	
	fclose(fa);
	fclose(fb);
	fclose(fout);
	return 0;
}