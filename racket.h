#ifndef RACKET_H_
#define RACKET_H_

#include <iostream>
#include <concepts>
#include <cstdint>
#include <cxxabi.h>
#include <vector>

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

template <typename T> 
concept Streamable = requires (T x) { std::cout << x; };

template<Streamable T>
void general_print(T arg) {
    std::cout << arg << std::endl;
}

template<typename T>
typename std::enable_if<!Streamable<T>, void>::type general_print(T& arg) {
    char *realname;
    const std::type_info &ti = typeid(arg);
    realname = abi::__cxa_demangle(ti.name(), NULL, NULL, NULL);
    std::cout << realname <<  " at 0x" << (uint64_t)&arg << std::endl;
    std::free(realname);
}

template<typename T>
typename std::enable_if<!Streamable<T>, void>::type general_print(T&& arg) {
    char *realname;
    const std::type_info &ti = typeid(arg);
    realname = abi::__cxa_demangle(ti.name(), NULL, NULL, NULL);
    std::cout << realname <<  " at 0x" << (uint64_t)&arg << std::endl;
    std::free(realname);
}

#define ⁣ ,
#define ​(b) fun(b);
#define ‌(b) general_print(fun(b));
#define MAKE_AUTO(arg) auto arg
#define fun(a, ...) a(__VA_ARGS__)
#define define(x, value) auto x = value;
#define GET_ARGS(...) __VA_ARGS__
#define lambda(args, body) [&](FOR_EACH(MAKE_AUTO, GET_ARGS args)) {return body;};
#define λ lambda
#define ⁡ int main() {
#define ⁢ }

#endif
