
            /**
                Author: Santosh Tandrothu
                Date: 1/18/2019
                Problem: Find if the full deck of cards are shuffled by a single triffle of two other half decks.
                Single Triffle: Random no of cards are placed in shuffled deck from either of the half decks alternatively.
            **/

            /**
                Run-time: O(n)
                Space: O(1)
            **/


#include<iostream>
#include<vector>

using namespace std;

bool isSingleRiffle(const vector<int>& shuffledDeck,
                    const vector<int>& halfDeck1,
                    const vector<int>& halfDeck2){

        int half1=0;
        int half2=0;
        for(int i=shuffledDeck.size()-1;i>=0;i--){

            //halfDeck should not be entirely visited && top of shuffledDeck should be equal to top of halfDeck
            if(half1!=halfDeck1.size() && shuffledDeck.at(i)==halfDeck1.at(half1)){
                half1++;
            }
            else if (half2!=halfDeck2.size() && shuffledDeck.at(i)==halfDeck2.at(half2)){
                half2++;
            }
            else{
                return false;
            }
        }
    return true;
}

int main(){
    vector<int> halfDeck1 = {3,2,1}; //{top to bottom}
    vector<int> halfDeck2 = {6,5,4}; //{top to bottom}
    //now pick each card from top of the above decks and place them in shuffledDeck
    vector<int> shuffledDeck = {4,1,2,5,3,6}; //{top to bottom}
    cout<<"Is this a single riffle?"<<isSingleRiffle(shuffledDeck,halfDeck1,halfDeck2)<<endl;
    //not a single riffle
    vector<int> shuffledDeck1 = {4,2,1,5,3,6}; //{top to bottom}
    cout<<"Is this a single riffle?"<<isSingleRiffle(shuffledDeck1,halfDeck1,halfDeck2)<<endl;
}
