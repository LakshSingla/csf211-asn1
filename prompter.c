#include "prompter.h"
#include "global_var.h"
#include "list_utils.h"

#include <stdio.h>

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
				printf("Total number of nodes in all lists are: xx\n");
				//TODO
				break;

			case 5:
				printf("Enter the list number: ");
				scanf("%d", &list_no);
				printf("Total number of nodes in list xx are: yy\n");
				//TODO
				break;

			case 6:
				display_all_lists();
				break;

			case 7:
				printf("Elements of free list are: ");
				//TODO
				break;

			case 8:
				//TODO
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
