#pragma once
#include <cstdint>
#include <string>
#include <string_view>

static constexpr uint8_t base64_lut[256][6] = {
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xf8, 0x03, 0xe0, 0x0f, 0x80, 0x3e, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xf8, 0x03, 0xe0, 0x0f, 0x80, 0x3e, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xfc, 0x03, 0xf0, 0x0f, 0xc0, 0x3f, },
    { 0xd0, 0x03, 0x40, 0x0d, 0x00, 0x34, }, { 0xd4, 0x03, 0x50, 0x0d, 0x40, 0x35, }, { 0xd8, 0x03, 0x60, 0x0d, 0x80, 0x36, }, { 0xdc, 0x03, 0x70, 0x0d, 0xc0, 0x37, },
    { 0xe0, 0x03, 0x80, 0x0e, 0x00, 0x38, }, { 0xe4, 0x03, 0x90, 0x0e, 0x40, 0x39, }, { 0xe8, 0x03, 0xa0, 0x0e, 0x80, 0x3a, }, { 0xec, 0x03, 0xb0, 0x0e, 0xc0, 0x3b, },
    { 0xf0, 0x03, 0xc0, 0x0f, 0x00, 0x3c, }, { 0xf4, 0x03, 0xd0, 0x0f, 0x40, 0x3d, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x04, 0x00, 0x10, 0x00, 0x40, 0x01, }, { 0x08, 0x00, 0x20, 0x00, 0x80, 0x02, },
    { 0x0c, 0x00, 0x30, 0x00, 0xc0, 0x03, }, { 0x10, 0x00, 0x40, 0x01, 0x00, 0x04, }, { 0x14, 0x00, 0x50, 0x01, 0x40, 0x05, }, { 0x18, 0x00, 0x60, 0x01, 0x80, 0x06, },
    { 0x1c, 0x00, 0x70, 0x01, 0xc0, 0x07, }, { 0x20, 0x00, 0x80, 0x02, 0x00, 0x08, }, { 0x24, 0x00, 0x90, 0x02, 0x40, 0x09, }, { 0x28, 0x00, 0xa0, 0x02, 0x80, 0x0a, },
    { 0x2c, 0x00, 0xb0, 0x02, 0xc0, 0x0b, }, { 0x30, 0x00, 0xc0, 0x03, 0x00, 0x0c, }, { 0x34, 0x00, 0xd0, 0x03, 0x40, 0x0d, }, { 0x38, 0x00, 0xe0, 0x03, 0x80, 0x0e, },
    { 0x3c, 0x00, 0xf0, 0x03, 0xc0, 0x0f, }, { 0x40, 0x01, 0x00, 0x04, 0x00, 0x10, }, { 0x44, 0x01, 0x10, 0x04, 0x40, 0x11, }, { 0x48, 0x01, 0x20, 0x04, 0x80, 0x12, },
    { 0x4c, 0x01, 0x30, 0x04, 0xc0, 0x13, }, { 0x50, 0x01, 0x40, 0x05, 0x00, 0x14, }, { 0x54, 0x01, 0x50, 0x05, 0x40, 0x15, }, { 0x58, 0x01, 0x60, 0x05, 0x80, 0x16, },
    { 0x5c, 0x01, 0x70, 0x05, 0xc0, 0x17, }, { 0x60, 0x01, 0x80, 0x06, 0x00, 0x18, }, { 0x64, 0x01, 0x90, 0x06, 0x40, 0x19, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xfc, 0x03, 0xf0, 0x0f, 0xc0, 0x3f, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0x68, 0x01, 0xa0, 0x06, 0x80, 0x1a, }, { 0x6c, 0x01, 0xb0, 0x06, 0xc0, 0x1b, }, { 0x70, 0x01, 0xc0, 0x07, 0x00, 0x1c, },
    { 0x74, 0x01, 0xd0, 0x07, 0x40, 0x1d, }, { 0x78, 0x01, 0xe0, 0x07, 0x80, 0x1e, }, { 0x7c, 0x01, 0xf0, 0x07, 0xc0, 0x1f, }, { 0x80, 0x02, 0x00, 0x08, 0x00, 0x20, },
    { 0x84, 0x02, 0x10, 0x08, 0x40, 0x21, }, { 0x88, 0x02, 0x20, 0x08, 0x80, 0x22, }, { 0x8c, 0x02, 0x30, 0x08, 0xc0, 0x23, }, { 0x90, 0x02, 0x40, 0x09, 0x00, 0x24, },
    { 0x94, 0x02, 0x50, 0x09, 0x40, 0x25, }, { 0x98, 0x02, 0x60, 0x09, 0x80, 0x26, }, { 0x9c, 0x02, 0x70, 0x09, 0xc0, 0x27, }, { 0xa0, 0x02, 0x80, 0x0a, 0x00, 0x28, },
    { 0xa4, 0x02, 0x90, 0x0a, 0x40, 0x29, }, { 0xa8, 0x02, 0xa0, 0x0a, 0x80, 0x2a, }, { 0xac, 0x02, 0xb0, 0x0a, 0xc0, 0x2b, }, { 0xb0, 0x02, 0xc0, 0x0b, 0x00, 0x2c, },
    { 0xb4, 0x02, 0xd0, 0x0b, 0x40, 0x2d, }, { 0xb8, 0x02, 0xe0, 0x0b, 0x80, 0x2e, }, { 0xbc, 0x02, 0xf0, 0x0b, 0xc0, 0x2f, }, { 0xc0, 0x03, 0x00, 0x0c, 0x00, 0x30, },
    { 0xc4, 0x03, 0x10, 0x0c, 0x40, 0x31, }, { 0xc8, 0x03, 0x20, 0x0c, 0x80, 0x32, }, { 0xcc, 0x03, 0x30, 0x0c, 0xc0, 0x33, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
    { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }, { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, },
};

