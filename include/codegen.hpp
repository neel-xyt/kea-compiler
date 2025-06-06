// include/codegen.hpp
#pragma once
#include "ast.hpp"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <map>

class CodegenContext {
public:
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::map<std::string, llvm::Value*> namedValues;

    CodegenContext()
        : builder(context), module(std::make_unique<llvm::Module>("kea", context)) {}

    llvm::Value* codegen(Expr* expr);
};
