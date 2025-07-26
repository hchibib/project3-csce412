#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
private:
    int id;
    bool busy;
    int remaining_time;
    Request current_request;

public:
    WebServer(int id);
    bool isBusy() const;
    void assignRequest(const Request& req);
    void tick();
    int getId() const;
};

#endif
