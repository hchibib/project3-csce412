#include "LoadBalancer.h"
#include <iostream>

int main() {
    int num_servers, cycles;

    std::cout << "Enter number of servers: ";
    std::cin >> num_servers;
    std::cout << "Enter number of clock cycles: ";
    std::cin >> cycles;

    LoadBalancer lb(num_servers, num_servers * 100);
    lb.generateInitialRequests();
    lb.run(cycles);

    return 0;
}
