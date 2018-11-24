/**Notes
    1. Thought: Consider the sub string except last char, place the last char in all the possible
                positions in the sub string to get all permutations. Recurse
    2. what is const string& inputString?
    3. Background on unordered_set

**/

    /**
        Author: Santosh Tandrothu
        Date: 11/24/2018
        Problem: Given a string, generate all the possible permutations
    **/

    /***
        Time Complexity = O(n!)
        Space Complexity = O(n!)
    **/


#include<unordered_set>
#include<iostream>
#include<string>

using namespace std;

unordered_set<string> getPermutations(const string& inputString){
    unordered_set<string> permutations;

    //base
    if(inputString.length()<=1){
        permutations.insert(inputString); //inserts single characters like a or b or c
        return permutations;
    }

    string allCharsExceptLast = inputString.substr(0,inputString.length()-1);
    char lastChar = inputString[inputString.length()-1];

    //generate all permutations for a given string except last
    //permutationsOfAllCharsExceptLast = temp spot to store all the permutations except last
    const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    //Insert the lastChar in all possible positions for each permutation
    for (const string& permutationOfAllCharsExceptLast:permutationsOfAllCharsExceptLast){
        for(size_t position=0;position<=permutationOfAllCharsExceptLast.length();++position){
            string permutation = permutationOfAllCharsExceptLast.substr(0,position)+
                                 lastChar+
                                 permutationOfAllCharsExceptLast.substr(position);
            permutations.insert(permutation); //permanent spot to store all the permutations
        }
    }
    return permutations;
}

int main(){

    unordered_set<string> permutations;
    permutations=getPermutations("abc");
    cout<<permutations.size()<<endl;
    for(auto it=permutations.begin();it!=permutations.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
