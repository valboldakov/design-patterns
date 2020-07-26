#ifndef PHONE_H
#define PHONE_H

#include "i_phone.h"
#include "locked_phone_state.h"

class Phone : public IPhone {
public:
    Phone();

    void lock_screen() override;

    void increase_audio() override;

    void set_state(std::shared_ptr<IPhoneState> state) override;

private:
    std::shared_ptr<IPhoneState> _state;
};


#endif
