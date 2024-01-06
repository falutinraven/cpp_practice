#include <iostream>
#include <vector>

std::vector<int> prod_except_self(std::vector<int>& nums){
    int size = nums.size();
    std::vector<int> sol(size);

    sol[0] = 1;
    for(int i = 1; i < size; i++){
        sol[i] = sol[i-1]*nums[i-1];
    }

    int right_prod = 1;
    for(int i = size-1; i >= 0; i--){
        sol[i]*=right_prod;
        right_prod*=nums[i];
    }

    return sol;
}

int main(void){
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> sol = prod_except_self(nums);


    for(int i: sol){
        std::cout << i << ", ";
    }
    std::cout << '\n';
    return 0;
    
}