[[nodiscard]] inline std::string to_base64(std::string_view data) {
    constexpr std::string_view a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const std::basic_string_view<uint8_t> s { reinterpret_cast<const uint8_t*>(data.data()), data.size() };
    std::string ret;
    const ssize_t origLen = s.size();
    const ssize_t newLen = (origLen / 3 + (origLen%3!=0)) * 4;
    ret.reserve(newLen);

    ssize_t i; // Signed because (origLen - 2) can underflow
    for (i = 0; i < origLen - 2; i += 3) {
        ret += a[ (s[i] & 0b11111100) >> 2 ];
        ret += a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        ret += a[ (s[i+1] & 0b00001111) << 2 | (s[i+2] & 0b11000000) >> 6 ];
        ret += a[ (s[i+2] & 0b00111111) ];
    }
    switch (origLen % 3) {
    case 2:
        ret += a[ (s[i] & 0b11111100) >> 2 ];
        ret += a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        ret += a[ (s[i+1] & 0b00001111) << 2 | (s[i+2] & 0b11000000) >> 6 ];
        break;
    case 1:
        ret += a[ (s[i] & 0b11111100) >> 2 ];
        ret += a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        break;
    }
    ret.resize(newLen, '=');
    return ret;
}


[[nodiscard]] inline std::string to_base64(const void* data, size_t size_bytes) {
    return to_base64({ reinterpret_cast<const char*>(data), size_bytes });
}


/// dstLen must be at least (3/4 * srcLen), even if there's less data encoded
/// dst may be equal to src
inline size_t from_base64(const void* src, size_t srcLen, void* dst, size_t dstLen) {
    std::basic_string_view<uint8_t> data { reinterpret_cast<const uint8_t*>(src), srcLen };
    const size_t origLen = data.size();
    if (origLen == 0) {
        return 0;
    }
    if (origLen % 4 != 0) {
        return 0;
    }
    const size_t newLen = origLen / 4 * 3;
    if (dstLen < newLen) {
        return 0;
    }

    size_t outLen = 0;
    uint8_t* out = reinterpret_cast<uint8_t*>(dst);

    for (size_t i = 0; i < origLen; i += 4) {
        out[outLen++] = base64_lut[data[i+0]][0] | base64_lut[data[i+1]][1];
        out[outLen++] = base64_lut[data[i+1]][2] | base64_lut[data[i+2]][3];
        out[outLen++] = base64_lut[data[i+2]][4] | base64_lut[data[i+3]][5];
    }
    // Min possible data.size() is 4, so rbegin() + 3 <= rend()
    // Min outLen is 3, so outLen-- will never underflow
    for (auto it = data.rbegin(); it != data.rbegin() + 3; ++it) {
        if (*it == '=') {
            outLen--;
        } else {
            break;
        }
    }
    return outLen;
}

inline void from_base64_inplace(std::string& data) {
    auto newLen = from_base64(data.data(), data.size(), data.data(), data.size());
    data.resize(newLen);
}

[[nodiscard]] inline std::string from_base64(const void* data, size_t size_bytes) {
    std::string ret;
    ret.resize(size_bytes / 4 * 3);
    auto newLen = from_base64(data, size_bytes, ret.data(), ret.size());
    ret.resize(newLen);
    return ret;
}

[[nodiscard]] inline std::string from_base64(std::string_view data) {
    return from_base64(data.data(), data.size());
}
