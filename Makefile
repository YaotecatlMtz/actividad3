CFLAGS = -Wall -Wextra -std=c99

# Targets (executables)
TARGETS = ejer1 ejer2 ejer3

# Default target: compile all executables
all: $(TARGETS)

# Rule to compile ejer1
ejer1: ejer1.c
        $(CC) $(CFLAGS) ejer1.c -o ejer1

# Rule to compile ejer2
ejer2: ejer2.c
        $(CC) $(CFLAGS) ejer2.c -o ejer2

# Rule to compile ejer3
ejer3: ejer3.c
        $(CC) $(CFLAGS) ejer3.c -o ejer3

# Rule to run all executables
run: all
        @echo "Running ejer1:"
        ./ejer1
        @echo "Running ejer2:"
        ./ejer2 5
        @echo "Running ejer3:"
        ./ejer3 3

# Rule to clean up compiled files
clean:
        rm -f $(TARGETS)

# Phony targets (not actual files)
.PHONY: all run clean