#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> rowVector;
std::vector<int> columnVector;
std::vector<int> sectionVector;
int rowVectorSize;
int columnVectorSize;
int sectionVectorSize;
int arraySum;
bool changed;
double status;

bool containsElement(const std::vector<int>& vec, int elementToFind) {
    return std::find(vec.begin(), vec.end(), elementToFind) != vec.end();
}

bool isValidSudoku(std::array<std::array<int, 9>, 9>& board) {
    std::array<std::array<bool, 10>, 9> rowContains{};
    std::array<std::array<bool, 10>, 9> colContains{};
    std::array<std::array<std::array<bool, 10>, 3>, 3> sectionContains{};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = board[i][j];
            if (num == 0) {
                continue;  
            }
            
            int sectionRow = i / 3;
            int sectionCol = j / 3;
            
            if (rowContains[i][num] || colContains[j][num] || sectionContains[sectionRow][sectionCol][num]) {
                return false;  
            }
            
            rowContains[i][num] = true;
            colContains[j][num] = true;
            sectionContains[sectionRow][sectionCol][num] = true;
        }
    }
    return true; 
}

std::array<std::array<int,9>, 9> printArray(std::array<std::array<int, 9>, 9> arrayCalculator){
    std::cout << "----------------------" << endl;
     for(int i = 0; i < 9; i++){
        if(i == 3){
            std::cout << "--------------------" << endl;
        }
        if(i == 6){
            std::cout << "--------------------" << endl;
        }
        std::cout << "|";
        
        for(int j = 0; j < 9; j++){
            std::cout << arrayCalculator[i][j] << " ";
            if(j == 2){
            std::cout << "|";
            }
            if(j == 5){
            std::cout << "|";
            }
        }
        std::cout << "|" << endl;
     }
    std::cout << "---------------------";
    
}

bool solveSudoku(std::array<std::array<int, 9>, 9>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    board[i][j] = num;
                    if (isValidSudoku(board) && solveSudoku(board)) {
                        return true;
                    }
                    board[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::array<std::array<int, 9>, 9> inputArray = {
       {
        {0,0,7,0,0,0,0,0,8},
        {5,0,0,0,0,6,0,0,7},
        {0,3,4,8,0,0,0,6,0},
        {0,0,0,0,3,7,1,0,9},
        {0,7,1,0,0,0,0,5,0},
        {0,0,0,0,5,0,0,7,0},
        {0,0,0,0,1,0,7,0,0},
        {0,0,0,0,1,0,7,0,0},
        {1,9,0,0,0,0,0,8,6}
    }
    };
    
    if (solveSudoku(inputArray)) {
        printArray(inputArray);
    }
    else {
        std::cout << "No solution found for Sudoku." << std::endl;
    }

    return 0;
}