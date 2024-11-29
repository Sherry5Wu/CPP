NAME := phoneBook
COMPILER := c++
RM := rm -f
FLAGS := -Wall -Wextra -Werror -std=c++11

GREEN = \033[1;92m
RESET = \033[0;0m

SCRS := Contact.cpp PhoneBook.cpp main.cpp

OBJS_DIR := obj
OBJ := $(SCRS:.cpp=.o)
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)phoneBook has been generated!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp
	@$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	@$(RM) -r $(OBJS_DIR)
	@echo "Objects have been cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "phoneBook has been cleaned."

re: fclean all

.PHONY: all, clean, fclean, re
