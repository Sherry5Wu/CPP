NAME := ex00
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -std=c++11

SRCS := main.cpp
OBJS_DIR := objs

OBJS = $(SRCS:.cpp=.o)
OBJS_FULL = $(addprefix $(OBJS_DIR)/, $(OBJS))

# colour define
GREEN := \033[1;32m
PURPLE := \033[0;35m
RESET := \033[0;0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS_FULL)
	@$(COMPILER) $(FLAGS) -o $@ $(OBJS_FULL)
	@ echo "$(GREEN) ✅ Built $(NAME)$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@ echo "$(PURPLE) Built object directory $(RESET)"

$(OBJS_DIR)/%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $^ -o $@
	@ echo "$(PURPLE) Built $@ $(RESET)"

clean:
	@rm -rf $(OBJS_DIR)
	@ echo "$(GREEN) ✅ Removed all the objects $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@ echo "$(GREEN) ✅ Removed $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
