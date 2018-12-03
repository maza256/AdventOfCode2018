#include <stdio.h>
#include <string.h>
#include <ctype.h>

void puzzle1();
void puzzle2();

int main(void)
{
	puzzle1();
	puzzle2();
}


void puzzle1()
{
	FILE *inventory_list;

	inventory_list = fopen("inventory_list.txt", "r");
	if(inventory_list == NULL)
	{
		printf("File not found\n");
		return;
		//return 1;
	}
	char s[26];
	int dubs = 0, trips = 0;
	int dubsFlag = 0, tripsFlag = 0;

	while(fscanf(inventory_list, "%s", s) != EOF)
	{
		int count = 1;
		for(int i = 0; i < 26; i++)
		{
			if(s[i] != '+')
			{
				for(int k = i + 1; k < 26; k++)
				{
					if(s[i] == s[k])
					{
						count++;
						s[k] = '+';
					}
				}
				if(count == 2 && dubsFlag == 0)
				{
					dubs++;
					dubsFlag++;
				}
				if(count == 3 && tripsFlag == 0)
				{
					trips++;
					tripsFlag++;
				}
				count =1;
			}

		}
		dubsFlag = 0;
		tripsFlag = 0;
	}
	printf("Result is: %d %d %d\n", dubs, trips, dubs*trips);
	fclose(inventory_list);
}



void puzzle2()
{
	FILE *inventory_list;

	inventory_list = fopen("inventory_list.txt", "r");
	if(inventory_list == NULL)
	{
		printf("File not found\n");
		return;
	}
	char s[27];
	char held[27];

	int mistakes = 2;
	long position;
	int testing = 0;
	int match = 0;
	while(match == 0)
	{
		while(fscanf(inventory_list, "%s", s) != EOF)
		{
			if(testing == 0)
			{
				strcpy(held, s);
				position = ftell(inventory_list);
				testing = 1;
			}
			mistakes = 2;
			for(int p = 0; p < 26; p++)
			{
				if(!(s[p] == held[p]))
				{
					mistakes--;
				}
				if(mistakes == 0)
					continue;
			}
			if(mistakes == 1)
			{
				printf("%s\n%s\n", s, held);
				match++;
				break;
			}
		}

		fseek(inventory_list, position, SEEK_SET);
		testing = 0;
	}
}
