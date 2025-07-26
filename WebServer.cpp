#include "WebServer.h"

WebServer::WebServer(int id) : id(id), busy(false), remaining_time(0) {}

bool WebServer::isBusy() const {
    return busy;
}

void WebServer::assignRequest(const Request& req) {
    current_request = req;
    remaining_time = req.process_time;
    busy = true;
}

void WebServer::tick() {
    if (busy && remaining_time > 0) {
        remaining_time--;
        if (remaining_time == 0) {
            busy = false;
        }
    }
}

int WebServer::getId() const {
    return id;
}
