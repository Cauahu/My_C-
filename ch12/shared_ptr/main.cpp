#include <iostream>
#include <memory>
using namespace std;

void fun1()
{
    auto p = make_shared< string> (10,'a');
    cout << *p << endl;


}

int main()
{
    fun1();
    return 0;
}
