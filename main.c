#include "prompter.h"
#include "list_utils.h"
#include "global_var.h"

/**
 * Entry point of the program
*/
int main(void){
	free_complete_list();
	prompt();
	return 0;
}
