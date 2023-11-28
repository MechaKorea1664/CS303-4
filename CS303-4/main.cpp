#include <iostream>
#include "tree.h"

int main() {

	// PART 2:
	int example_input[9] = { 30,15,4,20,18,19,35,32,38 };

	Binary_Tree* BT = new Binary_Tree(example_input[0]);
	for (int i = 1; i < 9; i++) {
		BT->new_node(example_input[i]);
	}

	BT->print(BT->get_top(), "");
	return 0;
}