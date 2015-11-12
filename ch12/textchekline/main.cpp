#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;
using line_no = vector<string>::size_type;//�к����Ͷ���

class QueryResult {
friend ostream & print(ostream &, const QueryResult&);//��ӡ��������Ԫ����
public :
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f )://���캯����s�ǲ�ѯ���ʣ�p���кţ�f��������
        sought(s), lines(p), file(f)){}
private :
    string sought;//Ҫ��ѯ������
    shared_ptr<set<line_no>> lines;//��ѯ����к�
    shared_ptr<vector<string>> file;//��ѯ���������

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
    TextQuery(ifstream &);//���캯�������ļ�
    QueryResult query(const string &) const;//��ѯ����
private :
    shared_ptr<vector<string>> file;//�����ļ�����

    shared_ptr<map<string, set<line_no>> wm;//��¼�������Ӧ�кŵ�map
};





int main()
{

    return 0;
}
