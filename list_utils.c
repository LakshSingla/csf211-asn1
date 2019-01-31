#include "list_utils.h"

#include <stdio.h>

#include "global_var.h"

void free_complete_list(){
	for(int i = 0; i < no_of_elems-1; ++i) {
		linked_list[3*i+1] = 3*(i+1);	
	}
	linked_list[3*(no_of_elems-1)+1] = -1;
	free_list = 0;
}

int create_new_list(int key) {
	if(no_of_lists == no_of_elems){
		return -2;	
	}

	else if(free_list == -1) {
		return -1;	
	}
	
	else {
		int pos = obtain_loc();
		if(pos == -1) return -1;
		listptrs[no_of_lists] = pos;

		linked_list[pos] = key;
		linked_list[pos+1] = -1;
		linked_list[pos+2] = -1;

		no_of_lists++;
	}

	return 1;
}

void insert_in_list(int list_no, int key){
	if(free_list == -1) {
		printf("FAILURE: Insufficient memory to enter new element\n");	
		return;
	}
	int freeloc = obtain_loc();
	linked_list[freeloc] = key;
	int head = listptrs[list_no];
	if(head == -1) {
		head = freeloc;
		linked_list[freeloc+1] = linked_list[freeloc+2] = -1;
		return;	
	}
	else if(linked_list[head] < key) {
		linked_list[freeloc+1] = head;
		linked_list[freeloc+2] = -1;
		linked_list[head+2] = freeloc;
		listptrs[list_no] = freeloc;
	}
	else {
		int next = linked_list[head+1];				
		while(next != -1) {
			if(linked_list[next] < key){
				break;
			}			
			next = linked_list[next+1];
			head = linked_list[head+1];
		}
		linked_list[freeloc+1] = next;
		linked_list[freeloc+2] = head;
		linked_list[head+1] = freeloc;
		if(next != -1){
			linked_list[next+2] = freeloc;
		}
	}
	printf("SUCCESS: Element inserted in list");
}

void delete_from_list(int list_no, int key) {
	int head = listptrs[list_no];
	if(head == -1) {
		printf("FAILURE: List already empty\n");
		return;	
	}
	else if (linked_list[head] == key) {
		int next =  linked_list[head+1];
		listptrs[list_no] = next;
		delete_loc(head);	
		if(next != -1) {
			linked_list[next+2] = -1;
		}
		printf("SUCCESS: Deleted element from the list\n");
		return;
	}
	else {
		int next = linked_list[head+1];	
		while(next != -1) {
			if(linked_list[next] == key) {
				int next_to_next = linked_list[next+1];
				linked_list[head+1] = next_to_next;
				if(next_to_next != -1) {
					linked_list[next_to_next+2] = head;
				}
				delete_loc(next);
				printf("SUCCES: Deleted element from the list");
				return;
			}
			head = linked_list[head+1];	
			next = linked_list[next+1];	
		}
	}
	printf("FAILURE: Element not found in list");
}

void display_all_lists() {
	for(int i = 0; i < no_of_lists; ++i) {
		printf("Elements of list-%d are: \n", i);
		printf("KEY\tNEXT\tPREV\n");
		int head = listptrs[i];	
		while(head != -1) { 
			printf("%d\t%d\t%d\n", linked_list[head], linked_list[head+1], linked_list[head+2]);
			head = linked_list[head+1];
		}
	}
}

int obtain_loc() {
	if(free_list == -1) return -1;

	int pos = free_list;
	free_list = linked_list[free_list+1];

	return pos;
}

void delete_loc(int loc) {
	linked_list[loc+1] = free_list;
	free_list = loc;
}
