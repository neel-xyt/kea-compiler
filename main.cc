// main.cc

#include <memory>
#include <string>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/raw_ostream.h>

#include "ast.hpp"
#include "codegen.hpp"

int main() {
    CodegenContext ctx;

    // Build AST: 5 + 6
    auto expr = std::make_unique<BinaryExpr>(
        '+',
        std::make_unique<NumberExpr>(5),
        std::make_unique<NumberExpr>(6)
    );

    // Generate LLVM IR from AST
    llvm::Value* val = ctx.codegen(expr.get());

    // Create LLVM function: int main() { return val; }
    auto funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(ctx.context), false);
    auto mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", ctx.module.get());
    auto block = llvm::BasicBlock::Create(ctx.context, "entry", mainFunc);
    ctx.builder.SetInsertPoint(block);
    ctx.builder.CreateRet(val);

    // Output the IR to stdout
    ctx.module->print(llvm::outs(), nullptr);

    return 0;
}

