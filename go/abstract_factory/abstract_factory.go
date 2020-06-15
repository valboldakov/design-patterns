package main

import "fmt"

type IChair interface {
	SitOn()
}

type ITable interface {
	EatFrom()
}

type ArtChair struct {
}

func (receiver ArtChair) SitOn() {
	fmt.Println("Sitting on art chair.")
}

type ArtTable struct {
}

func (receiver ArtTable) EatFrom() {
	fmt.Println("Eating from art table.")
}

type IFurnitureFactory interface {
	CreateChair() IChair
	CreateTable() ITable
}

type ArtFurnitureFactory struct {
}

func (receiver ArtFurnitureFactory) CreateChair() IChair {
	return ArtChair{}
}

func (receiver ArtFurnitureFactory) CreateTable() ITable {
	return ArtTable{}
}

func main() {
	factory := ArtFurnitureFactory{}
	chair := factory.CreateChair()
	table := factory.CreateTable()
	chair.SitOn()
	table.EatFrom()
}
