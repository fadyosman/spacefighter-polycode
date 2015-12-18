TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lrt -ldl -lpthread /home/fady/Apps/Polycode/Release/Linux/Framework/Core/lib/libPolycore.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libfreetype.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbisfile.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibvorbis.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/liblibogg.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libopenal.so /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libphysfs.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libpng15.a /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/lib/libPolycode2DPhysics.a /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBox2D.a /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/lib/libPolycode3DPhysics.a /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletDynamics.a /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libBulletCollision.a /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/lib/libLinearMath.a -lX11

INCLUDEPATH += /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/include /home/fady/Apps/Polycode/Release/Linux/Framework/Core/Dependencies/include/AL /home/fady/Apps/Polycode/Release/Linux/Framework/Core/include /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/include /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/include /home/fady/Apps/Polycode/Release/Linux/Framework/Modules/Dependencies/include/bullet



SOURCES += main.cpp \
    fighter.cpp \
    enemy.cpp \
    game.cpp \
    fireball.cpp \
    explosion.cpp

HEADERS += \
    fighter.h \
    enemy.h \
    game.h \
    fireball.h \
    explosion.h

OTHER_FILES += \
    Assets/explosion.png \
    Assets/fireball.png \
    Assets/fighter.png \
    Assets/ufo.png \
    Assets/bg.png

