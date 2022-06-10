#pragma once
#include <cstdint>
#include <string>
#include <string_view>

static constexpr std::string_view base64_lut1[256] = {
    "AAAA", "AQEB", "AgIC", "AwMD", "BAQE", "BQUF", "BgYG", "BwcH", "CAgI", "CQkJ", "CgoK", "CwsL", "DAwM", "DQ0N", "Dg4O", "Dw8P",
    "EBAQ", "ERER", "EhIS", "ExMT", "FBQU", "FRUV", "FhYW", "FxcX", "GBgY", "GRkZ", "Ghoa", "Gxsb", "HBwc", "HR0d", "Hh4e", "Hx8f",
    "ICAg", "ISEh", "IiIi", "IyMj", "JCQk", "JSUl", "JiYm", "Jycn", "KCgo", "KSkp", "Kioq", "Kysr", "LCws", "LS0t", "Li4u", "Ly8v",
    "MDAw", "MTEx", "MjIy", "MzMz", "NDQ0", "NTU1", "NjY2", "Nzc3", "ODg4", "OTk5", "Ojo6", "Ozs7", "PDw8", "PT09", "Pj4+", "Pz8/",
    "QEBA", "QUFB", "QkJC", "Q0ND", "RERE", "RUVF", "RkZG", "R0dH", "SEhI", "SUlJ", "SkpK", "S0tL", "TExM", "TU1N", "Tk5O", "T09P",
    "UFBQ", "UVFR", "UlJS", "U1NT", "VFRU", "VVVV", "VlZW", "V1dX", "WFhY", "WVlZ", "Wlpa", "W1tb", "XFxc", "XV1d", "Xl5e", "X19f",
    "YGBg", "YWFh", "YmJi", "Y2Nj", "ZGRk", "ZWVl", "ZmZm", "Z2dn", "aGho", "aWlp", "ampq", "a2tr", "bGxs", "bW1t", "bm5u", "b29v",
    "cHBw", "cXFx", "cnJy", "c3Nz", "dHR0", "dXV1", "dnZ2", "d3d3", "eHh4", "eXl5", "enp6", "e3t7", "fHx8", "fX19", "fn5+", "f39/",
    "gICA", "gYGB", "goKC", "g4OD", "hISE", "hYWF", "hoaG", "h4eH", "iIiI", "iYmJ", "ioqK", "i4uL", "jIyM", "jY2N", "jo6O", "j4+P",
    "kJCQ", "kZGR", "kpKS", "k5OT", "lJSU", "lZWV", "lpaW", "l5eX", "mJiY", "mZmZ", "mpqa", "m5ub", "nJyc", "nZ2d", "np6e", "n5+f",
    "oKCg", "oaGh", "oqKi", "o6Oj", "pKSk", "paWl", "pqam", "p6en", "qKio", "qamp", "qqqq", "q6ur", "rKys", "ra2t", "rq6u", "r6+v",
    "sLCw", "sbGx", "srKy", "s7Oz", "tLS0", "tbW1", "tra2", "t7e3", "uLi4", "ubm5", "urq6", "u7u7", "vLy8", "vb29", "vr6+", "v7+/",
    "wMDA", "wcHB", "wsLC", "w8PD", "xMTE", "xcXF", "xsbG", "x8fH", "yMjI", "ycnJ", "ysrK", "y8vL", "zMzM", "zc3N", "zs7O", "z8/P",
    "0NDQ", "0dHR", "0tLS", "09PT", "1NTU", "1dXV", "1tbW", "19fX", "2NjY", "2dnZ", "2tra", "29vb", "3Nzc", "3d3d", "3t7e", "39/f",
    "4ODg", "4eHh", "4uLi", "4+Pj", "5OTk", "5eXl", "5ubm", "5+fn", "6Ojo", "6enp", "6urq", "6+vr", "7Ozs", "7e3t", "7u7u", "7+/v",
    "8PDw", "8fHx", "8vLy", "8/Pz", "9PT0", "9fX1", "9vb2", "9/f3", "+Pj4", "+fn5", "+vr6", "+/v7", "/Pz8", "/f39", "/v7+", "////",
};

