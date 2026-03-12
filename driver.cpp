#include "ArrayStack.hpp"
#include <iostream>

using namespace std;

int main()
{
    ArrayStack<int>* stack = new ArrayStack<int>();

    stack->push(10);
    stack->push(12);
    stack->push(1);
    stack->push(32);
    stack->push(8);

    cout << *stack << endl;

    cout << "add one to stack" << endl;

    stack->push(1);

    cout << "\n one has been added, now verify with peek that it has indeed been added" << endl;

    cout << stack->peek();
    
    cout << "\ncheck stack to make sure that it is expected value" << endl;

    cout << *stack << endl;

    cout << "\npop 3 times, then check for expected values" << endl;

    stack->pop();
    stack->pop();
    stack->pop();

    cout << *stack << endl;
    return 0;
}