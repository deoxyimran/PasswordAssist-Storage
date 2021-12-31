SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/app
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC 		 := gcc
CFLAGS   := -Wall -Iinclude $$(pkg-config --cflags gtk+-3.0) -MMD -MP
LDFLAGS  := -no-pie -Llib
LDLIBS   := $$(pkg-config --libs gtk+-3.0)

.PHONY : all clean

all : $(EXE)

$(EXE) : $(OBJ) | $(BIN_DIR) 
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR) :
	mkdir -p $@

clean :
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)