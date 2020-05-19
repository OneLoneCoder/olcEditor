CC=g++

SDIR=.
ODIR=obj

# Ensure obj directory exists
_dummy := $(shell mkdir -p $(ODIR))

LIBS=$(shell wx-config --libs --gl-libs --optional-libs propgrid) -lGL
LFLAGS=

CFLAGS=$(shell wx-config --cppflags) -std=c++17

OBJ = $(patsubst %, $(ODIR)/%,$(patsubst %.cpp, %.o,$(shell find -name "*.cpp" -printf " %f")))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

./editor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o
