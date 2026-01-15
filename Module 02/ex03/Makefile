CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp	Fixed.cpp	Point.cpp	bsp.cpp

OBJDIR	=	OBJS
OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)

##########################################################################################

RESET	=	\033[0m
BOLD	=	\033[1m
YELLOW	=	\033[33m
RED		=	\033[31m

##########################################################################################

NAME	=	bsp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@printf "$(BOLD)$(YELLOW)$(NAME) successfully compiled\n$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "$(RED)"
	@if [ -d $(OBJDIR) ]; then						\
		rm -rf $(OBJDIR);							\
		printf "Removed $(NAME) OBJS directory\n";	\
	else											\
		printf "$(NAME) objects not found\n"; fi;
	@printf "$(RESET)"

fclean: clean
	@printf "$(RED)"
	@if [ -f $(NAME) ]; then						\
		rm -f $(NAME);								\
		printf "Removed $(NAME)\n"					\
	else											\
		printf "$(NAME) not found\n"; fi;
	@printf "$(RESET)"

re: fclean
	@make -s all

.PHONY: all clean fclean re
