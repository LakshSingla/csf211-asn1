#ifndef DEFRAGMENT_H
#define DEFRAGMENT_H

/*************************************************************************
 * WORKING OF DEFRAGMENT
 * After defragmentation, we know that all the allocated list members
 * will lie in starting positions of the array and all the free members 
 * will lie in latter posiitons. Hence we define a variable called `barrier`
 * which denotes the maximum position upto which a filled location can lie.
 * We start traversing all the linked lists in order and for the element not
 * present inside or on this barrier is moved to a free location lying inside 
 * barrier (which is in wrong place).
 * In the end, free list is initialized once again from position after the 
 * barrier in a linear fashion.
 * It achieves the following 
 *
 * Time Complexity: O(N), because it traverses each node of the list (be it 
 * free or filled) atmost twice (once while checking if in correct position 
 * and shifting in constant time if not) and then once more over the free list 
 * to update the next pointers
 *
 * Space Complexity: O(1), because number of elements stored outside the arra
 *                         is constant
**************************************************************************/
/**
 * Defragments the array
*/
void defragment();
/**
 * Returns that location of free_list starting from
 * fl_head, which is lying inside barrier (i.e is not
 * in its correct place)
*/
int update_fl_head(int fl_head, int barrier);

#endif
