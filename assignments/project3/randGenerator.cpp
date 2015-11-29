#include <iostream>
#include <cstdlib> // for atoi
#include <fstream> // for file
using namespace std;

int main(int argc, char* argv[])
{
    ifstream infile("rand.txt");
    string line;
    if (infile.is_open()) {
        while (getline(infile, line))
            cout << "I " << line << endl;
        infile.close();
    }

    return 0;
}
