#include <cstdint>
#include <string_view>
#include <string>
#include <array>
#include <iostream>

// Could be consteval in c++20
static void lut_from() {
    constexpr std::string_view a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    static_assert(a.size() == 64);

    std::array<std::array<uint8_t, 6>, 256> t;
    for (int ch = 0; ch < 256; ch++) {
        auto val = a.find(ch);
        // Support for base64url
        if (ch == '-') { val = 62; }
        if (ch == '_') { val = 63; }
        if (val != a.npos) {
            t[ch][0] = (uint8_t) val << 2;
            t[ch][1] = (uint8_t) val >> 4;
            t[ch][2] = (uint8_t) val << 4;
            t[ch][3] = (uint8_t) val >> 2;
            t[ch][4] = (uint8_t) val << 6;
            t[ch][5] = (uint8_t) val;
        } else {
            // val is always less than 64.
            // Bit shifted val will never have all bits on,
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
        std::cout << "\"";
        for (auto v : e) {
            std::cout << "\\x" << std::hex << (int) v << "";
        }
        std::cout << "\",\n";
    }
}

int main() {
    lut_from();
}
