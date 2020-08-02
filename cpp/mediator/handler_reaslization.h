#ifndef CPP_HANDLER_REASLIZATION_H
#define CPP_HANDLER_REASLIZATION_H

#include <utility>

#include "handler.h"
#include "mediator.h"

class WeatherHandler : public Handler {
public:
    explicit WeatherHandler(std::string string) : Handler(std::move(string)) {
    }

    void handle() override {
        std::cout << _name << std::endl;
        _mediator->handle("HomeHandler");
    }
};

class HomeHandler : public Handler {
public:
    explicit HomeHandler(std::string string) : Handler(std::move(string)) {
    }

    void handle() override {
        std::cout << _name << std::endl;
    }
};


#endif
