TARGET = push_swap

BUILD_DIR := ./build
SOURCE_DIR := ./src

CC ?= cc
VPATH := $(SOURCE_DIR)
INCLUSION_DIRS := -Iinclude
CFLAGS += -Wall -Wextra -Werror -MMD -MP -ggdb $(INCLUSION_DIRS)
#LDFLAGS :=
#LDLIBS :=

SRCS := deque/constructor.c deque/destructor.c
SRCS += input/parse_number.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

SRCS := $(addprefix $(SOURCE_DIR)/,$(SRCS))
OBJS := $(addprefix $(BUILD_DIR)/,$(OBJS))
DEPS := $(addprefix $(BUILD_DIR)/,$(DEPS))

all: $(TARGET)

# Use the implicit rule for linking. By default, Make will look for a file named
# `$(TARGET).c` and try to link it with every dependency listed (in this
# instance, every single file in `$(OBJS)`).
$(TARGET): $(BUILD_DIR)/$(TARGET)
	cp $(BUILD_DIR)/$@ $@

$(BUILD_DIR)/$(TARGET): $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE.c) $< $(OUTPUT_OPTION)

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
