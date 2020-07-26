#ifndef I_PHONE_STATE_H
#define I_PHONE_STATE_H

class IPhoneState {
public:
    virtual void lock_screen() = 0;

    virtual void increase_audio() = 0;
};

#endif
