#ifndef USAMIN_RB_COMMON_HPP
#define USAMIN_RB_COMMON_HPP

#include <ruby.h>

VALUE get_utf8_str(VALUE str);
VALUE new_utf8_str(const char *cstr, const long len);

#endif
