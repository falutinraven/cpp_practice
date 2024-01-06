#include <iostream>
#include <vector>
#include <unordered_set>

bool is_valid_sudoku(std::vector<std::vector<char>>& board){
    std::unordered_set<char> nums_on_board;
    for(auto row : board){
        for(char c : row){
            if(c == '.'){
                continue;
            }
            if(nums_on_board.contains(c)){
                return false;
            }
            nums_on_board.insert(c);
        }
        nums_on_board.clear();
    }

    for(int col = 0; col < 9; col++){
        for(int row = 0; row < 9; row++){
            char c = board[row][col];
            if(c == '.'){
                continue;
            }
            if(nums_on_board.contains(c)){
                return false;
            }
            nums_on_board.insert(c);
        }
        nums_on_board.clear();
    }

    for(int add_3 = 0; add_3 < 9; add_3 += 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                char c = board[i+add_3][j];
                if(c == '.'){
                    continue;
                }
                if(nums_on_board.contains(c)){
                    return false;
                }
                nums_on_board.insert(c);
            }
        }
        nums_on_board.clear();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                char c = board[i][j+add_3];
                if(c == '.'){
                    continue;
                }
                if(nums_on_board.contains(c)){
                    return false;
                }
                nums_on_board.insert(c);
            }
        }
        nums_on_board.clear();
    }

    return true;
}

int main(void){
    std::vector<std::vector<char>> right_board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    std::vector<std::vector<char>> wrong_board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool is_right_right = is_valid_sudoku(right_board);
    bool is_wrong_right = is_valid_sudoku(wrong_board);

    std::cout << "It is " << is_right_right << " that the valid board is valid.\n";
    std::cout << "It is " << is_wrong_right << " that the invalid board is valid.\n";
    return 0;
}
