/* 정적 배열을 이용한 스택 구현 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100;
#define ERROR_VALUE -1;

typedef struct stack{
    int top;
    int data[];
}Stack_Array;

void StackInitialize(Stack_Array *stk){
    stk -> top = -1;
}

int StackEmpty(Stack_Array *stk){
    return stk -> top == -1;
}

int StackSize(Stack_Array *stk){
    return stk -> top + 1;
}

void StackPrint(Stack_Array *stk){
    printf("Stack : ");
    for(int i = stk -> top; i>=0; i--){
        printf("%d", stk -> data[i]);
    }
    printf("\n");
}

void StackPush(Stack_Array *stk, int value){
    if(stk -> top < 100 -1){
        stk ->top++;
        stk->data[stk->top] = value;
    }
    else{
        printf("Stack Overflow");
    } 
}

int StackPop(Stack_Array *stk){
    if (stk -> top >=0){
        int value = stk->data[stk->top];
        stk ->top--;
        return value;
    }
    else{
        printf("Stack Empty");
        return ERROR_VALUE;
    }
}

int StackTop(Stack_Array *stk){
    int value = stk -> data[stk -> top];
    return value; 
}

int main(){
    Stack_Array stk;
    StackInitialize(&stk);
    StackPush(&stk, 1);
    StackPush(&stk, 2);
    StackPush(&stk, 3);
    StackPush(&stk, 7);
    StackPush(&stk, 5);
    StackPop(&stk);
    StackPrint(&stk);
    return 0;
}

/*-----------------------------------------------------------------------------------*/

/* 동적 배열을 이용한 스택 구현 */

#include<stdio.h>
#include<stdlib.h>

#define ERROR_VALUE -1;

typedef struct stack{
    int top;
    int *data;
    int capacity;
    int min;
}Stack_Dynamic;

void StackInitialize(Stack_Dynamic *stk, int size){
    stk -> data = (int *)malloc(size * sizeof(int));
    stk -> top = -1;
    stk ->capacity = size;
    stk ->min = size;
}

void MemoryAllocationFree(Stack_Dynamic *stk){
    free(stk -> data);
}

int StackEmpty(Stack_Dynamic *stk){
    return stk -> top == -1;
}

int StackSize(Stack_Dynamic *stk){
    return stk -> top + 1;
}

void StackPrint(Stack_Dynamic *stk){
    printf("Stack : ");
    for(int i = stk -> top; i>=0; i--){
        printf("%d", stk -> data[i]);
    }
    printf("\n");
}

void StackPush(Stack_Dynamic *stk, int value){
    if(stk -> top < 100 -1){
        stk ->top++;
        stk->data[stk->top] = value;
    }
    else{
        printf("Stack Overflow");
    } 
}

int StackPop(Stack_Dynamic *stk){
    if (stk -> top >=0){
        int value = stk->data[stk->top];
        stk ->top--;
        return value;
    }
    else{
        printf("Stack Empty");
        return ERROR_VALUE;
    }
}

int StackTop(Stack_Dynamic *stk){
    int value = stk -> data[stk -> top];
    return value; 
}

int main(){

    Stack_Dynamic stk;

    StackInitialize(&stk, 7);

    StackPush(&stk, 1);
    StackPush(&stk, 2);
    StackPush(&stk, 3);
    StackPush(&stk, 7);
    StackPush(&stk, 5);
    StackPush(&stk, 5);
    StackPush(&stk, 5);
    StackPush(&stk, 5);
    StackPush(&stk, 5);
    StackPop(&stk);

    StackPrint(&stk);

    printf("%d", StackSize(&stk));

    MemoryAllocationFree(&stk);

    return 0;
}
