#include "linklist.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	LinkList list;
	init_list(&list);
	insert_tail(&list,5);
	insert_tail(&list,10);
	insert_tail(&list,14);
	insert_head(&list,8);

	show_list(&list);
	//remove_node(&list,5);
	//show_list(&list);

	//cout << is_Empty(&list) << endl;
	//cout << list_size(&list) << endl;

//	clear_list(&list);
//	destroy_list(&list);
//	cout << list_size(&list) << endl;

	printListReversely_iteratively(list);
	printListReversely_recursively(list);
	cout << endl;

	insert_head(NULL,5);

	return 0;
}
