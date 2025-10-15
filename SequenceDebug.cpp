/**
* SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iomanip>

#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;


    Sequence seq;
    try {
        seq.push_back("p");
        seq.insert(0, "num5");
        seq.push_back("num6");
        seq.push_back("num7");
        seq.push_back("num8");


        cout << seq << endl;
        cout << seq.size() << endl;

        cout << endl;

        seq.erase(0, 2);
        cout << seq.size() << endl;
        cout << seq.front();
        cout << seq.back();

        cout << seq << endl;

        // seq.erase(1, 2);
        cout << seq.size() << endl;
        seq.insert(0, "num1");
        cout << seq.size() << endl;
        cout << seq << endl;


        seq.insert(4, "num1");

        cout << seq << endl;

        cout << seq.front();

        cout << seq.back();
        cout << seq.empty();

    }
    catch (const exception &e) {
        cout << "Exception:- "<< e.what() << endl;
    }

    return 0;
}