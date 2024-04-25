#include<iostream>
#include<stdexcept>
using namespace std;
#define eleType int
//������Ľṹ��
struct ListNode
{
	eleType data;
	ListNode* next;
	//c++��Ľṹ��������ƣ�Ҳ�й��캯��
	ListNode(eleType x) :data(x), next(NULL) {};
};
//ʵ��������
class LinkedList
{
private:
	ListNode* head;//ͷ���
	int size;//�����С

public:
	LinkedList() :head(NULL), size(0) {};
	~LinkedList();
	//��������
	void insert(int i, eleType value);
	//ɾ
	void remove(int i);
	//����
	//��ֵ
	ListNode* find(eleType value);
	//���±�
	ListNode* get(int i);
	//��
	void update(int i, eleType value);
	void print();
};
//����������һ��һ��ɾ�����
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
//��
void LinkedList::insert(int i, eleType value)
{
	//���ж��±��Ƿ�Υ��
	if (i < 0 || i > size)//ע�����ʱi���Ե���size����������
	{
		throw std::out_of_range("Invalid index");
	}
	ListNode* newNode = new ListNode(value);//���ýṹ��Ĺ��캯��
	//����ͷ���
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
//ɾ
void LinkedList::remove(int i)
{
	//���ж��±��Ƿ�Υ��
	if (i < 0 || i >= size)
	{
		throw std::out_of_range("Invalid index");
	}
	//����ͷ���
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
//��
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
//��
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