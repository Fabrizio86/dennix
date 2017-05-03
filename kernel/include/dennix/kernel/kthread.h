/* Copyright (c) 2017 Dennis Wölfing
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

/* kernel/include/dennix/kernel/kthread.h
 * Kernel threading functions.
 */

#ifndef KERNEL_KTHREAD_H
#define KERNEL_KTHREAD_H

typedef bool kthread_mutex_t;
#define KTHREAD_MUTEX_INITIALIZER false

int kthread_mutex_lock(kthread_mutex_t* mutex);
int kthread_mutex_unlock(kthread_mutex_t* mutex);

// A useful class that automatically unlocks a mutex when it goes out of scope.
class AutoLock {
public:
    AutoLock(kthread_mutex_t* mutex) {
        this->mutex = mutex;
        kthread_mutex_lock(mutex);
    }

    ~AutoLock() {
        kthread_mutex_unlock(mutex);
    }
private:
    kthread_mutex_t* mutex;
};

#endif
