ifeq ($(SPUNIT_OVERRIDE_CPP),)
SPUNIT_CPP = g++ -std=c++17
else
SPUNIT_CPP = $(SPUNIT_OVERRIDE_CPP)
endif

SPUNIT_CPP_DEBUG_FLAGS ?= -g3 -O0
SPUNIT_CPP_RELEASE_FLAGS ?= -g0 -O3
SPUNIT_CPP_FLAGS ?= -Wall -Werror -Wextra
#Place a target for building an output (.o) file based on a C++ (.cpp) file
# parameter 1 = source directory
# parameter 2 =  output directory
# Example usage: $(call spunit_make_build_cpp_target,src,build/src)
define spunit_make_build_cpp_target
	$(eval $(call _spunit_make_build_cpp_target,$(1),$(2),$(3)))
endef
define _spunit_make_build_cpp_target
$(2)/%.cpp.o: $(1)/%.cpp
	@$$(MKDIR) $$(@D)
	$$(SPUNIT_CPP) $$(SPUNIT_CPP_FLAGS) $$(SPUNIT_INCLUDE) -MMD -MP -MT $$@ -MF $(2)/$$*.cpp.d -c $$< -o $$@ $(3)
endef
