/**
 * @file doubly_linked_list.h
 * @brief This file is the collection of doubly linked list APIs and it's
 * description.
 * @author Bhavesh
 *
 * This file is provide information to create and perform some operations on
 * doubly linked list using below APIs.
 */

#ifndef _DOUBLY_H
#define _DOUBLY_H

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * @brief Initialize the list.
 *
 * This function initialize the list based on valid maximum size of list.
 *
 * @param[out] linkedList a list pointer
 * @param[in] maxLinkedListSize a non zero maximum size of list
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENOMEM: Memory is not sufficient.
 * @retval -EALREADY: List is already initialized
 * @retval -EINVAL: Size of the list is incorrect.
 */
int initList(void **linkedList, uint32_t maxLinkedListSize);

/**
 * @brief Insert node at top.
 *
 * This function insert node at top as per available space and also change head
 * pointer at the end of the insertion.
 *
 * @param[in] linkedList a list pointer
 * @param[in] data a node data
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENOMEM: Memory is not sufficient.
 * @retval -EINVAL: Initialization of list is not done.
 * @retval -ENOBUFS: Linked list is full.
 */
int insertNodeAtTop(void *linkedList, uint32_t data);

/**
 * @brief Insert node at specified location.
 *
 * This function insert node at specified location, if it is valid and also
 * arrange previous and next address of newly inserted node.
 *
 * @param[in] linkedList a list pointer
 * @param[in] position an integer param
 * @param[in] data a node data
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENOMEM: Memory is not sufficient.
 * @retval -EINVAL: Initialization of list is not done.
 * @retval -EPERM: Invalid position.
 * @retval -ENOBUFS: Linked list is full.
 */
int listInsertNodeAt(void *linkedList, int position, uint32_t data);

/**
 * @brief Get data from the top node.
 *
 * This function get data from the top node, if the list is not empty.
 *
 * @param[in] linkedList a list pointer
 * @param[out] data a node data
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 */
int listGetNodeFromTop(void *linkedList, uint32_t *data);

/**
 * @brief Get node data from specified position.
 *
 * This function get node data from specified position, if the list is not
 * empty and the position is also valid.
 *
 * @param[in] linkedList a list pointer
 * @param[in] position an integer param
 * @param[out] data a node data
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -EPERM: Invalid position.
 */
int listGetNodeFromPosition(void *linkedList, int position, uint32_t *data);

/**
 * @brief Remove the top node of list.
 *
 * This function remove the top node from the list, if the list is not empty.
 *
 * @param[in] linkedList a list pointer
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 */
int listRemoveTopNode(void *linkedList);

/**
 * @brief Remove node from the specified position.
 *
 * This function remove the node from the specified position, if the list is
 * not empty and the position is also valid.
 *
 * @param[in] linkedList a list pointer
 * @param[in] position an integer param
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -EPERM: Invalid position.
 */
int listRemoveNthNode(void *linkedList, int position);

/**
 * @brief Remove node by it's value.
 *
 * This function remove those nodes, which data matches with provided value, if
 * the list is not empty and value is present in the list.
 *
 * @param[in] linkedList a list pointer
 * @param[in] data a provided value
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 */
int listRemoveNodeByValue(void *linkedList, uint32_t data);

/**
 * @brief Get the current nodes count from the list.
 *
 * This function gives the current nodes count of the list, if the list is not
 * empty.
 *
 * @param[in] linkedList a list pointer
 * @param[out] size an output param
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -EPERM: Data is not present in the list.
 */
int getListSize(void *linkedList, uint32_t *size);

/**
 * @brief Get the node first index by providing data.
 *
 * This function get node first index, which data match with provided data, if
 * the list is not empty and the data is present in the list.
 *
 * @param[in] linkedList a list pointer
 * @param[in] data a provided data
 * @param[out] index an output param
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -ENODATA: List is empty.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -EPERM: Data is not present in the list.
 */
int getNodeIndex(void *linkedList, uint32_t data, uint32_t *index);

/**
 * @brief Print the list data.
 *
 * This function print the list data on console or on standard error stream or
 * file based on user choice, if the list is not empty.
 *
 * @param[in] linkedList a list pointer
 * @param[in] fp a file pointer
 * @param[in] delimiter a character pointer
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -ENODATA: List is empty.
 * @retval -EPERM: Invalid output stream.
 */
int printList(FILE *fp, void *linkedList, char *delimiter);

/**
 * @brief Delete the entire list.
 *
 * This function delete all the nodes and make head pointer null, if the list
 * is not empty.
 *
 * @param[in] linkedList a list pointer
 *
 * @return 0 on success and error codes on failure.
 * @retval 0: Success.
 * @retval -EINVAL: Initialization of the list is not done.
 * @retval -ENODATA: List is empty.
 */
int deleteList(void *linkedList);

/**
 * @brief Check the list is empty on success and error codes on failure. not.
 *
 * This function check the list is empty or not.
 *
 * @param[in] linkedList a list pointer
 *
 * @return true or false
 * @retval true: List is empty
 * @retval false: List is not empty
 */
bool isListEmpty(void *linkedList);

#endif
