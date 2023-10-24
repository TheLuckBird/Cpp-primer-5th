#include "Sequence_list.h"
#include "List.h"
#include "Stack.h"
#include "StackArray.h"
#include "QueueArray.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int postfix(const string expression)
{
    stringstream io(expression);
    string s;
    Stack<string> stack;
    int sum = 0;
    while(io >> s)
    {
        if(s == "+" || s == "-" || s == "*" || s == "/")
        {
            int right = stoi(stack.peek());
            stack.pop();
            int left = stoi(stack.peek());
            stack.pop();
            
            if(s == "+")
                sum = left + right;
            else if(s == "-")
                sum = left - right;
            else if(s == "*")
                sum = left * right;
            else 
                sum = left / right;
            
            stack.push(to_string(sum));
            continue;
        }   
        stack.push(s);
    }
    return stoi(stack.peek()) ;   
}

int prio(string op)                   //给运算符优先级排序
{
    int priority;
    if (op == "*" || op == "/")
        priority = 2;
    if (op == "+" || op == "-")
        priority = 1;
    if (op == "(")
        priority = 0;
    return priority;
}

//参考：https://www.cnblogs.com/wkfvawl/p/12864789.html
string mid2post(string expression)
{
    string s;
    Stack<string> opstack;
    stringstream in(expression);
    string out;
    in >> out;
    while(in >> s)
    {
        if(s >= "0" && s <= "9" || s >= "a" && s <= "z") out = out + " " + s;
        else
        {
            if(opstack.isEmpty()) opstack.push(s);//栈空，则入栈
            else if(s == "(") opstack.push(s);//左括号，入栈
            else if(s == ")")//右括号，出栈
            {
                while(opstack.peek() != "(")
                {
                    out = out + " " + opstack.peek();
                    opstack.pop();
                }
                opstack.pop();//左括号不输出
            }
            else
            {
                while(prio(s) <= prio(opstack.peek()))
                {
                    out = out + " " + opstack.peek();
                    opstack.pop();
                    if(opstack.isEmpty()) break;
                }
                opstack.push(s);
            }
        }
        
    }

    while(!opstack.isEmpty())
    {
        out = out + " " + opstack.peek();
        opstack.pop();
    }
    return out;

}



int main(int argc, char const *argv[])
{
    // cout << "hi" << endl;
    // Sequence_list<int> array(100);
    // array.init();
    // array.show();
    // // cout << array.getItemIndex(4) << endl;
    // // string s = "c";
    // // cout << array.getItem(4) << endl;

    // // vector<int> ivec;
    // // array.insert(0,999);
    // // array.show();
    // // array.deleteItem(4);
    // array.show();

    // Stack<int> myStack;

    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);

    // std::cout << "Top element: " << myStack.peek() << std::endl;

    // myStack.pop();
    // std::cout << "Top element after pop: " << myStack.peek() << std::endl;

    // StackArray<int> myStack(5);
    // // myStack.peek();

    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);

    // std::cout << "Top element: " << myStack.peek() << std::endl;

    // myStack.pop();
    // std::cout << "Top element after pop: " << myStack.peek() << std::endl;
    
    // cout << postfix("3 4 5 * + 7 8 + +") << endl;
    // cout << postfix("5 3 + 4 * 2 -") << endl;
    
    // std::string infixExpression = "a + b * c ( d * e + f ) * g";
    // std::string postfixExpression = infixToPostfix(infixExpression);

    // std::cout << "Infix Expression: " << infixExpression << std::endl;
    // std::cout << "Postfix Expression: " << postfixExpression << std::endl;

    // cout << mid2post("1 + 2 * 3 + ( 4 * 5 + 6 ) * 7 + 10 / 100") << endl;
    // cout <<postfix(mid2post("1 + 2 * 3 + ( 4 * 5 + 6 ) * 7 + 10 / 100")) << endl;

    QueueArray q(10);
    cout << q.empty() << endl;
    q.enqueue(1);
    q.enqueue(3);
    cout << q.empty() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.empty() << endl;

}
