using System;

namespace command
{
    interface ICommand
    {
        void Execute();
    }

    class Bulb
    {
        public void LightOn()
        {
            Console.WriteLine("Light on!");
        }

        public void LightOff()
        {
            Console.WriteLine("Light off!");
        }
    }

    class LightOnCommand : ICommand
    {
        private Bulb _bulb;

        public LightOnCommand(Bulb bulb)
        {
            _bulb = bulb;
        }

        public void Execute()
        {
            _bulb.LightOn();
        }
    }

    class LightOffCommand : ICommand
    {
        private Bulb _bulb;

        public LightOffCommand(Bulb bulb)
        {
            _bulb = bulb;
        }

        public void Execute()
        {
            _bulb.LightOff();
        }
    }

    class RemoteController
    {
        public ICommand OnCommand { private get; set; }
        public ICommand OffCommand { private get; set; }

        public void PressOnButton()
        {
            OnCommand.Execute();
        }

        public void PressOffButton()
        {
            OffCommand.Execute();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var bulb = new Bulb();
            var controller = new RemoteController
            {
                OnCommand = new LightOnCommand(bulb),
                OffCommand = new LightOffCommand(bulb)
            };
            controller.PressOnButton();
            controller.PressOffButton();
        }
    }
}