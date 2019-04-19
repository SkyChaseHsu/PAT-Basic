#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node
{
	char *name;
	char *id;
	int score;	
	struct _Node * next;
}Node;

typedef struct{
	Node *head;
	Node *tail;
}List;

void add_list(List *list, char *name, char *id, int score);
void trav_list(List *list);
void max_list(List *list);
void min_list(List *list);

int main()
{
	List list;
	list.head = NULL;
	list.tail = NULL;

	int n = 0;
	scanf("%d", &n);

	int i = 0;
	
	char name[11];
	char id[11];
	int score = 0;

	for(i = 1; i <= n; i++)
	{
		scanf("%s %s %d", name, id, &score);

		add_list(&list, name, id, score);
	}

	trav_list(&list);
	max_list(&list);
	min_list(&list);
	return 0;
}

void add_list(List *list, char *name, char *id, int score)
{
	Node * p = (Node *)malloc(sizeof(Node));

	p->name = (char *)malloc(sizeof(name)+1);
	p->id = (char *)malloc(sizeof(id)+1);

	strcpy(p->name, name);
	strcpy(p->id, id);
	p->score = score;
	p->next = NULL;

	if(list->head){
		list->tail->next = p;
		list->tail = p;
	}else{
		list->head = p;
		list->tail = p;
	}
}

void trav_list(List *list)
{
	Node *p;
	for(p = list->head;p;p = p->next){
		// printf("%p %p %p\n", p->name, p->id, &p->score);
		printf("%s %s %d\n", p->name, p->id, p->score);
	}
}

void max_list(List *list)
{
	Node *p;
	int max = list->head->score;
	for(p = list->head;p;p = p->next){
		if(p->score >= max){
			max = p->score;
		}
	}

	Node *q;
	for(q = list->head;q;q = q->next){
		if(q->score == max){
			printf("%s %s %d\n", q->name, q->id, q->score);
		}
	}

}

void min_list(List *list)
{
	Node *p;
	int min = list->head->score;
	for(p = list->head;p;p = p->next){
		if(p->score <= min){
			min = p->score;
		}
	}

	Node *q;
	for(q = list->head;q;q = q->next){
		if(q->score == min){
			printf("%s %s %d\n", q->name, q->id, q->score);
		}
	}

}



