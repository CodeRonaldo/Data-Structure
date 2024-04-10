#include<iostream>
using namespace std;
#define eleType double //�����޸���������
struct SequentialList
{
	
	eleType* elements;//Ԫ��
	int size;//��ǰԪ�ظ���
	int capacity;//������
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
	//���ж�index�Ƿ�Ϸ�,����ʱ������index=size����ʱ���뵽ĩβ
	if (index < 0 || index > List->size)
	throw std::invalid_argument("Invalid Index");//��ʾ�Ƿ�
	//�ж�˳����Ƿ����������������,���ݱ���
	if (List->size == List->capacity)
	{
		//����
		int newCapacity = List->capacity * 2;//����
		eleType* newElements = new eleType[newCapacity];
		//����ԭ���ı�
		for (int i = 0; i < List->size; ++i)
		{
			newElements[i] = List->elements[i];
		}
		//delete[]List->elements;
		List->elements = newElements;
		List->capacity = newCapacity;
		//�Ӻ���ǰ��ÿ���������һλ
		for (int i = List->size; i > index; --i)
		{
			List->elements[i] = List->elements[i - 1];
		}
		List->elements[index] = element;
		List->size++;//�޸ı�Ĵ�С
	}
	else
	{
		//���û����ֱ�ӴӺ���ǰ����Ԫ�أ��ٲ�
		for (int i = List->size; i > index; --i)
		{
			List->elements[i] = List->elements[i - 1];
		}
		List->elements[index] = element;
		List->size++;//�޸ı�Ĵ�С
	}
}
void deleteElement(SequentialList* List, int index)
{
	//���ж�index�Ƿ�Ϸ�
	if (index < 0 || index >= List->size)//ɾ��ʱ���ܳ����±�ķ�Χ������Ͳ��벻ͬ
		throw std::invalid_argument("Invalid Index");//��ʾ�Ƿ�
	//��ǰ����ǰ��Ԫ��
	for (int i = index; i < List->size; ++i)
	{
		List->elements[i] = List->elements[i + 1];
	}
	List->size--;//��С˳����С
}
int findElement(SequentialList* List, eleType element)
{
	//�����±�
	for (int i = 0; i < List->size; i++)
	{
		if (List->elements[i] == element)
			return i;
	}
	//�Ҳ����򷵻�-1
	return -1;
}
eleType getElement(SequentialList* List, int index)
{
	//���ж�index�Ƿ�Ϸ�
	if (index < 0 || index >= List->size)
		throw std::invalid_argument("Invalid Index");//��ʾ�Ƿ�
	return List->elements[index];
}
void updateElement(SequentialList* List, int index, eleType value)
{
	//���ж�index�Ƿ�Ϸ�
	if (index < 0 || index >= List->size)
		throw std::invalid_argument("Invalid Index");//��ʾ�Ƿ�
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
			//��ʱn==size
		}
		eleType sum = 0;
		eleType eMax = -1e8;//�ȼ������ֵΪһ���ǳ�С����
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