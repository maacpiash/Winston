//
// Created by maacpiash on 5/5/2020.
//

#ifndef WINSTON_LIST_H
#define WINSTON_LIST_H

#include<stdlib.h>

typedef struct Node
{
    void *value;
    unsigned int serial;
    struct Node *next;
} Node;

typedef struct List
{
    Node *first;
    unsigned int length;
} List;

void Push(List list, void *value, size_t data_size);
void* Pop(List list);
void Append(List list, void *value, size_t data_size);
void* Remove(List list);

Node* Get(List list, unsigned int serial);
void* GetValue(List list, unsigned int serial);
void Insert(List list, unsigned int serial, void *value, size_t data_size);
List Delete(List list, unsigned int serial);
void Clear(List list);
void Traverse(List list, void(*fptr)(void *));
List Reverse(List list);
List Copy(List list, size_t data_size);

#endif //WINSTON_LIST_H
