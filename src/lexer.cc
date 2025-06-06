// src/lexer.cpp
#include "lexer.hpp"
#include "token.hpp"  
#include <cctype>       
#include <string>     
#include <vector>     

Lexer::Lexer(const std::string& source)
    : src(source), pos(0), line(1), column(1) {}

char Lexer::peek() const {
    return pos < src.length() ? src[pos] : '\0';
}

char Lexer::advance() {
    char c = peek();
    pos++;
    if (c == '\n') {
        line++; column = 1;
    } else {
        column++;
    }
    return c;
}

void Lexer::skipWhitespace() {
    while (isspace(peek()) && peek() != '\n') advance();
}

Token Lexer::makeIdentifier() {
    int startCol = column;
    size_t start = pos;
    while (isalnum(peek()) || peek() == '_') advance();
    std::string text = src.substr(start, pos - start);
    return Token(TokenType::Identifier, text, line, startCol);
}

Token Lexer::makeNumber() {
    int startCol = column;
    size_t start = pos;
    while (isdigit(peek())) advance();
    std::string num = src.substr(start, pos - start);
    return Token(TokenType::Number, num, line, startCol);
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;

    while (peek() != '\0') {
        skipWhitespace();
        char c = peek();

        if (isalpha(c)) {
            tokens.push_back(makeIdentifier());
        } else if (isdigit(c)) {
            tokens.push_back(makeNumber());
        } else {
            int startCol = column;
            switch (c) {
                tokens.emplace_back(TokenType::Equals, "=", line, startCol);
                case '+': tokens.emplace_back(TokenType::Plus, "+", line, startCol); break;
                case '-': tokens.emplace_back(TokenType::Minus, "-", line, startCol); break;
                case '*': tokens.emplace_back(TokenType::Star, "*", line, startCol); break;
                case '/': tokens.emplace_back(TokenType::Slash, "/", line, startCol); break;
                case '(': tokens.emplace_back(TokenType::LParen, "(", line, startCol); break;
                case ')': tokens.emplace_back(TokenType::RParen, ")", line, startCol); break;
                case '\n': tokens.emplace_back(TokenType::Newline, "\\n", line, startCol); break;
                default: tokens.emplace_back(TokenType::Unknown, std::string(1, c), line, startCol); break;
            }
            advance();
        }
    }

    tokens.emplace_back(TokenType::Eof, "", line, column);
    return tokens;
}
