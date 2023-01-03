/*
 * MIT License
 *
 * Copyright (c) 2023 Mohammad Abdul Ahad Chowdhury
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdlib.h>
#include <string.h>
#include "../include/list.h"

void Push(List list, float value)
{
	struct ListNode* new_first = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_first->value = value;
	new_first->next = list.first;
	list.first = new_first;
	list.length++;
}

float Pop(List list)
{
	unsigned int length = list.length;
	unsigned int i;
	ListNode* last;
	for (i = 1; i < length; i++)
		last = last->next;
	return last->value;
}

void Append(List list, float value)
{
	struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_node->value = value;
	ListNode newLast;
	newLast.value = value;
	newLast.index = list.length;
	Get(list, list.length)->next = &newLast;
	list.length++;
}

ListNode* Get(List list, unsigned int index)
{
	if (index >= list.length)
		return NULL;
	unsigned int i;
	ListNode* current = list.first;
	for (i = 1; i < index; i++)
		current = current->next;
	return current;
}

float GetValue(List list, unsigned int index)
{
	return Get(list, index)->value;
}

void Insert(List list, unsigned int index, float value)
{
	struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

	new_node->value = value;

	ListNode newLast;
	newLast.value = value;
	newLast.index = list.length;
	Get(list, list.length)->next = &newLast;
	list.length++;
}

void Clear(List list)
{
	ListNode* node = list.first;
	ListNode* next = node->next;

	while (NULL != next) {
		free(node);
		node = next;
		next = node->next;
	}

	free(node);
	list.length = 0;
}

List Delete(List list, unsigned int index)
{
	unsigned int i;
	ListNode* previous = list.first;
	for (i = 1; i < index - 1; i++)
		previous = previous->next;
	ListNode* del = previous->next;
	previous->next = del->next;
	free(del);
	list.length--;
	return list;
}

void Traverse(List list, void (*fptr)(float ))
{
	ListNode* node = list.first;
	while (NULL != node) {
		(*fptr)(node->value);
		node = node->next;
	}
}

List Copy(List list)
{
	List new_list;
	unsigned int i;
	for (i = 0; i < list.length; i++)
		Push(new_list, Get(list, i)->value);
	return new_list;
}
