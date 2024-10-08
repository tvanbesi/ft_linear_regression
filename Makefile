# Target
TARGET := libft_linear_regression.a

# Libraries
LIBS :=

# ==================================================================================================

# Default mode
MODE ?= debug

# Compiler
CC = c++
ERRFLAGS := -Wall -Wextra -Werror
CPPFLAGS := $(ERRFLAGS)
CPPFLAGS += -std=c++17
ifeq ($(MODE), debug)
	CPPFLAGS += -g -O0 -DDEBUG
else ifeq ($(MODE), release)
	CPPFLAGS += -O2
else
$(error Invalid mode: $(MODE), valid modes are: debug, release)
endif

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
SRC_DIRS := $(shell find $(SRC_DIR) -type d)
OBJ_DIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRC_DIRS))
INC_DIRS := $(shell find $(INC_DIR) -type d)

# Files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
INCS := $(foreach dir,$(INC_DIRS),$(wildcard $(dir)/*.hpp))

# Compiler include flags
INC_FLAGS := $(foreach dir,$(INC_DIRS),-I$(dir))

# Commands
RM := rm -f
MKDIR := mkdir -p

# ==================================================================================================

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.cpp $(INCS)
					$(CC) $(CPPFLAGS) $(INC_FLAGS) -c $< -o $@

all:        	    $(TARGET)

$(TARGET):			$(OBJS) main_src/estimate.cpp main_src/train.cpp
					ar rc $(TARGET) $(OBJS)
					$(CC) $(CPPFLAGS) -o estimate.out main_src/estimate.cpp $(TARGET) -Iinc
					$(CC) $(CPPFLAGS) -o train.out main_src/train.cpp $(TARGET) -Iinc

$(OBJS):			| $(OBJ_DIRS)

$(OBJ_DIRS):
					$(MKDIR) $(OBJ_DIRS)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(TARGET) estimate.out train.out

re:					fclean all

.PHONY:
					all clean fclean re