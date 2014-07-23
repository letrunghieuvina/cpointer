#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 30

typedef struct _employee {
	char* name;
	int age;	
} Employee;

typedef struct _student {
	char* name;
	int age;
	char* class;
} Student;

typedef struct _node {
	void* data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* tail;
	Node* current;
} LinkedList;

typedef LinkedList Queue;
typedef LinkedList Stack;

typedef void (*DISPLAY)(void* data);
typedef int (*COMPARE)();

Employee* initEmployee(Employee* employee, char* name, int age);

void destroyEmployee(Employee* employee);

Student* initStudent(Student* student, char* name, int age, char* class);

void destroyStudent(Student* student);

// This initializes a LinkedList, set all fields to NULL
void initLinkedList(LinkedList* list);

// add data to head of the list
void addHead(LinkedList* list, void* data);

// add data to tail of the list
void addTail(LinkedList* list, void* data);

//delete a node in the list
void delete(LinkedList* list, Node* node);

// get a node in the list
Node* getNode(LinkedList* list, COMPARE compare, void* data);

/**---------- functions to manipulate Queue ----------**/
void initQueue(Queue* queue);

void enqueue(Queue* queue, void* data);

void* dequeue(Queue* queue);

/**---------- functions to manipulate Stack ----------**/
void initStack(Stack* stack);

void push(Stack* stack, void* data);

void* pop(Stack* stack);

/**---------------- functions for displaying object info ------------------**/
void displayLinkedList(LinkedList* list, DISPLAY display);

void displayEmployee(Employee* employee);

void displayStudent(Student* student);

int main() {
	
	Employee* peter = NULL;
	peter = initEmployee(peter, "Peter", 20);
	//displayEmployee(peter);
	
	Employee* mary = NULL;
	mary = initEmployee(mary, "Mary", 19);
	//displayEmployee(mary);
	
	Employee* david;
	david = initEmployee(david, "David", 30);
	//displayEmployee(david);
	
	/*
	//demo linked list
	LinkedList linkedList;
	initLinkedList(&linkedList);
	addHead(&linkedList, peter);
	addTail(&linkedList, mary);
	//addTail(&linkedList, &david);
	
	displayLinkedList(&linkedList, displayEmployee);
	//printf("it is %s", ((Employee*)(linkedList.head->data))->name);
	addTail(&linkedList, david);
	displayLinkedList(&linkedList, displayEmployee);
	*/
	
	/*
	//demo Queue
	Queue queue;
	initQueue(&queue);
	enqueue(&queue, peter);
	enqueue(&queue, mary);		
	enqueue(&queue, david);
	displayEmployee((Employee*)dequeue(&queue));
	displayEmployee(dequeue(&queue));
	displayEmployee(dequeue(&queue));	
	*/

	//demo Stack
	Stack stack;
	initStack(&stack);
	push(&stack, peter);
	push(&stack, mary);
	push(&stack, david);
	displayEmployee(pop(&stack));
	displayEmployee(pop(&stack));	
	displayEmployee(pop(&stack));
	
	//destroy employees	
	destroyEmployee(peter);
	destroyEmployee(mary);
	destroyEmployee(david);
	
	return 0;
}

Employee* initEmployee(Employee* employee, char* name, int age) {
	employee = (Employee*) malloc(sizeof(Employee));
	employee->age = age;
	employee->name = (char*) malloc(NAME_LENGTH + 1);
	strcpy(employee->name, name);
	
	return employee;
}

Student* initStudent(Student* student, char* name, int age, char* class) {
	student = (Student*) malloc(sizeof(Student));
	student->name = (char*) malloc(NAME_LENGTH + 1);
	student->class = (char*) malloc(NAME_LENGTH + 1);
	strcpy(student->name, name);
	strcpy(student->class, class);
	student->age = age;

	return student;
}

// This initializes a LinkedList, set all fields to NULL
void initLinkedList(LinkedList* list){
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
	if(node == list->head) {
		//case there is only 1 item in the linked list
		if(list->head == list->tail) {
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = list->head->next;
		}
	} else {
		while(temp != NULL && temp->next != node) {
			temp = temp->next;
		}
		if(temp != NULL) {
			temp->next = node->next;
		}
	}
	free(node);
}

// get a node in the list
Node* getNode(LinkedList* list, COMPARE compare, void* data){
	return NULL;
}

void displayLinkedList(LinkedList* list, DISPLAY display) {
	if(list == NULL) {
		return;
	}
	printf("\nLinked List\n");
	Node* current = list->head;
	while(current != NULL) {
		display(current->data);
		current = current->next;
	} 
}

void displayEmployee(Employee* employee){
	if(employee != NULL) {
		printf("Employee: name = %s, age = %i\n", employee->name, employee->age);
	}
}

void displayStudent(Student* student) {
	if(student != NULL) {
		printf("Student: name = %s, age = %i, class = %s\n", student->name, student->age, student->class);
	}
}



void destroyEmployee(Employee* employee) {
	if(employee->name != NULL) {
		free(employee->name);
	}
	free(employee);
}

void destroyStudent(Student* student) {
	if(student->name != NULL) {
		free(student->name);
	}

	if(student->class != NULL) {
		free(student->class);
	}
	free(student);
}

void initQueue(Queue* queue){
	queue->head = NULL;
	queue->tail = NULL;
	queue->current = NULL;
}

void enqueue(Queue* queue, void* data){
	addHead(queue, data);
}

void* dequeue(Queue* queue) {
	Node* tmp = NULL;
	void* data = NULL;
	if(queue->head == NULL){
		//case the queue is empty
		data = NULL;
	} else if(queue->head == queue->tail) {
		//case the queue has only one item
		tmp = queue->head;
		queue->head = queue->tail = NULL;
		data = tmp->data;
		free(tmp);
	} else {
		tmp = queue->head;
		while(tmp->next != queue->tail){
			tmp = tmp->next;
		}
		queue->tail = tmp;
		tmp = tmp->next;
		queue->tail->next = NULL;
		data = tmp->data;
		free(tmp);
	}
	return data;
}

void initStack(Stack* stack) {
	stack->head = stack->tail = stack->current = NULL;
}

void push(Stack* stack, void* data) {
	addHead(stack, data);
}

void* pop(Stack* stack) {
	Node* tmp = NULL;
	void* data = NULL;
	
	if(stack->head == NULL) {
	//case the stack is empty
		return NULL;	
	} else if(stack->head == stack->tail){
		tmp = stack->head;
		stack->head = stack->tail = NULL;
		data = tmp->data;
		free(tmp);
		
	} else {
		tmp = stack->head;
		stack->head = stack->head->next;
		data = tmp->data;
		free(tmp);	
	}
	return data;
}
