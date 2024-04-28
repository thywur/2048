# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchillon <kchillon@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 22:03:24 by ibertran          #+#    #+#              #
#    Updated: 2024/04/28 17:42:33 by kchillon         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = 2048

# *** FILES ****************************************************************** #

MAKE_DIR := .make/
BUILD_DIR := $(MAKE_DIR)$(shell git branch --show-current)/

SRCS_DIR = srcs/
SRCS = $(addsuffix .c, $(SRC))

OBJS = $(patsubst %.c,$(BUILD_DIR)%.o,$(SRCS))

DEPS = $(patsubst %.o,%.d,$(OBJS))

SRC = \
	draw_board \
	game_loop \
	generate_tile \
	update_gamestate \
	main \
	merge_check \
	move \
	ncurses_init \
	asc_print_num \
	biggest \

# *********** UTILS ********** #

SRC += $(addprefix $(UTILS_DIR),$(UTILS_SRC))

UTILS_DIR = utils/
UTILS_SRC = \
	ft_strlen \
	ft_intlen \
	max \
	min \

# *********** SCREENS ********** #

SRC += $(addprefix $(SCREENS_DIR),$(SCREENS_SRC))

SCREENS_DIR = screens/
SCREENS_SRC = \
	error_screen \
	menu_screen \
	size_screen \
	welcome_screen \

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

else ifneq ($(MODE),)
ERROR = MODE
endif

ifneq ($(LAST_MODE),$(MODE))
$(NAME) : FORCE
endif

# *** MISC ******************************************************************* #

LOGFILE = $(MAKE_DIR).mklog

LOADING_BAR_SIZE = 48

# *** TARGETS **************************************************************** #

.PHONY : all
all : $(NAME)


$(NAME) : $(LIBS_PATH) $(OBJS) | PREMAKE
	@echo "$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)" >> $(LOGFILE)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(MODE)" > $(MODE_TRACE)
	@printf "\n$(BOLD)\
██████╗  ██████╗ ██╗  ██╗ █████╗ \n\
╚════██╗██╔═████╗██║  ██║██╔══██╗\n\
 █████╔╝██║██╔██║███████║╚█████╔╝\n\
██╔═══╝ ████╔╝██║╚════██║██╔══██╗\n\
███████╗╚██████╔╝     ██║╚█████╔╝\n\
╚══════╝ ╚═════╝      ╚═╝ ╚════╝ \n\
		      $(RESET)@kchillon @alermolo\n"



$(BUILD_DIR)%.o : $(SRCS_DIR)%.c | count PREMAKE
	@true || echo "$(NAME)_object"
	$(eval COUNT_DONE := $(shell echo $$(($(COUNT_DONE) + 1))))
	$(eval LOADING_COMPLETED := $(shell echo "$(COUNT_DONE) * $(LOADING_BAR_SIZE) / $(COUNT_TOTAL)" | bc 2> /dev/null))
	@mkdir -p $(@D)
	@echo "$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@" >> $(LOGFILE)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@printf "$(ERASE)$(BOLD)$(CC) $(BLUE)$(CFLAGS) $(YELLOW)$(patsubst $(MAKE_DIR)%, %, $(basename $@)) $(RESET)\n"
	@printf "🔧 $(BOLD)$(CYAN)Compiling sources: $(WHITE)["
	@for i in $(shell seq 1 $(LOADING_COMPLETED)); do printf "="; done 
	@for i in $(shell seq 1 $(shell echo "$(LOADING_BAR_SIZE) - $(LOADING_COMPLETED)" | bc 2> /dev/null)); do printf " "; done
	@printf "] $(shell echo "$(COUNT_DONE) * 100 / $(COUNT_TOTAL)" | bc 2> /dev/null)%%$(RESET)"

$(LIBS_PATH): FORCE | PREMAKE
	@$(MAKE) -C $(@D)

.PHONY : bonus
bonus :
	$(MAKE) scam MODE=bonus

.PHONY : scam
scam :
	@echo "$(MODE)" > $(MODE_TRACE)
	@$(MAKE) -C bonus
	cp bonus/2048 2048

.PHONY : debug
debug :
	$(MAKE) MODE=debug

.PHONY : fsanitize
fsanitize :
	$(MAKE) MODE=fsanitize

.PHONY : print
print :
	$(MAKE) MODE=debug DEFINES=PRINT

.PHONY : clean
clean :
	$(MAKE) clean -C bonus
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(BUILD_DIR)
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) building files removed!$(RESET)\n"

.PHONY : fclean
fclean :
	$(MAKE) fclean -C bonus
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	rm -rf $(MAKE_DIR) $(NAME)
	@printf "$(BOLD)(╯°□°)╯︵ ┻━┻ $(NAME) files removed!$(RESET)\n"

.PHONY : re
re : fclean
	$(MAKE)

NORM_LOG = $(MAKE_DIR)norminette.log

.PHONY : norminette
norminette :
	-for f in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$f $@; done
	mkdir -p $(dir $(NORM_LOG))
	norminette $(INCS_DIR) $(SRCS_DIR) > $(NORM_LOG) || true
	if [ $$(< $(NORM_LOG) grep Error | wc -l) -eq 0 ]; \
		then echo "$(NAME): \e[32;49;1mOK!\e[0m"; \
		else echo "$(NAME): \e[31;49;1mKO!\e[0m" \
			&& < $(NORM_LOG) grep Error; fi
	$(RM) $(NORM_LOG)

.PHONY : print%
print% :
	echo $(patsubst print%,%,$@)=
	echo $($(patsubst print%,%,$@))

.PHONY : count
count :
ifneq ($(AS_COUNTED),TRUE)
	$(eval COUNT_TOTAL := $(shell $(MAKE) -j -n MODE=$(MODE) AS_COUNTED=TRUE | grep "$(NAME)_object" | wc -l))
	$(eval COUNT_DONE := 0)
endif

# *** SPECIAL TARGETS ******************************************************** #

-include $(DEPS)

.DEFAULT_GOAL := all

.SILENT : bonus clean fclean re debug %debug fsanitize norminette

.PHONY : FORCE
FORCE :

.PHONY : PREMAKE
PREMAKE :
ifneq ($(MODE),)
	@printf "🔨 $(BOLD)Building $(NAME)($(MODE))...$(RESET)\n"
else
	@printf "🔨 $(BOLD)Building $(NAME)...$(RESET)\n"
endif
	@rm -f $(LOGFILE)
ifeq ($(ERROR),MODE)
	$(error Invalid mode: $(MODE))
endif

# *** FANCY STUFF ************************************************************ #

RESET	=	\e[0m
ERASE	=	\033[2K\r
BOLD	=	\033[1m
UNDER	=	\033[4m
SUR		=	\033[7m
GREY	=	\033[30m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
PURPLE	=	\033[35m
CYAN	=	\033[36m
WHITE	=	\033[37m
C12	=	\033[39m
C13	=	\033[43m

# **************************************************************************** #
