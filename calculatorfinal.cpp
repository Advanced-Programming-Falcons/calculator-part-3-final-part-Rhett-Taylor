#include <iostream>
#include <string> 
#include <sstream>
#include <cmath>
using namespace std;
double num1 = 0;
char op = 'p';
double num2 = 0;
string input;
string history = "";
void runCalculator();
bool parseInput();
void historyAdd(string addition){
    history = history+addition;
}
int main(void){
    cout << "I'm sorry you have to do math, can I help you?" << endl;
    while (true){
    cout << "Enter equation";
    getline(cin, input);
    if(parseInput()){
        runCalculator();
    }
    else{
        cout << "Okay buddy nice try, you have to input it different than that like this: 5+5, 1-1, 6^4 etc \n";
    }

    }
    return 0;
}
bool parseInput(){
    istringstream iss(input);
    if(iss >> num1 >> op >> num2){
        return true;
    }
    return false;
}
void runCalculator(){
                if(op != 'h'){history = history + to_string(num1) + op + to_string(num2) + "\n";}
    switch(op){
        case '+':
            cout << num1 + num2;
            historyAdd(to_string(num1+num2) + "\n");
            break;
        case '*':
            cout << num1 * num2;
           historyAdd(to_string(num1*num2)+ "\n");
            break;
        case '-':
            cout << num1 - num2;
            historyAdd(to_string(num1-num2)+ "\n");
            break;
        case '^':
            cout << pow(num1, num2);
            historyAdd(to_string(pow(num1,num2))+ "\n");
            break;
        case '/':
            cout << num1/num2;
            historyAdd(to_string(num1/num2)+ "\n");
            break;
        case 'r':
            cout << pow(num1, (1/num2));
            historyAdd(to_string(pow(num1, (1/num2)))+ "\n");
            break;
        case 'h':
            cout << history;
            break;
        default:
            cout << "Okay buddy nice try, you have to input it different than that like this: 5+5, 1-1, 6^4 etc \n";
    }
    cout << endl;
}
