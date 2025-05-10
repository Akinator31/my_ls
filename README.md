# my_ls

[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))  
**my_ls** is a C programming project that replicates the functionality of the standard Unix `ls` command. This project is part of the Epitech curriculum and serves as an introduction to system-level programming, file handling, and understanding directory structures.

---

## 📖 About the Project

The goal of **my_ls** is to recreate the behavior of the `ls` command, which is used to list directory contents in Unix-like operating systems. This involves working with low-level system calls, managing file attributes, and producing output similar to the original `ls` command.

Through this project, developers will:

- Gain experience with system calls like `opendir`, `readdir`, and `stat`.
- Understand file permissions, ownership, and timestamps.
- Explore how to handle flags/options for modifying command behavior.
- Improve low-level programming skills in C.

---

## 🚀 Features

- **Basic Directory Listing**  
  Lists files and directories in the current or specified path.

- **Options/Flags Support** *(Subset of the original `ls` functionality)*  
  - `-l`: Long format output, including file permissions, ownership, size, and timestamps.
  - `-a`: Displays hidden files (those beginning with a `.`).
  - `-R`: Recursively lists subdirectories.
  - `-t`: Sorts files by modification time.

- **Error Handling**  
  Gracefully handles invalid directories, permissions issues, and unsupported options.

- **Custom Output Formatting**  
  Matches the style and structure of the original `ls` command.

---

## 🛠️ Technologies Used

- **C Programming Language**: The core language used for system-level programming and file handling.

- **Makefile**: Automates the build process for compiling the project.

---

## 📂 Project Structure

```
my_ls/
├── my_ls.c             # Core implementation of the ls functionality
├── src/                # Source code files
│   ├── flags/          # Flags handling
│   ├── utils/          # Utils files
├── lib/                # My lib folder
├── include/            # Header files
│   └── ...             # Function prototypes and macros
├── Makefile            # Build automation
└── README.md           # Project documentation
```

---

## 📝 Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/Akinator31/my_ls.git
   cd my_ls
   ```

2. Build the project using the provided `Makefile`:
   ```bash
   make
   ```

3. Run **my_ls**:
   ```bash
   ./my_ls [options] [path]
   ```

   Examples:
   - Basic directory listing:
     ```bash
     ./my_ls
     ```
   - Long listing format:
     ```bash
     ./my_ls -l
     ```
   - Show hidden files:
     ```bash
     ./my_ls -a
     ```
   - Recursively list directories:
     ```bash
     ./my_ls -R
     ```

4. Clean the project:
   ```bash
   make clean
   ```

---

## 🧪 Testing

To ensure the reliability of **my_ls**, test cases can be executed by running:
```bash
make tests
```

This will validate the functionality of the program against various edge cases and scenarios.

---

## 🎯 Goals of the Project

This project is designed to:

1. Familiarize developers with Unix system calls and file handling.
2. Deepen understanding of directory structures and file attributes.
3. Implement and handle command-line options.
4. Practice modular programming and error handling in C.
