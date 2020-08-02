#ifndef CPP_MEDIATOR_H
#define CPP_MEDIATOR_H

#include <map>
#include "handler.h"

class Mediator {
public:
    void add_handler(Handler *handler) {
        _handlers[handler->get_name()] = handler;
    }

    void handle(const std::string &handler_name) {
        _handlers[handler_name]->handle();
    }

private:
    std::map<std::string, Handler *> _handlers;
};

#endif
