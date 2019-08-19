package main

import "fmt"

type Expression interface {
	Accept(visitor Visitor)
}

type Visitor interface {
	Visit(expression Expression)
}

type Literal struct {
	value int
}

func (self *Literal) Accept(visitor Visitor) {
	visitor.Visit(self)
}

type Add struct {
	left Expression
	right Expression
}

func (self *Add) Accept(visitor Visitor) {
	visitor.Visit(self)
}

type Calculate struct {
	result int
}

func (self *Calculate) Visit(expression Expression) {
	switch expression.(type) {
	case *Literal:
		self.result = expression.(*Literal).value
	case *Add:
		expression.(*Add).left.Accept(self)
		l := self.result
		expression.(*Add).right.Accept(self)
		r := self.result
		self.result = l + r
	default:
		self.result = 0
	}
}

type Print struct {}

func (self *Print) Visit(expression Expression) {
	switch expression.(type) {
	case *Literal:
		fmt.Printf("%v", expression.(*Literal).value)
	case *Add:
		expression.(*Add).left.Accept(self)
		fmt.Printf(" + ")
		expression.(*Add).right.Accept(self)
	}
}

func main() {
	e := Add{
		left: &Add{
			left: &Literal{value: 1},
			right: &Literal{value: 2},
		},
		right: &Literal{value: 3},
	}

	c := Calculate{
		result: 0}
	p := Print{}

	e.Accept(&p)
	e.Accept(&c)
	fmt.Printf(" = %v\n", c.result)
}
