#include "racket.h"

int main() {
    ​(define ⁣ real_main ⁣ ​(λ ⁣ (a ⁣ b ⁣ c) ⁣ (a + b)))
    ​(define ⁣ make_thing ⁣ ​(λ ⁣ (a ⁣ b ⁣ c) ⁣ a))
    ​(define ⁣ make_thing2 ⁣ ​(λ ⁣ (a ⁣ b ⁣ c) ⁣ ​(make_thing ⁣ c ⁣ b ⁣ a)))
    ‌(real_main ⁣ 3 ⁣ 4 ⁣ 5)
    ‌(real_main ⁣ 3 ⁣ 8 ⁣ 5)
    ‌(make_thing ⁣ "test" ⁣ 8 ⁣ 5)
    ‌(make_thing2 ⁣ 1 ⁣ 8 ⁣ 5)
}
