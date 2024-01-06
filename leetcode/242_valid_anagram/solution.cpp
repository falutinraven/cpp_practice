#include <iostream>
#include <string>

using namespace std;

bool is_anagram(string s, string t){
    int letters_in_alphabet = 'z' - 'a' + 1;
    int counts[letters_in_alphabet] = {0};

    for(char i : s){
        counts[i-'a']++;
    }

    for(char i : t){
        counts[i-'a']--;
    }

    for(int i : counts){
        if(i != 0){
            return false;
	}
    }
    return true;
}

int main(){
    string s;
    string t; 

    std::cout << "Enter the first string: ";
    std::cin >> s;
    std::cout << "Enter the second string: ";
    std::cin >> t;

    bool anagram = is_anagram(s, t);
    cout << "it is ";

    if(anagram){
        cout << "True";
    }
    else {
        cout << "False";
    } 

    cout << " that strings \"" << s << "\" and \"" << t << "\" are anagrams." << '\n';
    return 0;
}
