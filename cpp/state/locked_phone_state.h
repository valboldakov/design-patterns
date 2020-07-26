#ifndef LOCKED_PHONE_STATE_H
#define LOCKED_PHONE_STATE_H

#include <iostream>
#include "unlocked_phone_state.h"

class LockedPhoneState : public IPhoneState {
public:
    explicit LockedPhoneState(IPhone &phone);

    void lock_screen() override;

    void increase_audio() override;

private:
    IPhone &_phone;
};

#endif
