#ifndef NODE_HPP
# define NODE_HPP

class	Node
{
	public:
		Node(void);
		Node(unsigned int value);
		Node(Node* left, Node* right);
		Node(const Node& other);
		Node&	operator=(const Node& other);
		~Node(void);

		void			setValue(unsigned int value);
		unsigned int	getValue(void) const;

	protected:
	private:
		bool			_has_value;
		unsigned int	_value;
		Node*			_left;
		Node*			_right;
};

#endif
