package main

import (
	"fmt"
	"sync"
)

type Pool struct {
	i int
}

func (receiver *Pool) Inc() {
	receiver.i += 1
}

var pool *Pool
var once sync.Once

func GetPoolInstance() *Pool {
	once.Do(func() {
		pool = &Pool{i: 0}
	})
	return pool
}

func main() {
	fmt.Println(GetPoolInstance().i)
	GetPoolInstance().Inc()
	GetPoolInstance().Inc()
	fmt.Println(GetPoolInstance().i)
}
