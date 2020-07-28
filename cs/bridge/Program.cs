using System;

namespace bridge
{
    class Remote
    {
        private IDevice _device;

        public Remote(IDevice device)
        {
            _device = device;
        }

        public void TogglePower()
        {
            _device.Enbale();
        }
    }

    interface IDevice
    {
        void Enbale();
    }

    class Radio : IDevice
    {
        public void Enbale()
        {
            Console.WriteLine("Enabling Radio.");
        }
    }


    class Tv : IDevice
    {
        public void Enbale()
        {
            Console.WriteLine("Enabling TV.");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var remote1 = new Remote(new Radio());
            var remote2 = new Remote(new Tv());
            remote1.TogglePower();
            remote2.TogglePower();
        }
    }
}