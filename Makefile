all:
	$(MAKE) --directory=src CC=g++ CXX=g++ DEBUG=no

debug:
	$(MAKE) --directory=src CC=g++ CXX=g++ DEBUG=yes

dist-clean:
	$(MAKE) dist-clean --directory=src

debug-clean:
	$(MAKE) debug-clean --directory=src

rules:
	$(MAKE) rules --directory=src CC=g++ CXX=g++
