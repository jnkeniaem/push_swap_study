#include "pushswap.h"
#include <stdio.h>

void init_stack(int argc, char **argv, t_circular_ary *p_ca, t_a *pa, t_b *pb)//a stack 만들기?
{
	int	i;

	i = 1;
	p_ca -> max_arg = argc - 1;
	pa->stack = malloc(p_ca -> max_arg * sizeof(int));
	pb->stack = malloc(p_ca -> max_arg * sizeof(int));
	pa -> front = p_ca->max_arg -1;
	pa -> rear = p_ca->max_arg -1;
	while (i < argc)
	{
		pa->stack[pa->front] = ft_atoi(argv[i]);//ft_atoi 지워야함. 다른 문자열을 정수로 바꿔주는것도 생각해보자 지금은 그냥 이게 생각나서 바로 하는거궁
		if (pa->front == 0)
			break;
		else
			pa->front = (pa->front -1) % (p_ca->max_arg);
		i++;
	}
	pb -> front = p_ca->max_arg -1;
	pb -> rear = p_ca->max_arg -1;
	current_arg(pa, pb);
	printf("%d\n", pa->current);
}

void sa(t_a *pa, t_b *pb)
{
	int	temp;

	current_arg(pa, pb);
	if (pa->current <= 1)
		return ;
	temp = pa->stack[pa->front];
	pa->stack[pa->front] = pa->stack[pa->front + 1];
	pa->stack[pa->front + 1] = temp;
}//a에 하나 이하의 경우 swap 안되게

void sb(t_a *pa, t_b *pb)
{
	int	temp;

	current_arg(pa, pb);
	if (pb->current <= 1)
		return ;
	temp = pb->stack[pb->front];
	pb->stack[pb->front] = pb->stack[pb->front + 1];
	pb->stack[pb->front + 1] = temp;
}//b에 하나 이하의 경우 swap 안되게

void ss(t_a *pa, t_b *pb)
{
	sa(pa, pb);
	sb(pa, pb);
}

void pa(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	current_arg(pa, pb);
	if (pa->current == 0)
		return ;
	pa->stack[pa->front] = pb->stack[pb->front];
	if (pa->front == 0)
		return ;
	else
		pa->front = (pa->front - 1) % p_ca->max_arg;
	if (pb->front == p_ca->max_arg -1)
		return ;
	pb->front = (pb->front + 1) % p_ca->max_arg;
}

void pb(t_circular_ary *p_ca, t_a *pa, t_b *pb)
{
	current_arg(pa, pb);
	if (pa->current == 0)
		return ;
	pb->stack[pb->front] = pa->stack[pa->front];
	if (pa->front == p_ca->max_arg -1) // 다 찼으면
		return ;
	else
		pa->front = (pa->front + 1) % p_ca->max_arg;
	if (pb->front == 0) // 다 찼으면
		return ; // 그만
	else
		pb->front = (pb->front - 1) % p_ca->max_arg;
}
//pb 했다가 pa했을때

void ra(t_circular_ary *p_ca, t_a *pa)
{
	pa->front = (pa->front + 1) % p_ca->max_arg;
	pa->rear = (pa->rear + 1) % p_ca->max_arg;
}
	//front, rear 둘다 하나씩 증가
//스택이 하나 둘 비어있을때 ra하면?
void current_arg(t_a *pa, t_b *pb)//현재 남아있는 원소 갯수
{
	pa->current = pa->rear - pa->front + 1;
	pb->current = pb->rear - pb->front + 1;
}