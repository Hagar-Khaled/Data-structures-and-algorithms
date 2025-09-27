#include <iostream>
using namespace std;

struct double_node { //public by default
	int dd;
	double_node* prev, * next;
};

class double_linked_list {//private by default
private:
	double_node* first, * last;
public:
	double_linked_list() {
		first = last = NULL;
	}
	bool is_empty() { return (first == NULL); }
	
	void insert_first(int data) {
		double_node* newnode = new double_node;
		newnode->dd = data;
		newnode->prev = NULL;
		//if (first != NULL)		
		//	first->prev = newnode;
		//first = newnode;
		//if (last == NULL)	
		//	last = newnode;

		if (is_empty()) {
			newnode->next = NULL;
			first = last = newnode;
		}
		else {
			newnode->next = first;
			first->prev = newnode;/*******donot forget*************/
			first = newnode;
		}
	}
	void insert_last(int data) {
		if (is_empty()) {
			insert_first(data); return;
		}
		else {
			double_node* newnode = new double_node;
			newnode->dd = data;
			newnode->next = NULL;
			newnode->prev = last;
			last->next = newnode;
			last = newnode;
		}
	}
	void insert_at_index(int index, int data) {
		if (index < 0)	return;
		if ((first == NULL) || (index <= 1))	insert_first(data);
		else if (index >= get_size()) insert_last(data);
		else {
			double_node* before = first;
			double_node* after;
			for (int i = 0; i < index; i++) {
				before = before->next;
			}
			after = before->next;
			double_node* newnode = new double_node;
			newnode->dd = data;
			newnode->prev = before;
			newnode->next = after;
			before->next = after->prev = newnode;///////////////////////////prev
		}
	}
	void insert_data_inorder(int data) {
		if (is_empty() || data < first->dd) { insert_first(data);}
		else if (data > last->dd) { insert_last(data);}
		else {
			double_node* after, * before;
			for (after = first; after->dd < data; after = after->next)
				continue;
			before = after->prev;
			double_node* newnode = new double_node;
			newnode->dd = data;
			newnode->prev = before;
			newnode->next = after;
			before->next = after->prev = newnode;
		}
	}
	int delete_first() {
		if (is_empty()) { cout << "Empty Linked List \n"; return -1; }
		double_node* temp = first;
		int data = first->dd;
		first = first->next;
		if (first == NULL)last = NULL;
		else
			first->prev = NULL;
		delete temp;
		return data;
	}
	int delete_last() {
		if (is_empty()) { cout << "Empty Linked List \n"; return -1; }
		double_node* temp = last;
		int data = last->dd;
		last = last->prev;
		if (last == NULL)first = NULL;
		else
			last->next = NULL;
		delete temp;
		return data;
	}
	int delete_index(int index) {
		if (is_empty()) { cout << "Empty Linked List \n"; return -1; }
		if (index < 0)return-1;
		if (index <= 1) return delete_first();
		if (index >= get_size()) return delete_last();
		else {
			double_node* temp = first;
			double_node* after, * before;
			int data;
			for (int i = 1; i < index; i++) {/**********help why <*/
				temp = temp->next;
			}
			data = temp->dd;
			before = temp->prev;
			after = temp->next;
			delete temp;
			before->next = after;
			after->prev = before;
			return data;
		}
	}
	int delete_first_data_occur(int data) {
		if (is_empty()) { cout << "Empty Linked List \n"; return -1; }

		double_node* temp, * after, * before;
		int k = 1;
		for (temp = first; temp != NULL; temp = temp->next) {
			if (temp->dd == data)break;
			else k++;
		}
		if (temp == NULL)
		{
			cout << data << " could not be found\n";    return -1;
		}
		if (temp == first)		return delete_first();
		if (temp == last)	return delete_last();
		before = temp->prev;
		after = temp->next;
		before->next = after;
		after->prev = before;
		delete temp;
		cout << data << " is found at index " << k << " and is deleted\n";
		return k;
	}
	int get_size() {
		double_node* temp;
		int k = 0;
		for (temp = first; temp != NULL; temp = temp->next) {
			k++;
		}
		return k;
	}
	int get_size2() {
		double_node* temp=first;
		int k = 0;
		while (temp != NULL) {
			temp = temp->next;
			k++;
		}
		return k;
	}

	int search(int data) {
		if (is_empty()) { cout << "Empty Linked List \n"; return -1; }

		double_node* temp;
		int k = 1, index = -1;
		for (temp = first; temp != NULL; temp = temp->next) {
			if (temp->dd == data) {////////////////dd not data
				index = k; break;
			}
			else k++;
		}
		if (index == -1)
		{
			cout << data << " could not be found\n";    return -1;
		}
		else {
			cout << data << " is found at index " << index << " \n";
			return index;
		}
	}
	void print_first_to_last() {
		double_node* temp;
		for (temp = first; temp != NULL; temp = temp->next) 
			cout << temp->dd << "\t";
		cout << "\n";
	}
	void print_last_to_first() {
		double_node* temp;
		for (temp = last; temp != NULL; temp = temp->prev)
			cout << temp->dd << "\t";
		cout << "\n";
	}
	void delete_list() {
		while (!is_empty())
			delete_first();
	}

};

void main()
{
	double_linked_list soso;
	int k;
	for (k = 1; k <= 10; k++)
		soso.insert_first(k * k);
	cout << "Print First to Last \t";
	soso.print_first_to_last();
	cout << endl;
	cout<<soso.get_size();
	cout << endl;
	cout << soso.get_size2();
	/*cout << "\nPrint Last to First \t";
	soso.print_last_to_first();

	while (!soso.is_empty())
		cout << soso.delete_last() << "\t";*/

}
