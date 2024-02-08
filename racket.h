#ifndef RACKET_H_
#define RACKET_H_

#define PARENS ()

#define EXPAND(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...)                                    \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                         \
  macro(a1)                                                     \
  __VA_OPT__(, FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define ⁣ ,
#define ​(b) fun(b);
#define ‌(b) return fun(b);
#define MAKE_AUTO(arg) auto arg
#define fun(a, ...) a(__VA_ARGS__)
#define define(x, value) auto x = value;
#define GET_ARGS(...) __VA_ARGS__
#define λ(args, body) [](FOR_EACH(MAKE_AUTO, GET_ARGS args)) {return body;};
#define lambda(args, body) [](FOR_EACH(MAKE_AUTO, GET_ARGS args)) {return body;};

#endif
