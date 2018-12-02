/**
    Author: Santosh Tandrothu
    Date: 01/12/2018

    Problem: Design a inflight entertain system with on-demand movie streaming.
    Given the flight time and move durations, provide a pair of movies that passengers
    could watch within the flight time.
**/


    /***
        Time Complexity = O(n)
        Space Complexity = O(n)
    **/


#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

void TwoMoviesThatFillFlightDuration(int flightDuration,const vector<int>& movieDurations){
    //lookup for movies
    unordered_set<int> movieQueue;

    //for each movie -
    for(int firstMovieDuration:movieDurations){
        int secondMovieDuration = flightDuration - firstMovieDuration;
        if(movieQueue.find(secondMovieDuration)!=movieQueue.end()){
            cout<<firstMovieDuration<<" "<<secondMovieDuration<<endl;
        }
        else movieQueue.insert(firstMovieDuration);
    }

    return;
}

int main(){
    int flightDuration = 5;
    vector<int> movieDurations = {1,2,3,4,5};
    cout<<"Two movies that can fill flight duration:"<<endl;
    TwoMoviesThatFillFlightDuration(flightDuration,movieDurations);

}
