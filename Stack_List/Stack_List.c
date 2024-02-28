#include<stdio.h>
#include<stdlib.h>
#define Error_Value -1;

typedef struct {
    int value;
    struct stack_Node *link;
}stack_Node;

void StackPush(stack_Node **ptrHead, int value){
    stack_Node *temp = (stack_Node *)malloc(sizeof(stack_Node));
    if(!temp){
        printf("Memory allocation Error\n");
        return;
    }
    temp -> value = value;
    temp -> link = (stack_Node *)*ptrHead;
    *ptrHead = temp;
}

int StackPop(stack_Node **ptrHead){
    stack_Node *delete;
    int value;
    if(*ptrHead){
        delete = *ptrHead;
        *ptrHead = (stack_Node *)delete -> link;
        value = delete -> value;
        free(delete);
        return value;
    }
    else{
        printf("Stack is Empty\n");
        return Error_Value;
    }
}

int main()
{
        stack_Node *head = NULL;
        StackPush(&head, 1);
        StackPush(&head, 2);
        StackPush(&head, 3);
        StackPush(&head, 4);
        StackPush(&head, 5);
        for(int i =0;i<5;i++){
            printf("Input Pop value : %d\n", StackPop(&head));
        }
        return 0;
    }
