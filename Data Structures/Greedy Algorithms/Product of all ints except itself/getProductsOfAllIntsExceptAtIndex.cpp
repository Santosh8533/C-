
    /**
        Author: Santosh Tandrothu
        Date: 01/17/2019
        Problem: Given a vector of integers, find the product of all integers
        except at the index and store all the products in a separate vector.

        Ex: nums = {1,2,3,4,5}
            product = {120,60,40,30,24}
    **/

    /***
        Time Complexity = O(n) - two passes through the vector (forward and backward)
        Space Complexity = O(n) - to save products
    **/



#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{

    if(intVector.size()<2){
        throw invalid_argument("Need at least two elements for product");
    }
    vector<int> productInts(intVector.size());
    //calculate left product using numbers left to current element
    int productSoFar = 1;

    for(int i=0;i<intVector.size();i++){
        productInts.at(i) = productSoFar;
        productSoFar = productSoFar*intVector.at(i);
    }
    //calculate right product using numbers right to current element
    productSoFar = 1;
    for(int i=intVector.size()-1;i>=0;i--){
        productInts.at(i) =  productInts.at(i) * productSoFar;
        productSoFar = productSoFar * intVector.at(i);
    }
    return productInts;
}


















// tests

const lest::test tests[] = {
    CASE("small vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
        const auto expected = vector<int> {6, 3, 2};
        EXPECT(actual == expected);
    },

    CASE("longer vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
        const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
        EXPECT(actual == expected);
    },

    CASE("vector has one zero") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
        const auto expected = vector<int> {0, 0, 36, 0};
        EXPECT(actual == expected);
    },

    CASE("vector has two zeros") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
        const auto expected = vector<int> {0, 0, 0, 0, 0};
        EXPECT(actual == expected);
    },

    CASE("one negative number") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
        const auto expected = vector<int> {32, -12, -24};
        EXPECT(actual == expected);
    },

    CASE("all negative numbers") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
        const auto expected = vector<int> {-8, -56, -14, -28};
        EXPECT(actual == expected);
    },

    CASE("error with empty vector") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
    },

    CASE("error with one number") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
    },
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
