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
	tree_node* newNode = new tree_node; // Creation of new node.
	newNode->content = input;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;

	char direction = 'c'; // default value ( c for center ) ( doesn't really matter ).
	tree_node *next_node = top, *prev_node = top;
	while (true) {
		prev_node = next_node;
		if (input <= next_node->content) { // If it is smaller or of equal value...
			if (next_node->leftNode != NULL) { // If there is already a node...
				next_node = next_node->leftNode; // Move to that node.
				continue;
			}
			direction = 'l'; // If not, this value is going to the LEFT side.
			break;
		}
		else { // If it is bigger than the value at current node...
			if (next_node->rightNode != NULL) { // but right node is not empty...
				next_node = next_node->rightNode; // move to that node.
				continue;
			}
			direction = 'r'; // If not, this value is going to the RIGHT side.
			break;
		}
	}
	// Set a side's node according to results above.
	if (direction == 'l') prev_node->leftNode = newNode;
	else prev_node->rightNode = newNode;
}

void Binary_Tree::print(tree_node* node, string indent_prefix) { // expected values: (top, "")
	if (node != NULL) {
		cout << to_string(node->content) << endl; // default return value.
	}
	else {
		cout << "NULL" << endl; // Error handling
		return;
	}

	//if (node->leftNode == NULL && node->rightNode == NULL) { // If there is nothing after, print nothing (removed to show NULL).
		//return;
	//}

	// print right.
	cout << indent_prefix << "|------";
	print(node->rightNode, indent_prefix + "|\t"); // add '|' to connect the left node print.
	// print left.
	cout << indent_prefix << "|______";
	print(node->leftNode, indent_prefix + "\t"); // no need for '|' as both values already printed.
}

tree_node* Binary_Tree::get_top() {
	return top;
}

void Binary_Tree::debug_print_both_sides(tree_node* node) { // for troubleshooting.
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