#include <queue>
#include <iostream>
#include <stack>
#include <string>  // Include <string> to use std::string

int main() {
    // Queue Example
    std::queue<std::string> callQueue;
    callQueue.push("Call 1");
    callQueue.push("Call 2");
    while (!callQueue.empty()) {
        std::string call = callQueue.front();
        callQueue.pop();
        std::cout << "Processing: " << call << std::endl;
    }

    // Stack Example
    std::stack<std::string> historyStack;
    historyStack.push("Movie A");
    historyStack.push("Movie B");
    historyStack.push("Movie C");
    std::string rewindMovie = historyStack.top();
    historyStack.pop();
    std::cout << "Rewinding to: " << rewindMovie << std::endl;
    std::string latestMovie = historyStack.top();
    std::cout << "Latest watched movie: " << latestMovie << std::endl;

    return 0;
}
