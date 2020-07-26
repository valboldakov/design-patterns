#include "unlocked_phone_state.h"
#include "locked_phone_state.h"


UnlockedPhoneState::UnlockedPhoneState(IPhone &phone) : _phone(phone) {
}

void UnlockedPhoneState::lock_screen() {
    _phone.set_state(std::make_shared<LockedPhoneState>(_phone));
}

void UnlockedPhoneState::increase_audio() {
    std::cout << "Increasing!" << std::endl;
}
