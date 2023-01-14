#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite


int main(int argc, char* argv[])
{
    ULListStr dat;
    
    for (int i = 0; i < 26; i++) {
        dat.push_back(to_string(i));
    }

    dat.print();

    dat.pop_back();
    dat.pop_back();
    dat.pop_back();
    dat.pop_back();
    dat.pop_back();
    dat.pop_back();

    dat.pop_front();
    dat.pop_front();
    dat.pop_front();
    dat.pop_front();
    dat.pop_front();
    dat.pop_front();

    cout << endl << endl;

    dat.print();

    return 0;
}
