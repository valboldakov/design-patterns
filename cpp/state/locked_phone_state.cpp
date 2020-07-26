#include "locked_phone_state.h"

LockedPhoneState::LockedPhoneState(IPhone &phone) : _phone(phone) {
}

void LockedPhoneState::lock_screen() {
    _phone.set_state(std::make_shared<UnlockedPhoneState>(_phone));
}

void LockedPhoneState::increase_audio() {
    std::cout << "Phone is locked!" << std::endl;
}
