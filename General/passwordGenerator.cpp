#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    int len,i,num;
    string s={"1234567890!@#$%^&*()"};
    //cout<<s.length()<<endl;
    cout<<"Enter the length of the password:"<<endl;
    cin>>len;
    cout<<"How many passwords do you want?"<<endl;
    cin>>num;
    string password(len,'x');
    cout<<"Initial Password:"<<password<<endl;
    srand(time(0));
    cout<<"Passwords Generated:"<<endl;
    for(int j=0;j<num;j++){
        for(i=0;i<len;i++){password[i]= s[rand()%s.length()];}
        cout<<password<<endl;
    }

    return 0;
}
