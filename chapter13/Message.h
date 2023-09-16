#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>
#include <algorithm>
#include "Folder.h"

using namespace std;

class Folder;
class Message
{
    friend class Folder;
public:
    Message(const string &str=""):contents(str){ }
    Message(const Message &);
    Message& operator=(const Message &);
    ~Message();
    void save(Folder &);
    void remove(Folder &); 
    void swap(Message &,Message &);
    void addFldr(Folder *);
    void addFldr(Folder *);


private:
    string contents; 
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

void Message::add_to_Folders(const Message &m)
{
    for(auto f:m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    // add_to_Folders(*this);
    return *this;
}

void Message::remove_from_Folders()
{
    for(auto f:folders)
        f->remMsg(this);
}
Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
} 

void Message::swap(Message &lhs,Message &rhs)
{
    using std::swap;
    for(auto f:lhs.folders)
        f->remMsg(&lhs);
    for(auto f:rhs.folders)
        f->remMsg(&rhs);
    
    swap(lhs.contents,rhs.contents);
    swap(lhs.folders,rhs.folders);

    for(auto f:lhs.folders)
        f->addMsg(&lhs);
    for(auto f:rhs.folders)
        f->addMsg(&rhs);
    
}

void Message::addFldr(Folder *f)
{
    folders.insert(f);
}
#endif