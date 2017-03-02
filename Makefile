# Simple Makefile
 
# Vars
CC= gcc
CPPFLAGS= -MMD                    
CFLAGS= -Wall -Wextra -std=c99 -O2 
LDFLAGS=                           
LDLIBS=                           

SRC= $(wildcard src/*.c)
OBJ= $(patsubst src/%.c, bin/%.o, $(SRC))                  
DEP= ${OBJ:.o=.d}                  

# Default rule: just ask for bin main
all: main

# main depends on object files, that's all we need
main: ${OBJ}

# cleaning rule
clean:
	${RM} ${OBJ} ${DEP} main

# includes deps
-include ${DEP}

# END of Makefile
