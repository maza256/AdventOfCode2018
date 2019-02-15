#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tnode
{
	int iterfreq;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

int findfreq(FILE *frequencies);
struct tnode *addtree(struct tnode *, int);
int main(void)
{
	printf("Hello World\n");
	FILE *frequencies;
	int stored_freq;
	time_t now, then;

	frequencies = fopen("frequencies.txt", "r");
	if(frequencies == NULL)
	{
		printf("File not found\n");
		return 1;
	}

	time(&now);
	stored_freq = findfreq(frequencies);
	time(&then);

	printf("%ld\n", then - now);

	printf("Frequency is %i\n", stored_freq);

	fclose(frequencies);

}
time_t now, then;

int findfreq(FILE *frequencies)
{
	int freq = 0, iread;
	int count = 0;

	int loop = 0;
	int stored_freq = 0;
	int match = 0;

	struct tnode * root = NULL;
	time(&now);
	while(match == 0)
	{
		while(fscanf(frequencies, "%d", &iread) != EOF)
		{
			freq += iread;
			root = addtree(root, freq);
		}
		fseek(frequencies, 0, SEEK_SET);
	}
}


struct tnode *addtree(struct tnode *p, int freq)
{
	if(p == NULL)
	{
		p = talloc();
		p->iterfreq = freq;
		p-> left = p->right = NULL;
//		printf("%d %d", p->iterfreq, freq);
		//getchar();
	}
	else if(p->iterfreq == freq)
	{
		time(&then);
		printf("Found: %d in %ld\n", freq, then - now);
		exit(1);
	}
	else if (p-> iterfreq < freq)
		p->left = addtree(p->left, freq);
	else
		p->right = addtree(p->right, freq);
	return p;

}
