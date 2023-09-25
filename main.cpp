#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "getFileSize.h"

inline void outputHelp(){
	std::cout << "getFileSize: returns the amount of Bytes in a Program" << std::endl;	
	std::cout << "Created By: peterdownie 2023-09-24" << std::endl;
	std::cout << "Use: getFileSize filename : this will return a long long of the number of bytes in the file" << std::endl;
	std::cout << "Use getFileSize --help : return this help" << std::endl;
	std::cout << "Use getFileSize --json filename, outputs the file name and its size in bytes as a json string" << std::endl;
	std::cout << "--json can be replaced with --jsonKB or --jsonMB" << std::endl;	
}

inline void notEnoughArguments(){
	std::cerr << "Invalid Use, --help for program instructions" << std::endl;
}

inline void outputFileSizeInBytes(char* fileName){
	long long fileSize = getFileSize(fileName);
	std::cout << fileSize << std::endl;
}

inline std::string createJsonOutput(const char * fileName, const long long fileSize){	
	std::ostringstream result;
	result << "{\"" << fileName << "\": " << fileSize << "}";
	return result.str();
}

inline std::string createJsonOutput(const char * fileName, const double fileSize){
	std::ostringstream result;
	result << "{\"" << fileName << "\": " << fileSize << "}";
	return result.str();
}

int main(int argc, char* argv[]){
	char* fileName;
	char* command;
	long long fileSize;
        if(argc == 1){
		notEnoughArguments();
                return 1;
        }else if(argc == 2){
		fileName = argv[1]; //This is checked for commands
		if(strcmp(fileName,"--help") == 0){
			outputHelp();
		}else{ 
			outputFileSizeInBytes(fileName);
			return 0;
		}
	}else if(argc > 2){
		command = argv[1];
		if(strcmp(command,"--json") == 0){
                        fileName = argv[2];
                       	fileSize = getFileSize(fileName);
			std::cout << createJsonOutput(fileName, fileSize) << std::endl;
			return 0;
		}else if(strcmp(command,"--jsonKB") == 0){
			fileName = argv[2];
			const double intoKB = 1024;
			double fileSizeKB = getFileSize(fileName) / intoKB;
			std::cout << createJsonOutput(fileName, fileSizeKB) << std::endl;	
		}else if(strcmp(command, "--jsonMB") == 0){
			fileName = argv[2];
			const double intoMB = 1024 * 1024;
			double fileSizeMB = getFileSize(fileName) / intoMB;
			std::cout << createJsonOutput(fileName, fileSizeMB) << std::endl;
                }else{
			std::cerr << command << " was not found, try without command for basic instructions" << std::endl;
			return 2;
		}
	}
}
