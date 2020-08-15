##############################################################################
# Makefile based on example projects from https://github.com/ChibiOS/ChibiOS/
# Modified by Johannes Herold, IFTE, Germany on June 22nd, 2020
##############################################################################

##############################################################################
# Project, target, sources and paths
#

# Project name
PROJECT = InfinityCube

# Target MCU
MCU = cortex-m3

# Folders for temporary build files as well as finished binaries. These should also appear in your .gitignore!
BUILDDIR := ./build
DEPDIR   := ./.dep

# Startup file
STARTUPASM = lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7/startup_stm32f10x_md.S

# Linker script
LDSCRIPT = lib/stm32f103c8_flash.ld

# C sources

# Source file directory for standard peripheral library
SPDSRCDIR = lib/STM32F10x_StdPeriph_Driver/src

# User source file directory. All .c files in this folder are compiled. 
USERSRCDIR = src

CSRC = $(wildcard $(SPDSRCDIR)/*.c) \
		lib/CMSIS/CM3/CoreSupport/core_cm3.c \
		lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c \
		$(wildcard $(USERSRCDIR)/*.c)

# C++ sources
CPPSRC = 

# ASM sources
ASMSRC = 

# ASM with preprocessor source files
ASMXSRC = $(STARTUPASM)

# Inclusion directories
INCDIR = inc \
        lib/CMSIS/CM3/CoreSupport \
        lib/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
        lib/STM32F10x_StdPeriph_Driver/inc

# C warning options
CWARN = -Wall -Wextra -Wundef -Wno-unused-parameter -Wno-misleading-indentation

# C++ warning options
CPPWARN = -Wall -Wextra -Wundef -Wno-unused-parameter -Wno-misleading-indentation

# Project wide C defines, format -Dxxx=yyy, where xxx is the symbol and yyy is an optional value assigned to it
# These defines are treated as if every source file had an extra line like this: #define xxx yyy
UDEFS = -DHSE_VALUE=8000000 -DARM_MATH_CM4 -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD

# Same for ASM defines
UADEFS =

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS =

#
# End of user section
##############################################################################

##############################################################################
# Build global options
#

# Compiler options here.
ifeq ($(USE_OPT),)
  USE_OPT = -O0 -ggdb -fomit-frame-pointer -falign-functions=16
endif

# C specific options here (added to USE_OPT).
ifeq ($(USE_COPT),)
  USE_COPT = 
endif

# C++ specific options here (added to USE_OPT).
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT = -fno-rtti
endif

# Enable this if you want the linker to remove unused code and data.
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif

# Linker extra options here.
ifeq ($(USE_LDOPT),)
  USE_LDOPT = 
endif

# Enable this if you want link time optimizations (LTO).
ifeq ($(USE_LTO),)
  USE_LTO = yes
endif

# Enable this if you want to see the full log while compiling.
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = no
endif

#
# Build global options
##############################################################################

##############################################################################
# Architecture or project specific options
#

# Stack size to be allocated to the Cortex-M process stack. This stack is
# the stack used by the main() thread.
ifeq ($(USE_PROCESS_STACKSIZE),)
  USE_PROCESS_STACKSIZE = 0x400
endif

# Stack size to the allocated to the Cortex-M main/exceptions stack. This
# stack is used for processing interrupts and exceptions.
ifeq ($(USE_EXCEPTIONS_STACKSIZE),)
  USE_EXCEPTIONS_STACKSIZE = 0x400
endif

# Enables the use of FPU (no, softfp, hard).
ifeq ($(USE_FPU),)
  USE_FPU = no
endif

# FPU-related options.
ifeq ($(USE_FPU_OPT),)
  USE_FPU_OPT = -mfloat-abi=$(USE_FPU) -mfpu=fpv4-sp-d16
endif

#
# Architecture or project specific options
##############################################################################

# The following lines are based on https://github.com/ChibiOS/ChibiOS/tree/master/os/common/startup/ARMCMx/compilers/GCC/mk/arm-none-eabi.mk
##############################################################################
# Common rules
#

TRGT = arm-none-eabi-
CC   = $(TRGT)gcc
CPPC = $(TRGT)g++
# Enable loading with g++ only if you need C++ runtime support.
# NOTE: You can use C++ even without C++ support if you are careful. C++
#       runtime support makes code size explode.
LD   = $(TRGT)gcc
#LD   = $(TRGT)g++
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
AR   = $(TRGT)ar
OD   = $(TRGT)objdump
SZ   = $(TRGT)size
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary

# Common rules
##############################################################################

# The following lines are based on https://github.com/ChibiOS/ChibiOS/tree/master/os/common/startup/ARMCMx/compilers/GCC/mk/rules.mk
##############################################################################

# Compiler options
OPT    := $(USE_OPT)
COPT   := $(USE_COPT)
CPPOPT := $(USE_CPPOPT)

# Garbage collection
ifeq ($(USE_LINK_GC),yes)
  OPT   += -ffunction-sections -fdata-sections -fno-common
  LDOPT := ,--gc-sections
else
  LDOPT :=
endif

# Linker extra options
ifneq ($(USE_LDOPT),)
  LDOPT := $(LDOPT),$(USE_LDOPT)
endif

# Link time optimizations
ifeq ($(USE_LTO),yes)
  OPT += -flto
endif

# FPU options default (Cortex-M4 and Cortex-M7 single precision).
ifeq ($(USE_FPU_OPT),)
  USE_FPU_OPT = -mfloat-abi=$(USE_FPU) -mfpu=fpv4-sp-d16
endif

# FPU-related options
ifeq ($(USE_FPU),)
  USE_FPU = no
endif
ifneq ($(USE_FPU),no)
  OPT    += $(USE_FPU_OPT)
  DDEFS  += -DCORTEX_USE_FPU=TRUE
  DADEFS += -DCORTEX_USE_FPU=TRUE
else
  DDEFS  += -DCORTEX_USE_FPU=FALSE
  DADEFS += -DCORTEX_USE_FPU=FALSE
endif

# Process stack size
ifeq ($(USE_PROCESS_STACKSIZE),)
  LDOPT := $(LDOPT),--defsym=__process_stack_size__=0x400
else
  LDOPT := $(LDOPT),--defsym=__process_stack_size__=$(USE_PROCESS_STACKSIZE)
endif

# Exceptions stack size
ifeq ($(USE_EXCEPTIONS_STACKSIZE),)
  LDOPT := $(LDOPT),--defsym=__main_stack_size__=0x400
else
  LDOPT := $(LDOPT),--defsym=__main_stack_size__=$(USE_EXCEPTIONS_STACKSIZE)
endif

# Output directory and files
ifeq ($(BUILDDIR),)
  BUILDDIR = build
endif
ifeq ($(BUILDDIR),.)
  BUILDDIR = build
endif

# Dependencies directory
ifeq ($(DEPDIR),)
  DEPDIR = .dep
endif
ifeq ($(DEPDIR),.)
  DEPDIR = .dep
endif

OUTFILES := $(BUILDDIR)/$(PROJECT).elf \
            $(BUILDDIR)/$(PROJECT).hex \
            $(BUILDDIR)/$(PROJECT).bin \
            $(BUILDDIR)/$(PROJECT).dmp \
            $(BUILDDIR)/$(PROJECT).list

ifdef SREC
  OUTFILES += $(BUILDDIR)/$(PROJECT).srec
endif

# Source files groups and paths
TCSRC     += $(CSRC)
TCPPSRC   += $(CPPSRC)
TSRC      := $(TCSRC) $(TCPPSRC)
SRCPATHS  := $(sort $(dir $(ASMXSRC)) $(dir $(ASMSRC)) $(dir $(TSRC)))

# Various directories
OBJDIR    := $(BUILDDIR)/obj
LSTDIR    := $(BUILDDIR)/lst

# Object files groups
TCOBJS    := $(addprefix $(OBJDIR)/, $(notdir $(TCSRC:.c=.o)))
#TCPPOBJS  := $(addprefix $(OBJDIR)/, $(notdir $(TCPPSRC:.cpp=.o)))
TCPPOBJS  := $(addprefix $(OBJDIR)/, $(notdir $(patsubst %.cpp, %.o, $(filter %.cpp, $(TCPPSRC)))))
TCCOBJS   := $(addprefix $(OBJDIR)/, $(notdir $(patsubst %.cc, %.o, $(filter %.cc, $(TCPPSRC)))))
ASMOBJS   := $(addprefix $(OBJDIR)/, $(notdir $(ASMSRC:.s=.o)))
ASMXOBJS  := $(addprefix $(OBJDIR)/, $(notdir $(ASMXSRC:.S=.o)))
#OBJS      := $(ASMXOBJS) $(ASMOBJS) $(ACOBJS) $(TCOBJS) $(ACPPOBJS) $(TCPPOBJS)
OBJS      := $(ASMXOBJS) $(ASMOBJS) $(ACOBJS) $(TCOBJS) $(ACPPOBJS) $(TCPPOBJS) $(TCCOBJS)

# Paths
IINCDIR   := $(patsubst %,-I%,$(INCDIR))
LLIBDIR   := $(patsubst %,-L%,$(ULIBDIR))

# Macros
DEFS      := $(DDEFS) $(UDEFS)
ADEFS     := $(DADEFS) $(UADEFS)

# Libs
LIBS      := $(ULIBS)

# Various settings
MCFLAGS   := -mcpu=$(MCU) -mthumb
ODFLAGS   = -x --syms
ASFLAGS   = $(MCFLAGS) $(OPT) -Wa,-amhls=$(LSTDIR)/$(notdir $(<:.s=.lst)) $(ADEFS)
ASXFLAGS  = $(MCFLAGS) $(OPT) -Wa,-amhls=$(LSTDIR)/$(notdir $(<:.S=.lst)) $(ADEFS)
CFLAGS    = $(MCFLAGS) $(OPT) $(COPT) $(CWARN) -Wa,-alms=$(LSTDIR)/$(notdir $(<:.c=.lst)) $(DEFS)
CPPFLAGS  = $(MCFLAGS) $(OPT) $(CPPOPT) $(CPPWARN) -Wa,-alms=$(LSTDIR)/$(notdir $(<:.cpp=.lst)) $(DEFS)
LDFLAGS   = $(MCFLAGS) $(OPT) -nostartfiles $(LLIBDIR) -Wl,-Map=$(BUILDDIR)/$(PROJECT).map,--cref,--no-warn-mismatch,--library-path=$(STARTUPLD),--script=$(LDSCRIPT)$(LDOPT)

# Generate dependency information
ASFLAGS  += -MD -MP -MF $(DEPDIR)/$(@F).d
ASXFLAGS += -MD -MP -MF $(DEPDIR)/$(@F).d
CFLAGS   += -MD -MP -MF $(DEPDIR)/$(@F).d
CPPFLAGS += -MD -MP -MF $(DEPDIR)/$(@F).d

# Paths where to search for sources
VPATH     = $(SRCPATHS)

##############################################################################
# Makefile rules
#

all: PRE_MAKE_ALL_RULE_HOOK $(OBJS) $(OUTFILES) POST_MAKE_ALL_RULE_HOOK

#  optional stuff to do before compiling (user message etc.)
PRE_MAKE_ALL_RULE_HOOK:

#  optional stuff to do after compiling (flash to target etc.)
POST_MAKE_ALL_RULE_HOOK:

$(OBJS): | PRE_MAKE_ALL_RULE_HOOK $(BUILDDIR) $(OBJDIR) $(LSTDIR) $(DEPDIR)

$(BUILDDIR):
ifneq ($(USE_VERBOSE_COMPILE),yes)
	@echo $(CC) -c $(CFLAGS) -I. $(IINCDIR) main.c -o main.o
endif
	@mkdir -p $(BUILDDIR)
	@echo 
	@echo Defines:
	@echo $(CFLAGS) | tr " " "\n" | grep ^-D | sed -r "s/^-D//"
	@echo
	@echo Includes:
	@echo $(IINCDIR)  | tr " " "\n" | grep ^-I | sed -r "s/^-I//"
	@echo

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LSTDIR):
	@mkdir -p $(LSTDIR)

$(DEPDIR):
	@mkdir -p $(DEPDIR)

$(TCPPOBJS) : $(OBJDIR)/%.o : %.cpp $(MAKEFILE_LIST)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(CPPC) -c $(CPPFLAGS) -I. $(IINCDIR) $< -o $@
else
	@echo Compiling $(<F)
	@$(CPPC) -c $(CPPFLAGS) -I. $(IINCDIR) $< -o $@
endif

$(TCCOBJS) : $(OBJDIR)/%.o : %.cc $(MAKEFILE_LIST)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(CPPC) -c $(CPPFLAGS) -I. $(IINCDIR) $< -o $@
else
	@echo Compiling $(<F)
	@$(CPPC) -c $(CPPFLAGS) -I. $(IINCDIR) $< -o $@
endif

$(TCOBJS) : $(OBJDIR)/%.o : %.c $(MAKEFILE_LIST)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(CC) -c $(CFLAGS) -I. $(IINCDIR) $< -o $@
else
	@echo Compiling $(<F)
	@$(CC) -c $(CFLAGS) -I. $(IINCDIR) $< -o $@
endif

$(ASMOBJS) : $(OBJDIR)/%.o : %.s $(MAKEFILE_LIST)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(AS) -c $(ASFLAGS) -I. $(IINCDIR) $< -o $@
else
	@echo Compiling $(<F)
	@$(AS) -c $(ASFLAGS) -I. $(IINCDIR) $< -o $@
endif

$(ASMXOBJS) : $(OBJDIR)/%.o : %.S $(MAKEFILE_LIST)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(CC) -c $(ASXFLAGS) $(TOPT) -I. $(IINCDIR) $< -o $@
else
	@echo Compiling $(<F)
	@$(CC) -c $(ASXFLAGS) $(TOPT) -I. $(IINCDIR) $< -o $@
endif

$(BUILDDIR)/$(PROJECT).elf: $(OBJS) $(LDSCRIPT)
ifeq ($(USE_VERBOSE_COMPILE),yes)
	@echo
	$(LD) $(OBJS) $(LDFLAGS) $(LIBS) -o $@
else
	@echo Linking $@
	@$(LD) $(OBJS) $(LDFLAGS) $(LIBS) -o $@
endif

%.hex: %.elf
ifeq ($(USE_VERBOSE_COMPILE),yes)
	$(HEX) $< $@
else
	@echo Creating $@
	@$(HEX) $< $@
endif

%.bin: %.elf
ifeq ($(USE_VERBOSE_COMPILE),yes)
	$(BIN) $< $@
else
	@echo Creating $@
	@$(BIN) $< $@
endif

%.srec: %.elf
ifdef SREC
  ifeq ($(USE_VERBOSE_COMPILE),yes)
	$(SREC) $< $@
  else
	@echo Creating $@
	@$(SREC) $< $@
  endif
endif

%.dmp: %.elf
ifeq ($(USE_VERBOSE_COMPILE),yes)
	$(OD) $(ODFLAGS) $< > $@
	$(SZ) $<
else
	@echo Creating $@
	@$(OD) $(ODFLAGS) $< > $@
	@echo
	@$(SZ) $<
endif

%.list: %.elf
ifeq ($(USE_VERBOSE_COMPILE),yes)
	$(OD) -S $< > $@
else
	@echo Creating $@
	@$(OD) -S $< > $@
	@echo
	@echo Done
endif

lib: $(OBJS) $(BUILDDIR)/lib$(PROJECT).a

$(BUILDDIR)/lib$(PROJECT).a: $(OBJS)
	@$(AR) -r $@ $^
	@echo
	@echo Done

clean: CLEAN_RULE_HOOK
	@echo Cleaning
	@echo - $(DEPDIR)
	@-rm -fR $(DEPDIR)/* $(BUILDDIR)/* 2>/dev/null
	@-if [ -d "$(DEPDIR)" ]; then rmdir -p --ignore-fail-on-non-empty $(subst ./,,$(DEPDIR)) 2>/dev/null; fi
	@echo - $(BUILDDIR)
	@-if [ -d "$(BUILDDIR)" ]; then rmdir -p --ignore-fail-on-non-empty $(subst ./,,$(BUILDDIR)) 2>/dev/null; fi
	@echo
	@echo Done

CLEAN_RULE_HOOK:

#
# Include the dependency files, should be the last of the makefile
#
-include $(wildcard $(DEPDIR)/*)