#include <ruby.h>
#include <ruby/encoding.h>
#include "generator.hpp"

#if SIZEOF_VALUE < SIZEOF_VOIDP
#error SIZEOF_VOIDP must not be greater than SIZEOF_VALUE.
#endif

rb_encoding *utf8;
int utf8index;
ID id_to_s, id_to_f, id_to_time, id_generate, id_Time, id_Date, id_DateTime, id_Value;
VALUE rb_mUsamin, rb_mUsaminJs, rb_eUsaminJsError;
VALUE utf8value, sym_indent, sym_single_line_array, sym_symbolize_names;
VALUE rb_cUsaminValue, rb_cTime, rb_cDate, rb_cDateTime;

extern "C" {
void __attribute__((visibility("default"))) Init_usamin_js() {
    utf8 = rb_utf8_encoding();
    utf8index = rb_enc_to_index(utf8);
    utf8value = rb_enc_from_encoding(utf8);
    sym_indent = rb_id2sym(rb_intern("indent"));
    sym_single_line_array = rb_id2sym(rb_intern("single_line_array"));
    sym_symbolize_names = rb_id2sym(rb_intern("symbolize_names"));
    id_to_s = rb_intern("to_s");
    id_to_f = rb_intern("to_f");
    id_to_time = rb_intern("to_time");
    id_generate = rb_intern("generate");
    id_Time = rb_intern("Time");
    id_Date = rb_intern("Date");
    id_DateTime = rb_intern("DateTime");
    id_Value = rb_intern("Value");

    rb_mUsamin = rb_define_module("Usamin");
    rb_mUsaminJs = rb_define_module_under(rb_mUsamin, "Js");
    rb_define_module_function(rb_mUsaminJs, "generate", RUBY_METHOD_FUNC(w_generate), 1);
    rb_define_module_function(rb_mUsaminJs, "pretty_generate", RUBY_METHOD_FUNC(w_pretty_generate), -1);

    rb_eUsaminJsError = rb_define_class_under(rb_mUsaminJs, "UsaminJsError", rb_eStandardError);
}
}
