# dir
SRC = src/
BUILD = build/
BIN = bin/

# extentions
CEXT = .c
AEXT = .asm
OEXT = .o

# sorce files
CFILE = source
AFUNC = func
ASORT = sort
EFILE = exec1

# build flags
NASM_FLAGS =  -f elf64
LINK_FLAGS = -no-pie -Wall -g -c
EXEC_FLAGS = -no-pie

# message texts
START_MESSAGE = "Process started"
FINISH_MESSAGE = "Process finished"


build_nasm_func:
	nasm $(NASM_FLAGS) $(SRC)$(AFUNC)$(AEXT) -o $(BUILD)$(AFUNC)$(OEXT)

build_nasm_sort:
	nasm $(NASM_FLAGS) $(SRC)$(ASORT)$(AEXT) -o $(BUILD)$(ASORT)$(OEXT)

build_source_c:
	gcc $(LINK_FLAGS) $(SRC)$(CFILE)$(CEXT) -o $(BUILD)$(CFILE)$(OEXT)

build_exec:
	gcc $(EXEC_FLAGS) -o $(BIN)$(EFILE) $(BUILD)$(CFILE)$(OEXT) $(BUILD)$(AFUNC)$(OEXT) $(BUILD)$(ASORT)$(OEXT)

run_exec:
	./$(BIN)$(EFILE)

clear:
#	rm -rf bin/
#	mkdir bin/
	rm -rf build/
	mkdir build/

process_only:
	make clear
	make build_nasm_func
	make build_nasm_sort
	make build_source_c
	make build_exec

process:
	echo $(START_MESSAGE)
	make process_only
	echo $(FINISH_MESSAGE)
