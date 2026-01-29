#include "data_lab.hpp"
#include <cstdint>

namespace data_lab {

int32_t add(int32_t a, int32_t b) {

    // separate the addition process into 2 parts: sum without carry （using ^）and carry part (using & and <<)
    int32_t carry; // the carry part of addition

    carry = static_cast<uint32_t>(a & b) << 1; 
    a = a ^ b; 
    b = carry;
    
    // repeat the process until there is no carry 
    // int32_t has 32 bits, so we unroll the loop 32 times considering the worst condition (32 consecutive carries)
    
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    
    return a;
}

// subtract：（a - b = a + (-b) = a + (~b + 1)）
int32_t subtract(int32_t a, int32_t b) {
    
    return add(a, add(~b, 1));
}

int32_t multiply(int32_t a, int32_t b) {
    
    int32_t sign_a = static_cast<uint32_t>(a) >> 31;
    int32_t sign_b = static_cast<uint32_t>(b) >> 31;
    int32_t sign_result = sign_a ^ sign_b;
    
    uint32_t abs_a = a;
    uint32_t abs_b = b;
    
    if (sign_a) {
        abs_a = add(~a, 1);
    }
    if (sign_b) {
        abs_b = add(~b, 1);
    }
    
    uint32_t result = 0;
    for (int32_t i = 0; i < 32; i++) {
        if ((abs_b >> i) & 1) {
            result = add(result, abs_a << i);
        }
    }
    
    if (sign_result) {
        return add(~result, 1);
    }
    return result;
}

int32_t divide(int32_t a, int32_t b) {
    
    int32_t sign_a = static_cast<uint32_t>(a) >> 31;
    int32_t sign_b = static_cast<uint32_t>(b) >> 31;
    int32_t sign_result = sign_a ^ sign_b;
    
    uint32_t dividend = a;
    uint32_t divisor = b;
    if (sign_a) {
        dividend = add(~a, 1);
    }
    if (sign_b) {
        divisor = add(~b, 1);
    }
    
    uint32_t quotient = 0;
    uint32_t remainder = 0;
    
    // divide algorithm with the help of AI 
    for (int32_t i = 31; i >= 0; i--) {
        // left shift remainder and bring down the next bit of dividend
        remainder = remainder << 1;
        remainder = remainder | ((dividend >> i) & 1);
        
        // judge whether remainder >= divisor
        uint32_t diff = subtract(remainder, divisor);
        int32_t not_negative = !(static_cast<uint32_t>(diff) >> 31);
        
        if (not_negative) {
            remainder = diff;
            quotient = quotient | (1U << i);
        }
    }
    
    if (sign_result) {
        return add(~quotient, 1);
    }
    return quotient;
}

// a % b = a - (a / b) * b
int32_t modulo(int32_t a, int32_t b) {
    int32_t quotient = divide(a, b);
    int32_t product = multiply(quotient, b);
    return subtract(a, product);
}

}  