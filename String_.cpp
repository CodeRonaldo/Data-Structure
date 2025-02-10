#define _CRT_SECURE_NO_WARNINGS
//DS_String
#include<iostream>
#include<cstring>
#include "string.h"

using namespace std;

class String
{
private:
	//动态字符数组
	char* str;
	//字符串大小
	size_t length;
public:
	String();
	String(const char* s);
	~String();
	size_t getLength() const;
	char operator[](size_t index) const;
	String& operator=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	String copy()const;
	String operator+(const String& s);

	friend ostream& operator<<(ostream& out, const String& s);
};
String::String()
{
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

String::~String()
{
	delete[]str;
	length = 0;
}

size_t String::getLength() const
{
	return length;
}

char String::operator[](size_t index) const
{
	return str[index];
}

String& String::operator=(const String& s)
{
	//先判断是否是同一对象
	if (*this != s)
	{
		delete[]str;
		length = s.length;
		str = new char[length + 1];
		strcpy(str, s.str);
	}
	return *this;
}

bool String::operator==(const String& s)
{
	//strcmp比较两字符串大小，如果大于返回正数，等于返回0，小于返回负数
	return strcmp(str, s.str) == 0;

}

bool String::operator!=(const String& s)
{
	return strcmp(str, s.str) != 0;
}

String String::copy() const
{
	String s = *this;
	return s;
}

String String::operator+(const String& s)
{
	String result;
	result.length = (*this).length + s.length;
	result.str = new char[result.length + 1];
	strcpy(result.str, str);
	strcat(result.str, s.str);
	return result;
}

ostream& operator<<(ostream& out, const String& s)
{
	out << s.str;
	return out;
}

int main()
{
	String s("123456");
	cout << s << endl;
	cout << s + "445" << endl;
	cout << s[5] << endl;
	cout << (s == "123456") << endl;
	s = s + "abcd";
	cout << s << endl;
	String a, b, c;
	a = b = c = s;
	cout << a << " " << b << " " << c << " " << s << endl;
	return 0;
}
