package main

import "fmt"

type Pizza struct {
}

func (p Pizza) bake() {
}

type PizzaType string

const (
	Cheese PizzaType = "Cheese"
)

type CheesePizza struct {
	Pizza
}

func (p CheesePizza) bake() {
	fmt.Println("Baking cheese pizza!")
}

type PizzaStore struct {
}

func (s PizzaStore) createPizza(t PizzaType) Pizza {
	
}

func (s PizzaStore) orderPizza()  {
}

func main() {

}
