#include <iostream>
#include <memory>
#include <utility>

class ICommand {
public:
    virtual void execute() = 0;
};

class RemoteController {
public:
    void set_on_command(std::shared_ptr<ICommand> command) {
        _on_command = std::move(command);
    }

    void set_off_command(std::shared_ptr<ICommand> command) {
        _off_command = std::move(command);
    }

    void press_on_button() {
        _on_command->execute();
    }

    void press_off_button() {
        _off_command->execute();
    }

private:
    std::shared_ptr<ICommand> _on_command;
    std::shared_ptr<ICommand> _off_command;
};

class Bulb {
public:
    void light_on() {
        std::cout << "Light On!" << std::endl;
    }

    void light_off() {
        std::cout << "Light Off!" << std::endl;
    }
};

class LightOnCommand : public ICommand {
public:
    explicit LightOnCommand(Bulb &bulb) : _bulb(bulb) {
    }

    void execute() override {
        _bulb.light_on();
    }

private:
    Bulb &_bulb;
};

class LightOffCommand : public ICommand {
public:
    explicit LightOffCommand(Bulb &bulb) : _bulb(bulb) {
    }

    void execute() override {
        _bulb.light_off();
    }

private:
    Bulb &_bulb;
};

int main() {
    Bulb bulb;
    RemoteController controller;
    controller.set_on_command(std::make_shared<LightOnCommand>(bulb));
    controller.set_off_command(std::make_shared<LightOffCommand>(bulb));
    controller.press_on_button();
    controller.press_off_button();
    return 0;
}
