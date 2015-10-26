#include <iostream>

using namespace std;

void fun1() //p34
{
    unsigned u = 10;
    int i = -42;
    cout << i+i << endl;
    cout << i+u << endl;
}

int main()
{
    fun1();
    cout << "hello world" << '\b' <<' ' ;
    return 0;
}
