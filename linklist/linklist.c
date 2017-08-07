#include <stdio.h>
#include <stdlib.h>

typedef struct node_str node;

typedef struct node_str {
	int data;
	node* next;
} node;



node* create_node(int data);
int insert_node(node* add,node* new);
node* create_random_list(int len);
int print_list(node* list);
int remove_node(node* target,node* del);
int free_list(node* list);

//Implementation

int insert_node(node* add,node* new){
	//printf("insert_node\n");
	if(add->next) {		
		new->next = add->next;
		add->next = new;
	
	} else
		add->next = new;
		
	return 0;
		
}

node* create_node(int data) {
	//printf("create_node\n");
	node* tmp = (node*) malloc(sizeof(node));
	if(tmp) {
		tmp->data = data;
		tmp->next = NULL;
		return tmp;
	}
	return NULL;
}

int print_list(node* list){
	node* ptr = list;
	printf("list = %p, &list = %p \n",list,&list);
	printf("ptr = %p, &ptr = %p \n",ptr, &ptr);
	while(ptr){
		printf("%2d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int free_list(node* list){
	node* ptr;
	while(list){
		ptr = list;
		list = list->next;
		free(ptr);
	}
	return 0;
}
node* create_random_list(int len){
	int i;
	node* ptr;
	printf("create_ramdom_list\n");
	node* head = create_node(rand()%100);
	for(i = 0,ptr = head;i < len;i++){
		insert_node(ptr, create_node(rand()%100));
		ptr = ptr->next;
	}
	return head;
}



int main(void) {
	node* list;
	
	list = create_random_list(10);
	
	printf("list = %p,&list = %p \n",list,&list);
	print_list(list);
	free_list(list);
	
	printf("Done!  \n");

	return 1;
}


