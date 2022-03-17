SPUNIT_SOURCE_DIRECTORY = $(SPUNIT_DIRECTORY)source
SPUNIT_INCLUDE_DIRECTORY = $(SPUNIT_DIRECTORY)include
SPUNIT_EXAMPLES_DIRECTORY = $(SPUNIT_DIRECTORY)examples
SPUNIT_BUILD_DIRECTORY ?= $(SPUNIT_DIRECTORY)build
SPUNIT_BINARY_DIRECTORY ?= $(SPUNIT_DIRECTORY)bin

SPUNIT_SOURCE_FILES =
SPUNIT_EXAMPLE_SOURCE_FILES = 
SPUNIT_INCLUDE=-I$(SPUNIT_INCLUDE_DIRECTORY)
# construct the output (.o) files from a list of C++ (.cpp)
# parameter 1 = Source Files
# parameter 2 = input pattern, excluding the extension, e.g. src/%
# parameter 3 = output pattern, exclusing the extension, e.g. build/src/%
# Example usage $(call spunit_make_output_files, $(SOURCE_FILES), src/%, build/src/%)
define spunit_make_output_files
$(patsubst $(2).cpp,$(3).cpp.o,$(1))
endef

# construct the dependency (.d) files from a list of C++ (.cpp)
# parameter 1 = Source Files
# parameter 2 = input pattern, excluding the extension, e.g. src/%
# parameter 3 = output pattern, exclusing the extension, e.g. build/src/%
# Example usage $(call spunit_make_dependency_files, $(SOURCE_FILES), src/%, build/src/%)
define spunit_make_dependency_files
$(patsubst $(2).cpp,$(3).cpp.d,$(1))
endef

SPUNIT_OUTPUT_FILES=$(call spunit_make_output_files,$(SPUNIT_SOURCE_FILES),$(SPUNIT_SOURCE_DIRECTORY)/%,$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_SOURCE_DIRECTORY)/%)
SPUNIT_DEPENDENCY_FILES=$(call spunit_make_dependency_files,$(SPUNIT_SOURCE_FILES),$(SPUNIT_SOURCE_DIRECTORY)/%,$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_SOURCE_DIRECTORY)/%)
SPUNIT_EXAMPLE_OUTPUT_FILES=$(call spunit_make_output_files,$(SPUNIT_EXAMPLE_SOURCE_FILES),$(SPUNIT_EXAMPLES_DIRECTORY)/%,$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_EXAMPLES_DIRECTORY)/%)
SPUNIT_EXAMPLE_DEPENDENCY_FILES=$(call spunit_make_dependency_files,$(SPUNIT_EXAMPLE_SOURCE_FILES),$(SPUNIT_EXAMPLES_DIRECTORY)/%,$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_EXAMPLES_DIRECTORY)/%)

$(call spunit_make_build_cpp_target,$(SPUNIT_SOURCE_DIRECTORY),$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_SOURCE_DIRECTORY))
$(call spunit_make_build_cpp_target,$(SPUNIT_EXAMPLES_DIRECTORY),$(SPUNIT_BUILD_DIRECTORY)/$(SPUNIT_EXAMPLES_DIRECTORY))

-include $(SPUNIT_DEPENDENCY_FILES)
-include $(SPUNIT_EXAMPLE_DEPENDENCY_FILES)