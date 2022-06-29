#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef struct {
	int data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//공백상태 만들기
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

//포화상태이면
int is_full(QueueType *q)
{
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

//원형 큐 출력
void queue_print(QueueType *q)
{
	printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			// if (i == q->rear)
			// 	break;
		}while (i != q->front);
	}
	printf("\n");
}

//삽입
void enqueue(QueueType *q, int item)
{
	if (is_full(q))
		error("큐가 포화상태임");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//삭제
int dequeue(QueueType *q)
{
	if (is_empty(q))
		error("큐 공백상태임");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (q->data[q->front]);
}
/*
int peek(QueueType *q)
{
	if (is_empty(q))
		error("큐 공백 상태임");
	return}}*/

int main()
{
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("---데이터 추가---\n");
	while (!is_full(&queue))
	{
		printf("정수를 입력하셈 : ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태이다.\n\n");

	printf("---데이터 삭제---\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수 : %d\n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태이다.\n");
	return 0;
}
/*원형큐 인터넷
#include <stdio.h>
#define MAX 100
int front=-1;
int rear=-1;
int queue[MAX];
 
int IsEmpty(void){
    if(front==rear)//front와 rear가 같으면 큐는 비어있는 상태 
        return 1;
    else return 0;
}
int IsFull(void){
    int tmp=(rear+1)%MAX; //원형 큐에서 rear+1을 MAX로 나눈 나머지값이
    if(tmp==front)//front와 같으면 큐는 가득차 있는 상태 
        return 1;
    else
        return 0;
}
void addq(int value){
    if(IsFull())
        printf("Queue is Full.\n");
    else{
rear = (rear+1)%MAX;
 queue[rear]=value;
 }
 
}
int deleteq(){
    if(IsEmpty())
        printf("Queue is Empty.\n");
    else{
        front = (front+1)%MAX;
        return queue[front];
    }
}
 
int main(){
    
    addq(4);
    addq(7);
    addq(12);
    printf("%d\n",deleteq());
    printf("%d\n",deleteq());
    printf("%d\n",deleteq());
deleteq();
    
    return 0;
}
*/
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 선형 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 선형 큐 초기화
void init_queue(QueueType *q)
{
	q->rear = -1;
	q->front = -1;
}
// 선형 큐 상태 출력
void queue_print(QueueType *q)
{
	for (int i = 0; i<MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i> q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// 선형 큐가 포화상태인가?
int is_full(QueueType *q)
{
	if (q->rear ==  MAX_QUEUE_SIZE - 1 )
		return 1;
	else
		return 0;
}
// 선형 큐가 공백상태인가?
int is_empty(QueueType *q)
{
	if ( q->front == q->rear )
		return 1;
	else
		return 0;
}
// 선형 큐에 데이터 삽입
void enqueue(QueueType *q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[  ++(q->rear)  ] = item;
}
// 선형 큐에서 데이터 제거
int dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[ ++(q->front) ];
	return item;
}	
// 메인
int main(void)
{
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}*/