/**
    Author: Santosh Tandrothu
    Date: 12/20/2018
    Problem: Given a deck of cards which are split into two halfs and the cards were shuffled.
    Find the if the cards are shuffled by riffle.
**/

/**
    Run-time complexity: O(n) - lookup of all cards one by one in either of the half decks
    Space-time complexity: O(n*n) -  stack space of height of recursion tree with n cards at beginning, n-1 for next call, n-2.....1
**/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

string findRotationPoint(const vector<string>& words){
    if(words.empty())return nullptr;

    string targetWord;

    //modified binary search
    //modification: Add decision making to higher and lower bounds
    int low =0, high = words.size()-1;

    while(low < high){
        int mid = (low+high)/2;
        targetWord = words.at(mid);

        if(targetWord[0] == 'a'){return targetWord;}

        string leftMostWord = words.at(low);
        string rightMostWord = words.at(high);

        if(leftMostWord[0] == 'a') return leftMostWord;
        else if(rightMostWord[0] == 'a') return rightMostWord;


        if(targetWord[0]>leftMostWord[0]){low=mid+1;}
        else if(targetWord[0]<leftMostWord[0]){high=mid-1;}
        else {
            return nullptr;
        }
    }
    return targetWord;
}




int main(){

    /**Test Case 1**/
    vector<string> words = {"cat","dog","egg","farmer","aim","brave"};
    string rotationPointWord = findRotationPoint(words);
    cout<<"The rotation point word is:"<<rotationPointWord<<endl;

    /**Test Case 2**/
    vector<string> words2 = {"farmer","aim","brave","cat","dog"};
    string rotationPointWord2 = findRotationPoint(words2);
    cout<<"The rotation point word is:"<<rotationPointWord2<<endl;

        /**Test Case 3**/
    vector<string> words3 = {"farmer","abraham","aim","brave","cat","dog"};
    string rotationPointWord3 = findRotationPoint(words3);
    cout<<"The rotation point word is:"<<rotationPointWord3<<endl;
    return 0;
}

/**
   what if multiple words with 'a' and you found second word with 'a'
**/
