#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "WebServer.h"
#include <queue>
#include <vector>

class LoadBalancer {
private:
    std::vector<WebServer*> servers;
    std::queue<Request> requestQueue;
    int current_time;
    int total_servers;
    int max_queue_size;

public:
    LoadBalancer(int num_servers, int queue_size);
    ~LoadBalancer();
    void generateInitialRequests();
    void run(int max_time);
    void maybeGenerateNewRequest();
    void tick();
    void logStatus() const;
};

#endif
