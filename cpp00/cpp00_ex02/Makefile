NAME := account
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -std=c++11
RM := rm -f

SRCS := tests.cpp Account.cpp
OBJS_DIR := obj
OBJ := $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re