#include<iostream>
#include<ctime> //std::time
#include<cstdlib> //std::rand and srand

using namespace std;

  size_t getRandom(size_t floor, size_t ceiling)
{
    static random_device rdev;
    static default_random_engine generator(rdev());
    static uniform_real_distribution<double> distribution(0.0, 1.0);
    double value = distribution(generator);
    return static_cast<size_t>(value * (ceiling - floor + 1)) + floor;
}
int main(){
    cout<<"Generating random numbers uniformly:"<<endl;

}
