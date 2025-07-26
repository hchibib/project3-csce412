#include "LoadBalancer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Request createRandomRequest(int current_time) {
    Request r;
    r.ip_in = "192.168.0." + std::to_string(rand() % 255);
    r.ip_out = "10.0.0." + std::to_string(rand() % 255);
    r.process_time = 1 + rand() % 10;
    r.arrival_time = current_time;
    return r;
}

LoadBalancer::LoadBalancer(int num_servers, int queue_size)
    : current_time(0), total_servers(num_servers), max_queue_size(queue_size) {
    for (int i = 0; i < total_servers; ++i) {
        servers.push_back(new WebServer(i));
    }
}

LoadBalancer::~LoadBalancer() {
    for (auto* s : servers) delete s;
}

void LoadBalancer::generateInitialRequests() {
    for (int i = 0; i < total_servers * 100; ++i) {
        requestQueue.push(createRandomRequest(current_time));
    }
}

void LoadBalancer::maybeGenerateNewRequest() {
    if (rand() % 10 < 3) {
        requestQueue.push(createRandomRequest(current_time));
    }
}

void LoadBalancer::tick() {
    for (auto* server : servers) {
        if (!server->isBusy() && !requestQueue.empty()) {
            server->assignRequest(requestQueue.front());
            requestQueue.pop();
        }
        server->tick();
    }
}

void LoadBalancer::run(int max_time) {
    srand(time(0));
    for (current_time = 0; current_time < max_time; ++current_time) {
        maybeGenerateNewRequest();
        tick();
        if (current_time % 1000 == 0) logStatus();
    }
    logStatus(); // Final log
}

void LoadBalancer::logStatus() const {
    std::cout << "Time: " << current_time
              << " | Queue size: " << requestQueue.size()
              << " | Active servers: ";
    for (auto* s : servers) {
        std::cout << (s->isBusy() ? "1 " : "0 ");
    }
    std::cout << std::endl;
}
