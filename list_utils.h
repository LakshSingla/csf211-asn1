#ifndef LIST_UTILS_H
#define LIST_UTILS_H

/**
 * Initializing function, used for creating the free list
*/
void free_complete_list();

/**
 * Creates a new list and inserts value in it
*/
int create_new_list(int);

/**
 * Inserts a value in descending order in the
 * given list if the list exists
*/
void insert_in_list(int, int);

/**
 * Deletes the first value from the list if 
 * the list and the key exists
*/
void delete_from_list(int, int);

/**
 * Returns no of elements present in a list
 * if it exists
*/
int list_elem_count(int);

/**
 * Returns total space occupied by all linked lists
*/
int all_elem_count();

/**
 * Displays all lists in the pattern specified by
 * the question
*/
void display_all_lists();

/**
 * Displays the free locations in the list
*/
void display_free_list();

/**
 * Removes a free member from the free list (if non emptt)
 * and returns it
*/
int obtain_loc();

/**
 * Adds the location specified in the parameter to the free list
*/
void delete_loc(int);

#endif
