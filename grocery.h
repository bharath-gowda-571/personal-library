#ifndef GROCERY_H
#define GROCERY_H

#include <string>
#include "hash_util.h"
#include <stdlib.h>
#include <QDebug>
#include <fstream>
#include <iomanip>
#define BUCKET_SIZE 501
#define REC_HASH_FILE "record_hash.txt"
#define REC_FILE "record.txt"
#include <QApplication>

using namespace std;
class Library{
private:
    string book_name;
    string author;
    string publisher;
    string description;

   public:
    void add_book(string name,string auth,string pub,string des){
        Hash h;
        string buff;
        string buff2;
        int hash=h.hash(name);
        buff=name+"|";
        buff+=auth+"|";
        buff+=pub+"|";
        buff+=des+"|";
        qDebug()<<QString::fromStdString(to_string(hash));
        qDebug()<<QString::fromStdString(buff);
        fstream f1(REC_HASH_FILE,ios::in|ios::out);
        fstream f2(REC_FILE,ios::out|ios::app);
        if(!f1)
             qDebug()<<QString::fromStdString("couldnt open file");
        f1.seekg(hash*501);
        getline(f1,buff2,'\n');

        f1.seekp(hash*501,ios::beg);
        int i=0;
        for( i=0;i<500;i+=100)
        {
            if(buff2[i]=='#')
                break;

        }

        if(i==500){
        // handle hash overflow
        }
        else{

            f1.seekp(i,ios::cur);
            qDebug()<<f1.tellp();
            f1<<left<<setw(100)<<buff;
            f2<<left<<setw(100)<<buff<<"\n";
        }

        f1.close();

    }

    void unpack(string substr)
    {
        int count=0;
        string temp="";
        for(int j=0;j<100;j++)
        {
              if(substr[j]=='|')
              {
                  switch(count){
                  case 0:

                  {
//                          qDebug()<<QString::fromStdString("here")<<"\n";
//                          qDebug()<<QString::fromStdString(book_name)<<"\n";

                      book_name=temp;
//                          qDebug()<<QString::fromStdString(book_name)<<"\n";
                      break;
                  }
                  case 1:
                  {
                      author=temp;
                       break;
                  }
                  case 2:
                  {
                      publisher=temp;
                      break;
                  }

                  case 3:
                  {
                      description=temp;
                       }
                  }
                  temp="";
                  count++;
                  continue;
              }

            temp+=substr[j];
        }


    }
    string search(string key){
        Hash h;
        string res="";
        int hash=h.hash(key);
        fstream f(REC_HASH_FILE,ios::in);
        f.seekg(hash*BUCKET_SIZE);
        string buff;
        getline(f,buff,'\n');
        int flag=0;
        int i;

        string substr;
        for(i=0;i<500;i+=100)
           {

            substr=buff.substr(i,100);

            if(substr[0]=='#')
                break;

            unpack(substr);
            if(book_name==key)
            {
                res+="Name: "+book_name+"\n";
                res+="Author: "+author+"\n";
                res+="Publisher: "+publisher+"\n";
                res+="Description: "+description+"\n\n";
            }


        }
return res;
    }
    string display(){
        string buff;
        string res="";
        fstream f(REC_FILE,ios::in);
        while(f.peek()!=EOF)
        {
            getline(f,buff,'\n');
            unpack(buff);
            res+="Name: "+book_name+"\n";
            res+="Author: "+author+"\n";
            res+="Publisher: "+publisher+"\n";
            res+="Description: "+description+"\n\n";
        }

        return res;
    }
    bool delete_rec(string key){
        Hash h;
        string res="";
        int hash=h.hash(key);
        fstream f(REC_HASH_FILE,ios::in|ios::out);
        f.seekg(hash*BUCKET_SIZE);
        string buff;
        getline(f,buff,'\n');
        bool flag=false;
        int i;
        f.seekp(hash*BUCKET_SIZE,ios::beg);
        f<<"###################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################";
        f.seekp(hash*BUCKET_SIZE,ios::beg);
        string substr;

        for(i=0;i<500;i+=100)
           {

            substr=buff.substr(i,100);

            if(substr[0]=='#')
                break;

            unpack(substr);
            if(book_name!=key)
            {
                string temp="";
                temp=book_name+"|";
                temp+=author+"|";
                temp+=publisher+"|";
                temp+=description+"|";
                f<<left<<setw(100)<<temp;
                f.seekp(100,ios::cur);
                 qDebug()<<f.tellp();
            }
            else{
                flag=true;
            }


        }
        f.close();
        fstream f2(REC_FILE,ios::in);
        string buff2[600];
        int j=0;
        while(f2.peek()!=EOF)
        {
            getline(f2,buff2[j],'\n');
            j++;
        }
        f2.close();
        fstream f3(REC_FILE,ios::out);
        f3.seekp(0,ios::beg);
        for(int k=0;k<j;k++){
            unpack(buff2[k]);
            if(book_name==key)
            {
                continue;
            }
            else{
                f3<<left<<setw(100)<<buff2[k]<<"\n";
            }
        }
        f3.close();
    return flag;
    }
};

#endif // GROCERY_H
