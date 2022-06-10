#include <cstdint>
#include <string_view>
#include <string>
#include <array>
#include <iostream>

// Could be consteval in c++20
static void lut_to() {
    constexpr std::string_view a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    static_assert(a.size() == 64);

    std::array<std::array<uint8_t, 4>, 256> t;
    for (int i = 0; i < 256; i++) {
        t[i][0] = a[i >> 2];
        t[i][1] = a[(i & 0b00000011) << 4 | (i & 0b11110000) >> 4];
        t[i][2] = a[(i & 0b00001111) << 2 | (i & 0b11000000) >> 6];
        t[i][3] = a[i & 0b00111111];
    }
    for (auto e : t) {
        std::cout << "\"" << e.data() << "\",\n";
    }
}

// Could be consteval in c++20
static void lut_from() {
    constexpr std::string_view a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    static_assert(a.size() == 64);

    std::array<std::array<uint8_t, 6>, 256> t;
    for (int ch = 0; ch < 256; ch++) {
        auto val = a.find(ch);
        if (val != a.npos) {
            t[ch][0] = (uint8_t) val << 2;
            t[ch][1] = (uint8_t) val >> 4;
            t[ch][2] = (uint8_t) val << 4;
            t[ch][3] = (uint8_t) val >> 2;
            t[ch][4] = (uint8_t) val << 6;
            t[ch][5] = (uint8_t) val;
        } else {
            // val is always less than 64
            // bit shifted val will never have all bits on
            // so 0xff can be used as an error value
            if (ch == '=') {
                val = 0x00;
            } else {
                val = 0xff;
            }
            t[ch][0] = (uint8_t) val;
            t[ch][1] = (uint8_t) val;
            t[ch][2] = (uint8_t) val;
            t[ch][3] = (uint8_t) val;
            t[ch][4] = (uint8_t) val;
            t[ch][5] = (uint8_t) val;
        }
    }
    for (auto e : t) {
        std::cout << "{ ";
        for (auto v : e) {
            std::cout << "0x" << std::hex << (int) v << ", ";
        }
        std::cout << "},\n";
    }
}

int main() {
    lut_from();
    lut_to();
}
