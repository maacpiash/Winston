//
// Created by maacpiash on 5/5/2020.
//

#include <stdlib.h>
#include <string.h>
#include "list.h"

void Push(List list, void *value, size_t data_size)
{
    struct Node *new_first = (struct Node*)malloc(sizeof(struct Node));
    new_first->value  = malloc(data_size);
    memcpy(new_first->value, value, data_size);
    new_first->next = list.first;
    list.first = new_first;
    list.length++;
}

void* Pop(List list)
{
    unsigned int length = list.length;
    unsigned int i;
    Node* last;
    for (i = 1; i < length; i++)
        last = last->next;
    return last->value;
}

void Append(List list, void *value, size_t data_size)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->value = malloc(data_size);

    Node newLast;
    newLast.value = value;
    newLast.serial = list.length;
    Get(list, list.length)->next = &newLast;
    list.length++;
}

Node* Get(List list, unsigned int serial)
{
    if (serial >= list.length)
        return NULL;
    unsigned int i;
    Node* current = list.first;
    for (i = 1; i < serial; i++)
        current = current->next;
    return current;
}

void* GetValue(List list, unsigned int serial)
{
    return Get(list, serial)->value;
}

void Insert(List list, unsigned int serial, void *value, size_t data_size)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->value = malloc(data_size);

    Node newLast;
    newLast.value = value;
    newLast.serial = list.length;
    Get(list, list.length)->next = &newLast;
    list.length++;
}

void Clear(List list)
{
    Node *node = list.first;
    Node *next = node->next;

    while (NULL != next) {
        free(node);
        node = next;
        next = node->next;
    }

    free(node);
    list.length = 0;
}

List Delete(List list, unsigned int serial)
{
    unsigned int i;
    Node *previous = list.first;
    for (i = 1; i < serial - 1; i++)
        previous = previous->next;
    Node* del = previous->next;
    previous->next = del->next;
    free(del);
    list.length--;
    return list;
}

void Traverse(List list, void (*fptr)(void *))
{
    Node *node = list.first;
    while (NULL != node) {
        (*fptr)(node->value);
        node = node->next;
    }
}

List Copy(List list, size_t data_size)
{
    List new_list;
    unsigned int i;
    for (i = 0; i < list.length; i++)
        Push(new_list, Get(list, i), data_size);
    return new_list;
}
