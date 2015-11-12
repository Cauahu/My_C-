#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;
using line_no = vector<string>::size_type;//行号类型定义

class QueryResult {
friend ostream & print(ostream &, const QueryResult&);//打印输出结果友元函数
public :
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f )://构造函数，s是查询单词，p是行号，f是行内容
        sought(s), lines(p), file(f)){}
private :
    string sought;//要查询的内容
    shared_ptr<set<line_no>> lines;//查询结果行号
    shared_ptr<vector<string>> file;//查询结果行内容

};

ostream & print(ostream & os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << (qr.lines->size==1)? time:times << endl;
    for(auto num :*qr.lines)
    {
        os << "\t(line " << num + 1 << ")"
        <<*(qr.file->begin() + num) << endl;
    }
    return os;
}

class TextQuery {

public :
    TextQuery(ifstream &);//构造函数读入文件
    QueryResult query(const string &) const;//查询函数
private :
    shared_ptr<vector<string>> file;//保存文件内容

    shared_ptr<map<string, set<line_no>> wm;//记录单词与对应行号的map
};





int main()
{

    return 0;
}
