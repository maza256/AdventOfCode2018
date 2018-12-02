#include <stdio.h>

int main(void)
{
	printf("Hello World\n");
	FILE *frequencies;
	int freq = 0, iread;


	frequencies = fopen("frequencies.txt", "r");
	if(frequencies == NULL)
	{
		printf("File not found\n");
		return 1;
	}
	char c;

	while(fscanf(frequencies, "%d", &iread) != EOF)
	{
		freq += iread;
	}	

	printf("Frequency is %i\n", freq);

	fclose(frequencies);

}
