#include "prompter.h"
#include "list_utils.h"
#include "global_var.h"

/**
 * Entry point of the program
*/
int main(void){
	// for(int i = 0; i < 150; ++i) linked_list[i] = -1;
	free_complete_list();
	prompt();
	return 0;
}
