#include<iostream>

using namespace std;

//Pass by value
void printTemp(int *temp){
    cout<< temp << endl;
    cout << *temp << endl;
}

//Pass by lvalue reference
void printTemp(int &temp){
    cout<< "lvalue reference:" << temp << endl;
    cout << &temp << endl;
}
int main(){
    int a = 2;
    int *temp = &a;
    printTemp(temp);
    printTemp (*temp);
    return 0;
}
