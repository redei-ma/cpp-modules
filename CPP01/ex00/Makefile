NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp

all: $(NAME)

HDRS =	Zombie.hpp

$(NAME): $(SRCS) $(HDRS)
	@echo "Compiling executable..."
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "Nothing to clean..."

fclean: clean
	@echo "Removing build output..."
	@rm -rf $(NAME) $(NAME).dSYM

re: fclean all

debug: fclean
	@$(CXX) $(CXXFLAGS) -g $(SRCS) -o $(NAME)

.PHONY: all clean fclean re debug
.SILENT:
