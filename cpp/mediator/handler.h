#ifndef CPP_HANDLER_H
#define CPP_HANDLER_H

#include <string>
#include <utility>
#include <iostream>

class Mediator;

class Handler {
public:
    explicit Handler(std::string name) : _name(std::move(name)) {}

    void set_mediator(Mediator *mediator) {
        _mediator = mediator;
    }

    const std::string &get_name() const {
        return _name;
    }

    virtual void handle() = 0;

protected:
    std::string _name;
    Mediator *_mediator = nullptr;
};

#endif
