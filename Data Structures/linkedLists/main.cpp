#include <iostream>
#include "linkedList.h"
#include <cstdlib>
using namespace std;

int main()
{
    int input;
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 5; ++i)
    {
        //list->addNodeAtBeginning(rand() % 100);
        cin>>input;
        //list->addNodeAtEnd(rand() % 100);
        list->addNodeAtBeginning(input);
        list->addNodeAtEnd(input);
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}
