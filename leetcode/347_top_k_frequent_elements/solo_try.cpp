#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> top_k_freq(vector<int> &nums, int k){
    unordered_map<int, int> freqs;
    vector<int> sol(k);
    for(int i: nums){
        freqs[i]++;
    }

    auto comp = [&freqs](int a, int b){
        return freqs[a] > freqs[b];
    };
    priority_queue<int, vector<int>, decltype(comp)> heap(comp);

    for(pair<int, int> kv: freqs){
        heap.push(kv.first);
        if(static_cast<int>(heap.size()) > k){
            heap.pop();
        }
    }

    for(int i = k-1; i >= 0; i--){
        sol[i] = heap.top();
        heap.pop();
    }
    return sol;
}

int main(void){
    vector<int> nums = {1, 1, 1, 1, 1, 3, 4, 5, 6, 8, 8, 8, 6};
    // should be 1, 8, 6
    vector<int> top_k_nums = top_k_freq(nums, 3);
    for(int i : top_k_nums){
        cout << i << ", ";
    } 
    cout <<'\n';
    return 0;
}
