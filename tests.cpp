#include "base64.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string_view>

TEST_CASE("base64") {
    constexpr std::string_view in =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
        "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut e"
        "nim ad minim veniam, quis nostrud exercitation ullamco laboris n"
        "isi ut aliquip ex ea commodo consequat. Duis aute irure dolor in"
        " reprehenderit in voluptate velit esse cillum dolore eu fugiat n"
        "ulla pariatur. Excepteur sint occaecat cupidatat non proident, s"
        "unt in culpa qui officia deserunt mollit anim id est laborum.";
    constexpr std::string_view out =
        "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2Np"
        "bmcgZWxpdCwgc2VkIGRvIGVpdXNtb2QgdGVtcG9yIGluY2lkaWR1bnQgdXQgbGFi"
        "b3JlIGV0IGRvbG9yZSBtYWduYSBhbGlxdWEuIFV0IGVuaW0gYWQgbWluaW0gdmVu"
        "aWFtLCBxdWlzIG5vc3RydWQgZXhlcmNpdGF0aW9uIHVsbGFtY28gbGFib3JpcyBu"
        "aXNpIHV0IGFsaXF1aXAgZXggZWEgY29tbW9kbyBjb25zZXF1YXQuIER1aXMgYXV0"
        "ZSBpcnVyZSBkb2xvciBpbiByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0ZSB2ZWxp"
        "dCBlc3NlIGNpbGx1bSBkb2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlhdHVyLiBF"
        "eGNlcHRldXIgc2ludCBvY2NhZWNhdCBjdXBpZGF0YXQgbm9uIHByb2lkZW50LCBz"
        "dW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2VydW50IG1vbGxpdCBhbmltIGlk"
        "IGVzdCBsYWJvcnVtLg==";
    static_assert(std::string_view("A").size() == 1);

    CHECK(to_base64("") == "");
    CHECK(to_base64("A") == "QQ==");
    CHECK(to_base64("AA") == "QUE=");
    CHECK(to_base64("AAA") == "QUFB");
    CHECK(to_base64("AAAA") == "QUFBQQ==");
    CHECK(to_base64("AAAAA") == "QUFBQUE=");
    CHECK(to_base64("<<?!?>>") == "PDw/IT8+Pg==");
    CHECK(to_base64(in) == out);
    CHECK(to_base64(in.data(), in.size()) == out);

    CHECK(from_base64("") == "");
    CHECK(from_base64("QQ==") == "A");
    CHECK(from_base64("QUE=") == "AA");
    CHECK(from_base64("QUFB") == "AAA");
    CHECK(from_base64("QUFBQQ==") == "AAAA");
    CHECK(from_base64("QUFBQUE=") == "AAAAA");
    CHECK(from_base64("PDw/IT8+Pg==") == "<<?!?>>");
    CHECK(from_base64(out) == in);
    CHECK(from_base64(out.data(), out.size()) == in);

    // base64url
    CHECK(from_base64("PDw_IT8-Pg==") == "<<?!?>>");

    {
        std::string s {out};
        from_base64_inplace(s);
        CHECK(s == in);
    }
    {
        std::string s {out};
        const auto len = from_base64_inplace(s.data(), s.size());
        s.resize(len);
        CHECK(s == in);
    }

    char buf[10];
    CHECK(from_base64(out.data(), out.size(), buf, sizeof(buf)) != -1);

    // Invalid input can result in
    // invalid output, but never UB
    CHECK(from_base64("!@#$") .size() != -1);
    CHECK(from_base64("!====").size() != -1);
    CHECK(from_base64("=AAA") .size() != -1);
    CHECK(from_base64("AA=A") .size() != -1);
    CHECK(from_base64("A==A") .size() != -1);
    CHECK(from_base64("=A==") .size() != -1);
    CHECK(from_base64("=A===").size() != -1);
    CHECK(from_base64("=")    .size() != -1);
    CHECK(from_base64("==")   .size() != -1);
    CHECK(from_base64("===")  .size() != -1);
    CHECK(from_base64("====") .size() != -1);
    CHECK(from_base64("A===") .size() != -1);
    CHECK(from_base64("!===") .size() != -1);
    CHECK(from_base64("====!").size() != -1);
}
