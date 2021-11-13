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
    std::string buttons[16][4] = {
        {"0", "space"}, 
        {"voicemail"},   {"a", "b", "c"}, {"d", "e", "f"}, 
        {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, 
        {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"},  
        {"*"}, {"#"}, {"call"}, {"middle"}, {"L"}, {"R"}
    };
    int buttonLengths[16] = {
        2, 
        1, 3, 3, 
        3, 3, 3, 
        4, 3, 4,  
        1, 1, 1, 1, 1, 1
    };
    int totalTime{}, lastButtonPressed{};

    // Check each letter in word 
    for(int i{}; i < length; ++i) {
        
        // Check each button
        bool letterFound{false};
        if(!letterFound) {
            for(int j{2}; j < 10; ++j) {
                int buttonPressCount{};

                // Check each letter in button to match letter in word
                if(!letterFound) {
                    for(int k{}; k < buttonLengths[j]; ++k) {

                        if(word[i] != buttons[j][k][0]) {
                            ++buttonPressCount;
                        } else {
                            ++buttonPressCount;
                            totalTime += buttonPressCount;
                            std::cout << buttonPressCount;
                            letterFound = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    return totalTime;
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

    std::cout << std::endl;    

    for (int j = 0; j < 10; j++){
        std::cout << calculateTime(words[j], lengths[j]);

    }

}

