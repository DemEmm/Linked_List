#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include"Linked_List_Lib.h"

int main()
{
	bool test;
	struct Node* Head1;
	struct Node* Head2;
	Head1 = list_new();
	Head2 = list_new();
	test = list_insert(1, Head1);
	test = list_insert(2, Head1);
	test = list_insert(4, Head1);
	print(Head1);
	test = list_remove(1, Head1);
	test = list_remove(4, Head1);
	print(Head1);
	//....
}