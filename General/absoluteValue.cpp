
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

void update(int *a,int *b) {
    // Complete this function
    *a = *a + *b;
    int c = (*a) - (*b);
    cout<< "c value"<< c <<endl;
    *b = abs(c);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
