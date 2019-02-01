#include "prompter.h"
#include "list_utils.h"
#include "global_var.h"

int main(void){
	for(int i = 0; i < 150; ++i) linked_list[i] = -256;
	free_complete_list();
	prompt();
}
