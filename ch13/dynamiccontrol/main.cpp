#include <iostream>
#include <memory>

using namespace std;

class StrVec {
public :
    StrVec():elements(nullptr), firstfree(nullptr), cap(nullptr){}
    StrVec(StrVec &);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void pushback(const string);
    size_t size() const {return firstfree-elements;}
    size_t capacity() const {return cap-elements;}
    string * begin() const {return elements;}
    string * end() const {return firstfree;}
private :
    allocator<string> alloc;
    pair<string *, string *> alloc_n_copy (const string*, const string*);
    void free();
    void reallocate();
    string * elements;
    string * firstfree;
    string * cap;
};

pair<string *,string *> StrVec::alloc_n_copy(const string *b,const string *e)
{
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if(elements)
    {
        for(auto p=firstfree;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap-elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size()? size()*2:1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0;i !=size();++i)
        alloc.construct(dest++,move(*elem++));
    free();
    elements = newdata;
    firstfree = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(StrVec& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    firstfree = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &s)
{
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    firstfree = cap = data.second;
    return *this;

}

StrVec::~StrVec()
{
    free();
}

int main()
{
    return 0;
}
