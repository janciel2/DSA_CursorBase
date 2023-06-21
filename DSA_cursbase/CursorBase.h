#ifndef CURSOR_BASE_H
#define CURSOR_BASE_H
#define MAX 10


typedef char String[20];
typedef int List;

typedef struct
{
	int studID;
	String studName;
	String program;
	char sex;
} Student;

typedef struct
{
	Student elem;
	int next;
} SType;

typedef struct
{
	SType elems[MAX];
	int avail;
} VirtualHeap;

Student newStudent(int studID, String studName, char sex, String program);
VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *vh);
void insertFront(VirtualHeap *vh, List *list, Student s);

void displayList(VirtualHeap vh, List list);
void visualizeSpace(VirtualHeap vh);

void deallocSpace(VirtualHeap *vh, int index);
Student removeStudent(VirtualHeap *vh, List *list, String keyword);



#endif