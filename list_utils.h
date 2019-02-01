#ifndef LIST_UTILS_H
#define LIST_UTILS_H

void free_complete_list();
int create_new_list(int);
int obtain_loc();
void delete_loc(int);
void insert_in_list(int, int);
void delete_from_list(int, int);
int list_elem_count(int);
int all_elem_count();
void display_all_lists();
void display_free_list();

#endif
