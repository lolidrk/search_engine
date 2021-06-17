all:
	gcc get_val.c -g search_engine.c  -ljson-c -o search_engine
	gcc ex-compile.c -o ex-compile `pkg-config --cflags --libs glib-2.0` 
	gcc input.c -o input