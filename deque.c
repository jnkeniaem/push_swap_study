#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {  // 덱 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;
// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 덱 초기화 
void init_deque(DequeType *q)
{
	q->front = q->rear =  0;
}
// 공백 상태 검출 함수
int is_empty(DequeType *q)
{
	return (  q->front == q->rear );
}
// 포화 상태 검출 함수
int is_full(DequeType *q)
{
	return (( q->rear  + 1) % MAX_QUEUE_SIZE == q->front);
}
// 덱 큐 출력 함수
void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front; // i에 현재 q의 front값을 넣어주고
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE); // i의 자리를 1증가
			printf("%d | ", q->data[i]); // 증가한 i 자리에 해당하는 data값을 출력
		} while ( i != q->rear); 
	}
	printf("\n");
}
// rear쪽 삽입 함수
void add_rear(DequeType *q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear값 1 증가
	q->data[ q->rear ] = item;
}
// rear쪽 삭제 함수
element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear =  (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // rear값 1감소
	return q->data[prev];
}
// rear쪽 반환
element get_rear(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[ q->rear ];
}
// front쪽 삽입 함수
void add_front(DequeType *q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[ q->front ] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // front값 1감소
} 
// front쪽 삭제 함수
element delete_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front =  (q->front + 1) % MAX_QUEUE_SIZE  ; // front값 1 증가
	return q->data[ q->front ];
}
// front쪽 반환
element get_front(DequeType *q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[ (q->front + 1) % MAX_QUEUE_SIZE ];
}
// 메인
int main(void)
{
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}