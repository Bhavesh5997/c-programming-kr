#include <stdlib.h>
#include "doubly_linked_list.h"

struct node {
	uint32_t data;
	struct node *next;
	struct node *prev;
};

struct doubly {
	struct node *head;
	uint32_t maxsize;
	uint32_t curr_size;
};

/* Initialize a Linked-list and return a head pointer */
int initList(void **linkedList, uint32_t maxLinkedListSize)
{
	struct doubly *ptr;

	if (*linkedList)
		return -EALREADY;

	if (!maxLinkedListSize)
		return -EINVAL;

	ptr = (struct doubly *)malloc(sizeof(struct doubly));

	if (!ptr)
		return -ENOMEM;

	ptr->head = NULL;
	ptr->maxsize = maxLinkedListSize;
	ptr->curr_size = 0;
	*linkedList = ptr;

	return 0;
}

/* Add a node in the Linked-list at top*/
int insertNodeAtTop(void *linkedList, uint32_t data)
{
	struct doubly *ptr = (struct doubly *)linkedList;
	struct node *newnode;

	if (!ptr)
		return -EINVAL;

	if (ptr->curr_size == ptr->maxsize)
		return -ENOBUFS;

	newnode = (struct node *)malloc(sizeof(struct node));

	if (!newnode)
		return -ENOMEM;

	newnode->data = data;
	newnode->prev = NULL;

	if (ptr->head)
		ptr->head->prev = newnode;

	newnode->next = ptr->head;
	ptr->head = newnode;
	ptr->curr_size++;

	return 0;
}

/* Insert a node at specific location */
int listInsertNodeAt(void *linkedList, int position, uint32_t data)
{
	struct node *temp, *newnode;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count;

	if (!ptr)
		return -EINVAL;

	if (position == 1) {
		insertNodeAtTop(linkedList, data);
		return 0;
	}

	temp = ptr->head;
	count = ptr->curr_size;

	if (position <= 0 || (count < position && position != count + 1))
		return -EPERM;

	if (ptr->curr_size == ptr->maxsize)
		return -ENOBUFS;

	newnode = (struct node *)malloc(sizeof(struct node));

	if (!newnode)
		return -ENOMEM;

	/* Traverse the list upto position - 1 */
	for (int i = 1; i < position - 1; i++)
		temp = temp->next;

	newnode->data = data;
	newnode->prev = temp;
	newnode->next = temp->next;
	temp->next = newnode;

	if (count > position)
		newnode->next->prev = newnode;

	ptr->curr_size++;

	return 0;
}

/* Retrieve a node from top of the list */
int listGetNodeFromTop(void *linkedList, uint32_t *data)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return -ENODATA;

	*data = temp->data;

	return 0;
}

/* Retrieve a node from specific location */
int listGetNodeFromPosition(void *linkedList, int position, uint32_t *data)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;
	count = ptr->curr_size;

	if (!temp)
		return -ENODATA;

	if (position <= 0 || count < position)
		return -EPERM;

	/* Traverse the list upto position */
	for (int i = 1; i <= position - 1; i++)
		temp = temp->next;

	*data = temp->data;

	return 0;
}

/* Remove the top node from list */
int listRemoveTopNode(void *linkedList)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return -ENODATA;

	if (!temp->next) {
		ptr->head = NULL;

		free(temp);

		ptr->curr_size--;

		return 0;
	}

	ptr->head = temp->next;
	ptr->head->prev = NULL;

	free(temp);

	ptr->curr_size--;

	return 0;
}

/* Remove Nth node from Linked-list */
int listRemoveNthNode(void *linkedList, int position)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;
	count = ptr->curr_size;

	if (!temp)
		return -ENODATA;

	if (position <= 0 || count < position)
		return -EPERM;

	if (position == 1) {
		if (!temp->next) {
			ptr->head = NULL;

			free(temp);

			ptr->curr_size--;

			return 0;
		}

		ptr->head = temp->next;
		ptr->head->prev = NULL;

		free(temp);

		ptr->curr_size--;

		return 0;
	}

	if (count == position) {
		/* Traverse the list upto last node */
		while (temp->next)
			temp = temp->next;

		temp->prev->next = NULL;

		free(temp);

		ptr->curr_size--;

		return 0;
	}

	/* Traverse the list upto position */
	for (int i = 1; i < position; i++)
		temp = temp->next;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	free(temp);

	ptr->curr_size--;

	return 0;
}

/* Remove a node containing a value 'n' */
int listRemoveNodeByValue(void *linkedList, uint32_t data)
{
	struct node *temp, *dnode;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count = 0, flag = 0;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return -ENODATA;

	/*
	 * Traverse the list upto last node and compare the data with node
	 * data, if it's match then, check whether it's match with first,
	 * in the between first and last or at last, then remove it.
	 */
	while (temp) {
		if (data == temp->data && count == 0) {
			if (!temp->next) {
				ptr->head = NULL;

				ptr->curr_size--;

				free(temp);

				return 0;
			}

			dnode = temp;
			ptr->head = temp->next;
			ptr->head->prev = NULL;
			temp = temp->next;
			flag = 1;

			free(dnode);

			ptr->curr_size--;
		} else if (data == temp->data && temp->next != NULL) {
			dnode = temp;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp = temp->next;
			flag = 1;

			free(dnode);

			ptr->curr_size--;
		} else if (data == temp->data && temp->next == NULL) {
			dnode = temp;
			temp->prev->next = NULL;
			temp = temp->next;
			flag = 1;

			free(dnode);

			ptr->curr_size--;
		} else {
			temp = temp->next;
			count++;
		}
	}

	if (flag == 0)
		return -EPERM;

	return 0;
}

/* Return size of Linked-list */
int getListSize(void *linkedList, uint32_t *size)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;
	count = ptr->curr_size;

	if (!temp)
		return -ENODATA;

	*size = count;

	return 0;
}

/* Return position of the node containing data 'n' */
int getNodeIndex(void *linkedList, uint32_t data, uint32_t *index)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;
	int count = 1;

	*index = -1;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return -ENODATA;

	/* Searching of data in linked list */
	while (temp) {
		if (data == temp->data)
			*index = count;

		temp = temp->next;
		count++;
	}

	if ((int)*index == -1)
		return -EPERM;

	return 0;
}

/*
 * Print Linked-list on specified output stream
 * (i.e. stdout / stderr / filestream)
 */
int printList(FILE *fp, void *linkedList, char *delimiter)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return -ENODATA;

	if (!fp)
		return -EPERM;

	/* Print the list data upto last node */
	while (temp) {
		fprintf(fp, "%d", temp->data);

		temp = temp->next;

		if (temp)
			fprintf(fp, "%s", delimiter);
	}

	return 0;
}

/* Delete a Linked-list and make head pointer NULL */
int deleteList(void *linkedList)
{
	struct node *temp, *dnode;
	struct doubly *ptr = (struct doubly *)linkedList;

	if (!ptr)
		return -EINVAL;

	temp = ptr->head;

	if (!temp)
		return 0;

	/* Traverse the list upto last node and parallelly remove also */
	while (temp) {
		dnode = temp;
		temp = temp->next;

		free(dnode);
		ptr->curr_size--;
	}

	ptr->head = NULL;

	return 0;
}

/* Check whether the Linked-list is empty or not */
bool isListEmpty(void *linkedList)
{
	struct node *temp;
	struct doubly *ptr = (struct doubly *)linkedList;

	if (!ptr)
		return true;

	temp = ptr->head;

	if (!temp)
		return true;

	return false;
}
