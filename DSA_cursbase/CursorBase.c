#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CursorBase.h"


Student newStudent(int studID, String studName, char sex, String program)
{
	Student s;
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap()
{
	VirtualHeap vh;
	int i;
	
	for(i = 0; i < MAX; i++)
	{
		vh.elems[i].elem = newStudent(0, "", ' ', "");
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX - 1;
	return vh;
}

int allocSpace(VirtualHeap *vh)
{
	int retVal;
	retVal = vh->avail;
	
	if(retVal != -1)
		{
			vh->avail = vh->elems[vh->avail].next;
		}	
	return retVal;
}

void insertFront(VirtualHeap *vh, List *list, Student s)
{
	List temp = allocSpace(vh);
	
	
	if(temp != -1)
	{
		vh->elems[temp].next = *list;
		*list = temp;
		vh->elems[temp].elem = s;
	}

}

void displayList(VirtualHeap vh, List list)
{
	int i;
	printf("%15s | %40s | %5s | %10s\n", "STUDENT ID", "STUDENT NAME", "SEX", "PROGRAM");
	printf("------------------------------------------------------------------------------\n");
	for(i = list; i != -1; i = vh.elems[i].next)
		{
			printf("%15d | %40s | %5c | %10s\n", vh.elems[i].elem.studID, vh.elems[i].elem.studName, vh.elems[i].elem.sex, vh.elems[i].elem.program);
		}
		printf("------------------------------------------------------------------------------\n");
}

void visualizeSpace(VirtualHeap vh)
{
	int i;
	printf("%5s | %30s | %5s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("--------------------------------------------\n");
	
	for(i = 0; i < MAX; i++)
	{
		printf("%5d | ", i);
			if(vh.elems[i].elem.studID == 0)
			{
				printf("%30s | ", "Empty");
			}
			
			else
			{
				printf("%4d - %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
			}
			
			printf("%d\n", vh.elems[i].next);
	}
	
		printf("--------------------------------------------\n");
		printf("AVAILABLE: %d\n\n", vh.avail);
}

Student removeStudent(VirtualHeap *vh, List *list, String keyword)
{	
  Student retval;
	if(*list != -1)
		{
		
			int i; 
			List temp, *trav;
			for(trav = list; *trav != -1 ; )
				{		
					if(strcmp(vh->elems[(*trav)].elem.studName, keyword) == 0)
					{
						   temp = (*trav);
						   (*trav) = vh->elems[temp].next;
							retval = newStudent(vh->elems[temp].elem.studID, vh->elems[temp].elem.studName, vh->elems[temp].elem.sex, vh->elems[temp].elem.program); 	
							deallocSpace(vh, temp);	 retval;
						return retval;
					}
					else
					{
						trav = &vh->elems[(*trav)].next;
					}
				}
	    }
	    
}

void deallocSpace(VirtualHeap *vh, int index)
{
	if(index != -1 || index < MAX)
	{
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0, "", ' ', "");
	    vh->avail = index;
	}
	
//	 vh->elems[index-1].next = vh->elems[index].next //update the connection 
}



