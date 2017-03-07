# Simple Makefile
 
# Vars
CC= gcc
CPPFLAGS= -MMD `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -std=c99 -O2 
LDFLAGS=                           
LDLIBS= `pkg-config --libs sdl` -export-dynamic -lSDL_ttf -lSDL_image -lm

BIN = main
SRCDIR= src
OBJDIR= bin

SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DEP= ${OBJ:.o=.d}

# Default rule: just ask for bin main
all: $(OBJDIR)/$(BIN)

# main depends on object files, that's all we need
$(OBJDIR)/$(BIN): $(OBJ)
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LDLIBS)

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -c $< -o $@ $(LDLIBS)

# cleaning rule
clean:
	${RM} ${OBJ} ${DEP} $(OBJDIR)/$(BIN)

run:
	./$(OBJDIR)/$(BIN) $(filter-out $@,$(MAKECMDGOALS))
%:
	@:

# END of Makefile
