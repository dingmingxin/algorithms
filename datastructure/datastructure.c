/* datastructure.c
 *
 * Author: Jimmy Pan
 * Email: dspjmt@gmail.com
 * Date: Wed Apr 10 11:01:15 CST 2013
 * 
 * Copyright (C) 2013 Jimmy Pan
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * Algorithm
 * Input:
 * Output:
 * Functions:
 *
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_NUM MAX_ELEMENT_NUM
#define MAX_ELEMENT_NUM 500
#define RAND_MOD 1000


void set_seed()
{
	time_t tmp;
	time(&tmp);
	srand((int)tmp);
}

void get_rand_array(int *tmp, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		tmp[i] = rand() % RAND_MOD;
	}
}

void print_array(int *a, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", a[i]);
	puts("");
}

struct simple_stack {
	int elements[MAX_ELEMENT_NUM];
	int top;
};

void init_simplestack(struct simple_stack *s)
{
	memset(s->elements, 0, sizeof *s);
	s->top = -1;
}

int simplestack_empty(struct simple_stack *s)
{
	if (s->top < 0)
		return 1;
	return 0;
}

int push_simplestack(struct simple_stack *s, int value)
{
	if (s->top >= MAX_ELEMENT_NUM) {
		fprintf(stderr, "stack overflow\n");
		return 1;
	} else {
		s->top++;
		s->elements[s->top] = value;
		return 0;
	}
}

int pop_simplestack(struct simple_stack *s, int *value)
{
	if (simplestack_empty(s)) {
		fprintf(stderr, "stack underflow\n");
		return 1;
	} else {
		*value = s->elements[s->top];
		s->top--;
		return 0;
	}
}

struct simple_queue {
	int elements[MAX_ELEMENT_NUM + 1];
	int head, tail;
};

void init_simplequeue(struct simple_queue *q)
{
	memset(q, 0, sizeof *q);
	q->head = 0;
	q->tail = 0;
}

int simplequeue_empty(struct simple_queue *q)
{
	if (q->head == q->tail)
		return 1;
	return 0;
}

int simplequeue_full(struct simple_queue *q)
{
	if (q->tail == MAX_ELEMENT_NUM) {
		if (!q->head)
			return 1;
	} else
		if (q->head == q->tail + 1)
			return 1;
	return 0;
}

int enqueue_simplequeue(struct simple_queue *q, int value)
{
	if (simplequeue_full(q)) {
		fprintf(stderr, "queue overflow\n");
		return 1;
	}
	q->elements[q->tail] = value;
	if (q->tail >= MAX_ELEMENT_NUM)
		q->tail = 0;
	else 
		q->tail++;
	return 0;
}

int dequeue_simplequeue(struct simple_queue *q, int *value)
{
	if (simplequeue_empty(q)) {
		fprintf(stderr, "queue underflow\n");
		return 1;
	}
	*value = q->elements[q->head];
	if (q->head >= MAX_ELEMENT_NUM)
		q->head = 0;
	else
		q->head++;
	return 0;
}

struct array_sentinel_llist {
	int key[MAX_ELEMENT_NUM + 2];
	int prev[MAX_ELEMENT_NUM + 2];
	int next[MAX_ELEMENT_NUM + 2];
	int head;
	int free_head;
};

void init_array_sentinel_llist(struct array_sentinel_llist *l)
{
	memset(l, 0, sizeof *l);
	l->head = MAX_ELEMENT_NUM;
	l->prev[l->head] = l->head;
	l->next[l->head] = l->head;
	l->free_head = MAX_ELEMENT_NUM + 1;
	l->prev[l->free_head] = l->free_head;
	l->next[l->free_head] = l->free_head;
}

int main(int argc, int **argv)
{
	int tmp[ARRAY_NUM];
	struct simple_stack tmp1;
	struct simple_queue tmp2;
	struct array_sentinel_llist tmp3;
	int i;
	get_rand_array(tmp, ARRAY_NUM);
/*
	init_simplestack(&tmp1);
	puts("array befor stack:");
	print_array(tmp, ARRAY_NUM);
	for (i = 0; i < ARRAY_NUM; i++) {
		push_simplestack(&tmp1, tmp[i]);
		enqueue_simplequeue(&tmp2, tmp[i]);
	}
	for (i = ARRAY_NUM - 1; i >= 0 ; i--) {
		pop_simplestack(&tmp1, tmp + i);
		dequeue_simplequeue(&tmp2, tmp + i);
	}
	puts("array after stack:");
	print_array(tmp, ARRAY_NUM);
	init_simplequeue(&tmp2);
	puts("array befor queue:");
	print_array(tmp, ARRAY_NUM);
	for (i = 0; i < ARRAY_NUM; i++) {
		push_simplestack(&tmp1, tmp[i]);
		enqueue_simplequeue(&tmp2, tmp[i]);
	}
	for (i = ARRAY_NUM - 1; i >= 0 ; i--) {
		pop_simplestack(&tmp1, tmp + i);
		dequeue_simplequeue(&tmp2, tmp + i);
	}
	puts("array after queue:");
	print_array(tmp, ARRAY_NUM);
*/
	init_array_sentinel_llist(&tmp3);
	search_array_sentinel
	return 0;
}
