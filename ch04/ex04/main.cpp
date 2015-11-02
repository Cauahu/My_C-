#include <iostream>
#include <string>
using namespace std;

void tsize()//p139
{
    int a[] = {1,2,3,4,5,6};
    cout << sizeof (int);
}
void fun2()
{
    string s("hello world");
    string s1=s.substr(6);
    cout << s1 << endl;
}
int main()
{
    fun2();
    return 0;
}
