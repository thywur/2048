# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 22:03:24 by ibertran          #+#    #+#              #
#    Updated: 2024/03/31 17:47:53 by kchillon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = alcu

# *** FILES ****************************************************************** #

MAKE_DIR := .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

SRC = \
	bot_turn \
	display \
	end_screen	\
	game \
	main \
	ncurses_init \
	player_turn \
	welcome_screen \
	# $(addprefix $(DEBUG_DIR),$(DEBUG_SRC)) ##REMOVE DEBUG

# ********** VECTOR *********** #

SRC += $(addprefix $(VECTOR_DIR),$(VECTOR_SRC))

VECTOR_DIR = vector/
VECTOR_SRC = \
	ft_vector_add \
	ft_vector_free \
	ft_vector_get \
	ft_vector_init \
	ft_vector_resize \
	ft_vector_set \

# *********** UTILS ********** #

SRC += $(addprefix $(UTILS_DIR),$(UTILS_SRC))

UTILS_DIR = utils/
UTILS_SRC = \
	atoi_from_read \
	ft_putchar \
	ft_putendl \
	ft_putnbr \
	ft_putstr \
	ft_strlen \
	max \
	min \

# ************ MEM *********** #

SRC += $(addprefix $(MEM_DIR),$(MEM_SRC))

MEM_DIR = mem/
MEM_SRC = \
	ft_memcpy \
	ft_memset \

################################################################################

DEBUG_DIR = debug/
DEBUG_SRC = \
	debug_print_str_mask \

# *** LIBRARIES && INCLUDES  ************************************************* #

LIBS_PATH = \
		
LIBS = \
	ncursesw

INCS_DIR = includes/
INCS = \
	$(INCS_DIR) \

# *** CONFIG ***************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror $(OFLAGS)
OFLAGS 		=

CPPFLAGS 	= 	$(addprefix -I, $(INCS)) \
				$(addprefix -D, $(DEFINES)) \
				-MMD -MP \

LDFLAGS		=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		=	$(addprefix -l, $(LIBS))

MAKEFLAGS	=	--no-print-directory

# *** COMPILATION MODES ****************************************************** #

MODE_TRACE = $(MAKE_DIR).trace 
LAST_MODE = $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

ifneq ($(MODE),)
BUILD_DIR := $(BUILD_DIR)$(MODE)/
endif

ifeq ($(MODE),debug)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3
else ifeq ($(MODE),fsanitize)
CFLAGS := $(filter-out $(OFLAGS),$(CFLAGS)) -g3 -fsanitize=address
else ifeq ($(MODE),bonus)
DEFINES += NCURSES
else ifneq ($(MODE),)
ERROR = MODE
endif

ifneq ($(LAST_MODE),$(MODE))
$(NAME) : FORCE
endif

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)


$(NAME) : $(LIBS_PATH) $(OBJS) | ERROR_CHECK
	@printf "\n🔗 Linking $(NAME)...\n"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)
ifneq ($(MODE),)
	@echo "$(GREEN) $(NAME)($(MODE)) has been built! $(RESET)"
else
	@echo "$(GREEN) $(NAME) has been built! $(RESET)"
endif

$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | ERROR_CHECK
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "🔧 $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@\n"

.PHONY : bonus
bonus :
	$(MAKE) MODE=bonus

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

.PHONY : clean
clean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR)
	echo "$(YELLOW) $(NAME) building files removed! $(RESET)"

.PHONY : fclean
fclean :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(MAKE_DIR) $(NAME)
	echo "$(YELLOW) $(NAME) files removed! $(RESET)"

.PHONY : re
re : fclean
	$(MAKE)

.PHONY : print%
print% :
	@echo $(patsubst print%,%,$@)=
	@echo $($(patsubst print%,%,$@))

.PHONY : run
run :	$(NAME)
	./$(NAME)

VALGRIND = \
	valgrind \
	--suppressions=.valgrindignore \
	--leak-check=full \
	--trace-children=yes \
	--track-fds=yes \
	--show-leak-kinds=all \

.PHONY : valgrind
valgrind : debug
	$(VALGRIND) ./$(NAME)

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all

.SILENT : bonus clean fclean re debug %debug fsanitize

.PHONY : FORCE
FORCE :

.PHONY : ERROR_CHECK
ERROR_CHECK :
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
RED		=	\e[31;49;1m ¯\_(ツ)_/¯ \e[39;41;1m
GREEN	=	\e[32;49;1m ¯\_(ツ)_/¯ \e[39;42;1m
YELLOW	=	\e[33;49;1m ¯\_(ツ)_/¯ \e[39;43;1m
BLUE	=	\e[34;49;1m ¯\_(ツ)_/¯ \e[39;44;1m

# **************************************************************************** #
