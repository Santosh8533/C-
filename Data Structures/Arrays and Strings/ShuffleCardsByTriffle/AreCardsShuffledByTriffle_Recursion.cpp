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

using namespace std;

bool isTriffle(vector<int>& halfDeck1, vector<int>& halfDeck2,vector<int>& shuffDeck ){

    //base condition
    if(shuffDeck.empty()){return true;}

    //pick a card from shuffled deck
    //check if it is the top card on either halfdeck1 or halfdeck2
    //if it is move on to next card in shuffled deck or remove the current card from shuffDeck
     if(!halfDeck1.empty() && shuffDeck.back()==halfDeck1.back()){
        shuffDeck.pop_back();
        halfDeck1.pop_back();
        return isTriffle(halfDeck1,halfDeck2,shuffDeck);
     }
     else if(!halfDeck2.empty() && shuffDeck.back()==halfDeck2.back()){
        shuffDeck.pop_back();
        halfDeck2.pop_back();
        return isTriffle(halfDeck1,halfDeck2,shuffDeck);
     }

     //if not on top of one of the halfdecks
     return false;

}

bool areCardsShuffledByTriffle(vector<int> shuffDeck){

    vector<int> halfDeck1 = {1,2,3};
    vector<int> halfDeck2 = {4,5,6};


    return isTriffle(halfDeck1,halfDeck2,shuffDeck);

}

int main(){

    /**Case1: A Triffle**/
    vector<int> shuffledDeck = {1,2,4,3,5,6};
    cout<<"Are cards shuffled by triffle?"<<areCardsShuffledByTriffle(shuffledDeck)<<endl;

    /**Case2: Not A Triffle**/
    shuffledDeck = {1,2,4,3,6,5};
    cout<<"Are cards shuffled by triffle?"<<areCardsShuffledByTriffle(shuffledDeck)<<endl;
    return 0;
}
