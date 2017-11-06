/*
Generally out of place algorithms are considered safer because they avoid side effects.
You should only use an in-place algorithm if you are very space constrained or
you're positive you don't need the original input anymore, even for debugging.
*/
#include<iostream>

using namespace std;

int main(){
    string str;
    cout << "Enter a string: \n" ;
    cin >> str;
    cout << "Original String:->" << str << endl;
    int str_start = 0;
    int str_end = str.length() - 1;
    while(str_start < str_end){
        swap(str[str_start],str[str_end]);
        str_start++;
        str_end--;
    }
    cout << "Reversed string:->" << str << endl;
    return 0;
}
