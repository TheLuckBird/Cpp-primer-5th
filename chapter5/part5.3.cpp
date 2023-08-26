#include <iostream>
using std::endl; using std::cout; using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;

// const vector<string> grades = {"F","D","C","B","A","A++"};
// string lettergrade;
int main(int argc, char const *argv[])
{   
    // int grade;
    // while(cin >> grade)
    // {
    //     if(grade < 60)
    //         lettergrade = grades[0];
    //     else
    //     {
    //         lettergrade = grades[(grade-50)/10];
    //         if(grade!=100)
    //         {
    //             if(grade%10>7)
    //                 lettergrade += '+';
    //             else if(grade%10<3)
    //                 lettergrade += '-';
    //         }     
    //     }
    //     lettergrade = grade<60 ? lettergrade = grades[0] : lettergrade = grades[(grade-50)/10];
    //     lettergrade += (grade==100 || grade<60) ? "" : grade%10>7 ? "+" : grade%10<3 ? "-" : ""; 
    //     cout << lettergrade << endl;
    // }
    unsigned otherCunt = 0;
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    // while(cin >> ch)
    // {
    //     if(ch == 'a'||ch == 'A')
    //         ++aCnt;
    //     else if(ch == 'e'||ch == 'E')
    //         ++eCnt;
    //     else if(ch == 'i')
    //         ++iCnt;
    //     else if(ch == 'o')
    //         ++oCnt;
    //     else if(ch == 'u')
    //         ++uCnt;
    //     else 
    //         ++otherCunt;
    
    // }
    while(cin >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            uCnt++;
            break;
        default:
            ++otherCunt;
            break;
        }
    }
     cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "otherCunt \t" << otherCunt << endl;
    return 0;
}

