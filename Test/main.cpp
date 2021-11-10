#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <unordered_set>
#include "TEST.H"

int main(int argc, char const *argv[])
{
    unordered_set<int> hashSet_int;
    hashSet_int.insert(1);
    hashSet_int.insert(12);
    hashSet_int.insert(13);
    hashSet_int.insert(14);

    while(hashSet_int.size() >1)
        hashSet_int.erase(hashSet_int.begin());
    
    cout << *(hashSet_int.begin()) << endl;

    system("pause");
    return 0;
}
