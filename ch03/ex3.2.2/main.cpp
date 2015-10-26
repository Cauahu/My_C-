#include <iostream>
#include <string>
#include <vector>
using namespace std;

string fun1()//3.2
{
    string line;
    getline(cin,line);
    return line;
}

void fun2()//3.14
{
    vector <int> vec;
    int i;
    while((cin >> i)&&i!=0){
        vec.push_back(i);
    }
    for(auto c:vec)
    {
        cout << c << endl;
    }

}
void fun3()//3.34
{
    int a1[] = {1,2,3,4,5,6,7,8,9};
    auto beg = begin(a1);
    auto en = end(a1);
    beg += en - beg;
    cout << *(beg-1) << endl;
}

int main()
{
    int i = ;
    cout << ~i <<endl;
    return 0;
}
