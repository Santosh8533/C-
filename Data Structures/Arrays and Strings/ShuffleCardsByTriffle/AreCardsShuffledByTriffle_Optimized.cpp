/**
    Author: Santosh Tandrothu
    Date: 12/21/2018
    Problem: Given a deck of cards which are split into two halfs and the cards were shuffled.
    Find the if the cards are shuffled by riffle.
**/

/**
    Run-time complexity: O(n) - all cards in the shuffled deck
    Space-time complexity: O(1)
**/

#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

bool areCardsShuffledByTriffle(vector<int>& halfDeck1,vector<int>& halfDeck2,vector<int>& shuffledDeck){

    if(shuffledDeck.empty()){return true;}
    //Start from the top of shuffledDeck
    //If it is present in deck1-update deck1 module
    //if its present in deck2-update deck2 module
    auto itDeck1 = halfDeck1.cbegin();
    auto itDeck2 = halfDeck2.cbegin();

    for(int i:shuffledDeck){
        if(itDeck1!=halfDeck1.cend() && i==*itDeck1){
            itDeck1++;
        }
        else if(itDeck2!=halfDeck2.cend() && i==*itDeck2){
            itDeck2++;
        }
        else {
            return false;
        }
    }

    return true;

}

int main(){

    vector<int> halfDeck1 = {1,2,3};
    vector<int> halfDeck2 = {4,5,6};

    /**Case1: A Triffle**/
    vector<int> shuffledDeck = {1,2,4,3,5,6};
    cout<<"Are cards shuffled by triffle?"<<areCardsShuffledByTriffle(halfDeck1,halfDeck2,shuffledDeck)<<endl;

    /**Case2: Not A Triffle**/
    shuffledDeck = {1,2,4,3,6,5};
    cout<<"Are cards shuffled by triffle?"<<areCardsShuffledByTriffle(halfDeck1,halfDeck2,shuffledDeck);
    return 0;
}
