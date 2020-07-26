using System;

namespace state
{
    interface IPhoneState
    {
        void PressIncreaseAudioButton();
        void PressLockScreenButton();
    }

    interface IPhone
    {
        IPhoneState State { set; }
        void PressLockButton();
        void PressIncreaseAudioButton();
    }

    class Phone : IPhone
    {
        public IPhoneState State { private get; set; }

        public Phone()
        {
            State = new LockedPhoneState(this);
        }

        public void PressLockButton()
        {
            State.PressLockScreenButton();
        }

        public void PressIncreaseAudioButton()
        {
            State.PressIncreaseAudioButton();
        }
    }

    class LockedPhoneState : IPhoneState
    {
        private IPhone _phone;

        public LockedPhoneState(IPhone phone)
        {
            _phone = phone;
        }

        public void PressIncreaseAudioButton()
        {
            Console.WriteLine("Phone is locked!");
        }

        public void PressLockScreenButton()
        {
            _phone.State = new UnloockedPhoneState(_phone);
        }
    }

    class UnloockedPhoneState : IPhoneState
    {
        private IPhone _phone;

        public UnloockedPhoneState(IPhone phone)
        {
            _phone = phone;
        }

        public void PressIncreaseAudioButton()
        {
            Console.WriteLine("Increasing!");
        }

        public void PressLockScreenButton()
        {
            _phone.State = new LockedPhoneState(_phone);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var phone = new Phone();
            phone.PressIncreaseAudioButton();
            phone.PressLockButton();
            phone.PressIncreaseAudioButton();
            phone.PressLockButton();
            phone.PressIncreaseAudioButton();
        }
    }
}