#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>

#include "ulliststr.h"

using namespace std;

// Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char *argv[])
{
    ULListStr list;
    list.push_front("fred");
    list.push_back("bob");
    list.push_back("joe");

    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2) << endl;
    
    srand(5);

    for(int i = 0; i < 50; i++) {
        int randNum = rand() % 10 + 1;
        cout << randNum << " ";
        list.push_back(to_string(randNum));
    }
    cout << endl;

    list.print(' ');
    cout << endl;

    for (int i = 0; i < 50; i++) {
        cout << i << endl;
        list.pop_front();
    }

    list.print();
    cout << endl;

    return 0;
}
