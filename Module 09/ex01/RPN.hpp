#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class	RPN
{
	private:
		RPN(void);
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN(void);

	public:
		static bool	calculateRPN(const std::string& input, int& result);

	protected:
	private:
};

#endif
