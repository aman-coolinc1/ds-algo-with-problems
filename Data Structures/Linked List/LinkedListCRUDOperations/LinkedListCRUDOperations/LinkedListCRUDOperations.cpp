#include <iostream>
#include "LinkedListCRUDOperations.h"

ListNode* create_node(int val) {
	return new ListNode(val);
}

ListNode* add_node_to_front(ListNode* root, ListNode* new_node) {
	if (new_node == nullptr) {
		throw std::invalid_argument("Adding nullptr to list is not allowed");
	}
	new_node->next = root;
	return new_node;
}

ListNode* add_node_after(ListNode* root, ListNode* new_node) {
	if (!root) {
		return add_node_to_front(root, new_node);
	}
	if (new_node == nullptr) {
		throw std::invalid_argument("Adding nullptr to list is not allowed");
	}
	root->next = new_node;
	return new_node;
}