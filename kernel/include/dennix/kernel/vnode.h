/* Copyright (c) 2016, 2017 Dennis Wölfing
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* kernel/include/dennix/kernel/vnode.h
 * Vnode class.
 */

#ifndef KERNEL_VNODE_H
#define KERNEL_VNODE_H

#include <sys/types.h>
#include <dennix/stat.h>

class Vnode {
public:
    virtual int ftruncate(off_t length);
    virtual Vnode* getChildNode(const char* path);
    virtual bool isSeekable();
    virtual ssize_t pread(void* buffer, size_t size, off_t offset);
    virtual ssize_t pwrite(const void* buffer, size_t size, off_t offset);
    virtual ssize_t read(void* buffer, size_t size);
    virtual ssize_t readdir(unsigned long offset, void* buffer, size_t size);
    virtual int stat(struct stat* result);
    virtual int tcgetattr(struct termios* result);
    virtual int tcsetattr(int flags, const struct termios* termio);
    virtual ssize_t write(const void* buffer, size_t size);
    virtual ~Vnode() {}
protected:
    Vnode(mode_t mode, dev_t dev, ino_t ino);
public:
    dev_t dev;
    ino_t ino;
    mode_t mode;
};

Vnode* resolvePath(Vnode* vnode, const char* path);

#endif
