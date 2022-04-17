#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include"Linked_List_Lib.h"

struct Node* list_new() {
    struct Node* Head = (struct Node*)malloc(sizeof(struct Node));
    (*Head).Next = NULL;
    return Head;
}

void print(struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    struct Node* temp = Head;
    while (temp != NULL)
    {
        printf("%d ", (*temp).Data);
        temp = (*temp).Next;
    }
    printf("\n");
}
bool list_exists(int x, struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    struct Node* temp = Head;
    while (temp != NULL)
    {
        if ((*temp).Data == x) return true;
        temp = (*temp).Next;
    }
    return false;
}
bool list_insert(int x, struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    bool flag = true;
    struct Node* temp = Head;
    while (temp != NULL)
    {
        if ((*temp).Data == x) flag = false;
        temp = (*temp).Next;
    }
    if (flag == true) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).Data = x;
        (*temp).Next = Head;
        (*HeadS).Next = temp;
        return true;
    }
    else return false;
}
bool list_remove(int x, struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    struct Node* temp = Head;
    struct Node* Previus_addres = NULL;
    while (temp != NULL)
    {
        if ((*temp).Data == x) {
            if (Previus_addres == NULL) {
                (*HeadS).Next = (*temp).Next;
                free(temp);
                return true;
            }
            else {
                (*Previus_addres).Next = (*temp).Next;
                free(temp);
                return true;
            }
        }
        Previus_addres = temp;
        temp = (*temp).Next;
    }
    return false;
}

void list_destroy(struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    struct Node* temp = Head;
    struct Node* Previus_addres = NULL;
    while (temp != NULL)
    {
        if (Previus_addres == NULL) {
            Previus_addres = temp;
            temp = (*temp).Next;
            free(&HeadS);
        }
        else {
            Previus_addres = temp;
            temp = (*temp).Next;
            free(Previus_addres);
        }
    }
}


void insert(int x, int poss, struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    if (Head == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).Data = x;
        (*temp).Next = NULL;
        (*HeadS).Next = temp;
        if (poss > 1) {
            printf("invalid  position the element was setted at last position \n");
            return;
        }
    }
    else {
        int carent_poss = 1;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        struct Node* addres = Head;
        struct Node* Next_addres = NULL;
        struct Node* Previus_addres = NULL;
        while ((addres != NULL) && (carent_poss <= poss - 1)) {
            if ((*addres).Next == NULL) {
                Next_addres = ((*addres).Next);
            }
            if (carent_poss == poss - 1) {
                Next_addres = (*addres).Next;
            }
            Previus_addres = addres;
            addres = (*addres).Next;
            carent_poss = carent_poss + 1;
        }
        if (poss == 1) {
            (*temp).Data = x;
            (*temp).Next = Head;
            (*HeadS).Next = temp;
        }
        else {
            (*temp).Data = x;
            (*temp).Next = Next_addres;
            (*Previus_addres).Next = temp;
        }
    }
}
void del_element(int poss, struct Node* HeadS) {
    struct Node* Head;
    Head = (*HeadS).Next;
    int carent_poss = 1;
    struct Node* addres = Head;
    struct Node* Next_addres=NULL;
    struct Node* Previus_addres=NULL;
    if (Head == NULL) {
        printf("There is no data to delete\n"); return;
    }
    else {
        while ((addres != NULL) && (carent_poss <= poss - 1)) {
            if ((*addres).Next == NULL) {
                Next_addres = (*addres).Next;
            }
            if (carent_poss == poss - 1) {
                Next_addres = (*addres).Next;
            }
            Previus_addres = addres;
            addres = (*addres).Next;
            carent_poss = carent_poss + 1;
        }
        if (poss == 1) {
            (*HeadS).Next = (*addres).Next;
            free(addres);
        }
        else {
            if (Next_addres != NULL) {
                (*Previus_addres).Next = (*Next_addres).Next;
                free(Next_addres);
            }
            else {
                printf("There is no element to delete on this position\n");
            }
        }
    }
}
