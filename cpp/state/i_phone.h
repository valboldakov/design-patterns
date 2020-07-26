#ifndef I_PHONE_H
#define I_PHONE_H

#include <memory>
#include "i_phone_state.h"

class IPhone {
public:
    virtual void lock_screen() = 0;

    virtual void increase_audio() = 0;

    virtual void set_state(std::shared_ptr<IPhoneState> state) = 0;
};


#endif
