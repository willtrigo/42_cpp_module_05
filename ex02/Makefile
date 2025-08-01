# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 14:31:32 by dande-je          #+#    #+#              #
#    Updated: 2025/07/29 15:28:25 by dande-je         ###   ########.fr        #
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

SRCS_APPLICATION_DIR            := $(SRCS_DIR)application/
SRCS_COMMANDS_DIR               := $(SRCS_APPLICATION_DIR)commands/

SRCS_DOMAIN_DIR                 := $(SRCS_DIR)domain/
SRCS_MODELS_DIR                 := $(SRCS_DOMAIN_DIR)models/
SRCS_BUREAUCRAT_DIR             := $(SRCS_MODELS_DIR)bureaucrat/
SRCS_BUREAUCRAT_EXCEPTIONS_DIR  := $(SRCS_BUREAUCRAT_DIR)exceptions/
SRCS_FORM_DIR                   := $(SRCS_MODELS_DIR)form/
SRCS_FORM_CREATIONS_DIR         := $(SRCS_FORM_DIR)creations/
SRCS_SHRUBBERY_DIR              := $(SRCS_FORM_CREATIONS_DIR)shrubbery/
SRCS_FORM_REQUESTS_DIR          := $(SRCS_FORM_DIR)requests/
SRCS_PRESIDENTIAL_DIR           := $(SRCS_FORM_REQUESTS_DIR)presidential/
SRCS_ROBOTOMY_DIR               := $(SRCS_FORM_REQUESTS_DIR)robotomy/
SRCS_FORM_EXCEPTIONS_DIR        := $(SRCS_FORM_DIR)exceptions/

SRCS_INFRASTRUCTURE_DIR         := $(SRCS_DIR)infrastructure/
SRCS_FILE_DIR                   := $(SRCS_INFRASTRUCTURE_DIR)file/
SRCS_IO_DIR                     := $(SRCS_INFRASTRUCTURE_DIR)io/
SRCS_UTILS_DIR                  := $(SRCS_INFRASTRUCTURE_DIR)utils/

SRCS_INTERFACES_DIR             := $(SRCS_DIR)interfaces/
SRCS_CLI_DIR                    := $(SRCS_INTERFACES_DIR)cli/
SRCS_TESTING_DIR                := $(SRCS_INTERFACES_DIR)testing/
SRCS_TESTING_DOMAIN_DIR         := $(SRCS_TESTING_DIR)domain/
SRCS_TESTING_INTEGRATION_DIR    := $(SRCS_TESTING_DIR)integration/

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

SRCS_FILES                      += $(addprefix $(SRCS_COMMANDS_DIR), ExecuteFormCommand.cpp \
								   ExecuteFormCommandUtility.cpp \
								   SignFormCommand.cpp \
								   SignFormCommandUtility.cpp)

SRCS_FILES                      += $(addprefix $(SRCS_FORM_DIR), AForm.cpp \
								   AFormUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_SHRUBBERY_DIR), ShrubberyCreationForm.cpp \
								   ShrubberyCreationFormUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_PRESIDENTIAL_DIR), PresidentialPardonForm.cpp \
								   PresidentialPardonFormUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_ROBOTOMY_DIR), RobotomyRequestForm.cpp \
								   RobotomyRequestFormUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_FORM_EXCEPTIONS_DIR), AFormException.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_BUREAUCRAT_DIR), Bureaucrat.cpp \
								   BureaucratUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_BUREAUCRAT_EXCEPTIONS_DIR), BureaucratException.cpp)

SRCS_FILES                      += $(addprefix $(SRCS_FILE_DIR), FileWriter.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_IO_DIR), BureaucratPrinter.cpp \
								   FormPrinter.cpp \
								   StreamWriter.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_UTILS_DIR), TerminalColor.cpp \
								   TerminalColorUtility.cpp)

SRCS_FILES                      += $(addprefix $(SRCS_CLI_DIR), main.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_TESTING_DIR), TestRunner.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_TESTING_DOMAIN_DIR), BureaucratTests.cpp \
								   FormTests.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_TESTING_INTEGRATION_DIR), IntegrationTests.cpp)

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

