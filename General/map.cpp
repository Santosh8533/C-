#include<iostream>
#include<map>
using namespace std;

int main(){

    //Declaration of an empty map container
    map <int, int> m;

    //Insert elements into the hash map
    m.insert( pair <int, int> (0,1));
    m.insert( pair <int, int> (1,2));
    //size
    cout << "size of map" << endl;
    //Access
    map <int, int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<< it->first << "--->";
        cout << it->second << endl;
    }
    //Modify

    //Delete
    return 0;
}
