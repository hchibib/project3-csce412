CC = g++
CFLAGS = -Wall -std=c++17
OBJS = main.o WebServer.o LoadBalancer.o

all: loadbalancer

loadbalancer: $(OBJS)
	$(CC) $(CFLAGS) -o loadbalancer $(OBJS)

main.o: main.cpp LoadBalancer.h
	$(CC) $(CFLAGS) -c main.cpp

WebServer.o: WebServer.cpp WebServer.h Request.h
	$(CC) $(CFLAGS) -c WebServer.cpp

LoadBalancer.o: LoadBalancer.cpp LoadBalancer.h WebServer.h Request.h
	$(CC) $(CFLAGS) -c LoadBalancer.cpp

clean:
	rm -f *.o loadbalancer
