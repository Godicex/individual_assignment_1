#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int score;
    Node *next;
} *head, *tail, *temp;

Node *createNode(int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

// void pushHead(int score){
//     Node *temp = createNode(score);
//     if(!head){
//         head = tail = temp;
//     } else {
//         temp->next = head;
//         head = temp;
//     }
// }

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

// void popTail(){
//     if (!head){
//         return;
//     } else if(head == tail){
//         free(head);
//         head = tail = NULL;
//     } else {
//         Node *temp = head;
//         while(temp->next != tail){
//             temp = temp->next;
//         }
//         tail->next = NULL;
//         free(tail);
//         tail = temp;
//     }
// }

// void printList(){
//     Node *curr = head;

//     while(curr){
//         printf("%d\n", curr->score);
//         curr = curr->next;
//     }
// }

void descen() {
    Node* curr = head;
    while (curr) {
        Node* newnode = createNode(curr->score);
        newnode->next = temp;
        temp = newnode;
        curr = curr->next;
    }
    while(temp){
        if (!temp->next) printf("%d\n", temp->score);
        else printf("%d ", temp->score);
        temp = temp->next;
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
    printf("Descending ordernya: ");
    descen();
    return 0;
} 