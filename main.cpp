/*
    CPSC 323 Project 1 - Prof. Vasikarlas

    GROUP:
    Mike Ploythai
    Bryan Cortes
    Alejandro Ramos
*/

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

    file.close();

    // removing whitespace
    int l = txt.length();
    int c = count(txt.begin(), txt.end(), ' ');

    remove(txt.begin(), txt.end(), ' ');
    txt.resize(l - c);

    // extending string
    unsigned sz = txt.size();
    txt.resize(sz + 1, ' ');

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
            output << first << endl << endl;

            string second = str.substr(pos, 1); // output delimiter
            output << second << endl << endl;
        }
        str = dlm.suffix().str(); // makes new string the remaining
    }

    output.close();

    // remove blanks from file
   ifstream file2("lexi.txt");

   // extracting everything from file, putting into single line string
   string curr2, text;

   while (getline(file2, curr2)) {
       if (curr2 != " ") {
           text += curr2 + "\n";
       }
   }

   file2.close();

   // writing to file
   ofstream file3("lexi.txt");
   text.resize(text.size() - 1);
   file3 << text;
   cout << text;
   file3.close();

    return 0;
}
