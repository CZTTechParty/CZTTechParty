# Makefile
 
MDIR = $(shell pwd)
 
ifeq (, $(KSRC))
	KSRC := /usr/src/linux-`uname -r`
endif
 
ifeq (, $(PROJECT_DIR))
	PROJECT_DIR := $(PWD)/../
endif
 
module := module_panic
 
obj-m := $(module).o
 
srcs =  $(wildcard, *.c)
 
$(module)-objs := $(addsuffix .o, $(basename $(srcs)))
 
EXTRA_CFLAGS += -g $(FLAG) -I$(PROJECT_DIR)/inc -I${SHAREDHDR} -I$(KERNELHDR) -O2 -D__KERNEL__ -DMODULE $(INCLUDE) -DEXPORT_SYMTAB 
 
TARGET = $(module).ko
 
all:
	make -C $(KSRC) M=$(MDIR) modules
 
debug:
	make EXTRA_FLAGS="${EXTRA_CFLAGS} -DDEBUG" -C $(KSRC) M=$(MDIR) modules
 
clean:
	make -C $(KSRC) M=$(MDIR) clean
 
install: all
	cp -f $(TARGET) $(INSTALL_DIR)
