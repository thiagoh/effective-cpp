
target = main

objects = main.o Widget.o

rebuildables = $(objects) $(target)

all: $(target)
	@echo "Success! All done."

#http://xahlee.info/UnixResource_dir/_/ldpath.html
$(target): $(objects)
	@g++ -o $(target) $(objects)
	
# Mode 2
%.o: %.cpp *.h *.hpp
	g++ -O -c -I/usr/lib/jvm/java-7-oracle/include/ -I/usr/lib/jvm/java-7-oracle/include/linux/ -Wall -o $@ $<

main.o: Widget.o

clean:
	@rm $(objects) $(target) || true


