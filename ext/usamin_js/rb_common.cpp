#include <ruby.h>
#include <ruby/encoding.h>

VALUE get_utf8_str(VALUE str) {
    extern int utf8index;
    extern VALUE utf8value;
    extern rb_encoding *utf8;

    Check_Type(str, T_STRING);
    int encoding = rb_enc_get_index(str);
    if (encoding == utf8index || rb_enc_compatible(str, utf8value) == utf8)
        return str;
    else
        return rb_str_conv_enc(str, rb_enc_from_index(encoding), utf8);
}

VALUE new_utf8_str(const char *cstr, const long len) {
    extern int utf8index;
    VALUE ret = rb_str_new(cstr, len);
    rb_enc_set_index(ret, utf8index);
    return ret;
}
