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

typedef void (*DISPLAY)(void* data);

Employee* initEmployee(Employee* employee, char* name, int age);

Student* initStudent(Student* student, char* name, int age, char* class);

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

void displayLinkedList(LinkedList* list, DISPLAY display);

void displayEmployee(Employee* employee);

void displayStudent(Student* student);

int main() {
	
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
		printf("Student: name = %s, age = %i, class = %s\n", student->name, student->age, student.class);
	}
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

