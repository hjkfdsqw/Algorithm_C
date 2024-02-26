//Linked list 시작, 끝 노드 insert 함수 

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *next; 
}ListNode;   



int insertAtStart_Node(ListNode **ptrHead, int value){
    ListNode *tempNode = (ListNode *)malloc(sizeof(ListNode));
    if(!tempNode){
        return -1;
    }
    tempNode -> value = value;
    tempNode -> next = *ptrHead;
    *ptrHead = tempNode;
    return 1;
}

int insertAtEnd_Node(ListNode **ptrHead, int value){
    ListNode *head = *ptrHead;
    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
     if(!tempNode){
        return -1;
    }
    tempNode -> value = value;
    tempNode -> next = NULL;

    if(head==NULL){
        tempNode -> next = *ptrHead;
        *ptrHead = tempNode;
        return 1;
    }

    while(head->next != NULL){
        head = head ->next;
    }

    tempNode -> next = head->next;
    head ->next = tempNode;
    return 1;
}

void printList(ListNode *head){
    printf("List Print : ");
    while(head){
        printf("%d ", head -> value);
        head = head -> next;
    }
    printf("\n");
}


int main()
{

    ListNode *head = NULL;
    insertAtStart_Node(&head, 1); // 3 <- 2 <- 1
    insertAtStart_Node(&head, 2);
    insertAtStart_Node(&head, 3);
    insertAtEnd_Node(&head, 4);  // 4 -> 5 -> 6
    insertAtEnd_Node(&head, 5);
    insertAtEnd_Node(&head, 6);
   
    printList(head); //3 2 1 4 5 6

}