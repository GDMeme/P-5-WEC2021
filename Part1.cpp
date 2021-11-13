#include <iostream>
#include <fstream>

int main();
void parseWords();
int getWordLength(std::string word);
int calculateTime();

/* Parse words from text files */
void parseWords(std::string words[]) {
    std::ifstream inFile;
    inFile.open(".\\Test1.txt");
    if (!inFile) {
        std::cout << "Unable to open file datafile.txt";
        exit(1); 
    }
    for(int i; i < 10; ++i) {
        inFile >> words[i];
    }
}

/* Returns length of each word */
int getWordLength(std::string word) {
    int counter{};
    int j{};
    while (word[j] != '\0'){
        j++;
        counter++;
    }
    return counter;
}

/* Calculates time to type a word */
int calculateTime(std::string word, int length) {
    
}

int main(){
    
    std::string word0{}, word1{}, word2{}, word3{}, word4{}, word5{}, word6{}, word7{}, word8{}, word9{};
    std::string words[10] = {word0, word1, word2, word3, word4, word5, word6, word7, word8, word9};
    parseWords(words);

    // Store word lengths in length[]
    int lengths[10]{};
    for (int i = 0; i < 10; i++){
        lengths[i] = getWordLength(words[i]);
        std::cout << getWordLength(words[i]);
    }    
}

