#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This implementation is a linear linked list
 * The binary tree version, puzzle2_tree.c is much quicker
*/
typedef struct numlist
{
	int iterfreq;
	struct numlist * next;
}numlist_t;

int findfreq(FILE *frequencies);

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


int findfreq(FILE *frequencies)
{
	int freq = 0, iread;
	int count = 0;

	int loop = 0;
	int stored_freq = 0;
	int match = 0;

	numlist_t * head = NULL;
	head = malloc(sizeof(numlist_t));

	numlist_t * current = head;
	numlist_t * iterator;



	while(match == 0)
	{

		while(fscanf(frequencies, "%d", &iread) != EOF)
		{
		//	printf("%d %d %d\n", freq, iread, freq+iread);
			freq += iread;
			//getchar();
			iterator = head;
			while(iterator != current)
			{
				count++;
				if(freq == iterator->iterfreq)
				{

					printf("Party %d: %d, %d\n", count, freq, iterator->iterfreq);
					match++;
					return freq;
				}
				else
					iterator = iterator->next;
			}
			current->iterfreq = freq;
			current->next = malloc(sizeof(numlist_t));

			current = current->next;
			iterator = head;

		}
		fseek(frequencies, 0, SEEK_SET);
	}
}
