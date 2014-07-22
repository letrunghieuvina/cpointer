#include <stdio.h>
#include <string.h>

typedef struct _node {
	void* data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* tail;
	Node* current;
} LinkedList;

// This initializes a LinkedList, set all fields to NULL
void initializeList(LinkedList* list);

// add data to head of the list
void addHead(LinkedList* list, void* data);

// add data to tail of the list
void addTail(LinkedList* list, void* data);

//delete a node in the list
void delete(LinkedList* list, Node* node);

// get a node in the list
Node* getNode(LinkedList* list, COMPARE compare, void* data);

void displayLinkedList(LinkedList* list, DISPLAY display);

int main() {

}


// This initializes a LinkedList, set all fields to NULL
void initializeList(LinkedList* list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

// add data to head of the list
void addHead(LinkedList* list, void* data){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	if(list->head == NULL){
		list->tail = node;
		node->next = NULL;
	} else {
		node->next = list->head;
	}
	list->head = node;
}

// add data to tail of the list
void addTail(LinkedList* list, void* data){
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(list->tail == NULL){
		list->head = NULL;
	} else {
		list->tail->next = node;
	}
	list->tail = node;
}

// delete a node in the list
// this also free the allocated memory of node (but node node->data).
void delete(LinkedList* list, Node* node) {
	Node* temp = list->head;
	if(temp == node) {
		//case there is only 1 item in the linked list
		if(list->head == list->tail) {
			
		}
		
	} else {
		while(temp != NULL && temp->next != node) {
			
		}
	}
}

// get a node in the list
Node* getNode(LinkedList* list, COMPARE compare, void* data);


