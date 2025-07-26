#include "LoadBalancer.h"
#include <iostream>

int main() {
    int total_servers, total_cycles;

    std::cout << "Enter number of servers: ";
    std::cin >> total_servers;
    std::cout << "Enter number of clock cycles: ";
    std::cin >> total_cycles;

    LoadBalancer lb(total_servers, total_servers * 100);
    lb.generateInitialRequests();
    lb.run(total_cycles);

    return 0;
}
