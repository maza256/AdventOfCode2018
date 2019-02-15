#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t timeNow, endtime;
    timeNow = clock();
    FILE * handle;
    handle = fopen("inputdata.txt", "r");
    char ch;
    int count = 0;
    int position = 1;
    while((ch = fgetc(handle)) != EOF)
    {
        if(ch == 40)
            count++;
        else if(ch == 41)
            count--;
        if(count < 0)
        {
            printf("%dth character\n", position);
            break;
        }
        position++;
    }
    printf("Floor: %d\n", count);

    fclose(handle);
    endtime = clock();
    printf("Time taken is: %lf\n", difftime(endtime, timeNow));
    return 0;
}
