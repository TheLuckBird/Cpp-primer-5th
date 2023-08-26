#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace std;

void readfile_stringvector(string &filename,vector<string> &vs)
{
     ifstream in(filename);
     if(in)
     {
        string buf;
        while(getline(in,buf))
            vs.push_back(buf);
     }
}

void readfile_stringvector(string &filename,vector<char> &vs)
{
     ifstream in(filename);
     if(in)
     {
        string buf;
        while(getline(in,buf))
        {
            for(auto p:buf)
                vs.push_back(p);
        }
            
     }
}

int main(int argc, char const *argv[])
{   
    // string ifile{"example.txt"};
    // //构造一个ifstream并打开给定文件
    // // ifstream infile("example.txt");
    // ifstream infile(ifile);
    // //输出文件流未关联到任何文�?
    // ofstream outfile;
    // string s;
    // infile >> s;
    // cout << s;

    ifstream input("infile.txt");//打开销售记录文�?
    
    // ofstream output("outfile.txt");//打开输出文件,默认清除数据，写入数�?
    ofstream output("outfile.txt",ofstream::app);//打开输出文件，append在文件末尾添加数�?
    
    Sales_data total;//保存销售总额的变�?
    
    if (read(input, total)) 
    {
        //读取第一条销售记�?
        Sales_data trans;
        //保存下一条销售记录的变量
        while(read (input, trans))
        {
            //读取剩余记录
            if (total.isbn ( ) == trans.isbn() ) //检查isbn
                 total.combine (trans); //更新销售总额
            else 
            {
                print (output, total) <<endl;//原例子传入ostream是打印结果，现在传入ofstream是将数据total写入文件outfile.txt
                total = trans;//处理下一本书
            }
        }
        print (output, total) <<endl;//原例子传入ostream是打印最后一本书的销售额，现在传入ofstream是将最后一个数据total写入文件outfile.txt
    } 
    else
        cerr <<"No data? !" <<endl;//文件中无输入数据

    // string file{"example.txt"};
    // ifstream in(file);
    // ofstream out;
    // out.open(file);
    // if(out)
    //     out << "file";
    // out.close();
    // out.open("cc.txt");
    // if(out)
    //     out << "cpp" ;
    // out.open(file+".copy"); 

    // string filename = "cc.txt";
    // vector<string> vs;
    // readfile_stringvector(filename,vs);
    // for(auto p:vs)
    //     cout << p << endl;
    // vector<char> vc;
    // readfile_stringvector(filename,vc);
    // for(auto p:vc)
    //     cout << p << endl;

    // ofstream out("example.txt");
    // ofstream out("example.txt",ofstream::out);
    // ofstream out("example.txt",ofstream::out | ofstream::trunc);
    // ofstream out("example.txt",ofstream::app);
    // ofstream out("example.txt",ofstream::out | ofstream::app);
    // out << "456";
    

    // out << "hbg" ;
    // out << "fghj" ;
    // string s{"你好"};
    // cout << s << endl;
    // cout << "bj" << endl;
    // cout << 1465 << endl;

    
    return 0;
}
