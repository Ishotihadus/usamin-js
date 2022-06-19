#ifndef USAMIN_GENERATOR_HPP
#define USAMIN_GENERATOR_HPP

#include <ruby.h>

class RubyCrtAllocator {
public:
    static const bool kNeedFree = true;
    void *Malloc(size_t size);
    void *Realloc(void *originalPtr, size_t, size_t newSize);
    static void Free(void *ptr);
};

VALUE w_generate(const VALUE self, const VALUE value);
VALUE w_pretty_generate(const int argc, const VALUE *argv, const VALUE self);

#endif
