gcc = 		/usr/bin/gcc 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h
g++ = 		/usr/bin/g++ 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h -Wno-deprecated
clang = 	/usr/bin/clang 		-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h
clang++ = 	/usr/bin/clang++	-Iinc -Wall -Wextra -Werror -Wfatal-errors -c $(C) -o obj/$(shell echo $C | cut -d / -f 1 --complement - | cut -d . -f 1 -).o -include wc/config.h -Wno-deprecated

.PHONY: _test test test_header compile clean asm obj

objdump:
	mkdir -p obj
	objdump -d $(C) > obj/$(shell basename $(C)).dmp
test:
	mkdir -p obj
	$(clang) -pedantic-errors -Wpedantic -std=c90 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=iso9899:199409 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c99 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c11 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c17 $(F)
	$(clang) -pedantic-errors -Wpedantic -std=c2x $(F)
	$(clang) -std=gnu90 $(F)
	$(clang) -std=gnu99 $(F)
	$(clang) -std=gnu11 $(F)
	$(clang) -std=gnu17 $(F)
	$(clang) -std=gnu2x $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c90 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=iso9899:199409 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c99 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c11 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c17 $(F)
	$(gcc) -pedantic-errors -Wpedantic -std=c2x $(F)
	$(gcc) -std=gnu90 $(F)
	$(gcc) -std=gnu99 $(F)
	$(gcc) -std=gnu11 $(F)
	$(gcc) -std=gnu17 $(F)
	$(gcc) -std=gnu2x $(F)
# /usr/bin/pcc -Iinc
test_header:
	mkdir -p obj/array
	$(clang) -std=c90 $(F)
	$(clang) -std=iso9899:199409 $(F)
	$(clang) -std=c99 $(F)
	$(clang) -std=c11 $(F)
	$(clang) -std=c17 $(F)
	$(clang) -std=c2x $(F)
	$(clang) -std=gnu90 $(F)
	$(clang) -std=gnu99 $(F)
	$(clang) -std=gnu11 $(F)
	$(clang) -std=gnu17 $(F)
	$(clang) -std=gnu2x $(F)
	$(gcc) -std=c90 $(F)
	$(gcc) -std=iso9899:199409 $(F)
	$(gcc) -std=c99 $(F)
	$(gcc) -std=c11 $(F)
	$(gcc) -std=c17 $(F)
	$(gcc) -std=c2x $(F)
	$(gcc) -std=gnu90 $(F)
	$(gcc) -std=gnu99 $(F)
	$(gcc) -std=gnu11 $(F)
	$(gcc) -std=gnu17 $(F)
	$(gcc) -std=gnu2x $(F)

	$(clang++) -std=c++98 $(F)
	$(clang++) -std=c++11 $(F)
	$(clang++) -std=c++14 $(F)
	$(clang++) -std=c++17 $(F)
	$(clang++) -std=c++20 $(F)
	$(clang++) -std=c++2b $(F)
	$(clang++) -std=gnu++98 $(F)
	$(clang++) -std=gnu++11 $(F)
	$(clang++) -std=gnu++14 $(F)
	$(clang++) -std=gnu++17 $(F)
	$(clang++) -std=gnu++20 $(F)
	$(clang++) -std=gnu++2b $(F)
	$(g++) -std=c++98 $(F)
	$(g++) -std=c++11 $(F)
	$(g++) -std=c++14 $(F)
	$(g++) -std=c++17 $(F)
	$(g++) -std=c++20 $(F)
	$(g++) -std=c++2b $(F)
	$(g++) -std=gnu++98 $(F)
	$(g++) -std=gnu++11 $(F)
	$(g++) -std=gnu++14 $(F)
	$(g++) -std=gnu++17 $(F)
	$(g++) -std=gnu++20 $(F)
	$(g++) -std=gnu++2b $(F)
compile:
	mkdir -p obj
	$(gcc) -pedantic-errors -Wpedantic $(F) -O2
asm:
	$(gcc) -pedantic-errors -Wpedantic -O2 -S $(F)
clean:
	rm -f $(shell find -name "*.gch")
	rm -f $(shell find -name "*.dmp")
	rm -f $(shell find -name "*.tmp")
	rm -f $(shell find -name "*.o")
	rm -f $(shell find -name "*.s")
	rm -f $(shell find -name "*.a")

theaders:
	make test_header F="inc/wc/sys/arch.h"
	make test_header F="inc/wc/sys/comp.h"
	make test_header F="inc/wc/sys/damo.h"
	make test_header F="inc/wc/sys/lang.h"
	make test_header F="inc/wc/sys/osys.h"
	make test_header F="inc/wc/array.h"
	make test_header F="inc/wc/char.h"
	make test_header F="inc/wc/config.h"
	make test_header F="inc/wc/core.h"
	make test_header F="inc/wc/error.h"
	make test_header F="inc/wc/string.h"
	make test_header F="inc/wc/types.h"
tarray:
	make test F="src/array/afa.c"
	make test F="src/array/afb.c"
	make test F="src/array/afl.c"
	make test F="src/array/asa.c"
	make test F="src/array/asb.c"
carray:
	make compile F="src/array/afa.c"
	make compile F="src/array/afb.c"
	make compile F="src/array/afl.c"
	make compile F="src/array/asa.c"
	make compile F="src/array/asb.c"
array: carray
	mkdir -p lib
	ar -rc lib/libwca.a obj/array/*
