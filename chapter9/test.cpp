#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val)
{   
    auto mid = [&](){ return v.begin() + v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);

    for (auto i : v) 
        std::cout << i << std::endl;
}
//To use other variables other than what was passed to lambda within it, we can use capture-clause []. You can capture by both reference and value, which you can specify using & and = respectively:
// [=] capture all variables within scope by value
// [&] capture all variables within scope by reference
// [&var] capture var by reference
// [&, var] specify that the default way of capturing is by reference and we want to capture var
// [=, &var] capture the variables in scope by value by default, but capture var using reference instead