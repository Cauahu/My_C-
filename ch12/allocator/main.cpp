#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void fun1()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(9);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++,10,'c');
    alloc.construct(q++,"hi");
    --q;
    while(q !=p)
    {
        cout << *q << endl;
        alloc.destroy(q--);
    }

    alloc.deallocate(p,9);
}

void fun2()
{
    vector<int> vi={1,2,3,4,5,6,7,8,9};
    allocator<int> alloc;
    auto const p = alloc.allocate(vi.size()*2);
    auto s = p;
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    uninitialized_fill_n(q, vi.size(), 42 );
     while(s != p+vi.size()*2)
    {
        cout << *s <<endl;
        s++;
    }
    alloc.deallocate(p, vi.size()*2);


}

int main()
{

    return 0;
}
