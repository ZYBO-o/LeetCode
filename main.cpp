#include "Bit operation/137_single_number_ii.h"
#include <iostream>
using namespace std;




int main() {

    //Test();
    int seen_once = 0;
    int seen_twice = 0;

    int i = 9;

    seen_once = ~seen_twice & (seen_once ^ i);
    cout << seen_once << endl;

    seen_twice = ~seen_once & (seen_twice ^ i);
    cout << seen_twice << endl;

    seen_once = ~seen_twice & (seen_once ^ i);
    cout << seen_once << endl;

    return 0;
}
