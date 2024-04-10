//顺序表板子
#include<iostream>
using namespace std;
#define eleType double //方便修改数据类型
struct SequentialList
{
	
	eleType* elements;//元素
	int size;//当前元素个数
	int capacity;//总容量
};
void initializeList(SequentialList* List, int capacity)
{
	List->elements = new eleType[capacity];
	List->size = 0;
	List->capacity = capacity;
}
void destroyList(SequentialList* List)
{
		delete []List->elements;
		List->capacity = 0;
		List->elements = NULL;
}
int size(SequentialList* List)
{
	return List->size;
}
bool isEmpty(SequentialList* List)
{
	return List->size == 0;
}
void insert(SequentialList* List, int index, eleType element)
{
	//先判断index是否合法,插入时可以让index=size，此时插入到末尾
	if (index < 0 || index > List->size)
	throw std::invalid_argument("Invalid Index");//提示非法
	//判断顺序表是否满，如果满需扩容,扩容倍增
	if (List->size == List->capacity)
	{
		//已满
		int newCapacity = List->capacity * 2;//扩容
		eleType* newElements = new eleType[newCapacity];
		//复制原来的表
		for (int i = 0; i < List->size; ++i)
		{
			newElements[i] = List->elements[i];
		}
		//delete[]List->elements;
		List->elements = newElements;
		List->capacity = newCapacity;
		//从后往前，每个数往后存一位
		for (int i = List->size; i > index; --i)
		{
			List->elements[i] = List->elements[i - 1];
		}
		List->elements[index] = element;
		List->size++;//修改表的大小
	}
	else
	{
		//如果没满，直接从后往前后移元素，再插
		for (int i = List->size; i > index; --i)
		{
			List->elements[i] = List->elements[i - 1];
		}
		List->elements[index] = element;
		List->size++;//修改表的大小
	}
}
void deleteElement(SequentialList* List, int index)
{
	//先判断index是否合法
	if (index < 0 || index >= List->size)//删除时不能超过下标的范围，这里和插入不同
		throw std::invalid_argument("Invalid Index");//提示非法
	//从前往后，前移元素
	for (int i = index; i < List->size; ++i)
	{
		List->elements[i] = List->elements[i + 1];
	}
	List->size--;//减小顺序表大小
}
int findElement(SequentialList* List, eleType element)
{
	//返回下标
	for (int i = 0; i < List->size; i++)
	{
		if (List->elements[i] == element)
			return i;
	}
	//找不到则返回-1
	return -1;
}
eleType getElement(SequentialList* List, int index)
{
	//先判断index是否合法
	if (index < 0 || index >= List->size)
		throw std::invalid_argument("Invalid Index");//提示非法
	return List->elements[index];
}
void updateElement(SequentialList* List, int index, eleType value)
{
	//先判断index是否合法
	if (index < 0 || index >= List->size)
		throw std::invalid_argument("Invalid Index");//提示非法
	List->elements[index] = value;
}
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		SequentialList mylist;
		initializeList(&mylist, 1);
		for (int i = 0; i < n; ++i)
		{
			eleType ele;
			cin >> ele;
			insert(&mylist, i, ele);
			//此时n==size
		}
		eleType sum = 0;
		eleType eMax = -1e8;//先假设最大值为一个非常小的数
		eleType eMin = 1e8;

		for (int i = 0; i < mylist.size; i++)
		{
			if (getElement(&mylist, i) > eMax) eMax = getElement(&mylist, i);
			if (getElement(&mylist, i) < eMin) eMin = getElement(&mylist, i);
			sum += getElement(&mylist, i);
		}
		sum = sum - eMax - eMin;
		sum /= (mylist.size - 2);
		printf("%.2f\n", sum);
	}
	
	return 0;
}
