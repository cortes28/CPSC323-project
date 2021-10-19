#include <iostream>
#include <fstream>
#include <sstream>

void parse(const std::string & file){

    // the read file
    std::ifstream my_file;
    // the write file
    std::ofstream read_file;
    std::string current_str;

    // open our file
    my_file.open(file);

    //if file is open
    if(my_file){
        
        // read line per line
        while (getline(my_file, current_str)){
            // printing to see if it works
            std::cout << current_str << std::endl;

            // iterate through each char (letter)
            for(int i = 0; i < current_str.length(); i++){

            }
        }

        std::cout << "File is valid" << std::endl;
        my_file.close();
        read_file.close();
    }

    else{
        std::cout << "Error: File does not exist or it is invalid"
                  << std::endl;
    }

}