static constexpr uint8_t base64_lut2[256][6] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0xf8, 0x03, 0xe0, 0x0f, 0x80, 0x3e, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0xfc, 0x03, 0xf0, 0x0f, 0xc0, 0x3f, },
    { 0xd0, 0x03, 0x40, 0x0d, 0x00, 0x34, }, { 0xd4, 0x03, 0x50, 0x0d, 0x40, 0x35, }, { 0xd8, 0x03, 0x60, 0x0d, 0x80, 0x36, }, { 0xdc, 0x03, 0x70, 0x0d, 0xc0, 0x37, }, { 0xe0, 0x03, 0x80, 0x0e, 0x00, 0x38, }, { 0xe4, 0x03, 0x90, 0x0e, 0x40, 0x39, }, { 0xe8, 0x03, 0xa0, 0x0e, 0x80, 0x3a, }, { 0xec, 0x03, 0xb0, 0x0e, 0xc0, 0x3b, },
    { 0xf0, 0x03, 0xc0, 0x0f, 0x00, 0x3c, }, { 0xf4, 0x03, 0xd0, 0x0f, 0x40, 0x3d, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x04, 0x00, 0x10, 0x00, 0x40, 0x01, }, { 0x08, 0x00, 0x20, 0x00, 0x80, 0x02, }, { 0x0c, 0x00, 0x30, 0x00, 0xc0, 0x03, }, { 0x10, 0x00, 0x40, 0x01, 0x00, 0x04, }, { 0x14, 0x00, 0x50, 0x01, 0x40, 0x05, }, { 0x18, 0x00, 0x60, 0x01, 0x80, 0x06, },
    { 0x1c, 0x00, 0x70, 0x01, 0xc0, 0x07, }, { 0x20, 0x00, 0x80, 0x02, 0x00, 0x08, }, { 0x24, 0x00, 0x90, 0x02, 0x40, 0x09, }, { 0x28, 0x00, 0xa0, 0x02, 0x80, 0x0a, }, { 0x2c, 0x00, 0xb0, 0x02, 0xc0, 0x0b, }, { 0x30, 0x00, 0xc0, 0x03, 0x00, 0x0c, }, { 0x34, 0x00, 0xd0, 0x03, 0x40, 0x0d, }, { 0x38, 0x00, 0xe0, 0x03, 0x80, 0x0e, },
    { 0x3c, 0x00, 0xf0, 0x03, 0xc0, 0x0f, }, { 0x40, 0x01, 0x00, 0x04, 0x00, 0x10, }, { 0x44, 0x01, 0x10, 0x04, 0x40, 0x11, }, { 0x48, 0x01, 0x20, 0x04, 0x80, 0x12, }, { 0x4c, 0x01, 0x30, 0x04, 0xc0, 0x13, }, { 0x50, 0x01, 0x40, 0x05, 0x00, 0x14, }, { 0x54, 0x01, 0x50, 0x05, 0x40, 0x15, }, { 0x58, 0x01, 0x60, 0x05, 0x80, 0x16, },
    { 0x5c, 0x01, 0x70, 0x05, 0xc0, 0x17, }, { 0x60, 0x01, 0x80, 0x06, 0x00, 0x18, }, { 0x64, 0x01, 0x90, 0x06, 0x40, 0x19, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x68, 0x01, 0xa0, 0x06, 0x80, 0x1a, }, { 0x6c, 0x01, 0xb0, 0x06, 0xc0, 0x1b, }, { 0x70, 0x01, 0xc0, 0x07, 0x00, 0x1c, }, { 0x74, 0x01, 0xd0, 0x07, 0x40, 0x1d, }, { 0x78, 0x01, 0xe0, 0x07, 0x80, 0x1e, }, { 0x7c, 0x01, 0xf0, 0x07, 0xc0, 0x1f, }, { 0x80, 0x02, 0x00, 0x08, 0x00, 0x20, },
    { 0x84, 0x02, 0x10, 0x08, 0x40, 0x21, }, { 0x88, 0x02, 0x20, 0x08, 0x80, 0x22, }, { 0x8c, 0x02, 0x30, 0x08, 0xc0, 0x23, }, { 0x90, 0x02, 0x40, 0x09, 0x00, 0x24, }, { 0x94, 0x02, 0x50, 0x09, 0x40, 0x25, }, { 0x98, 0x02, 0x60, 0x09, 0x80, 0x26, }, { 0x9c, 0x02, 0x70, 0x09, 0xc0, 0x27, }, { 0xa0, 0x02, 0x80, 0x0a, 0x00, 0x28, },
    { 0xa4, 0x02, 0x90, 0x0a, 0x40, 0x29, }, { 0xa8, 0x02, 0xa0, 0x0a, 0x80, 0x2a, }, { 0xac, 0x02, 0xb0, 0x0a, 0xc0, 0x2b, }, { 0xb0, 0x02, 0xc0, 0x0b, 0x00, 0x2c, }, { 0xb4, 0x02, 0xd0, 0x0b, 0x40, 0x2d, }, { 0xb8, 0x02, 0xe0, 0x0b, 0x80, 0x2e, }, { 0xbc, 0x02, 0xf0, 0x0b, 0xc0, 0x2f, }, { 0xc0, 0x03, 0x00, 0x0c, 0x00, 0x30, },
    { 0xc4, 0x03, 0x10, 0x0c, 0x40, 0x31, }, { 0xc8, 0x03, 0x20, 0x0c, 0x80, 0x32, }, { 0xcc, 0x03, 0x30, 0x0c, 0xc0, 0x33, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, }, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
};

