#include <stdio.h>
#include <stdlib.h>
#include "CursorBase.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	Student s;
	List myList = -1;
	
	visualizeSpace(myHeap);
	insertFront(&myHeap, &myList, newStudent(101, "Jonathan", 'M', "BS IT"));
	insertFront(&myHeap, &myList, newStudent(104, "Sebastian", 'M', "BS CS"));
	insertFront(&myHeap, &myList, newStudent(202, "Maria Clara", 'F', "BS IS"));
	

	visualizeSpace(myHeap);
	
	displayList(myHeap, myList);
	
	printf("\n%d %d\n", myHeap.avail, myList);
	s = removeStudent(&myHeap, &myList, "Sebastian");
	printf("REMOVE:  %s \n", s.studName);
	
	displayList(myHeap, myList);
	printf("\n%d %d\n", myHeap.avail, myList);
	visualizeSpace(myHeap);
	return 0;
}
