CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98 -g3 -MMD
OBJ_DIR = objs

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

DEPENDS = $(OBJS:.o=.d)

NAME = Convert
-include $(DEPENDS)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY:
re: fclean all