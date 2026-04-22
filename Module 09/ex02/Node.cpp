#include "Node.hpp"

Node::Node(void)
	:_has_value(false)
	 _left(NULL),
	 _right(NULL),
{
}

Node::Node(unsigned int value)
	:_has_value(true),
	 _value(value),
	 _left(NULL),
	 _right(NULL)
{
}

Node::Node(Node* left, Node* right)
	:_has_value(false),
	 _left(left),
	 _right(right)
{
}

Node::~Node(void)
{
	delete _left;
	delete _right;
}

void	Node::setValue(unsigned int value)
{
	_has_value = true;
	_value = value;
	delete _left;
	delete _right;
	_left = NULL;
	_right = NULL;
}

unsigned int	Node::getValue(void) const
{
	if (_has_value)
		return (value);
	return (_right->getValue);
}
