CC=g++

SDIR=.
ODIR=obj

# Ensure obj directory exists
_dummy := $(shell mkdir -p $(ODIR))

LIBS=$(shell wx-config --libs --gl-libs --optional-libs propgrid) -lGL
LFLAGS=

CFLAGS=$(shell wx-config --cppflags) -std=c++17

_OBJ = BaseGUI.o cImageResource.o cLayer.o cMainFrame.o cPanAndZoomRenderer.o cTiledLayer.o RenderToolkit.o cApp.o cImageResourceEditor.o cLayerHandler.o cMasterContext.o cPrimaryRenderer.o cTiledResourceViewer.o cArea.o cLayer_Boolean.o cLayer_Tile.o common.o cProject.o cTileSelection.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

./editor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o

