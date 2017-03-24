#include <fstream>
#include <iostream>
#include <string>
#include <list>

//hashmap or unordered map
int main() 
{ 
	std::string line_contents = "Read.txt";
	const char* linecontents=line_contents.c_str();
    std::ifstream file("Read.txt");
    std::string str; 
    int line_number = 0;
    std::list<std::string> n;
    std::list<int> v;
    int start;
    int end;
    while (std::getline(file, str))
    {
 		line_number ++;
 		fprintf(stderr,"Line Number: %d\n",line_number);
    	bool go = true;
    	int i = 0;
    	int nsemicolon = 0;
    	int divider = 0;
    	start = 0;
    	end=str.length();
    	std::string namestr;
    	std::string valuestr;
    	int valuenum;
    	const char* line=str.c_str();
    	
    	//ignore comments
    	std::size_t found = str.find("#");
 		if (found!=std::string::npos)
 		{ 
 			end=found;
 		}
 		//ignore empty lines 
 		if (str.empty())
 		{
 			go=false;
 		}
 		
    	while(go)
    	{
    		//eliminate white space at beginning and end
    		
    		found = str.find(" ",start);
	 		if (found==start | found==(end-2) )
	 		{
	 			str=str.erase(found,1);
	 		}
			
			found = str.find(";",start);
			
			if(found==std::string::npos) // no ;
			{
				go=false;
				fprintf(stderr, "[WARNING] Invalid tokens in configuration file: file %s on line %d\n", linecontents, line_number);
				start=0;				
			}
			std::cout <<  str.substr(start,found) << "\n";
	 		if(found!=std::string::npos)
	 		{	 			
	 			nsemicolon++;
	 			
	 			if(nsemicolon==1)
	 			{
	 				divider = found;
	 				start = found+1;
	 			}
	 			
	 			
				if(nsemicolon==2)
	 			{
		 			found = str.find(";",start);			
		 			start=found+1;
					if(found!=std::string::npos) // stop if too many ;
					{
						go=false;
						fprintf(stderr, "[WARNING] Invalid tokens in configuration file: file %s on line %d\n", linecontents, line_number);				
						start=0;
						continue;
					}
					namestr=str.substr(0,divider);
					valuestr=str.substr((divider+2),(str.length()-1));
					valuenum=std::stoi(valuestr);
					n.push_back(namestr);
					v.push_back(std::stoi(valuestr));
        			//std::cout << n << '\n';
 				}
			}
			
    	}
    }
}
