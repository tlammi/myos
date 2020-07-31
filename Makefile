ARCH := x86
SUBDIRS := src arch/$(ARCH)
objs :=

# Iterate SUBDIRS variable and include Makefile from each
#
# Also sets DIR-variable to point to target Makefile's containing directory
include_subdirs := $(foreach dir,$(SUBDIRS),$(eval DIR:=$(dir))$(eval include $(dir)/Makefile))

# Drops variable suffix moving it to value prefix
#
# E.g. obj-src = main.cpp changes to src/main.cpp
define suffix_to_path
$(foreach i,$($1-$2),$2/$(i))
endef

# Join all subdir suffices to one list
#
# E.g. $(call join_suffices,objs) will join all variables with format objs-<suffix>
# to one, modifying the variable values according to suffix_to_path.
define join_suffices
$(foreach dir,$(SUBDIRS),$(call suffix_to_path,$1,$(dir)))
endef

$(call include_subdirs)
objs += $(call join_suffices,objs)

INC_DIRS = -Iinclude -Iarch/$(ARCH)/include
CXXFLAGS += $(INC_DIRS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

myos.bin: $(objs)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	$(RM) myos.bin
	$(RM) $(objs)

