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
		printf("****%d", pos);

		no_of_lists++;
	}

	return 1;
}

int obtain_loc() {
	if(free_list == -1) return -1;

	int pos = free_list;
	free_list = linked_list[free_list+1];

	return pos;
}
