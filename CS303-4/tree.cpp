#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

Binary_Tree::Binary_Tree(int input) {
	top = new tree_node;
	top->content = input;
	top->leftNode = NULL;
	top->rightNode = NULL;
	height = 1;
}

void Binary_Tree::new_node(int input) {
	tree_node* newNode = new tree_node;
	char direction = 'c';
	newNode->content = input;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;

	size_t curr_height = 1;
	tree_node *next_node = top, *prev_node = top;
	while (true) {
		prev_node = next_node;
		if (input <= next_node->content) { 
			if (next_node->leftNode != NULL) {
				next_node = next_node->leftNode;
				continue;
			}
			direction = 'l';
			break;
		}
		else {
			if (next_node->rightNode != NULL) {
				next_node = next_node->rightNode;
				continue;
			}
			direction = 'r';
			break;
		}
		curr_height += 1;
	}
	if (curr_height > height) height = curr_height;

	if (direction == 'l') prev_node->leftNode = newNode;
	else prev_node->rightNode = newNode;
}

void Binary_Tree::print(tree_node* node, string indent_prefix) { // expected valueds: (top, "")
	if (node != NULL) {
		cout << to_string(node->content) << endl; // default return value.
	}
	else {
		cout << "NULL" << endl; // Error handling
		return;
	}

	if (node->leftNode == NULL && node->rightNode == NULL) { // If there is nothing after, print nothing.
		return;
	}

	// print left
	cout << indent_prefix << "|------";
	print(node->leftNode,indent_prefix+"|\t");
	// print right
	cout << indent_prefix << "|______";
	print(node->rightNode,indent_prefix+"\t");
}

tree_node* Binary_Tree::get_top() {
	return top;
}

void Binary_Tree::debug_print_both_sides(tree_node* node) {
	if (node == NULL) {
		cout << "NULL node" << endl;
		return;
	}
	// left side
	if (node->leftNode == NULL) cout << "Left: NULL, ";
	else cout << "Left: " << node->leftNode->content << ", ";
	// right side
	if (node->rightNode == NULL) cout << "Right: NULL.";
	else cout << "Right: " << node->rightNode->content << ".";
}