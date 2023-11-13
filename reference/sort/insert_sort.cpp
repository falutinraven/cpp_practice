#include <iostream>
using namespace std;

int main(void){
    int LEN = 8;
    int arr[LEN] = {4, 2, 6, 3, 77, 3, 8, 1};
    int tmp;

    for(int i = LEN-1; i >= 0; i--){
        for(int j = 1; j < LEN-i && arr[j-1] > arr[j]; j++){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        } 
    }

    for(int i = 0; i < LEN; i++){
        cout << arr[i] << ", ";
    }
    cout << '\n';
    return 0;
}
