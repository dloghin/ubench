### Building on Linux for ARM or x86_64 ###
UNAME := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(UNAME), Linux)

### x86_64 ###
ifeq ($(ARCH), x86_64)
CC=gcc
CCOPT=-Wall -O2 -g3 -m64
LD=$(CC)
LDOPT=-O2 -g -lrt -m64
OBJDMP=objdump
STRIP=strip
endif

### x86 (32-bit) ###
ifeq ($(ARCH), i686)
CC=gcc
CCOPT=-Wall -O2 -g3 -m32
LD=$(CC)
LDOPT=-O2 -g -lrt
OBJDMP=objdump
STRIP=strip
endif

### ARM 32-bit ###
ifeq ($(ARCH), armv7l) 
CC=gcc
# CCOPT=-Wall -O3 -marm -mcpu=cortex-a9 -mtune=cortex-a9 -mfpu=neon -mfloat-abi=hard -ffast-math -fstrict-aliasing
# CCOPT=-Wall -O3 -marm -mcpu=cortex-a15 -mtune=cortex-a15 -mfpu=neon -mfloat-abi=hard -ffast-math -fstrict-aliasing
CCOPT=-Wall -O3 -marm -mfpu=neon -mfloat-abi=hard -ffast-math -fstrict-aliasing -mcpu=cortex-a15
LD=$(CC)
LDOPT= -O3 -g -mfloat-abi=hard -lrt
OBJDMP=objdump
STRIP=strip
endif

### ARM 64-bit ###
ifeq ($(ARCH), aarch64)
CC=gcc
CCOPT=-Wall -O3 -ffast-math -fstrict-aliasing -mcpu=cortex-a57 -mtune=cortex-a57
LD=$(CC)
LDOPT= -O3 -g -lrt
OBJDMP=objdump
STRIP=strip
endif

endif

### Build all ###

all: floatint-java stall-java floatint stall

clean:
	rm -rf *.exe *.class

floatint: float-int.c common.c common.h
	$(CC) $(CCOPT) -DPROG=\"$@\" -DARCH=\"$(ARCH)\" -DSYS=\"$(UNAME)\" $^ -o $@.exe $(LDOPT)

stall: stall.c common.c common.h
	$(CC) $(CCOPT) -DPROG=\"$@\" -DARCH=\"$(ARCH)\" -DSYS=\"$(UNAME)\" $^ -o $@.exe $(LDOPT)

### Building Java ###

JC=javac

JCP=

floatint-java: FloatInt.class

stall-java: Stall.class
	
%.class: %.java
	$(JC) $^


