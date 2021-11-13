#include <iostream>
#include <fstream>
#include <cctype>

int main();
void parseWords();
int getWordLength(std::string word);
double calculateTime();

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
double calculateTime(std::string word, int length) {
    std::string buttons[16][4] = {
        {"0", "space"}, 
        {"voicemail"},   {"a", "b", "c"}, {"d", "e", "f"}, 
        {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, 
        {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"},  
        {"*"}, {"#"}, {"call"}, {"middle"}, {"Left"}, {"Right"}
    };
    int buttonLengths[16] = {
        2, 
        1, 3, 3, 
        3, 3, 3, 
        4, 3, 4,  
        1, 1, 1, 1, 1, 1
    };
    double totalTime{};
    int lastButtonPressed{};
    bool firstLetter{true};
    int j{};
    int capitalCount{};
    // Check each letter in word 
    for(int i{}; i < length; ++i) {
        // Add 2 seconds for every uppercase letter
        if (isupper(word[i])){ 
            word[i] = word[i] + 32;
            capitalCount += 1;
        }
        bool letterFound{false};
        // Check each button
        if(!letterFound) {
            for(j = 2; j < 12; ++j) {
                int buttonPressCount{0};
                
                // Check each letter in button to match letter in word
                if(!letterFound) {
                    for(int k{}; k < buttonLengths[j]; ++k) {

                        if(word[i] != buttons[j][k][0]) {
                            //std::cout << "fklajf" << std::endl;
                            ++buttonPressCount;
                        } else {
                            //std::cout << "yo" << std::endl;
                            //std::cout << "first letter status" << firstLetter;
                            if (firstLetter == false){
                                //std::cout << "supduao" << std::endl;
                                ++buttonPressCount;
                                if (lastButtonPressed == j){
                                    totalTime += 0.5 + ((buttonPressCount - 1) * 0.25);
                                    //std::cout << "sup" << std::endl;
                                } else{
                                    totalTime += buttonPressCount * 0.25;
                                }
                                //std::cout << totalTime;
                            } else{
                                //std::cout << totalTime;
                            }
                            letterFound = true;
                            lastButtonPressed = j;
                            firstLetter = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    //std::cout << std::endl;
    totalTime = totalTime + (2 * capitalCount);
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
        //std::cout << getWordLength(words[i]);
    }

    //std::cout << std::endl;    
    int shortestTimes{};
    int nextEmptyIndex{1};
    if (calculateTime(words[0], lengths[0]) == 0){
        shortestTimes = INT_MAX;
    } else{
        shortestTimes = calculateTime(words[0], lengths[0]);
    }
    for (int j = 1; j < 10; j++){
        if (calculateTime(words[j], lengths[j]) != 0){
            if (calculateTime(words[j], lengths[j]) < shortestTimes){
                shortestTimes = calculateTime(words[j], lengths[j]);
            }
        }
    }
    for (int k = 0; k < 10; k++){
        if (shortestTimes == INT_MAX){
            break;
        } else if (calculateTime(words[k], lengths[k]) == shortestTimes){
            std::cout << words[k] << " = " << shortestTimes << "s" << std::endl;
        }
    }
}

