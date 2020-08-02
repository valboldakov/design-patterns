#include "mediator.h"
#include "handler_reaslization.h"

int main() {
    Mediator mediator;
    WeatherHandler weather("WeatherHandler");
    HomeHandler home("HomeHandler");
    mediator.add_handler(&weather);
    mediator.add_handler(&home);
    weather.set_mediator(&mediator);
    home.set_mediator(&mediator);
    weather.handle();
    return 0;
}
