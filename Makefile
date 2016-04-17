all:
	mkdir -p build
	cd build; python ../../cppwrap/main.py /Users/ben/src/openvr/headers/openvr.h ../prefix.h /Users/ben/tools/clang-3.8/lib
	cd build; clang -x c++ -std=c++11 -I/Users/ben/src/openvr/headers -shared -undefined dynamic_lookup -o libopenvr_c.so openvr_c.cpp
	cd build; clang ../test_binding.c libopenvr_c.so -I. -L/Users/ben/src/openvr/lib/osx32 -l openvr_api -o test_binding
	cp /Users/ben/src/openvr/lib/osx32/libopenvr_api.dylib build/
	cd build; ./test_binding
