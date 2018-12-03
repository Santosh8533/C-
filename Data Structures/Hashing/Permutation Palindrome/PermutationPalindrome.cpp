    /**
        Author: Santosh Tandrothu
        Date: 12/02/2018
        Problem: Given a string, find whether any of the permutations of the string
        is a palindrome
        Ex: civic -> in order to be a palindrome it should have only one character with an odd occurrence
            c->2 v->1 i->2 = palindrome (only one odd occurrence)
            civi: c-> 1 i->2 v->1 = not a palindrome
            civivic: c->2 v->2 i->3 = palindrome (only one odd occurrence)
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(k) => k is the size of characters
        ASCII: 128 (letters and punctuation)
        Unicode: 110,000 --> it really depends on the encoding scheme
    **/



#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

bool hasPalindromePermutation(const string& inputString){
    //create an unordered map to store existence of odd characters
    unordered_set<char> unpairedCharacters;

    //iterate through the string
    //Add a character to the set if not already present - if present remove it
    for(char c:inputString){
        if(unpairedCharacters.find(c)!=unpairedCharacters.end()){
            unpairedCharacters.erase(c);
        }
        else{
            unpairedCharacters.insert(c);
        }
    }
    return unpairedCharacters.size() <=1;
}
int main(){
    string testInput = "civic";
    cout<<"Has palindrome permutation?"<<hasPalindromePermutation(testInput)<<endl;
    testInput = "civc";
    cout<<"Has palindrome permutation?"<<hasPalindromePermutation(testInput)<<endl;
    testInput = "civivic";
    cout<<"Has palindrome permutation?"<<hasPalindromePermutation(testInput)<<endl;
    return 0;
}
