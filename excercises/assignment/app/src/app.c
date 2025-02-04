#include <string.h>
#include "doubly_linked_list.h"

int main(void)
{
	void *list_ptr = NULL;
	uint32_t list_size, choice, data, index;
	int res, position;
	FILE *fp;

	while (1) {
		printf("\n------------------------------------------------\n");
		printf("\n1.Initialize the list\n");
		printf("2.Insert node at top\n");
		printf("3.Insert at any position\n");
		printf("4.Retrieve node from top of the list\n");
		printf("5.Retrieve node from specific location\n");
		printf("6.Remove the top node from list\n");
		printf("7.Remove Nth node from Linked list\n");
		printf("8.Remove node by value\n");
		printf("9.To get current size of list\n");
		printf("10.To get node index from data\n");
		printf("11.Print the list\n");
		printf("12.Delete Linked-list and make head pointer NULL\n");
		printf("13.Check whether the Linked-list is empty or not\n");
		printf("14.Exit\n\n");
		printf("Enter your choice: ");

		res = scanf("%u", &choice);

		if (res == -1)
			return -1;

		switch (choice) {
		case 1:
			printf("Enter max list size: ");
			scanf("%u", &list_size);

			res = initList(&list_ptr, list_size);

			switch (res) {
			case 0:
				printf("\nSuccessfully initialized.\n");
				break;
			case -ENOMEM:
				printf("\nError: Memory is not sufficient to "
				       "initialize the list.\n");
				break;
			case -EINVAL:
				printf("\nError: Size of the list is "
				       "invalid.\n");
				break;
			case -EALREADY:
				printf("\nError: List is already initialized."
				       "\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 2:
			printf("\nEnter your data: ");
			scanf("%u", &data);

			res = insertNodeAtTop(list_ptr, data);

			switch (res) {
			case 0:
				printf("\nSuccessfully inserted.\n");
				break;
			case -ENOMEM:
				printf("\nError: Memory is not sufficient for "
				       "insertion.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENOBUFS:
				printf("\nError: Linked list is full.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 3:
			printf("Enter your position\n");
			scanf("%d", &position);
			printf("\nEnter your data: ");
			scanf("%u", &data);

			res = listInsertNodeAt(list_ptr, position, data);

			switch (res) {
			case 0:
				printf("\nSuccessfully inserted.\n");
				break;
			case -ENOMEM:
				printf("\nError: Memory is not sufficient for "
				       "insertion.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -EPERM:
				printf("\nError: Invalid position\n");
				break;
			case -ENOBUFS:
				printf("\nError: Linked list is full.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 4:
			res = listGetNodeFromTop(list_ptr, &data);

			switch (res) {
			case 0:
				printf("\nTop position node data:\n%u\n",
				       data);
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 5:
			printf("Enter your position\n");
			scanf("%d", &position);

			res = listGetNodeFromPosition(list_ptr, position,
						      &data);

			switch (res) {
			case 0:
				printf("\nNode data at position %d is %u\n",
				       position, data);
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 6:
			res = listRemoveTopNode(list_ptr);

			switch (res) {
			case 0:
				printf("\nSuccessfully removed.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 7:
			printf("Enter your position\n");
			scanf("%d", &position);

			res = listRemoveNthNode(list_ptr, position);

			switch (res) {
			case 0:
				printf("\nSuccessfully removed.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -EPERM:
				printf("\nError: Invalid position\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 8:
			printf("\nEnter your data: ");
			scanf("%u", &data);

			res = listRemoveNodeByValue(list_ptr, data);

			switch (res) {
			case 0:
				printf("\nSuccessfully removed.");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			case -EPERM:
				printf("\nError: Data is not present in the "
				       "list.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 9:
			res = getListSize(list_ptr, &list_size);

			switch (res) {
			case 0:
				printf("\nCurrent size of linked list = %u\n",
					list_size);
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 10:
			printf("\nEnter your data: ");
			scanf("%u", &data);

			res = getNodeIndex(list_ptr, data, &index);

			switch (res) {
			case 0:
				printf("First index of %u is %u\n", data,
				       index);
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			case -EPERM:
				printf("\nError: Data is not present in the "
				       "list\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 11:
			printf("1.Print on the console\n");
			printf("2.Write in the output.txt file\n");
			printf("3.Print on standard error stream\n\n");
			printf("Enter your choice: ");
			scanf("%u", &choice);

			switch (choice) {
			case 1:
				fp = stdout;
				break;
			case 2:
				fp = fopen("output.txt", "w");
				break;
			case 3:
				fp = stderr;
				break;
			default:
				fp = NULL;
				break;
			}

			res = printList(fp, list_ptr, "->");

			if (choice == 2)
				fclose(fp);

			switch (res) {
			case 0:
				printf("\nSuccessfully printed.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize "
				       "the list.\n");
				break;
			case -ENODATA:
				printf("\nError: List is empty.\n");
				break;
			case -EPERM:
				printf("\nError: Invalid choice.\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 12:
			res = deleteList(list_ptr);

			switch (res) {
			case 0:
				printf("\nSuccessfully deleted.\n");
				break;
			case -EINVAL:
				printf("\nError: Please initialize the list."
				       "\n");
				break;
			default:
				printf("\nUnknown error code: %d\n", res);
				break;
			}
			break;
		case 13:
			res = isListEmpty(list_ptr);

			switch (res) {
			case true:
				printf("\nList is empty\n");
				break;
			case false:
				printf("\nList is not empty\n");
				break;
			}
			break;
		case 14:
			return 0;
		default:
			printf("Invalid choice.\n");
			break;
		}
	}

	return 0;
}
