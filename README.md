# 🛠️ Kea Compiler

A simple LLVM-based compiler that parses and compiles arithmetic expressions (e.g., `5 + 6`) into LLVM IR.

This is a toy compiler frontend written in C++ using LLVM. It currently supports basic arithmetic expressions and can be extended to parse a custom language (`.kea` files) and emit native code.

---

## ⚙️ Build Instructions

### 🧩 Requirements

- A C++ compiler (e.g., `clang++`)
- LLVM (install via your system's package manager)

---

### 🧪 Install LLVM (if not yet installed)

#### On Arch Linux:

```bash
sudo pacman -S llvm clang
````

#### On Ubuntu:

```bash
sudo apt install llvm clang
```

---

### 🔨 Build the Compiler

Make the build script executable and run it:

```bash
chmod +x buildComment.sh
./buildComment.sh
```

If everything is set up correctly, you should see:

```
Build succeeded!
```

---

## 🚀 Run the Compiler

```bash
./build/kea.exe
```

### ✅ Output

```llvm
define i32 @main() {
entry:
  ret i32 11
}
```

This LLVM IR is the result of compiling the expression `5 + 6`.

---

## 🤝 Contributing

Feel free to open issues or submit pull requests!

If you're new to compilers or LLVM, this is a great place to learn and contribute.
