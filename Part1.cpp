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
    std::string word0{}, word1{}, word2{}, word3{}, word4{}, word5{}, word6{}, word7{}, word8{}, word9{};
    inFile >> word0 >> word1 >> word2 >> word3 >> word4 >> word5 >> word6 >> word7 >> word8 >> word9;
    std::string words[10] = {word0, word1, word2, word3, word4, word5, word6, word7, word8, word9};
    int length[10]{};
    int counter{};
    int j{};
    for (int i = 0; i < 10; i++){
        while (words[i][j] != '\0'){
            j++;
            counter++;
        }
        length[i] = counter;
        counter = 0;
        j=0;
    }
    
}

