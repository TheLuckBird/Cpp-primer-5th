#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "TextQuery.h"
using namespace std;

class QueryResult
{
public:
    QueryResult(TextQuery tq_):tq(tq_){ }
    auto print();
private:
    TextQuery tq;
};

auto QueryResult::print()
{
    
}

#endif