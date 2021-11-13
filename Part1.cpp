#include <iostream>
#include <fstream>

int main();

int main(){
    std::ifstream inFile;
    inFile.open(".\\Test1.txt");
    if (!inFile) {
        std::cout << "Unable to open file datafile.txt";
        exit(1); 
    }
    std::string word1{}, word2{}, word3{}, word4{}, word5{}, word6{}, word7{}, word8{}, word9{}, word10{};
    inFile >> word1 >> word2 >> word3 >> word4 >> word5 >> word6 >> word7 >> word8 >> word9 >> word10;
    std::cout << word1 << word2 << word3 << word4 << word5 << word6 << word7 << word8 << word9 << word10;
    }