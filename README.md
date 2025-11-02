# 🏪 Inventory Management System (BST)

## 📘 Overview
This project is a **C++ console-based Inventory Management System** that uses a **Binary Search Tree (BST)** to efficiently manage store items.  
Each item contains a **name** and **price**, and users can perform operations such as inserting, displaying, searching, updating, and deleting items.  
The BST structure ensures that all items are stored in sorted order by name for fast access.

---

## ⚙️ Features
- ✅ **Insert Item** – Add a new item and its price to the inventory.  
- ✅ **Display Inventory** – Display all items in alphabetical order.  
- ✅ **Search Item** – Find details of an item by its name.  
- ✅ **Update Item Price** – Modify the price of an existing item.  
- ✅ **Delete Item** – Remove an item from the inventory.  
- ✅ **Exit Program** – Close the program safely.

---

## 🧩 Data Structure Used
The system uses a **Binary Search Tree (BST)** where each node contains:
- `name` → Item name (used as the key)
- `price` → Item price
- `left` and `right` → Pointers to child nodes

**Inorder traversal** is used to display items in sorted (alphabetical) order.

---

## 🧠 Learning Outcomes
By working on this project, you will learn to:
1. Implement **Binary Search Tree operations** such as insertion, searching, updating, and deletion.
2. Apply **object-oriented programming concepts** like classes, constructors, and encapsulation.
3. Use **recursion** effectively in tree-based algorithms.
4. Design a **menu-driven program** with user interaction.
5. Develop a basic **inventory management system** using data structures.

---

## 💻 Compilation and Execution

### 1. Save the code
Save the provided C++ code as:
```bash
inventory_bst.cpp
```

### 2. Open Terminal or Command Prompt
Navigate to the directory where the file is saved.

### 3. Compile the program
Use the g++ compiler:
```bash
g++ inventory_bst.cpp -o inventory
```
If there are no errors, it will create an executable file named inventory.±

### 4. Run the program
```bash
./inventory
```
(Use inventory.exe on Windows.)

## 📂 File Structure
📦 Inventory-Management-BST
 - 📜 inventory_bst.cpp     # Main source code file
 - 📜 README.md              # Project documentation
 - 📁 screenshots/           # (Optional) Folder for sample outputs or screenshots

 ## 🧰 Technologies Used
 	•	Programming Language: C++
	•	Data Structure: Binary Search Tree (BST)
	•	Concepts Applied: Recursion, Classes & Objects, Inorder Traversal
	•	Compiler: g++ (MinGW / GCC)
	•	IDE / Environment: Visual Studio Code, Code::Blocks, or any C++ compiler terminal
	•	Platform: Windows / Linux / macOS


