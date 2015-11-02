#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void fun1()//p375使用map
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


void fun2()//p385insert操作
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

void fun3()//p391单词转换map
{
       ifstream infile("transmap.txt"),infile2("text.txt");//映射转换规则文件
       ofstream outfile("test.txt");//待转换文件
       map<string, string> transmaps;//转换规则保存map
       string keyword , valueword ;// 关键字和映射字
       while(infile >> keyword)
       {
           infile >> valueword ;
           transmaps.insert({keyword ,valueword});
       }
      /* auto b = transmaps.begin();
       auto e = transmaps.end();
       for(;b!=e;b++)              //测试map：正常
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


void fun4()//p394无序容器
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
