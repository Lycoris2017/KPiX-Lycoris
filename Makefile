# Variables
CC     := g++ -g -std=c++11
DEF    := -DMAKE_SW_VERSION=\"kpixSw_3.10\"
BIN    := $(PWD)/bin
OBJ    := $(PWD)/.obj
XMLC   := xml2-config
CFLAGS := -Wall `$(XMLC) --cflags` -I$(PWD)/generic -I$(PWD)/kpix -I$(PWD)/offline -I$(PWD)/deviceLib -fPIC
LFLAGS := `$(XMLC) --libs` -pthread -lrt -lbz2
SYSLIB := /usr/local/lib/kpix
SYSINC := /usr/local/include/kpix

# Generic Sources
GEN_DIR := $(PWD)/generic
GEN_SRC := $(wildcard $(GEN_DIR)/*.cpp)
GEN_HDR := $(wildcard $(GEN_DIR)/*.h)
GEN_OBJ := $(patsubst $(GEN_DIR)/%.cpp,$(OBJ)/%.o,$(GEN_SRC))

# Device Lib Sources
#DEV_DIR := $(PWD)/deviceLib
#DEV_SRC := $(wildcard $(DEV_DIR)/*.cpp)
#DEV_HDR := $(wildcard $(DEV_DIR)/*.h)
#DEV_OBJ := $(patsubst $(DEV_DIR)/%.cpp,$(OBJ)/%.o,$(DEV_SRC))

# Kpix Sources
KPX_DIR := $(PWD)/kpix
KPX_SRC := $(wildcard $(KPX_DIR)/*.cpp)
KPX_HDR := $(wildcard $(KPX_DIR)/*.h)
KPX_OBJ := $(patsubst $(KPX_DIR)/%.cpp,$(OBJ)/%.o,$(KPX_SRC))

# Util Sources
UTL_DIR := $(PWD)/util
UTL_SRC := $(wildcard $(UTL_DIR)/*.cpp)
UTL_BIN := $(patsubst $(UTL_DIR)/%.cpp,$(BIN)/%,$(UTL_SRC))

# Default
min: dir $(GEN_OBJ) $(KPX_OBJ) $(UTL_BIN) gui libkpix.so.1
# working point: kpix onlineGui can only work with old qwt libs which were already replaced by and updated in the current database.
# can be fixed by mannually debugging everywhere... (todo: mengqing @Nov27)
all: dir $(GEN_OBJ) $(KPX_OBJ) $(UTL_BIN) gui online pylibs libkpix.so
norm: dir $(GEN_OBJ) $(KPX_OBJ) $(UTL_BIN) gui online pylibs
share: dir $(GEN_OBJ) $(KPX_OBJ) $(UTL_BIN) libkpix.so
install:
	test -d $(SYSLIB) || mkdir $(SYSLIB)
	cp libkpix.so.1 $(SYSLIB)
	test -d $(SYSINC) || mkdir $(SYSINC) 
	cp ./generic/*.h ./kpix/*.h $(SYSINC)

# Object directory
dir:
	test -d $(OBJ) || mkdir $(OBJ)
	test -d $(BIN) || mkdir $(BIN)

# Clean
clean:
#	rm -rf $(OBJ)
	rm -r ./.obj 
#	rm -f $(BIN)/*
	rm  ./bin/*
	cd cntrlGui; qmake; make clean
#	cd root; make clean
	cd python; make clean
#ifneq ($(QWTDIR),)
	cd onlineGui; qmake; make clean
#endif

# Compile Common Sources
$(OBJ)/%.o: $(GEN_DIR)/%.cpp $(GEN_DIR)/%.h
	$(CC) -c $(CFLAGS) $(DEF) -o $@ $<

# Compile Generic Sources
#$(OBJ)/%.o: $(DEV_DIR)/%.cpp $(DEV_DIR)/%.h
#	$(CC) -c $(CFLAGS) $(DEF) -o $@ $<

# Compile Tracker Sources
$(OBJ)/%.o: $(KPX_DIR)/%.cpp $(KPX_DIR)/%.h
	$(CC) -c $(CFLAGS) $(DEF) -o $@ $<

# Comile utilities
#$(BIN)/%: $(UTL_DIR)/%.cpp $(GEN_OBJ) $(DEV_OBJ) $(KPX_OBJ)
$(BIN)/%: $(UTL_DIR)/%.cpp $(GEN_OBJ) $(KPX_OBJ)
	$(CC) $(CFLAGS) $(DEF) $(OBJ)/* -o $@ $< $(LFLAGS) 

# Compile all c-level code to a shared lib for EUDAQ: wmq@15-Jun-2017
libkpix.so.1: $(GEN_OBJ) $(KPX_OBJ)
	$(CC) -shared -fPIC $(CFLAGS) $(DEF) $(OBJ)/* -o $@  $(LFLAGS) 

# root
# ana:
# #ifneq ($(ROOTSYS),)
# 	cd root; make
# #endif

# python libs
pylibs:
ifneq ($(PYTHONPATH),)
	cd python; make
endif

# Compile gui
gui:
	cd cntrlGui; qmake
	cd cntrlGui; make

# online gui
online:
#ifneq ($(QWTDIR),)
	cd onlineGui; qmake
	cd onlineGui; make
#endif

