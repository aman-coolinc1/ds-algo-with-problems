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
	new_node->next = root->next;
	root->next = new_node;
	return new_node;
}

ListNode * find_value_in_list(ListNode * root, int val)
{
	ListNode* curr = root;
	while (curr) {
		if (curr->data == val)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

ListNode* delete_node_after(ListNode*, int) {
	return nullptr;
}
