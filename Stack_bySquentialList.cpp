#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	T* data;//Ԫ������
	int size;//˳���ǰ��С
	int capacity;//����
	void resize();//���ݺ���
public:
	Stack() :capacity(10),data(new T[capacity]), size(0) {};
	~Stack();
	//��ջ
	void push(T element);
	//��ջ
	T pop();
	//��ȡԪ��
	T top()const;
	int getSize()const;
};
template<typename T>
Stack<T>::~Stack()
{
	delete[]data;
	data = NULL;
}
//����
template<typename T>
void Stack<T>::resize()
{
	int newCapacity = capacity * 2;
	T* newdata = new T[newCapacity];
	for (int i = 0; i < size; ++i)
	{
		newdata[i] = data[i];
	}
	delete []data;
	//�ı�ԭ˳���
	data = newdata;
	capacity = newCapacity;
}
//��ջ
template<typename T>
void Stack<T>::push(T element)
{
	//���ж�˳����Ƿ�����
	if (size == capacity) resize();
	data[size++] = element;
}
//��ջ
template<typename T>
T Stack<T>::pop()
{
	//ջΪ��ʱ
	if (size == 0) throw std::underflow_error("Stack is empty!");
	return data[--size];
}
//��ȡԪ��
template<typename T>
T Stack<T>::top()const
{
	//ջΪ��ʱ
	if (size == 0) throw std::underflow_error("Stack is empty!");
	return data[size-1];
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
	cout<<stack.top();
	stack.pop();
	stack.pop();
	stack.pop();
	cout<<stack.top();
	system("pause");
	return 0;
}