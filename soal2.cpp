#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int score;
    Node *next;
} *head, *tail;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->score = value;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}

void pushTail(int score){
    Node *temp = createNode(score);
    if(!head){
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void popHead(){
    if (!head){
        return;
    } else if(head == tail){
        free(head);
        head = tail = NULL;
    } else {
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }
}

void popTail(){
    if (!head){
        return;
    } else if(head == tail){
        free(head);
        head = tail = NULL;
    } else {
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail->next = NULL;
        free(tail);
        tail = temp;
    }
}

void printList(){
    Node *curr = head;
    while(curr){
        printf("%d\n", curr->score);
        curr = curr->next;
    }
}

int main() {
    int tc;
    printf("Linked list size: ");
    scanf("%d", &tc);
    for (int i=0;i<tc; i++){
        int temp;
        printf("Link ke - %d : ", i+1);
        scanf("%d", &temp);
        pushTail(temp);
    }
    Node *curr = head;
    int max = head->score, min = head->score;
    while(curr){
        if(curr->score > max){
            max = curr->score;
        }
        if (curr->score < min){
            min = curr->score;
        }
        curr = curr->next;
    }
    int range = max-min;
    printf("Rangenya adalah %d\n", range);
    return 0;
} 