#include <iostream>
using namespace std;
//                          Write **linked list** class which has at least the following functions
// 
//1.	void insert_in_order(int dd)
//2.	bool delete_item(int dd)
//3.	int get_item_index(int dd)
//4.	void delete_index(int index)
//5.	void insert_index(int data, int index)
//6.	void insert_first(int dd)
//7.	void insert_last(int dd)
//8.	int delete_first(void)
//9.	int delete_last(void)
//10.	Constructor

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
    int count = 0;
public:
    LinkedList() : head(NULL) {}

    // Function to insert an element in order
    void insert_in_order(int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && current->next->data < val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }


// while (current->next ) {//as long as there is next
////current->next: is used to access the next node in the list 
////(i.e., the node that follows the current node)


    // Function to delete an item by value
    bool delete_item(int dd) {
        if (!head) {
            return false;
        }

        if (head->data == dd) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* current = head;
        while (current->next && current->next->data != dd) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return true;
        }

        return false;
    }

    // Function to get the index of an item by value
    int get_item_index(int dd) {
        if (!head) {
            return -1;//empty
        }
        else {
            Node* current = head;//we will start searching 
            int index = 0;
            while (current) {
                if (current->data == dd) {
                    return index;
                }
                current = current->next;
                index++;
            }
            return -1; // Item not found
        }
    }

    // Function to delete an item by index
    void delete_index(int index) {
        if (index < 0 || !head) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next) {
                current = current->next;
            }
            else {
                return; // Index out of bounds
            }
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Function to insert an item at a specific index
    void insert_index(int data, int index) {
        if (index < 0) {
            return;
        }

        Node* newNode = new Node(data);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current->next) {
                current = current->next;
            }
            else {
                return; // Index out of bounds
            }
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to insert an item at the beginning of the list
    void insert_first(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to insert an item at the end of the list
    void insert_last(int val) {
        Node* newNode = new Node(val);
        if (!head) {//empty
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    // Function to delete the first item
    int delete_first() {
        if (!head) {
            cout << "Runtime error: empty list"; return -1; // List is empty
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
        }
    }

    // Function to delete the last item
    void delete_last() {
        if (!head) {
            cout << "Runtime error: empty list";
            return ; // List is empty
        }
        else {
            Node* current = head;
            Node* past = NULL;
            while (current->next) {
                past = current;
                current = current->next;
            }
            //int data = current->next->data;
            delete current;
            past = NULL;
        }
        count--;
    }
};
