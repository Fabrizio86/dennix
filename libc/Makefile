# Copyright (c) 2016, 2017, 2018 Dennis Wölfing
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

ARCH ?= i686

REPO_ROOT = ..

include $(REPO_ROOT)/build-aux/paths.mk
include $(REPO_ROOT)/build-aux/toolchain.mk

BUILD = $(BUILD_DIR)/libc

ARFLAGS = -crs
CFLAGS ?= -O2 -g
CFLAGS += --sysroot=$(SYSROOT) -std=gnu11 -ffreestanding -Wall -Wextra
CXXFLAGS ?= -O2 -g
CXXFLAGS += --sysroot=$(SYSROOT) -std=gnu++14 -ffreestanding -Wall -Wextra
CPPFLAGS += -I include -D_ALL_SOURCE

LIBC_FLAGS += -D__is_dennix_libc
LIBK_FLAGS += -D__is_dennix_libk

COMMON_OBJ = \
	ctype/isblank \
	ctype/isdigit \
	ctype/isspace \
	cxx/new \
	cxx/purevirtual \
	errno/errno \
	getopt/getopt \
	getopt/getopt_long \
	inttypes/strtoimax \
	inttypes/strtoumax \
	libgen/basename \
	libgen/dirname \
	sched/sched_yield \
	signal/sigaddset \
	signal/sigdelset \
	signal/sigemptyset \
	signal/sigfillset \
	signal/sigismember \
	stdio/vcbprintf \
	stdlib/calloc \
	stdlib/free \
	stdlib/malloc \
	stdlib/malloc-util \
	stdlib/qsort \
	stdlib/qsort_r \
	stdlib/rand \
	stdlib/realloc \
	stdlib/reallocarray \
	stdlib/strtol \
	stdlib/strtoll \
	stdlib/strtoul \
	stdlib/strtoull \
	string/memcmp \
	string/memcpy \
	string/memmove \
	string/memset \
	string/stpcpy \
	string/strchr \
	string/strcmp \
	string/strcpy \
	string/strcspn \
	string/strdup \
	string/strerror \
	string/strlcpy \
	string/strlen \
	string/strncmp \
	string/strndup \
	string/strnlen \
	string/strrchr \
	string/strsignal \
	string/strspn \
	string/strtok \
	time/gmtime \
	time/gmtime_r \
	time/timegm

