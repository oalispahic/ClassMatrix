This project is licensed under the [MIT License](LICENSE).
# ClassMatrix

**A lightweight C++ library that models a mathematical matrix using raw C-style dynamic arrays.**

---

This library allows you to easily create, manipulate, and perform mathematical operations on matrices — built from scratch using raw pointers.

---

### ✨ Features

- Clean and simple syntax  
- Easy to use and extend  
- Mathematical methods (coming soon)  
- Fast, raw memory management with dynamically allocated arrays  

---

### 📦 Overview

Currently supports:

- **Default constructor** → creates a 3x3 null matrix  
- **Parameterized constructor** → takes row/column size and an optional fill value  

```cpp
matrix matrixName;            // Creates a 3x3 null matrix  
matrix matrixName(5, 5);      // Creates a 5x5 null matrix  
matrix matrixName(6, 6, 5);   // Creates a 6x6 matrix filled with 5s  
```




- **Built in ```print()``` method for a nice and easy way of printing a matrix**

```cpp
matrixName.print(); // Prints out the matrix
```

- **Supports ```.at()```method similar to how std::vector does it, can chain .at() and throws range_error if out of index range**

- **Supports ```.size()``` for returning size of current row/colum**


---

### 🚧 Work in progress:


- **Overloading operators ```< > = == [] + - * ```**

- **```.inverse()``` method for an instant inverted matrix**

- **```.resize()``` for dynamically resizing the matrix**

- **```.identity``` for transforming a matrix into identity matrix and much more...**


---

### Who am I?:

Im Omar, a software engineering student working on cool micro-libraries and low level C++ experiments.
This is a part of my learning journey and portofolio and I'm having a blast building it.

