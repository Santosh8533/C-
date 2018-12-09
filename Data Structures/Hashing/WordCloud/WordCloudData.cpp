    /**
        Author: Santosh Tandrothu
        Date: 12/09/2018
        Problem: Given a string, form a wordcloud infographic where the size of each
        word increases with it's occurence.
        Ex: This is crazy. Tom is crazy to do these kind of things. Oh! Tom.
        Here in the infographic, word "Tom" will be biggest, next is and so on...
    **/

    /***
        Time Complexity = O(n) - traverse the entire string
        Space Complexity = O(n) - entire string and it's no of occurences
    **/




#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>



using namespace std;


        // count the frequency of each word
class WordCloudData
{
private:
    unordered_map<string, size_t> wordsToCounts_;

    void populateWordsToCounts(const string& inputString)
    {
        // iterates over each character in the input string, splitting
        // words and passing them to addWordToHashMap()

        size_t currentWordStartIndex = 0;
        size_t currentWordLength = 0;

        for (size_t i = 0; i < inputString.length(); ++i) {
            char character = inputString[i];

            // if we reached the end of the string we check if the last
            // character is a letter and add the last word to our hash map
            if (i == inputString.length() - 1) {
                if (isalpha(character)) {
                    if (currentWordLength == 0) {
                        currentWordStartIndex = i;
                    }
                    ++currentWordLength;
                }
                if (currentWordLength > 0) {
                    string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                    addWordToHashMap(currentWord);
                }
            }

            // if we reach a space we know we're at the end of a word
            // so we add it to our hash map and reset our current word
            else if (character == ' ') {
                if (currentWordLength > 0) {
                    string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                    addWordToHashMap(currentWord);
                    currentWordLength = 0;
                }
            }

            // we want to make sure we split on ellipses so if we get two periods in
            // a row we add the current word to our hash map and reset our current word
            else if (character == '.') {
                if (i < inputString.length() - 1 && inputString[i + 1] == '.') {
                    if (currentWordLength > 0) {
                        string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                        addWordToHashMap(currentWord);
                        currentWordLength = 0;
                    }
                }
            }

            // if the character is a letter or an apostrophe, we add it to our current word
            else if (isalpha(character) || character == '\'') {
                if (currentWordLength == 0) {
                    currentWordStartIndex = i;
                }
                ++currentWordLength;
            }

            // if the character is a hyphen, we want to check if it's surrounded by letters
            // if it is, we add it to our current word
            else if (character == '-') {
                if (i > 0 && isalpha(inputString[i - 1])
                        && isalpha(inputString[i + 1])) {
                    if (currentWordLength == 0) {
                        currentWordStartIndex = i;
                    }
                    ++currentWordLength;
                }
                else if (currentWordLength > 0) {
                    string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                    addWordToHashMap(currentWord);
                    currentWordLength = 0;
                }
            }
            //to handle other characters like '!' in Oh! my god
            else{
                string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                addWordToHashMap(currentWord);
                currentWordLength = 0;
            }
        }
    }

    void addWordToHashMap(const string& word)
    {
        // if the word is already in the hash map we increment its count
        auto it = wordsToCounts_.find(word);
        if (it != wordsToCounts_.end()) {
            ++it->second;
        }

        // if a lowercase version is in the hash map,
        // we know our input word must be uppercase
        // but we only include uppercase words if they're always uppercase
        // so we just increment the lowercase version's count
        else if ((it = wordsToCounts_.find(toLowerCase(word))) != wordsToCounts_.end()) {
            ++it->second;
        }

        // if an uppercase version is in the hash map,
        // we know our input word must be lowercase.
        // since we only include uppercase words if they're always uppercase,
        // we add the lowercase version and give it the uppercase version's count
        else if ((it = wordsToCounts_.find(capitalize(word))) != wordsToCounts_.end()) {
            size_t newCount = it->second + 1;
            wordsToCounts_.erase(it);
            wordsToCounts_.insert(make_pair(word, newCount));
        }

        // otherwise, the word is not in the hash map at all, lowercase or uppercase
        // so we add it to the hash map
        else {
            wordsToCounts_.insert(make_pair(word, 1));
        }
    }

    static string toLowerCase(const string& word)
    {
        string result = word;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    static string capitalize(const string& word)
    {
        string result = word;
        result[0] = toupper(result[0]);
        return result;
    }

public:
    WordCloudData (const string& inputString)
    {
        populateWordsToCounts(inputString);
    }

    const unordered_map<string, size_t> getWordsToCounts() const
    {
        return wordsToCounts_;
    }
};

void printWordsToCounts(unordered_map<string, size_t> wordsToCounts){
    for(auto it=wordsToCounts.begin();it!=wordsToCounts.end();it++){
        cout<<it->first<<":"<<it->second<<endl;
    }
}
int main()
{
    //Test case: 1 -> Simple string
    WordCloudData cloud1("Hi there");
    unordered_map<string, size_t> wordsToCounts = cloud1.getWordsToCounts();
    printWordsToCounts(wordsToCounts);
    //Test case: 2 -> Longer string
    WordCloudData cloud2("This is a longer string");
    wordsToCounts = cloud2.getWordsToCounts();
    printWordsToCounts(wordsToCounts);
    //Test case: 3 -> Punctuation
    WordCloudData cloud3("Oh!God, punctuation.");
    wordsToCounts = cloud3.getWordsToCounts();
    printWordsToCounts(wordsToCounts);
    //Test case: 4 -> Hyhpenated words
    WordCloudData cloud4 ("You are a Dundie-Muffie");
    wordsToCounts = cloud4.getWordsToCounts();
    printWordsToCounts(wordsToCounts);
    //Test case: 5 -> Ellipses
    WordCloudData cloud5 ("That's....mmmm...interesting");
    wordsToCounts = cloud5.getWordsToCounts();
    printWordsToCounts(wordsToCounts);
    //Test case: 6 -> apostrophes
    WordCloudData cloud6 ("That's what she said in Nick's game!Lol");
    wordsToCounts = cloud6.getWordsToCounts();
    printWordsToCounts(wordsToCounts);

}
