#include <stdio.h>
#include <stdlib.h>
void puzzle1();
void puzzle2();

typedef struct fabric_cut
{
    int id;
    int left;
    int top;
    int height;
    int width;
    int overlap;
    struct fabric_cut *next;
}fabric_cut_t;

int main(void)
{
    puzzle1();
    puzzle2();
    return 0;
}

void puzzle1()
{
    FILE *fabric_list;
    fabric_list = fopen("full_cuts.txt", "r");
    if(!fabric_list)
    {
        printf("File not found\n");
        return;
    }
    int id, left, top, width, height;
    fabric_cut_t * head = malloc(sizeof(fabric_cut_t));
    fabric_cut_t * current = head;
    fabric_cut_t * iterator = head;

    //The space at the start of the format is important.
    while(fscanf(fabric_list, " %*c %d %*c %d %*c %d %*c %d %*c %d",&id,&left,&top,&width,&height) != EOF)
    {
        current->id = id;
        current->left = left;
        current->top = top;
        current->width = width;
        current->height = height;
        current->overlap = 0;
        current ->next = malloc(sizeof(fabric_cut_t));
        current = current->next;
    }

    int current_window[1000][1000];
    for(int i = 0; i < 1000; i++)
    {
        for(int k = 0; k < 1000;k++)
        {
            current_window[i][k] = 0;
        }
    }

    current = head;
    int overlap = 0;
    int overlap_flag = 0;
    while(current->next != NULL)
    {
        for(int i = current->left; i < (current->left + current->width); i++)
        {
            for(int k = current->top; k < (current->top + current->height);k++)
            {
                if(current_window[i][k] == 0)
                {
                    current_window[i][k] = current->id;
                }
                else
                {
                    if(current_window[i][k] != -1)
                    {
                        overlap++;
                        iterator = head;
                        while(iterator->next != NULL)
                        {
                            if(iterator->id == current_window[i][k])
                                iterator->overlap = 1;
                            iterator = iterator->next;
                        }
                    }
                    current_window[i][k] = -1;
                    current->overlap = 1;
                }
            }
        }

        current = current->next;
    }
    printf("Overlap amount is: %i\n", overlap);
    current = head;
    while(current->next != NULL)
    {
        if(current->overlap == 0)
        {
            printf("Non-Overlapped is: %d\n", current->id);
            //break;
        }
        current = current->next;
    }
}

void puzzle2()
{
    NULL;
}
