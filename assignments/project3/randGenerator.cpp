#include <iostream>
#include <cstdlib> // for atoi
#include <fstream> // for file
using namespace std;

int main(int argc, char* argv[])
{
    string line;
    ifstream infile1("rand.txt");
    ifstream infile2("rand2.txt");
    ifstream infile3("rand3.txt");
    if (infile1.is_open()) {
        while (getline(infile1, line)) {
            cout << "I " << line << endl;
        }
        infile1.close();
    }
    if (infile2.is_open()) {
        while (getline(infile2, line)) {
            cout << "F " << line << endl;
        }
        infile2.close();
    }
    if (infile3.is_open()) {
        while (getline(infile3, line)) {
            cout << "R " << line << endl;
        }
        infile3.close();
    }

    return 0;
}
