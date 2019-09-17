#gcc i2cCycleMemBridge.c `pkg-config --cflags glib-2.0` `pkg-config --libs glib-2.0` -lm
CC=gcc
CFLAGS= `pkg-config --cflags glib-2.0`
LIBS= `pkg-config --libs glib-2.0` -lm

cyclemake: i2cCycleMemBridge.c
	$(CC) i2cCycleMemBridge.c $(CFLAGS) $(LIBS)
