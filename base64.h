#pragma once
#include <cstdint>
#include <string>
#include <string_view>

[[nodiscard]] inline std::string to_base64(std::string_view data);
[[nodiscard]] inline std::string to_base64(const void* data, size_t size_bytes);

inline void from_base64_inplace(std::string& data);
[[nodiscard]] inline std::string from_base64(const void* data, size_t size_bytes);
[[nodiscard]] inline std::string from_base64(std::string_view data);

static constexpr uint8_t base64_lut[256][7] = {
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xf8\x03\xe0\x0f\x80\x3e",
    "\xff\xff\xff\xff\xff\xff", "\xf8\x03\xe0\x0f\x80\x3e", "\xff\xff\xff\xff\xff\xff", "\xfc\x03\xf0\x0f\xc0\x3f",
    "\xd0\x03\x40\x0d\x00\x34", "\xd4\x03\x50\x0d\x40\x35", "\xd8\x03\x60\x0d\x80\x36", "\xdc\x03\x70\x0d\xc0\x37",
    "\xe0\x03\x80\x0e\x00\x38", "\xe4\x03\x90\x0e\x40\x39", "\xe8\x03\xa0\x0e\x80\x3a", "\xec\x03\xb0\x0e\xc0\x3b",
    "\xf0\x03\xc0\x0f\x00\x3c", "\xf4\x03\xd0\x0f\x40\x3d", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\x00\x00\x00\x00\x00\x00", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\x00\x00\x00\x00\x00\x00", "\x04\x00\x10\x00\x40\x01", "\x08\x00\x20\x00\x80\x02",
    "\x0c\x00\x30\x00\xc0\x03", "\x10\x00\x40\x01\x00\x04", "\x14\x00\x50\x01\x40\x05", "\x18\x00\x60\x01\x80\x06",
    "\x1c\x00\x70\x01\xc0\x07", "\x20\x00\x80\x02\x00\x08", "\x24\x00\x90\x02\x40\x09", "\x28\x00\xa0\x02\x80\x0a",
    "\x2c\x00\xb0\x02\xc0\x0b", "\x30\x00\xc0\x03\x00\x0c", "\x34\x00\xd0\x03\x40\x0d", "\x38\x00\xe0\x03\x80\x0e",
    "\x3c\x00\xf0\x03\xc0\x0f", "\x40\x01\x00\x04\x00\x10", "\x44\x01\x10\x04\x40\x11", "\x48\x01\x20\x04\x80\x12",
    "\x4c\x01\x30\x04\xc0\x13", "\x50\x01\x40\x05\x00\x14", "\x54\x01\x50\x05\x40\x15", "\x58\x01\x60\x05\x80\x16",
    "\x5c\x01\x70\x05\xc0\x17", "\x60\x01\x80\x06\x00\x18", "\x64\x01\x90\x06\x40\x19", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xfc\x03\xf0\x0f\xc0\x3f",
    "\xff\xff\xff\xff\xff\xff", "\x68\x01\xa0\x06\x80\x1a", "\x6c\x01\xb0\x06\xc0\x1b", "\x70\x01\xc0\x07\x00\x1c",
    "\x74\x01\xd0\x07\x40\x1d", "\x78\x01\xe0\x07\x80\x1e", "\x7c\x01\xf0\x07\xc0\x1f", "\x80\x02\x00\x08\x00\x20",
    "\x84\x02\x10\x08\x40\x21", "\x88\x02\x20\x08\x80\x22", "\x8c\x02\x30\x08\xc0\x23", "\x90\x02\x40\x09\x00\x24",
    "\x94\x02\x50\x09\x40\x25", "\x98\x02\x60\x09\x80\x26", "\x9c\x02\x70\x09\xc0\x27", "\xa0\x02\x80\x0a\x00\x28",
    "\xa4\x02\x90\x0a\x40\x29", "\xa8\x02\xa0\x0a\x80\x2a", "\xac\x02\xb0\x0a\xc0\x2b", "\xb0\x02\xc0\x0b\x00\x2c",
    "\xb4\x02\xd0\x0b\x40\x2d", "\xb8\x02\xe0\x0b\x80\x2e", "\xbc\x02\xf0\x0b\xc0\x2f", "\xc0\x03\x00\x0c\x00\x30",
    "\xc4\x03\x10\x0c\x40\x31", "\xc8\x03\x20\x0c\x80\x32", "\xcc\x03\x30\x0c\xc0\x33", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
    "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff", "\xff\xff\xff\xff\xff\xff",
};

[[nodiscard]] inline std::string to_base64(std::string_view data) {
    constexpr std::string_view a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const std::basic_string_view<uint8_t> s { reinterpret_cast<const uint8_t*>(data.data()), data.size() };
    std::string ret;
    const ssize_t origLen = s.size();
    const ssize_t newLen = (origLen / 3 + (origLen%3!=0)) * 4;
    ret.resize(newLen, '=');

    ssize_t i; // Signed because (origLen - 2) can underflow
    for (i = 0; i < origLen - 2; i += 3) {
        ret[i / 3 * 4 + 0] = a[ (s[i] & 0b11111100) >> 2 ];
        ret[i / 3 * 4 + 1] = a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        ret[i / 3 * 4 + 2] = a[ (s[i+1] & 0b00001111) << 2 | (s[i+2] & 0b11000000) >> 6 ];
        ret[i / 3 * 4 + 3] = a[ (s[i+2] & 0b00111111) ];
    }
    switch (origLen % 3) {
    case 2:
        ret[i / 3 * 4 + 0] = a[ (s[i] & 0b11111100) >> 2 ];
        ret[i / 3 * 4 + 1] = a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        ret[i / 3 * 4 + 2] = a[ (s[i+1] & 0b00001111) << 2 | (s[i+2] & 0b11000000) >> 6 ];
        break;
    case 1:
        ret[i / 3 * 4 + 0] = a[ (s[i] & 0b11111100) >> 2 ];
        ret[i / 3 * 4 + 1] = a[ (s[i+0] & 0b00000011) << 4 | (s[i+1] & 0b11110000) >> 4 ];
        break;
    }
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

    size_t outLen = newLen;
    uint8_t* out = reinterpret_cast<uint8_t*>(dst);

    for (size_t i = 0; i < origLen; i += 4) {
        out[i / 4 * 3 + 0] = base64_lut[data[i+0]][0] | base64_lut[data[i+1]][1];
        out[i / 4 * 3 + 1] = base64_lut[data[i+1]][2] | base64_lut[data[i+2]][3];
        out[i / 4 * 3 + 2] = base64_lut[data[i+2]][4] | base64_lut[data[i+3]][5];
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
