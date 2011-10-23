SOURCES := ../src/*.cpp
ROOT := ..

TOOL := mingw-shared-win32
COMPILER := g++

BUILDDIR := $(ROOT)/build/
INCLUDES := $(ROOT)/includes/
EXTINCLUDE := $(ROOT)/extinclude/
EXTLIBS := $(ROOT)/extlibs/$(TOOL)/

CFLAGS := -I$(EXTINCLUDE) -I$(INCLUDES)
OFLAGS := -O3 -ffast-math -ftree-vectorize -funsafe-math-optimizations
LFLAGS := -lm -lsfml-window -lsfml-system -lsfml-main -lsfml-graphics -L$(EXTLIBS)
MFLAGS := -march=native -DX86 -DX86_SSE3 -msse3
MFLAGS_LEGACY := -march=native -DX86

clean:
	rm $(BUILDDIR)*.dll
	rm powder*

powder-debug: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS_LEGACY) $(SOURCES) $(LFLAGS) -ggdb -DLIN32
	mv $@ $(BUILDDIR)

powder-legacy: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS_LEGACY) $(SOURCES) $(LFLAGS) -DLIN32
	strip $@
	mv $@ $(BUILDDIR)

powder: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS) $(SOURCES) $(LFLAGS) -DLIN32
	strip $@
	mv $@ $(BUILDDIR)
	
powder-debug.exe: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS_LEGACY) $(SOURCES) $(LFLAGS) -ggdb -DWIN32
	mv $@ $(BUILDDIR)
	cp $(EXTLIBS)*.dll $(BUILDDIR)

powder-legacy.exe: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS_LEGACY) $(SOURCES) $(LFLAGS) -DWIN32
	strip $@
	mv $@ $(BUILDDIR)
	cp $(EXTLIBS)*.dll $(BUILDDIR)

powder.exe: $(SOURCES)
	$(COMPILER) -o$@ $(CFLAGS) $(OFLAGS) $(MFLAGS) $(SOURCES) $(LFLAGS) -DWIN32
	strip $@
	mv $@ $(BUILDDIR)
	cp $(EXTLIBS)*.dll $(BUILDDIR)
