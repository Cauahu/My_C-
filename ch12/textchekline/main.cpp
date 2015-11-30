#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>
#include <iterator>

using namespace std;
using line_no = vector<string>::size_type;//�к����Ͷ���

class QueryResult {
friend ostream & print(ostream &, const QueryResult&);//��ӡ��������Ԫ����
public :
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f )://���캯����s�ǲ�ѯ���ʣ�p���кţ�f��������
        sought(s), lines(p), file(f){}
private :
    string sought;//Ҫ��ѯ������
    shared_ptr<set<line_no>> lines;//��ѯ����к�
    shared_ptr<vector<string>> file;//��ѯ���������

};

string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;//make_plural(wc, "word ", "s ")���������ı���
                                            //word������һ����word���s��ΪwordsΪword�ĸ�����
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
    TextQuery(ifstream &);//���캯�������ļ�
    QueryResult query(const string &) const;//��ѯ����
private :
    shared_ptr<vector<string>> file;//�����ļ�����
    map<string, shared_ptr<set<line_no>>> wm;//��¼�������Ӧ�кŵ�map
};

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
    string text;//�ݴ�ÿ������
    while(getline(is, text))//����ÿ��
    {
        file->push_back(text);//���浽file��vector������
        int n = file->size()-1;
        istringstream line(text);//�ֽ�ÿ��
        string word;//�ݴ浥��
        while(line>>word)
        {
            auto &lines = wm[word];//��ȡmap�е��ʶ�Ӧ��set��
            if(!lines)
                lines.reset(new set<line_no>);//����һ������������ڴ�ռ�
            lines->insert(n);//�����к�
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);//��ѯʧ�ܵ�ģ��
    auto loc = wm.find(sought);//��ʼ��ѯ
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);//��ѯʧ��
    else
        return QueryResult(sought, loc->second, file);//��ѯ�ɹ�
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
