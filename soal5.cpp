#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int score;
    Node *next;
} *head, *tail;

Node *createNode(int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score){
    Node *temp = createNode(score);
    if(!head){
        head = tail = temp;
    } else {
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

// void popHead(){
//     if (!head){
//         return;
//     } else if(head == tail){
//         free(head);
//         head = tail = NULL;
//     } else {
//         Node *temp = head->next;
//         head->next = NULL;
//         free(head);
//         head = temp;
//     }
// }

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
    for (int i = 0; i < tc; i++){
        int temp;
        printf("Link ke - %d : ", i+1);
        scanf("%d", &temp);
        pushTail(temp);
    }
    int target;
    printf("Nomor urut dari belakang : ");
    scanf("%d", &target);
    Node *curr = head;
    int panjang = 0;
    while(curr){
        panjang++;
        curr = curr->next;
    }
    curr = head;
    for(int i=0;i<(panjang-target); i++){
        curr = curr->next;
    }
    printf("Angka anda : %d\n", curr->score);
    return 0;
} 