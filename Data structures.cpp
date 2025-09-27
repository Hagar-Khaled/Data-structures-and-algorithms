#include <iostream>
using namespace std;

// Stack    FILO  ,   LIFO
class stack_using_array
{
private:
	int  top, size, * arr;
public:
	stack_using_array()
	{
		arr = new int[10];	size = 10;	top = 0;
	}
	stack_using_array(int ss)
	{
		arr = new int[ss];	size = ss;	top = 0;
	}
	void push(int data)
	{
		if (top >= size)
		{
			cout << "Stack is full, so size will be double\n";
			double_size();
		}
		arr[top] = data;
		top++;
	}
	int pop(void)
	{
		if (top == 0)
		{
			cout << "Stack is empty\n";
			return -1;
		}
		top--;
		return arr[top];
	}
	int read_top_data(void)
	{
		if (top == 0)		return -1;
		else				return arr[top - 1];
	}
	bool is_full(void){		return top == size;		}
	bool is_empty(void){	return top == 0;	}
	int get_max_size(void){	return size;	}
	int get_nuumber_of_item(void){	return top;	}
	void double_size(void)
	{
		int* temparr = new int[size * 2];
		for (int k = 0; k < top; k++)
			temparr[k] = arr[k];
		delete arr;
		size = size * 2;
		arr = temparr;
	}
	void delete_stack_data() { top = 0; }
	~stack_using_array()
	{
		delete arr;
	}
};

// Queue	FIFO	,	LILO
class queue_using_array
{
private:
	int* arr, front, rear, size, counter;
public:
	queue_using_array(int ss)
	{
		size = ss;
		arr = new int[size];
		front = rear = counter = 0;
	}
	queue_using_array()
	{
		size = 10;
		arr = new int[size];
		front = rear = counter = 0;
	}
	void enqueue(int n)
	{
		arr[rear] = n;
		rear = (rear + 1) % size;
		counter++;
	}
	int dequeue(void)
	{
		int temp = front;
		front = (front + 1) % size;
		counter--;
		return arr[temp];
	}
	bool isempty() {	return (counter == 0); }
	bool isfull(){		return counter == size;	}
	int get_number_of_elements(){	return counter;	}
	int get_max_size(void)
	{
		return size;
	}
	int get_front(void)
	{
		return arr[front];
	}
	void double_size(void)
	{
		int* temp = new int[size * 2];
		for (int k = 0; k < size; k++)
			temp[k] = arr[(k + front) % size];
		delete arr;
		size = size * 2;
		arr = temp;
		front = 0;
		rear = counter;
	}
};
/*
int main()
{
	stack_using_array st1 ;

	int k ;
	for(k = 1 ; k <= 12 ; k++)
		st1.push(k*10);
	st1.push(55);
	for(k = 1 ; k <= 15 ; k++)
		cout << st1.pop() << "\t";

}
*/


//Stack by linked list
struct stackNode
{
	int data;
	stackNode* next;
};
class LinkedListStack
{
private:
	stackNode* top;
public:
	LinkedListStack()
	{
		top = NULL;
	}
	bool isEmpty(void)
	{
		return top == NULL;
	}
	void push(int dd)
	{
		stackNode* temp = new stackNode;
		temp->data = dd;
		temp->next = top;
		top = temp;
	}
	int pop(void)
	{
		int dd= top->data;
		stackNode* temp = top;
		top = top->next;
		delete temp;
		return dd;
	}
	int getNumberOfElements(void)
	{
		int counter = 0;
		stackNode* temp;
		for (temp = top; temp != NULL; temp = temp->next)
			counter++;
		return counter;
	}
	void printStack(void)
	{
		stackNode* temp;
		cout << "Data in stack: ";
		for (temp = top; temp != NULL; temp = temp->next)
			cout << temp->data << "\t";
		cout << "\n";
	}
	void deleteStack(void)
	{
		stackNode* temp;
		while (top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
	}
};

//int main()
//{
//	LinkedListStack st1;
//	for(int k = 1 ; k <= 10 ; k++)
//		st1.push(k*k);
//
//	cout << "Number of elements 1 = " << st1.getNumberOfElements() << "\n";
//
//	st1.printStack();
//	cout << "Number of elements 2= " << st1.getNumberOfElements() << "\n";
//
//	while(st1.isEmpty() == false)
//		cout << st1.pop() << "\n";
//
//	cout << "Number of elements 3= " << st1.getNumberOfElements() << "\n";
//
//}

//Queue by linked list
struct queueNode
{
	int data;
	queueNode* next;
};

class LinkedListQueue
{
private:
	queueNode* front, * rear;
public:
	LinkedListQueue()
	{
		front = rear = NULL;
	}
	void enqueue(int dd)
	{
		queueNode* temp = new queueNode;
		temp->data = dd;
		temp->next = NULL;
		if (rear == NULL)		front = rear = temp;//only one ,the first and last in the same time 
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	int dequeue(void)
	{
		int dd = front->data;
		queueNode* temp = front;
		front = front->next;
		delete temp;
		if (front == NULL)		rear = NULL;
		return dd;
	}
	bool isEmpty(void){	return front == NULL;	}
	void printQueue(void)
	{
		queueNode* temp;
		cout << "All data in queue : ";
		for (temp = front; temp != NULL; temp = temp->next)
			cout << temp->data << "\t";
		cout << "\n";
	}
	int getNumberOfElements(void)
	{
		int counter = 0;
		queueNode* temp;
		for (temp = front; temp != NULL; temp = temp->next)
			counter++;
		return counter;
	}
};

//*
void main(void)
{
	LinkedListQueue qu1;
	for(int k = 1 ; k <= 10 ; k++)
		qu1.enqueue(k*k);

	cout << "Number of elements 1 = " << qu1.getNumberOfElements() << "\n";

	qu1.printQueue();
	cout << "Number of elements 2= " << qu1.getNumberOfElements() << "\n";

	while(qu1.isEmpty() == false)
		cout << qu1.dequeue() << "\n";

	cout << "Number of elements 3= " << qu1.getNumberOfElements() << "\n";
}
//*/
