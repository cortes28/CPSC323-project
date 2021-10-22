#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    ofstream written;
    string word;

    file.open("file.txt");
    written.open("lexi.txt");

    while(file >> word) {
        written << word << endl;
    }

    file.close();
    written.close();
}