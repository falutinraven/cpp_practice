#include <iostream>
using namespace std;

int get_int_cin(){
    cout << "insert integer: " << '\n';
    char digit; 
    int total = 0;
    while(true) {
        digit = cin.get();

        if (digit == '\n') {
            return total;
	}

        total = (total * 10) + (digit - '0');
    }
    return total;
}

int main(void){
    int input = get_int_cin();
    cout << "this is the int you input: " << input << '\n'; 
    return 0;
}
