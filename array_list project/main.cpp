#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayList;


void init(ArrayList* L)
{
	L->size = 0;
}

int is_empty(ArrayList* L)
{
	return L->size == 0;
}

int is_full(ArrayList* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayList* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		fprintf(stderr, "error");
	return L->array[pos];
}

void print_list(ArrayList* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayList* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
	{
		fprintf(stderr, "list overflow");
	}
	L->array[L->size++] = item;
}

void item_insert(ArrayList* L, int pos, element item)
{
	int count=0;
	if (L->size == 0 && pos != 0)
	{
		printf("List size is zero. please enter again(number position): ");
		scanf_s("%d %d", &item, &pos);
	}

	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
			count++;
		}
		L->array[pos] = item;
		L->size++;
		printf("\n");
		printf("Move : %d\n", count);
	}
}

element item_delete(ArrayList* L, int pos)
{
	element item;
	int count = 0;
	int Delete_item = 0;

	if (pos < 0 || pos >= L->size)
	{
		fprintf(stderr, "position error");
	}
	item = L->array[pos];
	Delete_item = item;
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
		count++;
	}
	printf("\n");
	printf("Move : %d\n", count);
	printf("Delete : %d\n", Delete_item);
	L->size--;
	return item;
}

int main(void)
{
	ArrayList list;

	init(&list);
	int num;
	int position;

	while (1)
	{
		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf_s("%d", &num);

		if (num == 1)
		{
			printf("Enter the number and position: ");
			scanf_s("%d %d", &num, &position);
			item_insert(&list, position, num);
		}
		else if (num == 2)
		{
			if (list.size == 0)
			{
				printf("List is empty\n");
			}
			else
			{
				printf("Enter the position: ");
				scanf_s("%d", &position);
				item_delete(&list, position);
			}
		}
		else if (num == 3)
		{
			print_list(&list);
		}
		else if (num == 0)
		{
			printf("Exit the program.");
			return 0;
		}
		else
		{
			printf("Invalid Menu. Please select again.\n");
		}
		printf("\n");
	}
}