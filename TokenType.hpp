#pragma once

namespace Parsing {
    enum class TokenType {
        NUMBER,

        WORD,

        PRINT,

        PLUS,
        MINUS,
        STAR,
        SLASH,

        LPAREN, // (
        RPAREN, // )
        
        SET,

        FILEEND
    };
}
