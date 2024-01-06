#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> top_k_freq(vector<int>& nums, int k){
    int size = nums.size();
    if(k == size){
        return nums;
    }

    vector<int> sol(k);
    unordered_map<int, int> freqs;

    for(int num : nums){
        freqs[num]++;
    }

    auto comp = [&freqs](int a, int b) {return freqs[a] > freqs[b];};
    priority_queue<int, vector<int>, decltype(comp)> heap(comp); 
 

    for(pair<int, int> kv : freqs){
        heap.push(kv.first);
        if(static_cast<int>(heap.size()) > k){
            heap.pop();
        }
    }
    
    for(int i = 0; i < k; i++){
        sol[i] = heap.top();
        heap.pop();
    }
    return sol;
}

int main(void){
    vector<int> nums = {1, 1, 1, 2, 2,6, 6, 6, 6, 6, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3};
    vector<int> sol = top_k_freq(nums, 3);
    for(int freq : sol){
        cout << freq << ", ";
    }
    cout << '\n';
    return 0;
}
