#include <stdio.h>
#include <stdlib.h>


#define LIST_LENGTH 4

typedef struct node_str node;

typedef struct node_str {
	int data;
	node* next;
	node* prev;
} node;



node* create_node(int data);
int insert_node(node* add,node* new);
node* create_random_list(int len);
int print_list(node* list);
int remove_node(node* target,node* del);
int free_list(node* list);

//Implementation
//add is the node which will the add new after.
int insert_node(node* add,node* new){
	//printf("insert_node\n");
	if(add->next) {		
		new->next = add->next;
		new->prev = add;
		new->next->prev = new;
		add->next = new;
	
	} else {
		add->next = new;
		new->prev = add;
	}

		
	return 0;
		
}
//del is the parent of the delete node
int delete_node(node* del){
	
	if((!del) && (!del->next)) {
		printf("Empty target!");
		return -1;
	}
			
	node* tmp = del->next; 
	if(!tmp->next) {
		printf("Delete end targed!");
		del->next = NULL;
	} else
		del->next = del->next->next;
	
	free(tmp);

	return 0;
		
}

node* search_node(node* list,int data) {
	while(list){
		if(list->data == data)
			return list;
		list = list->next;
	}
	return NULL;
}

/*
//Search the node befor target node
node* search_target_front_node(node* list,int data) {
	node* front = NULL;
	while(list){
		if(list->data == data)
			return front;
		front = list;
		list = list->next;
	}
	
	return NULL;
}
*/
//Delete the node whose value is data
int delete_data(node** list,int data){
	node* current = *list;
	node* previous = NULL;
	if(list == NULL) {
		printf("Empty list\n");
		return -1;
	}
		
	while(current && (current->data != data)) {
		//previous = current;
		current = current->next;
	}
	if(current == NULL){
		printf("Not Found! \n"); 
		return -1;
	}
		
	//The first node
	if(current->prev == NULL) {
		printf("First node!!!\n");
		(*list) = (*list)->next;
		(*list)->prev = NULL;
		free(current);
		printf("Delete the first node\n");
	} else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		printf("Find and free %d!\n",data);
	}
		
	return 0;
		
}
int reverse_list(node** list) {
	//node* previous = *list;
	node* current = (*list)->next;
	node* preceding = NULL;
	
	printf("reverse_list\n");
	if(!current)
		return 0;
		
	//preceding = current->next;	
	current->prev->next = NULL;
	
	while(current) {
	//	printf(" %2d ",current->data);
		preceding = current->next;
		current->prev->prev = current;
	    //previous = current;
	    current->next = current->prev;
	    if(!preceding)
	    	break;
	    current = preceding;
	}
	
	*list = current;
	
}
//Push a node in the back of the list
int push_back(node* list, node* back) {
	//node* previous = NULL;
	
	printf("Push_back \n");
	if(list == NULL) {
		printf("Empty list!\n");
		return -1;
	}
	
	while(list->next) {
		list = list->next;
	}
	list->next = back;
	back->prev = list;
	return 0;
}
//Add a node to the first
int push_front(node** list, node* front) {
	
	if(list == NULL) {
		printf("Empty list!\n");
		return -1;
	}
	
	front->next = *list;
	(*list)->prev = front;
	*list = front;
	
	printf("push_front \n");
	
	return 0;
}

node* create_node(int data) {
	//printf("create_node\n");
	node* tmp = (node*) malloc(sizeof(node));
	if(tmp) {
		tmp->data = data;
		tmp->next = NULL;
		tmp->prev = NULL;
		return tmp;
	}
	return NULL;
}

int print_list(node* list){
	node* ptr = list;
	if(list == NULL) {
		printf("Null List!!! \n");
		return -1;
	}
	
//	printf("list = %p, &list = %p \n",list,&list);
//	printf("ptr = %p, &ptr = %p \n",ptr, &ptr);
	while(ptr) {
		printf("%2d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int free_list(node* list){
	node* ptr;
	printf("Free ");
	while(list){
		ptr = list;
		printf("%d ", ptr->data);
		list = list->next;
		free(ptr);
	}
	printf("\n");
	return 0;
}
node* create_random_list(int len){
	int i;
	node* ptr;
	printf("create_ramdom_list\n");
	node* head = create_node(rand()%100);
	for(i = 0,ptr = head;i < len - 1;i++){
		insert_node(ptr, create_node(rand()%100));
		ptr = ptr->next;
	}
	return head;
}



int main(void) {
	node* list;
	
	list = create_random_list(LIST_LENGTH);
	
//	printf("list = %p,&list = %p \n",list,&list);
	print_list(list);
	//insert a node
//	delete_data(&list,58);
	
	push_back(list,create_node(rand()%100)); 
	print_list(list);
	push_front(&list,create_node(rand()%100));
	print_list(list);
	
	reverse_list(&list);
	print_list(list);
	
	delete_data(&list,41);
	print_list(list);
	free_list(list);
	list = NULL;
//	print_list(list);
	printf("Done!  \n");

	return 1;
}


