#include <iostream>
#include <cstring>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int ret = 0;
    if (s.size() < 3) {}
    else
    {
        int count = s.size() - 3 + 1;
        string* arr = new string[count];
        for (int i = 0; i < count; ++i)
        {
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) ret++;
        }
        delete[] arr;
    }
   cout<< ret;

  

	return 0;
}