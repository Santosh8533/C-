    /**
        Author: Santosh Tandrothu
        Date: 12/17/2018
        Problem: Given a certain meetings time slots in random order, merge the
        meetings into one meeting within the same timeframe.

        Ex: [1pm,3pm] [2pm,4pm] results in [1pm,4pm]
    **/

    /***
        Time Complexity = O(nlogn) - (sorting + comparison)
        Space Complexity = O(n) (merged meetings considering no merges possible)
    **/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Meeting{

private:
    //30 min block
    unsigned int startTime_;
    unsigned int endTime_;

public:
    Meeting():
        startTime_(0),
        endTime_(0)
        {

        }

    Meeting(int startTime, int endTime):
        startTime_(startTime),
        endTime_(endTime)
        {

        }

    unsigned int getStartTime() const{
        return startTime_;
    }

    void setStartTime(unsigned int startTime){
        startTime_ = startTime;
    }

    unsigned int getEndTime() const{
        return endTime_;
    }

    void setEndTime(unsigned int endTime){
        endTime_ = endTime;
    }

    bool operator==(const Meeting &other) const{
        return
            startTime_ == other.startTime_ &&
            endTime_ == other.endTime_;
    }


};

//compare function to built-in sort function
bool compareMeetingsByStartTime(const Meeting& m1, const Meeting& m2){
    return (m1.getStartTime()<m2.getStartTime());
}


vector<Meeting> mergeMeetings(const vector<Meeting>& meetings){
    //sort the meeting by start time
   vector<Meeting> sortedMeetings(meetings);
   sort(sortedMeetings.begin(),sortedMeetings.end(),compareMeetingsByStartTime);

   //initialize merged meeting with earliest meeting
   vector<Meeting> mergedMeetings;
   mergedMeetings.push_back(sortedMeetings.front());

   //iterate over all the meetings
   for(const Meeting& currentMeeting: sortedMeetings){
        Meeting& lastMergedMeeting = mergedMeetings.back();

        //modify
        if(currentMeeting.getStartTime() <= lastMergedMeeting.getEndTime()){
            lastMergedMeeting.setEndTime(max(currentMeeting.getEndTime(),lastMergedMeeting.getEndTime()));
        }
        //create a new entry
        else{
            mergedMeetings.push_back(currentMeeting);
        }
   }
   return mergedMeetings;
}


int main(){
    vector<Meeting> meetings;
    Meeting meeting1(6,8);
    meetings.push_back(meeting1);
    Meeting meeting2(3,5);
    meetings.push_back(meeting2);
    Meeting meeting3(2,3);
    meetings.push_back(meeting3);
    Meeting meeting4(1,2);
    meetings.push_back(meeting4);

    vector<Meeting> mergedMeetings = mergeMeetings(meetings);
    for(const Meeting meeting:mergedMeetings){
        cout<<"Meeting time:"<<meeting.getStartTime()<<"->"<<meeting.getEndTime()<<endl;
    }
}
