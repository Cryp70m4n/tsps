// STDs
#include <iostream>

// Data structures
#include <stack>
#include <unordered_map>

int process_scheduler(std::unordered_map<int, int> plist) {
    std::stack<int> main;
    std::stack<int> execute;
    std::stack<int> waiting;
    while (plist.size() > 0) {
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
        
        while(execute.size()) {
            //EXECUTE PROCESS HERE
            std::cout << "Execution:" << "PID:" << execute.top() << "|PRIORITY:" << plist[execute.top()] << "\n";
            plist.erase(execute.top());
            execute.pop();
        }

        int waiting_size = waiting.size();
        for(int i = 0; i < waiting_size; i++) {
            if(waiting.top() > 1) {
                waiting.top() = waiting.top()--;
            }
            main.push(waiting.top());
            waiting.pop();
        }
    }

    return 0;
}

int main() {
    std::unordered_map<int, int> plist;
    int priority = 10;
    int pid = 4000;

    while(priority >= 0) {
        plist[pid] = priority;
        pid+=5;
        priority--;
    }


    
    std::cout << "\n\n\n";

    std::cout << process_scheduler(plist);

    return 0;
}