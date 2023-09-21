#pragma once

class Cmp
{
public:
    Cmp():i(0),j(0){}
    Cmp(int i_,int j_):i(i_),j(j_){}

    bool operator()(int p,int v){
        return p==v ? 1:0;
    }
private:
    int i,j;
};