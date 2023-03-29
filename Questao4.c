#include <stdio.h>
#include <stdlib.h>

struct list_node
{
	int data;
	struct list_node *next_node;
};

void insert(struct list_node **start_node, int new_data)
{
	struct list_node *node = malloc(sizeof(struct list_node));
	struct list_node *current = *start_node;
	struct list_node *previous = NULL;

	node->data = new_data;
	node->next_node = NULL;
	
	while (current != NULL)
	{
		if (current->data > node->data)
		{
			node->next_node = current;
			if (previous != NULL)
			{
				previous->next_node = node;
			}
			else
			{
				*start_node = node;
			}
			return;
		}
		previous = current;
		current = current->next_node;
	}
	if (previous != NULL)
	{
		previous->next_node = node;
		node->next_node = NULL;
	}
	else
	{
		*start_node = node;
	}
}

void print_list(struct list_node *list_to_print)
{
	struct list_node *print = list_to_print;
	
	while (print != NULL)
	{
		printf("%d", print->data);
		print = print->next_node;
	}

	return;
}

struct list_node** fill_entries(int *count)
{
	struct list_node **result = NULL;
	int list_size;
	int data;
	printf("Insira quantas listas tem no total\n");
	scanf_s("%d", count);

	result = malloc(sizeof(struct list_node*) * (*count));

	for (int i = 0; i < *count; i++)
	{
		result[i] = NULL;
		struct list_node *asd = NULL;

		printf("Insira quantos valores terao na lista %d\n", i+1);
		scanf_s("%d", &list_size);

		printf("Insira os valores da lista %d\n", i+1);
		for (int j = 0; j < list_size; j++)
		{
			scanf_s("%d", &data);

			struct list_node* aux = malloc(sizeof(struct list_node));
			aux->data = data;
			if (asd != NULL)
			{
				asd->next_node = aux;
			}
			else
			{
				result[i] = aux;
			}
			asd = aux;
		}
		asd->next_node = NULL;
	}

	return result;
}

struct list_node* merge_lists(struct list_node **all_lists, int list_count)
{
	struct list_node *aux_list = NULL;
	struct list_node *result = NULL;

	for (int i = 0; i<list_count; i++)
	{
		aux_list = all_lists[i];
		while (aux_list != NULL)
		{
			insert(&result, aux_list->data);
			aux_list = aux_list->next_node;
		}
	}

	return result;
}

void free_list(struct list_node* target_list)
{
	struct list_node *aux;
	while (target_list != NULL)
	{
		aux = target_list;
		target_list = target_list->next_node;
		free(aux);
	}
}

int main()
{
	int count = 0;
	struct list_node **entries;
	struct list_node *result;

	entries = fill_entries(&count);

	result = merge_lists(entries, count);

	print_list(result);

	for (int i = 0; i < count; i++)
	{
		free_list(entries[i]);
	}
	free(entries);

	free_list(result);

	return 0;
}