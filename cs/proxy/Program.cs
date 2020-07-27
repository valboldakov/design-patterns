using System;

namespace proxy
{
    interface IPhone
    {
        void Call();
    }

    class Phone : IPhone
    {
        public void Call()
        {
            Console.WriteLine("Calling!");
        }
    }

    class LazyPhoneProxy : IPhone
    {
        private IPhone _phone;

        public void Call()
        {
            if (_phone == null)
            {
                Console.WriteLine("Creating phone!");
                _phone = new Phone();
            }

            _phone.Call();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var phone = new LazyPhoneProxy();
            phone.Call();
            phone.Call();
        }
    }
}