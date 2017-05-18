#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() { 
    std::string line_contents;
    std::cout << "Enter a file name to read: ";
    std::cin >> line_contents;
    const char* linecontents=line_contents.c_str();
    std::ifstream file(line_contents);
    std::string str; 
    int line_number = 0;
    std::map<std::string, std::string> configs;
    
    while (std::getline(file, str)) {
        line_number ++;
        auto start = str.begin();
        auto end = str.end();
        std::string valuestr[2];
     
        //ignore comments
        std::size_t found = str.find("#");
        if (found!=std::string::npos) { 
            end = start + found;
            std::string substring(start,end);
            str=substring;
            if(str.length()<4){
                fprintf(stderr, "[WARNING] Invalid tokens in configuration file: file %s on line %d\n", linecontents, line_number);
                continue;
            }
        }
        
        int num_semicolons = std::count(start,end,';');
        if(num_semicolons != 2) {
            fprintf(stderr, "[WARNING] Invalid tokens in configuration file: file %s on line %d\n", linecontents, line_number);
            continue;
        }else {
            int begin=0;
            for(int i=0; i<2; i++){
                found = str.find(";",begin);
                valuestr[i]=str.substr(begin,(found-begin));
                if(valuestr[i].length()==0) {
                    fprintf(stderr, "[WARNING] Invalid tokens in configuration file: file %s on line %d\n", linecontents, line_number);
                    continue;
                }
                int foundws = valuestr[i].find(" ");
                while(foundws == 0 | foundws == (valuestr[i].length()-1)){
                    //eliminate whitespace at beginning and end
                    valuestr[i]=valuestr[i].erase(foundws,1);
                    foundws = valuestr[i].find(" ");
                }
                while(foundws!=std::string::npos){
                    //replace other whitespace with "_"
                    valuestr[i]=valuestr[i].replace(foundws,1,"_");
                    foundws = valuestr[i].find(" ");
                }
                begin = found+1;
            }
            // Convert string to uppercase
            std::transform(valuestr[0].begin(),valuestr[0].end(),valuestr[0].begin(),::toupper);
            std::transform(valuestr[1].begin(),valuestr[1].end(),valuestr[1].begin(),::toupper);
   
            configs[valuestr[0]]=valuestr[1];
        } 
    }
}
