// inside main.cc
CodegenContext ctx;

// Example: a = 5 + 6
auto expr = std::make_unique<BinaryExpr>(
    '+',
    std::make_unique<NumberExpr>(5),
    std::make_unique<NumberExpr>(6)
);

// generate code and store result
llvm::Value* val = ctx.codegen(expr.get());

// optionally create a function and return the value
auto funcType = llvm::FunctionType::get(llvm::Type::getInt32Ty(ctx.context), false);
auto mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", ctx.module.get());
auto block = llvm::BasicBlock::Create(ctx.context, "entry", mainFunc);
ctx.builder.SetInsertPoint(block);
ctx.builder.CreateRet(val);

// print IR
ctx.module->print(llvm::outs(), nullptr);
