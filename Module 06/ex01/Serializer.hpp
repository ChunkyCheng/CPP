#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

typedef struct s_Data
{
	char	c;
	int		i;
	float	f;
	double	d;
}	Data;

class	Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer(void);
	
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	protected:
	private:
};

#endif
