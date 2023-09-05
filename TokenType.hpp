#pragma once

namespace Parsing {
    enum class TokenType {
        NUMBER, //число

        WORD, //переменные

        PRINT, //оператор вывода

        PLUS,
        MINUS,
        STAR,
        SLASH,

        LPAREN, // (
        RPAREN, // )
        
        SET, //оператор присвоения значения переменной

        FILEEND //окончание файла
    };
}
