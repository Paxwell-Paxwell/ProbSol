DIRS := $(wildcard */)

.PHONY: clean

clean:
	@for dir in $(DIRS); do \
		if [[ -d "$$dir" ]]; then \
			echo "Cleaning directory: $$dir"; \
			(cd $$dir && ls | grep -v "\." | xargs rm); \
		fi \
	done