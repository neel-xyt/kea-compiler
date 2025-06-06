#pragma once

#include <string>
#include <ostream> // required for std::ostream

enum class TokenType {
    Identifier,
    Number,
    Equals,
    Plus,
    Minus,
    Star,
    Slash,
    LParen,
    RParen,
    Newline,
    Eof,
    Unknown
};

struct Token {
    TokenType type;
    std::string text;
    int line, column;

    Token(TokenType type, const std::string& text, int line, int column)
        : type(type), text(text), line(line), column(column) {}
};

inline const char* to_string(TokenType type) {
    switch (type) {
        case TokenType::Identifier: return "Identifier";
        case TokenType::Number:     return "Number";
        case TokenType::Equals:     return "Equals";
        case TokenType::Plus:       return "Plus";
        case TokenType::Minus:      return "Minus";
        case TokenType::Star:       return "Star";
        case TokenType::Slash:      return "Slash";
        case TokenType::LParen:     return "LParen";
        case TokenType::RParen:     return "RParen";
        case TokenType::Newline:    return "Newline";
        case TokenType::Eof:        return "Eof";
        case TokenType::Unknown:    return "Unknown";
        default:                    return "Invalid";
    }
}

inline std::ostream& operator<<(std::ostream& os, const Token& tok) {
    return os << "Token(type=" << to_string(tok.type)
              << ", text=\"" << tok.text
              << "\", line=" << tok.line
              << ", column=" << tok.column << ")";
}
