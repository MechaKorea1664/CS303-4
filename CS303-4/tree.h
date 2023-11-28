#pragma once
#include <iostream>
using namespace std;

struct tree_node {
	int content;
	tree_node* leftNode;
	tree_node* rightNode;
};

class Binary_Tree {
private:
	tree_node* top;
	size_t height;

public:
	Binary_Tree(int);
	void new_node(int);
	void print(tree_node*,string);
	tree_node* get_top();
	void debug_print_both_sides(tree_node*);
};