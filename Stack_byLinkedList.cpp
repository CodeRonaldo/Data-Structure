#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	
	//���
	struct Node
	{
		T data;
		Node* next;
		Node(T d) :data(d), next(NULL) {};
	};
	Node* head;//ͷָ��
	int size;//��ǰԪ�ش�С
public:
	Stack() :head(NULL), size(0) {};
	~Stack();
	//��ջ
	void push(T element);
	//��ջ
	T pop();
	//��ȡԪ��
	T top()const;
	//���Ԫ�ظ���
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

//��ջ
template<typename T>
void Stack<T>::push(T element)
{
	//����һ���½�����Ϊ�µ�ͷ��㼴��
	Node* newNode = new Node(element);
	newNode->next = head;
	head = newNode;
	size++;
}
//��ջ
template<typename T>
T Stack<T>::pop()
{
	//ջΪ��ʱ
	if (head == NULL) throw std::underflow_error("Stack is empty!");
	T result = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
	return result;
}
//��ȡԪ��
template<typename T>
T Stack<T>::top()const
{
	//ջΪ��ʱ
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