LIBC_OBJ = \
	$(COMMON_OBJ) \
	assert/assert \
	dirent/alphasort \
	dirent/closedir \
	dirent/fdopendir \
	dirent/opendir \
	dirent/readdir \
	dirent/rewinddir \
	dirent/scandir \
	err/err \
	err/errc \
	err/errx \
	err/verr \
	err/verrc \
	err/verrx \
	err/vwarn \
	err/vwarnc \
	err/vwarnx \
	err/warn \
	err/warnc \
	err/warnx \
	errno/initProgname \
	fcntl/open \
	fcntl/openat \
	signal/kill \
	signal/raise \
	signal/sigaction \
	signal/signal \
	stdio/clearerr_unlocked \
	stdio/clearerr \
	stdio/fclose \
	stdio/fdopen \
	stdio/feof_unlocked \
	stdio/feof \
	stdio/ferror_unlocked \
	stdio/ferror \
	stdio/fflush \
	stdio/fgetc_unlocked \
	stdio/fgetc \
	stdio/fgets_unlocked \
	stdio/fgets \
	stdio/flockfile \
	stdio/fopen \
	stdio/fprintf \
	stdio/fputc_unlocked \
	stdio/fputc \
	stdio/fputs_unlocked \
	stdio/fputs \
	stdio/fseek \
	stdio/fseeko_unlocked \
	stdio/fseeko \
	stdio/ftell \
	stdio/ftello_unlocked \
	stdio/ftello \
	stdio/funlockfile \
	stdio/fwrite_unlocked \
	stdio/fwrite \
	stdio/getc_unlocked \
	stdio/getc \
	stdio/getchar_unlocked \
	stdio/getchar \
	stdio/getdelim \
	stdio/getline \
	stdio/printf \
	stdio/putc_unlocked \
	stdio/putc \
	stdio/putchar_unlocked \
	stdio/putchar \
	stdio/puts \
	stdio/remove \
	stdio/rename \
	stdio/renameat \
	stdio/rewind \
	stdio/stderr \
	stdio/stdin \
	stdio/stdout \
	stdio/vfprintf_unlocked \
	stdio/vfprintf \
	stdlib/abort \
	stdlib/atexit \
	stdlib/canonicalize_file_name \
	stdlib/_Exit \
	stdlib/exit \
	stdlib/getenv \
	stdlib/setenv \
	stdlib/unsetenv \
	string/strcoll \
	sys/mman/mmap \
	sys/mman/munmap \
	sys/stat/fstat \
	sys/stat/fstatat \
	sys/stat/lstat \
	sys/stat/mkdir \
	sys/stat/mkdirat \
	sys/stat/stat \
	sys/utsname/uname \
	sys/wait/wait \
	sys/wait/waitpid \
	termios/tcgetattr \
	termios/tcsetattr \
	time/clock_gettime \
	time/clock_nanosleep \
	time/localtime \
	time/mktime \
	time/nanosleep \
	time/strftime \
	time/time \
	time/tzset \
	unistd/access \
	unistd/chdir \
	unistd/close \
	unistd/confstr \
	unistd/dup2 \
	unistd/dup3 \
	unistd/environ \
	unistd/execl \
	unistd/execv \
	unistd/execve \
	unistd/_exit \
	unistd/fchdirat \
	unistd/fork \
	unistd/getcwd \
	unistd/gethostname \
	unistd/getlogin \
	unistd/getpid \
	unistd/isatty \
	unistd/link \
	unistd/linkat \
	unistd/lseek \
	unistd/pipe \
	unistd/pipe2 \
	unistd/read \
	unistd/regfork \
	unistd/rmdir \
	unistd/sleep \
	unistd/symlink \
	unistd/symlinkat \
	unistd/unlink \
	unistd/unlinkat \
	unistd/write

LIBK_OBJ = $(COMMON_OBJ)

include $(ARCH).mk

LIBC_OBJ := $(addprefix $(BUILD)/, $(addsuffix .o, $(LIBC_OBJ)))
LIBK_OBJ := $(addprefix $(BUILD)/, $(addsuffix .libk.o, $(LIBK_OBJ)))

all: $(BUILD)/libc.a $(BUILD)/libk.a $(CRT_OBJ)

-include $(LIBC_OBJ:.o=.d)
-include $(LIBK_OBJ:.o=.d)

install: install-headers install-libs

install-headers:
	@mkdir -p $(INCLUDE_DIR)
	cp -rf --preserve=timestamp include/. $(INCLUDE_DIR)
	touch $(SYSROOT)

install-libs: $(BUILD)/libc.a $(BUILD)/libk.a $(CRT_OBJ)
	@mkdir -p $(LIB_DIR)
	cp -f --preserve=timestamp $^ $(LIB_DIR)
	touch $(SYSROOT)

$(BUILD)/libc.a: $(LIBC_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(BUILD)/libk.a: $(LIBK_OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(BUILD)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBC_FLAGS) -MD -MP -c -o $@ $<

$(BUILD)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LIBC_FLAGS) -MD -MP -c -o $@ $<

$(BUILD)/%.o: src/%.S
	@mkdir -p $(dir $@)
	$(CC) $(ASFLAGS) $(CPPFLAGS) $(LIBC_FLAGS) -c -o $@ $<

$(BUILD)/%.libk.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBK_FLAGS) -MD -MP -c -o $@ $<

$(BUILD)/%.libk.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LIBK_FLAGS) -MD -MP -c -o $@ $<

clean:
	rm -rf $(BUILD)

.PHONY: all install install-headers install-libs clean
