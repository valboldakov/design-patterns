using System;

namespace memento
{
    class Program
    {
        class Originator
        {
            private int _state;
            private int _hiddenState;

            public Originator()
            {
                _state = 0;
                _hiddenState = 2;
            }

            public void ChangeState(int state)
            {
                _state = state;
                _hiddenState += 1;
            }

            public void Show()
            {
                Console.WriteLine(_state);
                Console.WriteLine(_hiddenState);
            }

            public StateMemento Save()
            {
                return new StateMemento
                {
                    State = _state,
                    HiddenState = _hiddenState
                };
            }

            public void Load(StateMemento stateMemento)
            {
                _state = stateMemento.State;
                _hiddenState = stateMemento.HiddenState;
            }
        }

        class StateMemento
        {
            public int State { get; set; }
            public int HiddenState { get; set; }
        }

        static void Main(string[] args)
        {
            var orig = new Originator();
            orig.Show();
            var memento = orig.Save();
            orig.ChangeState(3);
            orig.ChangeState(4);
            orig.Load(memento);
            orig.Show();
        }
    }
}