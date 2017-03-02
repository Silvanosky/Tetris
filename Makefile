# Simple Makefile
 
# Vars
CC= gcc
CPPFLAGS= -MMD `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -std=c99 -O2 
LDFLAGS=                           
LDLIBS= -export-dynamic -lSDL_image -lm                          

BIN = main
SRCDIR= src
OBJDIR= bin

SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DEP= ${OBJ:.o=.d}

# Default rule: just ask for bin main
all: $(BIN)

# main depends on object files, that's all we need
$(BIN): ${OBJ}

${OBJ} : $(SRC)
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@ $(LDLIBS)

# cleaning rule
clean:
	${RM} ${OBJ} ${DEP} $(BIN)

# includes deps
-include ${DEP}

# END of Makefile
