#include <iostream>
#include <set>
#include <string>

using namespace std;
class Folder;

class Messages {
    friend class Folder;
public :
    Messages(const string str = "") : contents(str) {}
    Messages(const Messages &);
    Messages & operator=(const Messages &);
    ~Messages();
    void save(Folder&);
    void remove(Folder&);
private :
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Messages &);
    void remove_from_Folders();
};

class Folder{
    friend class Messages;
public :
    Folder()=default;
    Folder(Folder&);
    Folder& operator=(Folder&);
    ~Folder();

private:
    set<Messages *> msg;
    void addMsg(Messages *m){msg.insert(m);};
    void remMsg(Messages *m){msg.erase(m);};

};

//Messages ÊµÏÖ

void Messages::add_to_Folders(const Messages& m)
{
    for(auto f:m.folders)
        f->addMsg(this);
}

void Messages::remove_from_Folders()
{
    for(auto f:folders)
        f->remMsg(this);
}

Messages::Messages(const Messages& m):contents(m.contents),folders(m.folders)
{
    add_to_Folders(m);
}

Messages&  Messages::operator=(const Messages& m)
{
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

Messages::~Messages()
{
    remove_from_Folders();
}




int main()
{

    return 0;
}
