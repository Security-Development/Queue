#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2

typedef struct Node{
	int node;
	struct Node *next;
} Node;


// 맨 앞은 front, 초기 인덱스의 -1 만큼 한 값은 rear 
typedef struct Queue{
	int n; // 큐의 노드 개수 
	Node *front; // front = rear
	Node *rear; // rear = index -1
} Queue;


// 큐의 초기화  
void initQueue(Queue *q) {
	q->front = q->rear = NULL;
	q->n = 0;
	
} 

// 큐가 비었는지 확인 
bool isEmpty(Queue *q) {
	return q->n == 0;
}

// 큐에 데이터 할당 
void push(Queue *q, int data) {
	
	if( q->n >= MAX_SIZE ) {
		printf("최대 큐의 범위는 %d 입니다. 현재 할당하려는 범위는 %d 이여서 오류가 발생 했습니다.\n", MAX_SIZE, q->n + 1);
		return;
	}
	
	Node *n = (Node *)malloc(sizeof(Node));
	n->node = data;
	n->next = NULL;
	
	if( isEmpty(q) )
		q->front = n;
	else
		q->rear->next = n;
	
	q->rear = n; 
	q->n++; // 노드 개수 1 증가 
}

// 큐에서 데이터를 빼오기 
int pop(Queue *q) {
	Node *n;
	
	if( q->n == 0 ) 
		return 0;
		
	n = q->front;
	int r = n->node;
	q->front = n->next;
	free(n);
	q->n--;
	
	return r;
}


int main() { 
	Queue *q = (Queue *)malloc(sizeof(Queue));
	initQueue(q);
	
	for(int i = 1; i <= 3; i++) 
		push(q, i * 2);
	
	while( !isEmpty(q) )
		printf("%d ", pop(q));
	
	free(q); 
	
	return 0;
}
