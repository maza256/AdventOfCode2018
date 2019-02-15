//Read FILE
//Sort data into chronological order
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void puzzle1();
//void puzzle2();
//guard_details* push(char line[50], guard_details current);
typedef struct guard_details
{
    char guard_list[50];
    struct guard_details *next;
}guard_details;

guard_details * push(char input[50], guard_details current);


int main(void)
{
    puzzle1();
//    puzzle2();
    return 0;
}

void puzzle1()
{
    FILE *security_list;
    security_list = fopen("security_detail.txt", "r");
    if(!security_list)
    {
        printf("File not found\n");
        return;
    }
    guard_details * head = NULL;
    guard_details * current = NULL;
    guard_details * temp_struct = NULL;
    char temp[50];
    //The space at the start of the format is important.
    while(fscanf(security_list, "%[^\n]\n",temp) != EOF)
    {
        if(head == NULL)
        {
            head = malloc(sizeof(guard_details));
            strcpy(head->guard_list,temp);
            head->next = NULL;
            continue;
        }
        current = head;
        int result;
        int pushed = 0;
        do{
            result = strcmp(current->guard_list, temp);
            if(result < 0)
            {
                if(current->next != NULL)
                    current = current->next;
                else
                    pushed = 1;
            }
            else
            {

                pushed = 1;
            }
        }while(pushed == 0);
        if(head == current)
            push(temp, *current);
        else
            push(temp, *current);
    }
    current = head;
    while(current->next != NULL)
    {
        printf("%s\n", current->guard_list);
        current = current->next;
    }

}

guard_details * push(char input[50], guard_details current)
{
    guard_details *new_node = malloc(sizeof(guard_details));
    strcpy(new_node->guard_list, input);
    new_node->next = current.next;
    current.next = new_node;
    return new_node;
}

//
// guard_details* push(char line[50], guard_details current)
// {
//     guard_details temp_struct = malloc(sizeof(guard_details));
//     temp_struct->next = current->next;
//     current->next = temp_struct;
//     strcpy(temp_struct->guard_list, temp);
//     return &current;
// }
