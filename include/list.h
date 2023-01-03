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
#ifndef WINSTON_LIST_H
#define WINSTON_LIST_H

#include <stdlib.h>

typedef struct ListNode
{
	float value;
	unsigned int index;
	struct ListNode *next;
} ListNode;

typedef struct List
{
	ListNode *first;
	unsigned int length;
} List;

void Push(List list, float value);
float Pop(List list);
void Append(List list, float value);
float Remove(List list);

ListNode* Get(List list, unsigned int index);
float GetValue(List list, unsigned int index);
void Insert(List list, unsigned int index, float value);
List Delete(List list, unsigned int index);
void Clear(List list);
void Traverse(List list);
List Reverse(List list);
List Copy(List list);

#endif //WINSTON_LIST_H
