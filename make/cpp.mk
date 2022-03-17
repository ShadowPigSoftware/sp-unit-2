CPP = g++

CPP_DEBUG_FLAGS ?= -g3 -O0
CPP_RELEASE_FLAGS ?= -g0 -O3
CPP_FLAGS ?= -Wall -Werror -Wextra
#Place a target for building an output (.o) file based on a C++ (.cpp) file
# parameter 1 = source directory
# parameter 2 =  output directory
# Example usage: $(call spunit_make_build_cpp_target,src,build/src)
define spunit_make_build_cpp_target
	$(eval $(call _spunit_make_build_cpp_target,$(1),$(2)))
endef
define _spunit_make_build_cpp_target
$(2)/%.cpp.o: $(1)/%.cpp
	@$$(MKDIR) $$(@D)
	$$(CPP) $$(CPP_FLAGS) $$(SPUNIT_INCLUDE) -MMD -MP -MT $$@ -MF $(2)/$$*.cpp.d -c $$< -o $$@
endef
