#include <iostream>

using namespace std;

class Box{
    public:
    int l,b,h;
    Box():l(0),b(0),h(0){ cout<< "Initialized";}
    Box(const Box& b):l(b.l),b(b.b),h(b.h){} // This should be 'const' because it references the object b1's base address. This should not be modified. If this is modified, there would be serious issues.

};

int main() {

    Box b1;
    b1.l = 1;
    b1.b = 2;
    b1.h = 3;
    cout<< "Address of b1"<< &b1 <<endl;
    Box b2(b1);
    cout<< "Address of b2"<< &b2 <<endl;
    cout<< "b2 length - breadth - height " << b2.l << b2.b << b2.h << endl;
    return 0;
}
