#include <iostream>
#include "vector"
#include "string"
#include "fstream"

std::vector<int> findRange(std::vector<int> allNums){
    std::vector<int> range;
    int min = allNums.front();
    int max = 0;
    for (auto elem: allNums) {
        if (min > elem) min = elem;
        if (max < elem) max = elem;
    }
    range.push_back(min);
    range.push_back(max);

    return range;
}

void removeLines(std::vector<int> allNums){
    auto range = findRange(allNums);
    std::string line;
    std::ifstream inputFile("text.txt");
    std::ofstream outputFile("file.txt");

    int lineNumber = 0;
    while(std::getline(inputFile,line)){
        lineNumber++;
        if (lineNumber <= range.front() || lineNumber >= range.back()){
            outputFile << line <<std::endl;
        }
    }
    inputFile.close();
    outputFile.close();

}


int main() {
    std::vector<int> allNums;
    std::string line;

    std::ifstream inputFile("text.txt");
    std::ofstream outputFile("file.txt");

    auto input = 0;

    while (input!=-1){

        std::cin >> input;
        if (input == -1) break;
        allNums.push_back(input);
    }
    removeLines(allNums);


    return 0;
}
