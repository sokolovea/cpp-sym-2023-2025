#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    Node* next;
};

void init(Node** node) {
    *node = NULL;
}

void add(Node** head, int value) {
    Node* newValue = (Node*)malloc(sizeof(Node));
    newValue->value = value;
    newValue->next = *head;
    *head = newValue;
}

void printAll(Node* head) {
    Node* temp_head = head;
    while (temp_head != NULL) {
        printf("[%d]\n", temp_head->value);
        temp_head = temp_head->next;
    }
}

int main()
{
    Node* head;
    init(&head);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    printAll(head);
}