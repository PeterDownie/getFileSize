getFileSize: getFileSize.o main.cpp
	g++ main.cpp getFileSize.o -o getFileSize

getFileSize.o: getFileSize.h getFileSize.cpp
	g++ -c getFileSize.cpp -o getFileSize.o	
