SPUNIT_LIBRARY = $(SPUNIT_BINARY_DIRECTORY)/libspunit.a

$(SPUNIT_LIBRARY): $(SPUNIT_OUTPUT_FILES)
	@$(MKDIR) $(@D)
	$(ARCHIVE) $@ $^

define spunit_namespace
spu_$(strip $(subst =,,\
	$(subst /,_s,\
		$(subst +,_p,\
			$(shell echo "\
				$(word 1,\
					$(shell echo $^ | md5sum)\
				)\
			" | xxd -r -p | base64)\
		)\
	)\
))
endef