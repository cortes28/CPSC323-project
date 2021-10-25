#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main() {
    // file
    ifstream file("file.txt");

    // extracting everything from file, putting into single line string
    string curr;
    string txt;

    while (!file.eof()) {
        getline(file, curr);
        txt += curr;
    }

    // removing whitespace
    int l = txt.length();
    int c = count(txt.begin(), txt.end(), ' ');

    remove(txt.begin(), txt.end(), ' ');
    txt.resize(l - c);

    // separating delimiters from string
    string str(txt);

    regex delimiter("[ ;:,()><={}]");
    smatch dlm;

    ofstream output;
    output.open("lexi.txt");

    while (regex_search(str, dlm, delimiter)) {
        for (auto x : dlm) {
            size_t pos = str.find(x);          // finds x that matches delimiter
            string first = str.substr(0, pos); // output text up to delimiter
            output << first << endl;

            string second = str.substr(pos, 1); // output delimiter
            output << second << endl;
        }
        str = dlm.suffix().str(); // makes new string the remaining
    }
    output.close();

    return 0;
}