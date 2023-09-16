#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include "Message.h"

using namespace std;
class Folder
{
public:
    void Folder::addMsg(Message *m){msgs.insert(m);}
    void Folder::remMsg(Message *m){msgs.erase(m);}
private:
    set<Message *> msgs;
};


#endif