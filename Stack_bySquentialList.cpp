#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Stack
{
private:
	T* data;//元素数组
	int size;//顺序表当前大小
	int capacity;//容量
	void resize();//扩容函数
public:
	Stack() :capacity(10),data(new T[capacity]), size(0) {};
	~Stack();
	//入栈
	void push(T element);
	//弹栈
	T pop();
	//获取元素
	T top()const;
	int getSize()const;
};
template<typename T>
Stack<T>::~Stack()
{
	delete[]data;
	data = NULL;
}
//扩容
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
	//改变原顺序表
	data = newdata;
	capacity = newCapacity;
}
//入栈
template<typename T>
void Stack<T>::push(T element)
{
	//先判断顺序表是否已满
	if (size == capacity) resize();
	data[size++] = element;
}
//弹栈
template<typename T>
T Stack<T>::pop()
{
	//栈为空时
	if (size == 0) throw std::underflow_error("Stack is empty!");
	return data[--size];
}
//获取元素
template<typename T>
T Stack<T>::top()const
{
	//栈为空时
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