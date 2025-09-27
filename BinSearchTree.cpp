// Construct binary search tree from these numbers 
//5,7,2,9,3,4,6,1,8,7,3
//Show how to visit this tree using 4 different algorithms
//(BFS,pre-order,in-order,post-order)
// BFS: 5, 2, 7, 1, 3, 6, 9, 4, 8
//in-order: LFR: 1,2,3,4,5,6,7,8,9
//Pre-order: FLR
///post-order: LRF


/**************************** Binary search tree****************************/
#include <iostream>
using namespace std;

struct binary_node
{
	int data;
	binary_node* left, * right;
};

class binary_search_tree
{
private://7
	binary_node* root;
	binary_node* make_new_node(int dd);
	void rec_insertion(binary_node* ptr, int dd);
	void rec_pre_order(binary_node* ptr);
	void rec_in_order(binary_node* ptr);
	void rec_post_order(binary_node* ptr);
	bool rec_search(binary_node* ptr, int dd);
	bool rec_delete_data(binary_node** ptr, int dd);
public://7
	binary_search_tree() { root = NULL; }
	void insert_data(int dd);
	bool search_data(int dd);
	bool remove_data(int dd);
	void print_pre_order(void);
	void print_in_order(void);
	void print_post_order(void);
};

binary_node* binary_search_tree::make_new_node(int dd)
{
	binary_node* temp = new binary_node;
	temp->data = dd;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void binary_search_tree::insert_data(int dd)
{
	if (root == NULL)		root = make_new_node(dd);
	else					rec_insertion(root, dd);
}

void binary_search_tree::rec_insertion(binary_node* ptr, int dd)
{
	if (dd < ptr->data)
	{
		if (ptr->left == NULL)		ptr->left = make_new_node(dd);
		else						rec_insertion(ptr->left, dd);
	}
	else if (dd > ptr->data)
	{
		if (ptr->right == NULL)		ptr->right = make_new_node(dd);
		else						rec_insertion(ptr->right, dd);
	}
}

void binary_search_tree::print_pre_order()
{
	if (root == NULL)	cout << "Empty tree, pre order print will be canceled \n";
	else
	{
		cout << "Nodes by Pre order: \t";
		rec_pre_order(root);
		cout << "\n";
	}
}
void binary_search_tree::print_in_order()
{
	if (root == NULL)	cout << "Empty tree, in order print will be canceled \n";
	else
	{
		cout << "Nodes by in order:\t";
		rec_in_order(root);
		cout << "\n";
	}
}
void binary_search_tree::print_post_order()
{
	if (root == NULL)	cout << "Empty tree, post order print will be canceled \n";
	else
	{
		cout << "Nodes by post order: \t";
		rec_post_order(root);
		cout << "\n";
	}
}

void binary_search_tree::rec_pre_order(binary_node* ptr)//FLR
{
	if (ptr == NULL)		return;
	cout << ptr->data << "\t";
	rec_pre_order(ptr->left);
	rec_pre_order(ptr->right);
}
void binary_search_tree::rec_in_order(binary_node* ptr)//LFR
{
	if (ptr == NULL)		return;
	rec_in_order(ptr->left);
	cout << ptr->data << "\t";
	rec_in_order(ptr->right);
}
void binary_search_tree::rec_post_order(binary_node* ptr)
{
	if (ptr == NULL)		return;
	rec_post_order(ptr->left);
	rec_post_order(ptr->right);
	cout << ptr->data << "\t";
}

bool binary_search_tree::search_data(int dd)
{
	if (root == NULL)
	{
		cout << "You can not search for " << dd << " in an empty tree\n"; 
		return false;
	}
	else  return rec_search(root, dd);
}

bool binary_search_tree::rec_search(binary_node* ptr, int dd)
{
	if (ptr == NULL)
	{
		cout << dd << "could not be found \n";  return false;
	}
	else if (ptr->data == dd)
	{
		cout << dd << "found in the tree\n";	return true;
	}
	else if (ptr->data < dd)		return rec_search(ptr->right, dd);
	else if (ptr->data > dd)		return rec_search(ptr->left, dd);
}

bool binary_search_tree::remove_data(int dd)
{
	if (root == NULL)
	{
		cout << "You can not delete from an empty tree\n";  return false;
	}
	else  return rec_delete_data(&root, dd);//sends the adresse of root 
}

bool binary_search_tree::rec_delete_data(binary_node** pt, int key)//data that is inside the addresse i gues
{
	if (*pt == NULL) { cout << key << " could not be deleted\n"; return false; }
	//* -> value inside 
	if ((*pt)->data > key)		return rec_delete_data(&((*pt)->left) , key);
	else if ((*pt)->data < key)	return rec_delete_data(&((*pt)->right), key);
	
	else if ((*pt)->data == key)
	{
		if ((*pt)->left == NULL)				*pt = (*pt)->right;
		else if ((*pt)->right == NULL)			*pt = (*pt)->left;
		
		else if ((*pt)->left->right == NULL) { (*pt)->left->right = (*pt)->right;	*pt = (*pt)->left; }
		else if ((*pt)->right->left == NULL) { (*pt)->right->left = (*pt)->left;	*pt = (*pt)->right; }
		
		else
		{
			binary_node* temp = *pt;
			temp = temp->left;
			while (temp->right->right != NULL)
				temp = temp->right;
			(*pt)->data = temp->right->data;
			temp->right = temp->right->left;
		}
		cout << "\nNumber " << key << " will be replaced in the tree by number " << (*pt)->data << "\n";
		return true;
	}
}


int main() {
	binary_search_tree bst;
	//bst.insert_data(5);
	//bst.insert_data(3);
	//bst.insert_data(8);
	//bst.insert_data(1);
	//bst.insert_data(9);
	//bst.insert_data(7);
	//bst.insert_data(6);
	//bst.insert_data(2);
	//bst.insert_data(4);

	bst.insert_data(5);
	bst.insert_data(7);
	bst.insert_data(2);
	bst.insert_data(9);
	bst.insert_data(3);
	bst.insert_data(4);
	bst.insert_data(6);
	bst.insert_data(1);
	bst.insert_data(8);
	bst.insert_data(7);
	bst.insert_data(3);

	bst.print_pre_order();
	bst.print_in_order();
	bst.print_post_order();

	bst.remove_data(5);
	bst.print_pre_order();
}


































//struct BIN_node
//{
//	int data;
//	BIN_node *left, *right;
//};
//
//class binary_search_tree
//{
//private:
//
//	BIN_node* make_new_node(int dd);
//	void rec_insertion(BIN_node *ptr, int dd);
//	void rec_pre_order(BIN_node *ptr);
//	void rec_in_order(BIN_node *ptr);
//	void rec_post_order(BIN_node *ptr);
//	bool rec_search(BIN_node *ptr , int dd);
//	bool rec_delete_data(BIN_node **ptr , int dd);
//	BIN_node* find_min_right_sub_tree(BIN_node* n) {
//		while (n->left) {
//			n = n->left;
//		}
//		return n;
//	}
//public:
//	BIN_node *root;
//	binary_search_tree()  { root = NULL; }
//	void insert_data(int dd);
//	bool search_data(int dd);
//	bool remove_data(int dd);
//	void print_pre_order(void);
//	void print_in_order(void);
//	void print_post_order(void);
//	void delete_node(int val, BIN_node* n) {
//		if (!n)		return;
//		//1-search for the required node to delete
//		if (val < n->data) {
//			delete_node(val, n->left);
//		}
//		else if (val > n->data) {
//			delete_node(val, n->right);
//		}
//		//2-if right ==NULL then replace with left 
//		//3- if left ==NULL then replace with right
//		//4- else search for the smallesr node in the right subtree
//		// whe found 5- replace 6- delete
//		else {
//			if (!n->right) {
//				BIN_node* temp = n->left;
//				delete n;
//				n = temp;
//			}
//			else if (!n->left) {
//				BIN_node* temp = n->right;
//				delete n;
//				n = temp;
//			}
//			else {
//				/*we have both sides rightand left
//				//so we either delete the most right in the left branch 
//				//or the most left in the right branch */
//				BIN_node* temp = find_min_right_sub_tree(n->right);
//				n->data = temp->data;//replace
//				delete_node(temp->data, n->right);
//			}
//		}
//	}
//};
///*::is called the scope resolution operator in C++
//// It is used to :
//// access class members (variables or functions) from outside  
////the class or from a different scope and
//// also used with static members of a class to access them without the need for an instance of the class:*/
//
//BIN_node*  binary_search_tree::make_new_node(int dd)
//	{
//		BIN_node *temp = new BIN_node;
//		temp->data = dd;
//		temp->left = NULL;
//		temp->right = NULL;
//		return temp;
//	}
//
//void binary_search_tree::insert_data(int dd)
//{
//	if(root == NULL)	root = make_new_node(dd);
//	else			    rec_insertion(root,dd);
//}
//void binary_search_tree::rec_insertion(BIN_node *ptr , int dd)
//{
//	if(dd < ptr->data)
//	{
//		if(ptr->left == NULL)		ptr->left = make_new_node(dd);
//		else						rec_insertion(ptr->left , dd);
//	}
//	else if(dd > ptr->data)
//	{
//		if(ptr->right == NULL)		ptr->right = make_new_node(dd);
//		else						rec_insertion(ptr->right , dd);
//	}
//}
//
//void binary_search_tree::print_pre_order(void)
//{
//	if(root == NULL)	cout << "Empty tree, pre order print will be canceled \n";
//	else
//	{
//		cout << "Nodes by Pre order:\t";
//		rec_pre_order(root);
//		cout << "\n";
//	}
//}
//void binary_search_tree::rec_pre_order(BIN_node *ptr)//FLR
//{
//	if(ptr == NULL)		return;
//	cout << ptr->data << "\t";		//F
//	rec_pre_order(ptr->left);		//L
//	rec_pre_order(ptr->right);		//R
//}
//
//void binary_search_tree::print_in_order(void)
//{
//	if(root == NULL)	cout << "Empty tree, in order print will be canceled \n";
//	else
//	{
//		cout << "Nodes by in order:\t";
//		rec_in_order(root);
//		cout << "\n";
//	}
//}
//void binary_search_tree::rec_in_order(BIN_node *ptr)	//LFR
//{
//	if(ptr == NULL)		return;
//	rec_in_order(ptr->left);		//L
//	cout << ptr->data << "\t";		//F
//	rec_in_order(ptr->right);		//F
//}
//
//void binary_search_tree::print_post_order(void)
//{
//	if(root == NULL)	cout << "Empty tree, post order print will be canceled \n";
//	else
//	{
//		cout << "Nodes by post order:\t";
//		rec_post_order(root);
//		cout << "\n";
//	}
//}
//void binary_search_tree::rec_post_order(BIN_node *ptr)	//LRF
//{
//	if(ptr == NULL)		return;
//	rec_post_order(ptr->left);		//L
//	rec_post_order(ptr->right);		//R
//	cout << ptr->data << "\t";		//F
//}
//
//bool binary_search_tree::search_data(int dd)
//{
//	if(root == NULL){
//		cout << "You can not search for " << dd << " in an empty tree\n";  return false;
//	}
//	else  return rec_search(root , dd);
//}
//
//bool binary_search_tree::rec_search(BIN_node *ptr , int dd)
//{
//	if(ptr == NULL)
//		{ cout << dd << "could not be found \n";  return false;  }
//	else if(ptr-> data == dd){
//		cout << " We find " << dd << " in the tree\n";	return true; }
//	else if(ptr->data < dd)		return rec_search(ptr->right , dd);
//	else if(ptr->data > dd)		return rec_search(ptr->left , dd);
//}
//
//bool binary_search_tree::remove_data(int dd)
//{
//	if(root == NULL)
//	{  cout << "You can not delete from an empty tree\n";  return false; }
//	else  return rec_delete_data(&root , dd);
//}
//
//bool binary_search_tree:: rec_delete_data(BIN_node **pt, int key)
//{
//	if (*pt == NULL)		{ cout << "The number " << key << " could not be deleted\n"; return false; }
//
//	if ((*pt)->data > key)		return rec_delete_data(&((*pt)->left), key);
//
//	else if ((*pt)->data < key)	return rec_delete_data(&((*pt)->right), key);
//	else if ((*pt)->data == key)
//	{
//		if ((*pt)->left == NULL)		*pt = (*pt)->right;
//		else if ((*pt)->right == NULL)		*pt = (*pt)->left;
//		else if((*pt)->left->right == NULL)	{(*pt)->left->right = (*pt)->right ;	*pt = (*pt)->left ; }
//		else if((*pt)->right->left == NULL)	{(*pt)->right->left = (*pt)->left ;		*pt = (*pt)->right ; }
//		else
//		{
//			BIN_node *temp = *pt;
//			temp = temp->left;
//			while (temp->right->right != NULL)
//				temp = temp->right;
//			(*pt)->data = temp->right->data;
//			temp->right = temp->right->left;
//		}
//		cout << "\nNumber " << key << " will be replaced in the tree by number " << (*pt)->data << "\n";
//		return true;
//	}
//}
//
//
//int main() {
//	binary_search_tree bst;
//	bst.insert_data(5);
//	bst.insert_data(3);
//	bst.insert_data(8);
//	bst.insert_data(1);
//	bst.insert_data(9);
//	bst.insert_data(7);
//	bst.insert_data(6);
//	bst.insert_data(2);
//	bst.insert_data(4);
//
//	bst.print_pre_order();
//	bst.print_in_order();
//	bst.print_post_order();
//
//	//bst.delete_node(8, bst.root);//not working 
//	bst.remove_data(8);
//	bst.print_pre_order();
//}
///*
//void delete_node(int val, node* n) {
//	if (!n)		return;
//	if (val < n->data) {
//		delete_node(val, n->left);
//	}
//	else if (val > n->data) {
//		delete_node(val, n->right);
//	}
//	else {
//		if (!n->right) {
//			node* temp = n->left;
//			delete n;
//			n = temp;
//		}
//		else if (!n->left) {
//			node* temp = n->right;
//			delete n;
//			n = temp;
//		}
//		else {
//			node* temp = find_min_right_sub_tree(n->right);
//			n->data = temp->data;//replace
//			delete_node(temp->data, n->right);
//		}
//	}
//}*/