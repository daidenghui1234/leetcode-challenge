#include <iostream>
#include <vector>
#include <string>
using namespace std;

string replaceSpace(string s)
{
    size_t found = s.find(" ");
    while (s.find(" ") != string::npos)
    {
        s.replace(found, 1, "%20");
        found = s.find(" ");
    }
    return s;
}
string reverseLeftWords(string s, int n)
{
    char tempc;
    int len = s.length()-1;
    for(int i =0; i<n; i++){
        tempc = s[0];
        for(int j = 0; j<len; j++){
            s[j] = s[j+1];
        }
        s[len] = tempc;
    }
    
    return s;
}

void test01()
{
    
}
int main(int argc, char const *argv[])
{
    reverseLeftWords("123456", 2);
    return 0;
}
