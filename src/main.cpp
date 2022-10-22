#include <iostream>
#include <stack>

int main() {
    std::stack<int> main;
    std::stack<int> execute;
    std::stack<int> waiting;

    for(int i = 0; i <= 10; i++)
        main.push(i);
    
    int tmp = main.size();
    for(int i = 0; i < tmp; i++)
    {
        std::cout << "Element:" << main.top() << "\n";
        main.pop();
    }

    return 0;
}