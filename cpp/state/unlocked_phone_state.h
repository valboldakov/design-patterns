#ifndef UNLOCKED_PHONE_STATE_H
#define UNLOCKED_PHONE_STATE_H

#include "i_phone_state.h"
#include "i_phone.h"

class UnlockedPhoneState : public IPhoneState {
public:
    explicit UnlockedPhoneState(IPhone &phone);

    void lock_screen() override;

    void increase_audio() override;

private:
    IPhone &_phone;
};

#endif
