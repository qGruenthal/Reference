#include <stdio.h>

class Expression;
class Literal;
class Add;
class Visitor;

class Expression
{
public:
  virtual void accept (Visitor& visitor) = 0;
};

class Visitor
{
public:
  virtual void visit (Literal& l) = 0;
  virtual void visit (Add& e) = 0;
};

class Literal
  : public Expression
{
public:
  Literal (int value)
    : value (value)
  {}

  void accept (Visitor& visitor) override
  {
    visitor.visit (*this);
  }

  int value;
};

class Add
  : public Expression
{
public:
  Add (Expression* left, Expression* right)
    : left (left)
    , right (right)
  {}

  void accept (Visitor& visitor) override
  {
    visitor.visit (*this);
  }

  Expression* left;
  Expression* right;
};

class Calculate
  : public Visitor
{
public:
  void visit (Literal& l)
  {
    this->result = l.value;
  }

  void visit (Add& e)
  {
    e.left->accept (*this);
    int l = this->result;
    e.right->accept (*this);
    int r = this->result;

    this->result = l + r;
  }

  int result;
};

class Print
  : public Visitor
{
  void visit (Literal& l)
  {
    printf ("%d", l.value);
  }

  void visit (Add& e)
  {
    e.left->accept (*this);
    printf (" + ");
    e.right->accept (*this);
  }
};

int
main ()
{
  Expression* e = new Add
    (
     new Add
     (
      new Literal (1),
      new Literal (2)
      ),
     new Literal (3)
     );

  Calculate c = Calculate ();
  Print p = Print ();

  e->accept (p);
  e->accept (c);
  printf (" = %d\n", c.result);
}
