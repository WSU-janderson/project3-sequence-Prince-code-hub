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

void testCopy();

void addSomeGrades(Sequence nod);

void addSomeGrades(Sequence nod) {
    nod.push_back("p");
    nod.push_back("a");
    nod.push_back("b");

    cout << "in addSomeGrades(nod)" << endl;
    cout << nod << endl;
    cout << endl;
}

void testAddGrade();


using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;


    Sequence seq;
    seq.push_back("p");
    seq.insert(0, "num5");
    seq.push_back("num6");
    seq.push_back("num7");
    seq.push_back("num8");


    cout << seq << endl;

    cout << endl;

    seq.erase(1, 2);


    cout << seq << endl;

    cout << seq.front();

    cout << seq.back();
    cout << seq.empty();
    cout << seq.size() << endl;


    return 0;
}

void testAddGrade() {
    Sequence seq1(1);
    cout << "In testADDGRADE" << endl;
    cout << endl;

    seq1.push_back("some");
    seq1.insert(2, "num");

    cout << seq1 << endl;

    cout << "In testADDGRADE" << endl;
    cout << endl;
}

void testCopy() {
    Sequence testCopy(1);

    testCopy.push_back("prince");
    testCopy.push_back("1");

    cout << "In testCopy" << endl;
    cout << testCopy << endl;
    cout << endl;

    addSomeGrades(testCopy);

    cout << "In testCopy" << endl;
    cout << testCopy << endl;
    cout << endl;
}
