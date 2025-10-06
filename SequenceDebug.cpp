/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;

    Sequence seq(1);

    seq.push_back("num1");
    seq.push_back("num2");
    seq.push_back("num3");
    seq.push_back("num4");

    seq.insert(2, "num5");

    cout << seq << endl;



    return 0;
}