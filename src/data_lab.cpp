#include "data_lab.hpp"
#include <cstdint>

namespace data_lab {

//==============================================================================
// add: 加法（无控制流，循环展开32次）
//==============================================================================
int32_t add(int32_t a, int32_t b) {
    int32_t carry;
    
    // 展开32次迭代，处理最坏情况的进位传播
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
    carry = static_cast<uint32_t>(a & b) << 1; a = a ^ b; b = carry;
    
    return a;
}

//==============================================================================
// subtract: 减法（a - b = a + (~b + 1)）
//==============================================================================
int32_t subtract(int32_t a, int32_t b) {
    // 计算 -b = ~b + 1
    int32_t neg_b = ~b;
    int32_t one = 1;
    int32_t carry;
    
    // 展开32次：neg_b = neg_b + 1
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    carry = static_cast<uint32_t>(neg_b & one) << 1; neg_b = neg_b ^ one; one = carry;
    
    // 返回 a + (-b)
    return add(a, neg_b);
}

//==============================================================================
// multiply: 乘法（移位相加法）
//==============================================================================
int32_t multiply(int32_t a, int32_t b) {
    // 确定结果符号
    int32_t sign_a = static_cast<uint32_t>(a) >> 31;
    int32_t sign_b = static_cast<uint32_t>(b) >> 31;
    int32_t result_negative = sign_a ^ sign_b;
    
    // 取绝对值
    uint32_t abs_a = a;
    uint32_t abs_b = b;
    if (sign_a) {
        abs_a = subtract(0, a);
    }
    if (sign_b) {
        abs_b = subtract(0, b);
    }
    
    // 移位相加
    uint32_t result = 0;
    for (int32_t i = 0; i < 32; i = add(i, 1)) {
        if ((abs_b >> i) & 1) {
            result = add(result, abs_a << i);
        }
    }
    
    // 应用符号
    if (result_negative) {
        return subtract(0, result);
    }
    return result;
}

//==============================================================================
// divide: 除法（二进制长除法）
//==============================================================================
int32_t divide(int32_t a, int32_t b) {
    // 确定结果符号
    int32_t sign_a = static_cast<uint32_t>(a) >> 31;
    int32_t sign_b = static_cast<uint32_t>(b) >> 31;
    int32_t result_negative = sign_a ^ sign_b;
    
    // 取绝对值
    uint32_t dividend = a;
    uint32_t divisor = b;
    if (sign_a) {
        dividend = subtract(0, a);
    }
    if (sign_b) {
        divisor = subtract(0, b);
    }
    
    // 二进制长除法
    uint32_t quotient = 0;
    uint32_t remainder = 0;
    
    for (int32_t i = 31; i >= 0; i = subtract(i, 1)) {
        // 余数左移，加入被除数的当前位
        remainder = remainder << 1;
        remainder = remainder | ((dividend >> i) & 1);
        
        // 判断 remainder >= divisor
        uint32_t diff = subtract(remainder, divisor);
        int32_t not_negative = !(static_cast<uint32_t>(diff) >> 31);
        
        if (not_negative) {
            remainder = diff;
            quotient = quotient | (1U << i);
        }
    }
    
    // 应用符号
    if (result_negative) {
        return subtract(0, quotient);
    }
    return quotient;
}

//==============================================================================
// modulo: 取模（a % b = a - (a / b) * b）
//==============================================================================
int32_t modulo(int32_t a, int32_t b) {
    int32_t quotient = divide(a, b);
    int32_t product = multiply(quotient, b);
    return subtract(a, product);
}

}  // namespace data_lab