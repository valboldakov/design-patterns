package main

import "fmt"

type IFlyBehaviour interface {
	fly()
}

type LowFlyBehaviour struct {
}

func (behaviour *LowFlyBehaviour) fly() {
	fmt.Println("Flying low!")
}

type HighFlyBehaviour struct {
}

func (behaviour *HighFlyBehaviour) fly() {
	fmt.Println("Flying high!")
}

type Duck struct {
	flyBehaviour IFlyBehaviour
}

func newDuck(behaviour IFlyBehaviour) *Duck {
	duck := new(Duck)
	duck.flyBehaviour = behaviour
	return duck
}

func (duck *Duck) fly() {
	duck.flyBehaviour.fly()
}

type LittleDuck struct {
	duck *Duck
}

func (duck *LittleDuck) fly()  {
	duck.duck.fly()
}

func NewLittleDuck() *LittleDuck {
	duck := new(LittleDuck)
	duck.duck = newDuck(new(LowFlyBehaviour))
	return duck
}

type BigDuck struct {
	duck *Duck
}

func (duck *BigDuck) fly()  {
	duck.duck.fly()
}

func NewBigDuck() *BigDuck {
	duck := new(BigDuck)
	duck.duck = newDuck(new(HighFlyBehaviour))
	return duck
}

func main() {
	littleDuck := NewLittleDuck()
	littleDuck.fly()
	bigDuck := NewBigDuck()
	bigDuck.fly()
}
