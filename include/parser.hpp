// include/parser.hpp
#pragma once
#include "token.hpp"
#include "ast.hpp"
#include <vector>
#include <memory>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::vector<std::unique_ptr<class ASTNode>> parse();

private:
    const std::vector<Token>& tokens;
    size_t current;

    bool match(TokenType type);
    const Token& advance();
    const Token& peek() const;

    std::unique_ptr<class ASTNode> parseStatement();
};
