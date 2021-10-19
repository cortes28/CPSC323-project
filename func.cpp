#include <iostream>
#include <fstream>
#include <sstream>

void parse(const std::string & file){

    // the read file
    std::ifstream my_file;
    // the write file
    std::ofstream write_file;
    std::string curr_str;
    std::string temp_str;
    bool flag = false;

    // open both files
    my_file.open(file);
    write_file.open("lexi.txt");

    //if file is open
    if(my_file){     
        // read line per line
        while (getline(my_file, curr_str)){
            // printing to see if it works
            // std::cout << current_str << std::endl;
            if(flag){
                write_file << "\n";
            }

            // iterate through each char (letter)
            for(int i = 0; i < curr_str.length(); i++){
                // if it doesn't equal whitespace, we add it to temp string
                // later add another && condition bool function to see if there
                // is an operator
                if(curr_str[i] != ' '){
                    temp_str += curr_str[i];
                }
                //if it does equal whitespace
                else{
                    std::cout << temp_str << std::endl;
                    // to make it jump to the next line per token
                    temp_str += "\n";
                    // write to the new file and clear the temp string
                    write_file << temp_str;
                    temp_str = "";
                    int j = i;
                    //check for reduntant whitespace
                    while(curr_str[j] == ' '){
                        temp_str += curr_str[j];
                        j++;
                    }
                    // write a whitespace into the file and clear the whitespace
                    // std::cout << temp_str << j - i << std::endl;
                    write_file << " \n";
                    temp_str = "";
                    // j - 1 is due to the j++ which may have made it jump a step
                    // ahead and may lead to not reading the next token correctly
                    i = j - 1;
                }

                // if i + 1 equals the length of the string, add the last token of
                // the line
                if(i + 1 == curr_str.length()){
                    write_file << temp_str << "\n";
                    temp_str = "";
                }
            }

            // This flag is to add a newline after the current line was read
            flag = true;
        }

        std::cout << "File is valid" << std::endl;
        my_file.close();
        write_file.close();
    }

    else{
        std::cout << "Error: File does not exist or it is invalid"
                  << std::endl;
    }

}
