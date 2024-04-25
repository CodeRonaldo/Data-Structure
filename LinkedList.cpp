#include<iostream>
#include<stdexcept>
using namespace std;
#define eleType int
//链表结点的结构体
struct ListNode
{
	eleType data;
	ListNode* next;
	//c++里的结构体和类相似，也有构造函数
	ListNode(eleType x) :data(x), next(NULL) {};
};
//实现链表类
class LinkedList
{
private:
	ListNode* head;//头结点
	int size;//链表大小

public:
	LinkedList() :head(NULL), size(0) {};
	~LinkedList();
	//增，插入
	void insert(int i, eleType value);
	//删
	void remove(int i);
	//查找
	//查值
	ListNode* find(eleType value);
	//查下标
	ListNode* get(int i);
	//改
	void update(int i, eleType value);
	void print();
};
//析构函数：一个一个删除结点
LinkedList::~LinkedList()
{
	ListNode* curr = head;
	while (curr)
	{
		ListNode* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}
//增
void LinkedList::insert(int i, eleType value)
{
	//先判断下标是否违法
	if (i < 0 || i > size)//注意插入时i可以等于size！！！！！
	{
		throw std::out_of_range("Invalid index");
	}
	ListNode* newNode = new ListNode(value);//调用结构体的构造函数
	//特判头结点
	if (i == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		ListNode* curr = head;
		for (int j = 0; j < i - 1; ++j)
		{
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	size++;
}
//删
void LinkedList::remove(int i)
{
	//先判断下标是否违法
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	//特判头结点
	if (i == 0)
	{
		ListNode* tmp = head;
		head = head->next;
		delete tmp;
	}
	else
	{
		ListNode* curr = head;
		for (int j = 0; j < i - 1; ++j)
		{
			curr = curr->next;
		}
		ListNode* tmp = curr->next;
		curr->next = tmp->next;
		delete tmp;
	}
	size--;
}
//查
ListNode* LinkedList::find(eleType value)
{
	ListNode* curr = head;
	while (curr && curr->data != value)
	{
		curr = curr->next;
	}
	return curr;
}
ListNode* LinkedList::get(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	ListNode* curr = head;
	for (int j = 0; j < i; j++)
	{
		curr = curr->next;
	}
	return curr;
}
//改
void LinkedList::update(int i, eleType value)
{
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	get(i)->data = value;
}
void LinkedList::print()
{
	ListNode* curr = head;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		LinkedList list;
		int m;
		cin >> m;
		if (!n && !m) break;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			list.insert(i, x);
		}
		list.insert(n, m);
		for (int i = 0; i < n+1-1; ++i)
		{
			for (int j = 0; j < n+1 - i - 1; ++j)
			{
				if (list.get(j)->data > list.get(j + 1)->data)
				{
					eleType temp = list.get(j)->data;
					list.get(j)->data = list.get(j + 1)->data;
					list.get(j + 1)->data = temp;
				}
			}
		} 
		list.print();
	}
	
	return 0;
}