default: all

all:
	mkdir -p objs bin
	$(MAKE) -f src/Makefile

clean:
	rm -rf objs bin