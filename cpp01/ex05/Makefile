NAME := harl
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SRCS := main.cpp Harl.cpp
OBJS_DIR := objs

OBJS = $(SRCS:.cpp=.o)
OBJS_FULL = $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_FULL)
	$(COMPILER) $(FLAGS) -o $@ $(OBJS_FULL)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY all clean fclean re