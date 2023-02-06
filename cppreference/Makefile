# https://makefiletutorial.com/
# https://www.gnu.org/software/make/manual/html_node/index.html
# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)

BUILD_DIR := ./build
SRC_DIRS := ./w

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
# SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c')

TARGET_EXEC := $(SRCS:%=$(BUILD_DIR)/%.exe)

CFLAGS := -std=c2x

ifeq ($(CXX),g++)
	CPPFLAGS := -std=c++23 -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors
else ifeq ($(CXX),c++)
	CPPFLAGS := -std=c++2b -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors
endif

LDFLAGS=-lm -latomic

all: $(TARGET_EXEC)

# Build step for C source
$(BUILD_DIR)/%.c.exe: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.exe: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
