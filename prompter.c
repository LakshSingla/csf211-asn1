#include "prompter.h"

#include <stdio.h>

#include "global_var.h"
#include "list_utils.h"
#include "list_utils.h"
#include "defragment.h"


void prompt() {

	int key, list_no;
	int exit = 0;

	do{
		int choice;
		printf("\n\n");
		printf("1. Create a new list\n");
		printf("2. Insert a new element in a given list in sorted order\n");
		printf("3. Delete an element from a given list\n");
		printf("4. Count total elements excluding free list\n");
		printf("5. Count total elements of a list\n");
		printf("6. Display all lists\n");
		printf("7. Display free list\n");
		printf("8. Perform defragmentation\n");
		printf("0. Press 0 to exit\n");
		
		printf("Select an option: \n");
		scanf("%d", &choice);
	
		switch(choice) {
			case 1:
				printf("Enter key value to be inserted in the newly created list: \n");
				scanf("%d", &key);
				int status = create_new_list(key);
				if(status == 1){
					printf("SUCCESS: ");
				printf("The sequence number of newly created list is: %d\n", no_of_lists-1);
				}
				else if(status == -1) {
					printf("FAILURE: Not enough memory\n");
				}
				else if(status == -2) {
					printf("Maximum no of lists created");	
				}
				break;

			case 2:
				printf("List you want to insert in: ");
				scanf("%d", &list_no);
				if(!(list_no < no_of_lists)) {
					printf("Invalid list no!!\n");
					break;
				}
				printf("Enter the key value: ");
				scanf("%d", &key);
				insert_in_list(list_no, key);
				break;

			case 3:
				printf("List you want to delete from: ");
				scanf("%d", &list_no);
				if(!(list_no < no_of_lists)) {
					printf("Invalid list no!!\n");
					break;
				}
				printf("Enter the key value: ");
				scanf("%d", &key);
				delete_from_list(list_no, key);
				break;

			case 4:
				printf("Total number of nodes in all lists are: %d\n", all_elem_count());
				break;

			case 5:
				printf("Enter the list number: ");
				scanf("%d", &list_no);
				if(!(list_no < no_of_lists)) {
					printf("Invalid list no!!\n");
					break;
				}
				printf("Total number of nodes in list %d are: %d\n", list_no, list_elem_count(list_no));
				break;

			case 6:
				display_all_lists();
				break;

			case 7:
				display_free_list();
				break;

			case 8:
				defragment();
				break;

			case 9:
				for(int i = 0; i < 150; i=i+3){
					printf("* %d ", linked_list[i]);	
				}
				break;

			case 0:
				exit = 1;		
				break;

			default:
				printf("Please enter a valid option!!\n");
				break;
		}
	}while(!exit);
}
