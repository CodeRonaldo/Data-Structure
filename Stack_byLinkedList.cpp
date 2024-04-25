#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	
	//结点
	struct Node
	{
		T data;
		Node* next;
		Node(T d) :data(d), next(NULL) {};
	};
	Node* head;//头指针
	int size;//当前元素大小
public:
	Stack() :head(NULL), size(0) {};
	~Stack();
	//入栈
	void push(T element);
	//弹栈
	T pop();
	//获取元素
	T top()const;
	//获得元素个数
	int getSize()const;
};
template<typename T>
Stack<T>::~Stack()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

//入栈
template<typename T>
void Stack<T>::push(T element)
{
	//创建一个新结点插入为新的头结点即可
	Node* newNode = new Node(element);
	newNode->next = head;
	head = newNode;
	size++;
}
//弹栈
template<typename T>
T Stack<T>::pop()
{
	//栈为空时
	if (head == NULL) throw std::underflow_error("Stack is empty!");
	T result = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
	return result;
}
//获取元素
template<typename T>
T Stack<T>::top()const
{
	//栈为空时
	if (size == 0) throw std::underflow_error("Stack is empty!");
	return head->data;
}
template<typename T>
int Stack<T>::getSize()const
{
	return size;
}
int main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(3);
	stack.push(5);
	stack.push(7);
	cout << stack.top();
	stack.pop();
	stack.pop();
	stack.pop();
	cout << stack.top();
	system("pause");
	return 0;
}