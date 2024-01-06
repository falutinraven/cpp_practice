#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> group_anagrams(vector<string>& strs){
    vector<vector<string>> sol;
    unordered_map<string, vector<string>> mp;

    for(auto s : strs){
        string word = s;
        sort(word.begin(), word.end());
        mp[word].push_back(s);
    }

    for(auto kv : mp) {
        sol.push_back(kv.second);  
    } 

    return sol;
}

// This solution i am just copying the best solution i found on leetcode. my other solution i came up with on my own
int main(void){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> solution = group_anagrams(strs);

    for(auto i : solution){
        cout << '[';
        for(string s : i){
            cout << s << ", ";
        }
        cout << "], ";
    }
    cout << '\n';
    return 0;
}
