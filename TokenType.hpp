#pragma once

namespace Parsing {
    enum class TokenType {
        NUMBER,
        HEX_NUMBER,

        PLUS,
        MINUS,
        STAR,
        SLASH,

        LPAREN, // (
        RPAREN, // )

        FILEEND
    };
}
