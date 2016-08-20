/* Copyright (c) 2016, Dennis Wölfing
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

/* kernel/include/dennix/kernel/addressspace.h
 * Address space class.
 */

#ifndef KERNEL_ADDRESSSPACE_H
#define KERNEL_ADDRESSSPACE_H

#include <dennix/mman.h>
#include <dennix/kernel/memorysegment.h>

class AddressSpace {
public:
    ~AddressSpace();
    void activate();
    AddressSpace* fork();
    paddr_t getPhysicalAddress(vaddr_t virtualAddress);
    vaddr_t mapFromOtherAddressSpace(AddressSpace* sourceSpace,
            vaddr_t sourceVirtualAddress, size_t size, int protection);
    vaddr_t mapMemory(size_t size, int protection);
    vaddr_t mapMemory(vaddr_t virtualAddress, size_t size, int protection);
    vaddr_t mapPhysical(paddr_t physicalAddress, size_t size, int protection);
    vaddr_t mapPhysical(vaddr_t virtualAddress, paddr_t physicalAddress,
            size_t size, int protection);
    void unmapMemory(vaddr_t virtualAddress, size_t size);
    void unmapPhysical(vaddr_t firstVirtualAddress, size_t size);
private:
    AddressSpace();
    bool isFree(size_t pdIndex, size_t ptIndex);
    vaddr_t map(paddr_t physicalAddress, int protection);
    vaddr_t mapAt(vaddr_t virtualAddress, paddr_t physicalAddress,
            int protection);
    vaddr_t mapAt(size_t pdIndex, size_t ptIndex, paddr_t physicalAddress,
            int protection);
    vaddr_t mapAtWithFlags(size_t pdIndex, size_t ptIndex,
            paddr_t physicalAddress, int flags);
    void unmap(vaddr_t virtualAddress);
private:
    paddr_t pageDir;
    MemorySegment* firstSegment;
    AddressSpace* next;
public:
    static void initialize();
private:
    static AddressSpace _kernelSpace;
};

// Global variable for the kernel's address space
extern AddressSpace* kernelSpace;

#endif
