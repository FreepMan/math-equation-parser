CC=clang


# Dependencies flags for .h files (to make make recompile the project when .h was changed)
DEPFLAGS=-MP -MD
LFLAGS=-lstdc++
EFLAGS=-Wall
CFLAGS=-g $(EFLAGS) $(DEPFLAGS)
LIBS=src
CODEDIRS=. $(LIBS) $(foreach D,$(LIBS), $(wildcard $(D)/*))
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))
BINARY=bin


compile_commands:
	@bear -- make all -j12

all:$(BINARY)

$(BINARY):$(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)


-include $(DEPFILES)

%.o:%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(BINARY) $(DEPFILES) compile_commands.json
