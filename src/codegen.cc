// src/codegen.cc
#include "codegen.hpp"
using namespace llvm;

Value* CodegenContext::codegen(Expr* expr) {
    if (auto* num = dynamic_cast<NumberExpr*>(expr)) {
        return ConstantInt::get(Type::getInt32Ty(context), num->value);
    }
    if (auto* var = dynamic_cast<VariableExpr*>(expr)) {
        return namedValues[var->name]; // assumes already defined
    }
    if (auto* bin = dynamic_cast<BinaryExpr*>(expr)) {
        Value* left = codegen(bin->lhs.get());
        Value* right = codegen(bin->rhs.get());

        switch (bin->op) {
            case '+': return builder.CreateAdd(left, right, "addtmp");
            case '-': return builder.CreateSub(left, right, "subtmp");
            case '*': return builder.CreateMul(left, right, "multmp");
            case '/': return builder.CreateSDiv(left, right, "divtmp");
            default: return nullptr;
        }
    }
    return nullptr;
}
