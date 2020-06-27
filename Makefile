rel 	= out/release
dbg 	= out/debug
dbgout 	= $(dbg)/spaceman
relout 	= $(rel)/spaceman

#Basic targets
debug: $(dbgout)
release: $(relout)

#Debug targets
$(dbgout): $(dbg)/main.o $(dbg)/spaceman_package.o $(dbg)/toml.o;
	@echo linking
	@gcc -g $^ -o $@

$(dbg)/main.o: src/main.c
	@echo $@
	@gcc -c -g $< -o $@

$(dbg)/spaceman_package.o: src/spaceman_package.c
	@echo $@
	@gcc -c -g $< -o $@

$(dbg)/toml.o: src/ctoml/toml.c
	@echo $@
	@gcc -c -g $< -o $@


#Release targets
$(relout): $(rel)/main.o $(rel)/spaceman_package.o $(rel)/toml.o;
	@echo linking
	@gcc -O3 $^ -o $@

$(rel)/main.o: src/main.c
	@echo $@
	@gcc -c -O3 $< -o $@

$(rel)/spaceman_package.o: src/spaceman_package.c
	@echo $@
	@gcc -c -O3 $< -o $@

$(rel)/toml.o: src/ctoml/toml.c
	@echo $@
	@gcc -O3 -c -g $< -o $@
