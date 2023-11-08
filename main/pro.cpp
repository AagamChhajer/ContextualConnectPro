#include <queue>
#include <iostream>
#include <stack>
#include <hiredis/hiredis.h>

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

    // Redis Example
    redisContext *context = redisConnect("localhost", 6379);
    if (context != NULL && context->err) {
        printf("Error: %s\n", context->errstr);
        return 1;
    }

    redisReply *reply;
    reply = (redisReply *)redisCommand(context, "HSET customer_database cust value");
    freeReplyObject(reply);
    reply = (redisReply *)redisCommand(context, "HGET customer_database cust");
    printf("Customer 1: %s\n", reply->str);
    freeReplyObject(reply);
    redisFree(context);

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
