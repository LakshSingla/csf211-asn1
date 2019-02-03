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
 * barrier.
 * It achieves the following 
 * Time Complexity: O(N), because it traverses each node of the 
 *                        list (be it free or filled) atmost once
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
