#include <iostream>
#include <cstring>
#include "getFileSize.h"

inline void outputHelp(){
	std::cout << "getFileSize: returns the amount of Bytes in a Program" << std::endl;	
	std::cout << "Use: getFileSize filename : this will return a long long of the number of bytes in the file" << std::endl;
	std::cout << "Use getFileSize --help : return this help" << std::endl;
	std::cout << "Use getFileSize --json filename, outputs the file name and its size in bytes as a json string" << std::endl;
	std::cout << "Created By: peterdownie 2023-09-24" << std::endl;
}

int main(int argc, char* argv[]){
	char* fileName;
	char* command;
	long long fileSize;
        if(argc == 1){
                std::cerr << "Invalid Use, --help for program instructions" << std::endl;
                return 1;
        }else if(argc == 2){
		fileName = argv[1];
		if(strcmp(fileName,"--help") == 0){
			outputHelp();
		}else{ 
			fileSize = getFileSize(fileName);
			std::cout << fileSize << std::endl;
			return 0;
		}
	}else if(argc > 2){
		command = argv[1];
		if(strcmp(command,"--json") == 0){
                        fileName = argv[2];
                       	fileSize = getFileSize(fileName);
                        std::cout << "{" << "\"" << fileName << "\":" << "\"" << fileSize  << "\"" <<  "}";
			return 0;
                }else{
			std::cerr << command << " was not found, try without command for basic instructions" << std::endl;
			return 2;
		}
	}
}
