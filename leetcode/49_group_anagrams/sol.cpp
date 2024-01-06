#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


string sort_str(string& str){
    int size = str.length();
    char temp[str.length()];
    string ret = "";

    for(int i = 0; i < size; i++){
        temp[i] = str[i];
    }

    sort(temp, temp + size);

    for(int i = 0; i < size; i++){
        ret += temp[i];
    }
    return ret;
}

vector<vector<string>> group_anagrams(vector<string>& strs){
    vector<string> sorted;
    vector<vector<string>> sol;
    unordered_map<string, vector<string>> sorted_anagram_to_indices;
    int size = strs.size();

    for(string s : strs){
        sorted.push_back(sort_str(s));
    }

    for(int i = 0; i < size; i++){
        if(sorted_anagram_to_indices.contains(sorted[i])){
            sorted_anagram_to_indices[sorted[i]].push_back(strs[i]);
        }
        else{
            sorted_anagram_to_indices.insert({sorted[i], {strs[i]}});
        }
    }

    for(auto kv : sorted_anagram_to_indices) {
        sol.push_back(kv.second);  
    } 

    return sol;
}

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
