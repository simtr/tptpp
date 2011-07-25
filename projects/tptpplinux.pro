LIBS += -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += \
	../includes \
	../src

HEADERS += \
    ../includes/Particles/Particle.hpp \
    ../includes/Particles/Metl.hpp \
    ../includes/Sandbox.hpp \
    ../includes/Renderer.hpp \
    ../includes/Layer.hpp \
    ../includes/GlobalFunctions.hpp \
    ../includes/GlobalDefines.hpp \
    ../includes/ui/State.hpp \
    ../includes/ui/Component.hpp \
    ../includes/ui/Button.hpp

SOURCES += \
    ../src/Sandbox.cpp \
    ../src/Renderer.cpp \
    ../src/main.cpp \
    ../src/Layer.cpp \
    ../src/GlobalFunctions.cpp \
    ../src/ui/State.cpp \
    ../src/ui/Component.cpp \
    ../src/ui/Button.cpp \
    ../src/Particles/Particle.cpp \
    ../src/Particles/Metl.cpp
