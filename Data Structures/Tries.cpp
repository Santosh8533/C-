/**
    Data Structure: Tries
    Author: Santosh Tandrothu
    Date: 06/27/2018

    Algorithm Complexity: Run-time: Insertion & Search- O(string size)
                          Space: O(largest string size * 26bytes)- in case of alphabetical strings
*/
#include<iostream>
#include<string>

using namespace std;

const int SIZE=26;

//Trie Node
class Node{
public:
    Node* character[SIZE];
    bool isEndOfWord;
};

//Create a Trie Node

Node* newTrieNode(){
    Node* temp = new Node;
    for(int i=0;i<SIZE;i++){
        temp->character[i] = nullptr;
    }
    temp->isEndOfWord = false;
    return temp;
}

//Insert a word in the Trie

void InsertAWordInTrie(Node* root, string word){
    if(!root){return;}

    Node* temp = root;
    int index = 0;

    for(int i=0;i<word.length();i++){
        index = word[i] - 'a';
        if(!temp->character[index]){
            temp->character[index] = newTrieNode();
        }
        temp = temp->character[index];
    }
    //Mark end of word as true
    temp->isEndOfWord = true;
}
//Search a word in the Trie

bool SearchAWordInTrie(Node* root,string word){
    if(!root){return false;}

    Node* temp = root;
    int index = 0;
    for(int i=0;i<word.length();i++){
        index = word[i] - 'a';
        if(temp->character[index]){
            temp = temp->character[index];
        }
        else {return false;}
    }
    if(temp->isEndOfWord && temp!=nullptr){return true;}
}


int main(){

    string words[]={"the","there","ant","ball"};
    int words_ = sizeof(words)/sizeof(words[0]);

    //Create a root for trie
    Node* root = newTrieNode();

    //Insert words in trie
    for(int i=0;i<words_;i++){
        InsertAWordInTrie(root,words[i]);
    }

    //Search for words in trie
    for(int i=0;i<words_;i++){
        cout<<"Word:"<<words[i]<<"\t Found:"<<SearchAWordInTrie(root,words[i])<<"\n";
    }

    //False Cases
    cout<<"Word:santosh"<<"\t Found:"<<SearchAWordInTrie(root,"santosh")<<"\n";

}
