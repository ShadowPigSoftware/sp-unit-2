spunit/clean:
	$(REMOVE_FILE) $(SPUNIT_OUTPUT_FILES)
	$(REMOVE_FILE) $(SPUNIT_DEPENDENCY_FILES)
	$(REMOVE_FILE) $(SPUNIT_EXAMPLE_OUTPUT_FILES)
	$(REMOVE_FILE) $(SPUNIT_EXAMPLE_DEPENDENCY_FILES)
	$(REMOVE_FILE) $(SPUNIT_LIBRARY)
	$(REMOVE_FILE) $(SPUNIT_EXAMPLE_APPLICATION)