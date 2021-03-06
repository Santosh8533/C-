#include<iostream>
#include<sstream>

using namespace std;

//This function only separates the words based on space - 5 min
void printWordsInString(string str){
    stringstream ss(str);
    string word;
    while(!ss.eof()){
        ss>>word;
        cout<<word<<endl;
    }

}

//count no of words in a string- don't catch special characters
int countNoOfWordsInString(string str){
    stringstream ss(str);
    string word;
    int count_ = 0;
    while(!ss.eof()){
        ss>>word;
        count_++;
    }
    return count_;
}

//count no of words of size 'x' in a string- don't catch special characters
int countNoOfXLetterWords(string str, int wordLength){
    stringstream ss(str);
    string word;
    int count_=0;
    while(ss>>word){
        if(word.length()==wordLength){
            count_++;
        }
    }
    return count_;
}

int main(){
    string str = "This    is a string slash!";
    int wordLength = 6;
    cout<<"Words in the string are:"<<endl;
    printWordsInString(str);
    cout<<"No of words in the string are:"<<countNoOfWordsInString(str)<<endl;
    cout<<"No of words with 'x' size in the string are:"<<countNoOfXLetterWords(str,wordLength);

}
