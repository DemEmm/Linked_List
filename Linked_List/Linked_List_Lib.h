#pragma once
struct Node {
    int Data;
    struct Node* Next;
};
struct Node* list_new();
void print(struct Node* HeadS);
bool list_exists(int x, struct Node* HeadS);
bool list_insert(int x, struct Node* HeadS);
bool list_remove(int x, struct Node* HeadS);
void list_destroy(struct Node* HeadS);
void insert(int x, int poss, struct Node* HeadS);
void del_element(int poss, struct Node* HeadS);