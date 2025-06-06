// include/ast.hpp
#pragma once
#include <string>
#include <memory>

struct Expr {
    virtual ~Expr() = default;
};

struct NumberExpr : Expr {
    int value;
    NumberExpr(int value) : value(value) {}
};

struct VariableExpr : Expr {
    std::string name;
    VariableExpr(const std::string& name) : name(name) {}
};

struct BinaryExpr : Expr {
    char op;
    std::unique_ptr<Expr> lhs, rhs;
    BinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
        : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
};
