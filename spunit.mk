SPUNIT_MAKE_PATH := $(lastword $(MAKEFILE_LIST))
SPUNIT_DIRECTORY := $(dir $(SPUNIT_MAKE_PATH))

ifeq ($(SPUNIT_DIRECTORY),./)
SPUNIT_DIRECTORY :=
endif
include $(SPUNIT_DIRECTORY)make/help.mk
include $(SPUNIT_DIRECTORY)make/tools.mk
include $(SPUNIT_DIRECTORY)make/cpp.mk
include $(SPUNIT_DIRECTORY)make/sources.mk

#Source code
include $(SPUNIT_SOURCE_DIRECTORY)/make.mk
include $(SPUNIT_EXAMPLES_DIRECTORY)/make.mk

# Main targets
include $(SPUNIT_DIRECTORY)make/spunit.mk
include $(SPUNIT_DIRECTORY)make/debug.mk
include $(SPUNIT_DIRECTORY)make/release.mk
include $(SPUNIT_DIRECTORY)make/examples.mk
include $(SPUNIT_DIRECTORY)make/clean.mk

-include $(SPUNIT_DEPENDENCY_FILES)
-include $(SPUNIT_EXAMPLE_DEPENDENCY_FILES)