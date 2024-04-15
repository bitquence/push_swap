TARGET = push_swap

BUILD_DIR := ./build
SOURCE_DIR := ./src

CC ?= cc
VPATH := $(SOURCE_DIR)
INCLUSION_DIRS := -Iinclude
ifndef RELEASE_MODE
	DEBUGGER ?= gdb
	ADD_DEBUGGING_INFO := -g$(DEBUGGER)
else
	ENABLE_OPTIMIZATIONS := -O3
endif
CFLAGS += -Wall -Wextra -Werror -MMD -MP $(ENABLE_OPTIMIZATIONS) $(ADD_DEBUGGING_INFO) $(INCLUSION_DIRS)
#LDFLAGS :=
#LDLIBS :=

SRCS := push_swap.c
SRCS += deque/constructor.c deque/destructor.c \
	deque/push.c deque/pop.c deque/get.c deque/rotate.c \
	deque/properties.c
SRCS += input/parse_number.c input/string_length.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

SRCS := $(addprefix $(SOURCE_DIR)/,$(SRCS))
OBJS := $(addprefix $(BUILD_DIR)/,$(OBJS))
DEPS := $(addprefix $(BUILD_DIR)/,$(DEPS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $(OUTPUT_OPTION) $^ $(LDLIBS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

# ty vincent! https://github.com/vincent-lafouasse/C-sandbox-gtest
run_tests: $(OBJS)
	cmake -B ./build/test -S ./test
	cmake --build ./build/test
	exec valgrind ./build/test/test_runner

.PHONY: clean fclean re
clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want
# those errors to show up.
-include $(DEPS)
