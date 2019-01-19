    /**
        Author: Santosh Tandrothu
        Date: 01/19/2019
        Problem: Given a vector of integers, shuffle the ints uniformly in-place.
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(1)
    **/


#include <iostream>
#include <random>
#include <vector>

using namespace std;

size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}

void shuffle(vector<int>& v)
{
    // shuffle the input in place
    if(v.size()==0){throw invalid_argument("Vector is empty");}
    if(v.size()==1){return;}

    for(int indexSelected = 0; indexSelected<v.size();indexSelected++){
        int randomGenUniformIndex = getRandom(0,v.size()-1);

        if(indexSelected!=randomGenUniformIndex){
            swap(v[indexSelected],v[randomGenUniformIndex]);
        }
    }

}

void printVector(const char* title, const vector<int>& v)
{
    cout << title << ": [";
    bool isFirst = true;
    for (int value: v) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << ", ";
        }
        cout << value;
    }
    cout << ']' << endl;
}

int main(int argc, char** argv)
{
    const vector<int> initial {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> shuffled(initial);
    shuffle(shuffled);
    printVector("initial vector", initial);
    printVector("shuffled vector", shuffled);
    return 0;
}