[[nodiscard]] inline std::string to_base64(std::string_view data) {
    const std::basic_string_view<uint8_t> s { reinterpret_cast<const uint8_t*>(data.data()), data.size() };
    std::string ret;
    const ssize_t origLen = s.size();
    const ssize_t newLen = (origLen / 3 + (origLen%3!=0)) * 4;
    ret.reserve(newLen);

    ssize_t i;
    for (i = 0; i < origLen - 2; i += 3) {
        ret += base64_lut1[  s[i]                                         ][0];
        ret += base64_lut1[ (s[i+0] & 0b00000011) | (s[i+1] & 0b11110000) ][1];
        ret += base64_lut1[ (s[i+1] & 0b00001111) | (s[i+2] & 0b11000000) ][2];
        ret += base64_lut1[  s[i+2]                                       ][3];
    }
    switch (origLen % 3) {
    case 2:
        ret += base64_lut1[  s[i]                                         ][0];
        ret += base64_lut1[ (s[i+0] & 0b00000011) | (s[i+1] & 0b11110000) ][1];
        ret += base64_lut1[  s[i+1] & 0b00001111                          ][2];
        break;
    case 1:
        ret += base64_lut1[  s[i]                                         ][0];
        ret += base64_lut1[  s[i+0] & 0b00000011                          ][1];
        break;
    }
    ret.resize(newLen, '=');
    return ret;
}

[[nodiscard]] inline std::string from_base64(std::string_view data) {
    const std::basic_string_view<uint8_t> s { reinterpret_cast<const uint8_t*>(data.data()), data.size() };
    std::string ret;
    const ssize_t origLen = s.size();
    if (origLen % 4 != 0) {
        return std::string();
    }
    const ssize_t newLen = origLen / 4 * 3;
    ret.reserve(newLen);

    ssize_t i;
    for (i = 0; i < origLen; i += 4) {
        ret += base64_lut2[s[i+0]][0] | base64_lut2[s[i+1]][1];
        ret += base64_lut2[s[i+1]][2] | base64_lut2[s[i+2]][3];
        ret += base64_lut2[s[i+2]][4] | base64_lut2[s[i+3]][5];
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == '=') {
            ret.pop_back();
        } else {
            break;
        }
    }
    return ret;
}

// [[nodiscard]] inline std::string from_base64_check(std::string_view data) {
//     const std::basic_string_view<uint8_t> s { reinterpret_cast<const uint8_t*>(data.data()), data.size() };
//     std::string ret;
//     const ssize_t origLen = s.size();
//     if (origLen % 4 != 0) {
//         return std::string();
//     }
//     const ssize_t newLen = origLen / 4 * 3;
//     ret.reserve(newLen);
//
//     ssize_t i;
//     for (i = 0; i < origLen; i += 4) {
//         const uint8_t b[6] = {
//             lut_from[s[i+0]][0],
//             lut_from[s[i+1]][1],
//             lut_from[s[i+1]][2],
//             lut_from[s[i+2]][3],
//             lut_from[s[i+2]][4],
//             lut_from[s[i+3]][5],
//         };
//         if (
//             b[0] == 0xff ||
//             b[1] == 0xff ||
//             b[3] == 0xff ||
//             b[5] == 0xff
//         ) {
//             return std::string();
//         }
//         ret += b[0] | b[1];
//         ret += b[2] | b[3];
//         ret += b[4] | b[5];
//     }
//     size_t padLen = 0;
//     for (auto it = s.rbegin(); it != s.rend(); ++it) {
//         if (*it == '=') {
//             padLen++;
//             if (padLen > 2) {
//                 return std::string();
//             }
//             ret.pop_back();
//         } else {
//             break;
//         }
//     }
//     return ret;
// }