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

CFLAGS := -std=gnu17

ifeq ($(CXX),g++)
	CPPFLAGS := -std=gnu++23 -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors -g
else ifeq ($(CXX),c++)
	CPPFLAGS := -std=c++2b -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors -fcolor-diagnostics -fansi-escape-codes -g
endif

LDFLAGS=-lm -lpthread

all: $(TARGET_EXEC)

# Build step for C source
$(BUILD_DIR)/%.c.exe: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.cpp.exe: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
# make -i / --ignore
# .IGNORE:
# make -s / --silent
# .SILENT:
