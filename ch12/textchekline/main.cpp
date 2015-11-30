#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>

using namespace std;
using line_no = vector<string>::size_type;//行号类型定义

class QueryResult {
friend ostream & print(ostream &, const QueryResult&);//打印输出结果友元函数
public :
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f )://构造函数，s是查询单词，p是行号，f是行内容
        sought(s), lines(p), file(f){}
private :
    string sought;//要查询的内容
    shared_ptr<set<line_no>> lines;//查询结果行号
    shared_ptr<vector<string>> file;//查询结果行内容

};

string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;//make_plural(wc, "word ", "s ")当输入中文本中
                                            //word数大于一是在word后加s，为words为word的复数！
}

ostream & print(ostream & os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(),"time","s") << endl;
    for(auto num :*qr.lines)
    {
        os << "\t(line " << num + 1 << "): "
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
    map<string, shared_ptr<set<line_no>>> wm;//记录单词与对应行号的map
};

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
    string text;//暂存每行内容
    while(getline(is, text))//读入每行
    {
        file->push_back(text);//保存到file的vector容器中
        int n = file->size()-1;
        istringstream line(text);//分解每行
        string word;//暂存单词
        while(line>>word)
        {
            auto &lines = wm[word];//获取map中单词对应的set集
            if(!lines)
                lines.reset(new set<line_no>);//若第一次添加则申请内存空间
            lines->insert(n);//插入行号
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);//查询失败的模子
    auto loc = wm.find(sought);//开始查询
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);//查询失败
    else
        return QueryResult(sought, loc->second, file);//查询成功
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;

    }
}


int main()
{
    ifstream infile("testfile.txt");
    runQueries(infile);

    return 0;
}
