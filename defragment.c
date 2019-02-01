#include "defragment.h"

#include "global_var.h"
#include "list_utils.h"

void defragment() {
	int total_elems = all_elem_count();
	int barrier = (total_elems-1) * 3;

	if(free_list == -1) return;

	int fl_head = free_list;

	for(int i = 0; i < no_of_lists && fl_head != -1; ++i) {
		int list_head = listptrs[i];

		if(list_head == -1) continue;
		int list_next = linked_list[list_head+1];

		if(list_head > barrier) {
			fl_head = update_fl_head(fl_head, barrier);	
			if(fl_head == -1) break;
			int x = linked_list[fl_head+1];
			linked_list[fl_head] = linked_list[list_head];
			linked_list[fl_head+1] = linked_list[list_head+1];
			linked_list[fl_head+2] = linked_list[list_head+2];
			listptrs[i] = fl_head;
			if(list_next != -1) {
				linked_list[list_next+2] = fl_head;
			}
			fl_head = x;
		}

		while(list_next != -1) {
			if(list_next > barrier)	{
				fl_head = update_fl_head(fl_head, barrier);
				if(fl_head == -1) break;
				int x = linked_list[fl_head+1];
				linked_list[fl_head] = linked_list[list_head];
				linked_list[fl_head+1] = linked_list[list_head+1];
				linked_list[fl_head+2] = linked_list[list_head+2];

				linked_list[list_head+1] = fl_head;
				
				int ntn = linked_list[fl_head+1];
				if(ntn != -1) {
					linked_list[ntn+2] = fl_head;
				}
				
				fl_head = x;
				
			}

			list_head = linked_list[list_head+1];
			list_next = linked_list[list_next+1];
		}
		
	}
	free_list = total_elems * 3;
	for(int i = free_list; i < (no_of_elems-1) * 3; i=i+3) {
		linked_list[i+1] = i+3;	
	}


	linked_list[(no_of_elems-1)*3] = -1;

}


int update_fl_head(int fl_head, int barrier) {
	while(fl_head > barrier) fl_head = linked_list[fl_head+1];
	return fl_head;
}
