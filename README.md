# Project 3 – Load Balancer Simulation

This project simulates a load balancer distributing web requests to backend servers. It models incoming requests in a queue and distributes them to active servers based on availability across a series of clock cycles.

## How to Compile

```
make
```

This uses the provided Makefile to compile the C++ files and generates an executable named `loadbalancer`.

## How to Run

```
./loadbalancer
```

You'll be prompted to enter:
- Number of servers 
- Number of clock cycles 

The program will output queue size and server activity at each 1000-cycle interval.

## Files Included

- `main.cpp` – Entry point of the program
- `LoadBalancer.cpp` / `LoadBalancer.h` – Load balancer logic
- `WebServer.cpp` / `WebServer.h` – Web server object and behavior
- `Makefile` – Build instructions
- `server_log.txt` – Sample output log from running the simulation
- `html/` – Doxygen-generated documentation (open `html/index.html` in a browser)

## Author

Henry Chibib  
CSCE 412 – Cloud Computing  
