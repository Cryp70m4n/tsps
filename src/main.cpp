// STDs
#include <iostream>

// Data structures
#include <stack>
#include <unordered_map>


int main() {
    std::unordered_map<int, int> plist;
    std::stack<int> main;
    std::stack<int> execute;
    std::stack<int> waiting;
    
    int priority = 10;
    int pid = 4000;

    while(priority >= 0) {
        plist[pid] = priority;
        pid+=5;
        priority--;
    }
    
    for (auto pid : plist)
        main.push(pid.first);
    
    execute.push(main.top());
    main.pop();
    
    int main_size = main.size();
    for(int i = 0; i < main_size; i++)
    {
        if(plist[main.top()] < plist[execute.top()]) {
            execute.push(main.top());
        }
        else {
            waiting.push(main.top());
        }
        main.pop();
    }

    for (auto element : plist)
        std::cout << "Element::" << element.first << " " << element.second << "\n";
    
    std::cout << "\n\n\n";
    std::cout << "Execution:" << "PID:" << execute.top() << "|PRIORITY:" << plist[execute.top()] << "\n";

    return 0;
}