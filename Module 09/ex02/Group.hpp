#ifndef GROUP_HPP
# define GROUP_HPP

template<typename T>
class	Group
{
	public:
		Group(void);
		Group(const Group& other);
		Group&	operator=(const Group& other);
		~Group(void);

		bool	operator<(const Group& other)

	protected:
	private:
		const T::iterator	_begin;
		const T::iterator	_end;
};

# include "Group.tpp"

#endif
