#include <iostream>
#include "LinkedListCRUDOperations.h"

ListNode* create_node(int val) {
	return new ListNode(val);
}

ListNode* add_node_to_front(ListNode* root, ListNode* new_node) {
	new_node->next = root;
	return new_node;
}