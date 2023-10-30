#include <iostream>
using namespace std;

int get_int_cin(){
    cout << "insert integer: " << '\n';
    int num;
    cin >> num;
    return num;
}

int main(void){
    int input = get_int_cin();
    cout << "this is the int you input: " << input << '\n'; 
    return 0;
}
