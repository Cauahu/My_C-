#include <iostream>
#include <string>
using namespace std;

 class Hasptr {
private :
    string *ps;
    int i;
public :
    Hasptr(const string &s = string()) : ps(new string(s)), i(0) {}
    Hasptr(const Hasptr &p) : ps(new string(*p.ps)), i(p.i){}
    Hasptr& operator= (const Hasptr &);
    ~Hasptr() {delete ps;}
 };

Hasptr& Hasptr::operator=(const Hasptr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;

}


int main()
{
    Hasptr hp("hello");

    cout << "Hello world!" << endl;
    return 0;
}

