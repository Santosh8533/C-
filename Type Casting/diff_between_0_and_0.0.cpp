/*Diff between 0 and 0.0: The compiler treats both literals as same*/
#include<iostream>

using namespace std;

int main(){
    int i=0;
    double j=1/float (2); // If you want to print 0.5, one of the literals should be float/double
    //double j=1/2; //Here 0 is store in j because 1 and 2 are evaluated as integers
    cout<<"i value"<<i<<"size is:"<<sizeof(i)<<endl;
    cout<<"j value"<<j<<"size is:"<<sizeof(j)<<endl;

return 0;
}
