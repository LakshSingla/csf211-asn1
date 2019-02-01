#include "defragment.h"

#include "global_var.h"
#include "list_utils.h"

void defragment() {
	int total_elems = all_elem_count();	
	//Filled elements can have index upto and including barrier
	int barrier = (total_elems-1) * 3;
	int fl_head = free_list;

	/*int current_list = 0;
	int current_elem = listptrs[current_list];

	if(head == -1) return;
	
	while(head <= unpermissible_free_list) {
		head = free_list = linked_list[head+1];
		while(current_elem <= unpermissible_free_list){
			increment_elem();
		}
		head = current_elem;
		increment_elem();
	}*/

	for(int i = 0; i < no_of_lists && fl_head != -1; ++i) {
		int list_head = listptrs[i];
		if(list_head == -1) continue;
		while (list_head > barrier) {
			if(free_list <= barrier) {
				
				int fl_head = free_list;

				free_list = linked_list[fl_head+1];

				linked_list[fl_head] = linked_list[list_head];
				linked_list[fl_head+1] = linked_list[list_head+1];
				linked_list[fl_head+2] = linked_list[list_head+2];

				int list_next = linked_list[fl_head+1];
				if(list_next != -1) {
					linked_list[list_next+2] = fl_head;	
				}

				listptrs[i] = fl_head;
				list_head = listptrs[i];

				delete_loc(list_head);

			}
			else {
				int free_list_head = free_list;
				int free_list_next = linked_list[free_list+1];
				while(free_list_next > barrier) {
					linked_list[free_list_head] = linked_list[free_list_head+1];
					linked_list[free_list_next] = linked_list[free_list_next+1];
				}

				listptrs[i] = free_list_next;
				list_head = listptrs[i];

				linked_list[free_list_next] = linked_list[list_head];
				linked_list[free_list_next+1] = linked_list[list_head+1];
				linked_list[free_list_next+2] = linked_list[list_head+2];

				int list_next = linked_list[list_head+1];
				if(list_next != -1) {
					linked_list[list_head+1] = linked_list[linked_list[list_head+1]];	
				}
					
				delete_loc(list_head);

			}

		}
		int list_next = linked_list[list_head+1];
		while(list_next != -1) { 
			if(list_next > barrier) {
				if(free_list <= barrier) {
					int fl_head = free_list;	

					free_list = linked_list[fl_head+1];

					linked_list[fl_head] = linked_list[list_next];
					linked_list[fl_head+1] = linked_list[list_next+1];
					linked_list[fl_head+2] = linked_list[list_next+2];

					linked_list[list_head+1] = list_next;
					int list_next_to_next = linked_list[list_next+1];
					if(list_next_to_next != -1) {
						linked_list[list_next_to_next+2] = list_next;
					}

					delete_loc(list_next);

					list_next = linked_list[fl_head];
				}

				else {
					int free_list_head = free_list;				
					int free_list_next = linked_list[free_list+1];				
					while(free_list_next > barrier) {
						linked_list[free_list_head] = linked_list[free_list_head+1];
						linked_list[free_list_next] = linked_list[free_list_next+1];
					}
					linked_list[free_list_next] = linked_list[list_next];
					linked_list[free_list_next+1] = linked_list[list_next+1];
					linked_list[free_list_next+2] = linked_list[list_next+2];
					int x = free_list_next;
					int free_list_next_to_next = linked_list[free_list_next+1];
							
				}
			}
			list_head = linked_list[list_head+1];
			list_next = linked_list[list_next+1];
		}
	}
}


/*void increment_elem(int *current_list, int *current_elem) {
	if(*current_list == no_of_lists-1 || current_elem == -1) {
		printf("No more elems\n");	
		return
	}
	if(elem == -1) {
		(*current_list)++;
		*current_elem = linked_list[listptrs[*current_list]];
		return;
	}
	*current_elem = linked_list[*current_elem + 1];
}

int is_head(int current_elem, current_list) {
	return listptrs[current_list] == current_elem;
}*/
