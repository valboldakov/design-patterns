#include "phone.h"

Phone::Phone() : _state(std::make_shared<LockedPhoneState>(*this)) {}

void Phone::lock_screen() {
    _state->lock_screen();
}

void Phone::increase_audio() {
    _state->increase_audio();
}

void Phone::set_state(std::shared_ptr<IPhoneState> state) {
    _state = state;
}