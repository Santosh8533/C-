#include <iostream>

using namespace std;

class Box{
    public:
    int l,b,h;
    Box():l(0),b(0),h(0){ cout<< "Initialized \n";}
    //Box(const Box& b):l(b.l),b(b.b),h(b.h){} // This should be 'const' because it references the object b1's base address. This should not be modified. If this is modified, there would be serious issues.

      void output(ostream& out){
          cout << l << " " << b << " " << h << endl;
      }


};

ostream& operator<<(ostream& out, Box& b){
    b.output(out);
}

int main() {

    Box b1;
    b1.l = 1;
    b1.b = 2;
    b1.h = 3;
    cout << b1;

    return 0;
}
