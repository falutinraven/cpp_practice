#include <stdio.h>
#include <string>
#include <vector>

void recursive_parenthesis(int open, int close, std::string curr, std::vector<std::string>& sol){
    if(open == 0 && close == 0){
        sol.push_back(curr);
    }
    if(open > 0){
        recursive_parenthesis(open-1, close, curr + '(', sol);
    }
    if(open < close){
        recursive_parenthesis(open, close-1, curr + ')', sol);
    }
}

std::vector<std::string> generate_parens(int num){
    std::vector<std::string> sol;
    recursive_parenthesis(num, num, "", sol);
    return sol;
}

int main(int argc, char* argv[]){
    std::vector<std::string> parens = generate_parens(5);
    for(std::string s: parens){
        printf("%s\n", s.c_str());
    }
    return 1;
}
