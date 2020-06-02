package main

import "fmt"

type IBeverage interface {
	getCost() float32
}

type Coffee struct {
	cost float32
}

func (coffee Coffee) getCost() float32 {
	return coffee.cost
}

type BeverageDecorator struct {
	beverage IBeverage
	cost     float32
}

func (decorator BeverageDecorator) getCost() float32 {
	return decorator.beverage.getCost() + decorator.cost
}

func main() {
	coffee := Coffee{cost: 2.0}
	coffeeWithMocha := BeverageDecorator{
		beverage: coffee,
		cost:     0.2,
	}
	fmt.Println(coffeeWithMocha.getCost())
	coffeeWithMocha = BeverageDecorator{
		beverage: coffeeWithMocha,
		cost:     0.2,
	}
	fmt.Println(coffeeWithMocha.getCost())
}
