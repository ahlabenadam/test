/*
 * matrix_quiz.cpp
 *
 *  Created on: Jun 4, 2012
 *      Author: aka_w
 */


#include <vector>
#include <iostream>

using namespace std;


template<int NUM_ELEM>
class Test {
public:
    Test() : v(NUM_ELEM){
        cout << v.size() << endl;
    };
private:
    vector<int> v;
};

int main(int argc, char* argv[]) {

    Test<100> t;
    return 0;
}
