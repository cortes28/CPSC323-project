#include "func.hpp"
#include <iostream>
#include <sstream>

int main(){

    std::string file;
    // Either read a seperate file to use or use default text.txt file
    std::cout << "Enter a valid txt file or 'Def'"
                 " to use default 'text.txt file" << std::endl;
    std::cin >> file;

    if(file == "Def"){
        file = "text.txt";
         parse(file);
    }
    else{
        // uncommented until we see a need for this in the
        // possible future
        // parse(file);
        std::cout << "Else" << std::endl;
    }
    return 0;
}