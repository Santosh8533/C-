#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main()
{
    /*If no seed has given, by default it takes srand(1) and prints 41*/
    for(int i=0;i<10;i++)
        cout<<"First random value"<<rand()%100<<endl;

    /*srand(1); here sets the second random value to 41*/
    srand(time(0));
    cout<<"Second random value"<<rand()%100<<endl;
    return 0;
}
