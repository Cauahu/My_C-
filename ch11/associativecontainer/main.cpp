#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void fun1()//p375ʹ��map
{
    ifstream in("text.txt");
    string word;
    map<string , size_t> word_count;
    size_t count = 0;
    set<string> exclude = {"," , "the" , "a" , "A" , "an" , "." };
    while((in >> word))
    {
        if(exclude.find(word) == exclude.end())
        {
            ++word_count[word];
            count++;
        }
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second>1)? " times" : " time") << endl;
    }
     cout << "The file conclude " << count << "words" << endl;

}


void fun2()//p385insert����
{
    ifstream in("text.txt");
    string word;
    map<string , size_t> word_count;
    set<string> exclude = {"," , "the" , "a" , "A" , "an" , "." };
    while((in >> word))
    {
        if(exclude.find(word) == exclude.end())
        {
            auto ret = word_count.insert({word,1});
            if(!ret.second)
            {
                ++ret.first->second;
            }
            cout << ret.first->first<< " " << ret.second << endl << endl;
        }
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second>1)? " times" : " time") << endl;
    }

}

void fun3()//p391����ת��map
{
       ifstream infile("transmap.txt"),infile2("text.txt");//ӳ��ת�������ļ�
       ofstream outfile("test.txt");//��ת���ļ�
       map<string, string> transmaps;//ת�����򱣴�map
       string keyword , valueword ;// �ؼ��ֺ�ӳ����
       while(infile >> keyword)
       {
           infile >> valueword ;
           transmaps.insert({keyword ,valueword});
       }
      /* auto b = transmaps.begin();
       auto e = transmaps.end();
       for(;b!=e;b++)              //����map������
       {

           cout << b->first << " " << b->second << endl;
       }*/
       string outputs;
       while(getline(infile2,outputs) )
       {
           istringstream s(outputs);
           string word;
           bool firstword = true;
            while(s >> word)
            {
                if(firstword)
                    firstword = false;
                else
                    outfile << " ";
                auto locate = transmaps.find(word);
                if(locate != transmaps.end())
                {
                    outfile << locate->second;
                }
                else{
                    outfile << word;
                }

            }
            outfile << endl;

       }


}


void fun4()//p394��������
{
    ifstream in("text.txt");
    string word;
    unordered_map<string , size_t> word_count;
    size_t count = 0;
    set<string> exclude = {"," , "the" , "a" , "A" , "an" , "." };
    while((in >> word))
    {
        if(exclude.find(word) == exclude.end())
        {
            ++word_count[word];
            count++;
        }
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second>1)? " times" : " time") << endl;
    }
     cout << "The file conclude " << count << "words" << endl;

}

int main()
{
    fun1();
    cout << "\n\n\n" ;
    fun4();
    return 0;
}
