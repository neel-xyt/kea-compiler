// include/lexer.hpp
#pragma once
#include "token.hpp"
#include <string>
#include <vector>

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string src;
    size_t pos;
    int line, column;

    char peek() const;
    char advance();
    void skipWhitespace();
    Token makeIdentifier();
    Token makeNumber();
};
