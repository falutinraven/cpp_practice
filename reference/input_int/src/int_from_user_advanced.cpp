#include <iostream>
#include <limits>
using namespace std;

int get_int_cin(){
    int num;
    while (true) {
        cout << "Insert integer: " << '\n';
        cin >> num;
        
        if (cin.fail()) { // If cin fails,
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
            cout << "Invalid input. Please enter an integer." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard remaining characters in buffer
            return num;
        }
    }
}

int main(void){
    int input = get_int_cin();
    cout << "this is the int you input: " << input << '\n'; 
    return 0;
}
