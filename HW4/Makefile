# dir
SRC = ./src/
BUILD = ./build/
BIN = ./bin/

# extentions
CEXT = .c
AEXT = .asm
OEXT = .o

# sorce files
CFILE = source
AFILE = code
EFILE = exec

# build flags
ASM_FLAGS =  -f elf64
LINK_FLAGS = -no-pie -Wall -g -c
EXEC_FLAGS = -no-pie

# message texts
START_MESSAGE = "Process started"
FINISH_MESSAGE = "Process finished"


build_asm:
	nasm $(ASM_FLAGS) $(SRC)$(AFILE)$(AEXT) -o $(BUILD)$(AFILE)$(OEXT)

build_linked:
	gcc $(LINK_FLAGS) $(SRC)$(CFILE)$(CEXT) -o $(BUILD)$(CFILE)$(OEXT)

build_exec:
	gcc $(EXEC_FLAGS) -o $(BIN)$(EFILE) $(BUILD)$(CFILE)$(OEXT) $(BUILD)$(AFILE)$(OEXT)

run_exec:
	./$(BIN)$(EFILE)

clear:
	rm -rf bin/
	mkdir bin/
	rm -rf build/
	mkdir build/

process_only:
	make clear
	make build_asm
	make build_linked
	make build_exec
	make run_exec

process:
	echo $(START_MESSAGE)
	make process_only
	echo $(FINISH_MESSAGE)
