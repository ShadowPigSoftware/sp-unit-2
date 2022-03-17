SPUNIT_EXAMPLE_APPLICATION = $(SPUNIT_BINARY_DIRECTORY)/spunit-examples

$(SPUNIT_EXAMPLE_APPLICATION): $(SPUNIT_EXAMPLE_OUTPUT_FILES) $(SPUNIT_LIBRARY) 
	$(CPP) $(CPP_FLAGS) $(SPUNIT_INCLUDE) -I$(SPUNIT_EXAMPLES_DIRECTORY) -o $@ $(SPUNIT_EXAMPLE_OUTPUT_FILES) -L$(SPUNIT_BINARY_DIRECTORY) -lspunit

spunit/examples: CPP_FLAGS += $(CPP_DEBUG_FLAGS)
spunit/examples: SPUNIT_INCLUDE += -I$(SPUNIT_EXAMPLES_DIRECTORY)
spunit/examples: $(SPUNIT_EXAMPLE_APPLICATION)