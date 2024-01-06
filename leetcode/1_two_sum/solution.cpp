#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target){
    unordered_map<int, int> match_to_index; 

    int i = 0;
    for(int num : nums){
        if(match_to_index.contains(num)){
            return {match_to_index[num], i};
        }
        match_to_index.insert({target - num, i});
        i++;
    }
    return {0};
}

int main() {
    vector<int> nums = {3, 2, 5, 4};
    int target = 6;

    vector<int> sol = two_sum(nums, target);

    for(int i : sol){
        cout << i << ", ";
    }
    cout << '\n';
    return 0;
}
