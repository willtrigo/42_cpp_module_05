# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 15:09:19 by dande-je          #+#    #+#              #
#    Updated: 2025/07/06 14:48:09 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_DIR                        := src/
SRCS_MAIN_DIR                   := $(SRCS_DIR)main/
SRCS_CORE_DIR                   := $(SRCS_DIR)core/
SRCS_BUREAUCRAT_DIR             := $(SRCS_CORE_DIR)bureaucrat/
SRCS_BUREAUCRAT_EXCEPTIONS_DIR  := $(SRCS_BUREAUCRAT_DIR)exceptions/
SRCS_FORM_DIR                   := $(SRCS_CORE_DIR)form/
SRCS_FORM_EXCEPTIONS_DIR        := $(SRCS_FORM_DIR)exceptions/
SRCS_TEST_DIR                   := $(SRCS_DIR)test/
SRCS_UTILS_DIR                  := $(SRCS_DIR)utils/
INCS                            := src/
BIN_DIR                         := bin/
BUILD_DIR                       := build/

#******************************************************************************#
#                                  COMMANDS                                    #
#******************************************************************************#

RM                              := rm -rf
MKDIR                           := mkdir -p
MAKEFLAGS                       += --no-print-directory
SLEEP                           := sleep 0.01

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

NAME_OUTPUT                     = bureaucrat
NAME                            = $(BIN_DIR)$(NAME_OUTPUT)

SRCS_FILES                      += $(addprefix $(SRCS_MAIN_DIR), main.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_BUREAUCRAT_DIR), Bureaucrat.cpp \
								   BureaucratUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_BUREAUCRAT_EXCEPTIONS_DIR), BureaucratException.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_FORM_DIR), Form.cpp \
								   FormUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_FORM_EXCEPTIONS_DIR), FormException.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_TEST_DIR), TestEx00.cpp \
								   TestEx01.cpp \
								   TestHelpers.cpp \
								   TestSuite.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_UTILS_DIR), TerminalColor.cpp \
								   TerminalColorUtility.cpp)

OBJS                            += $(SRCS_FILES:%.cpp=$(BUILD_DIR)%.o)

DEPS                            += $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                           = 0
OBJS_COUNT                      = 0
MATH                            = 0
CLEAN_MESSAGE                   := $(NAME_OUTPUT) objects deleted
FCLEAN_MESSAGE                  := $(NAME_OUTPUT) deleted
EXE_MESSAGE                     = $(RESET)[100%%] $(GREEN)Built target $(NAME_OUTPUT)
COMP_MESSAGE                    = Building CPP object

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                             := c++
CFLAGS                         = -Wall -Wextra -Werror -Wshadow -Ofast -Wunreachable-code -Wpedantic -std=c++98
CPPFLAGS                       := $(addprefix -I,$(INCS)) -MMD -MP
DFLAGS                         := -Wall -Wextra -Werror -g3 -std=c++98
LFLAGS                         := -march=native
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(LFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE                    = $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS                     = $(DFLAGS)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(eval MATH=$(shell expr "$(COUNT)" \* 100 \/ "$(OBJS_COUNT)"))
	$(eval MATH=$(shell if [ $(COUNT) -lt 1 ]; then echo $(shell expr "$(MATH)" + 100) ; else echo $(MATH) ; fi))
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $(MATH))
endef

define comp_exe
	$(MKDIR) $(BIN_DIR)
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(EXE_MESSAGE)\n$(RESET)"
endef

define clean
	$(RM) $(BUILD_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
endef

define fclean
	$(RM) $(BIN_DIR)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
endef

define reset_count
	$(eval COUNT=$(1))
	$(eval OBJS_COUNT=$(words $(SRCS_FILES)))
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.cpp
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(call reset_count, -$(words $(OBJS))) $(OBJS)
	$(call comp_exe)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

.PHONY: all clean fclean re debug
.DEFAULT_GOAL := all
.SILENT:

