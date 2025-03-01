# I. Build process overview

Preprocessing: mở rộng macro, handle các header file. process #if, #ifdef, #else, #endif. Output sẽ là file .i (intermediate file)

Compilation: compiler convert các đoạn tiền xử lí sang mã assembly cho kiến trức tương ứng. Output sẽ là file .a

Assembly: assembler convert the assembly code tạo bởi compiler sang mã máy (01). output là các file .o

Linking: linker kết hợp các file object lại thành một file duy nhất, sắp xếp mọi thứ như ghi ở vùng nào, các function nào. Output là file .exe

Execution: file exe run trên hệ thống. OS load the program into memory and starts the program's execution

# II. Memory layout

Variable and memory location

- Toàn bộ file code C tạo ra ở .text section

- Các hằng số const tạo ra ở .rodata section
- các dữ liệu khởi tạo khác 0 VD: int a = 4; được tạo ra ở .data section
- dữ liệu khởi tạo bằng 0 -> .bss section
- không khởi tạo VD: int b; -> COMMON section (1 số compiler gộp chung trong .bss)
- khi sử dụng static thì biến thay vì lưu ở stack thì lưu ở .data

# III. Pointer

Pointer là một biến lưu trữ địa chỉ của một biến khác

Có thể có nhiều con trỏ cùng chứa một địa chỉ

Kích thước của con trở bằng bao nhiêu? phụ thuộc vào kiến trúc và platform của system. Không phụ thuộc vào type of data mà con trỏ point

- Trên OS 32 bit thì mọi con trỏ là 4 bytes
- Trên OS 64 bit thì mọi con trỏ là 8 bytes

Ở trong một số embedded system size of pointer có thể là 2 byte hoặc 1 số chắn byte

## 1. Advanced pointer

Pointer to pointer: 1 con trỏ chứa địa chỉ của con trỏ khác VD int \*\*ptr;

- Tác dụng: cho phép thao tác động cho địa chỉ vùng nhớ

Pointer to an array

- là 1 con trỏ trỏ tới phần tử đầu tiên của mảng
- VD: int (\*arr_ptr)[5] 1 con trỏ tới 1 mảng 5 số int
- sử dụng với passing array to function và cấp phát động vùng nhớ cho con trỏ

Pointer to a function

- Là con trỏ chứa địa chỉ 1 hàm
- VD: int (\*func_ptr) (int, int) là một con trỏ tới 1 hàm với 2 số int là các đố số
- Sử dụng cho call back function, điều hướng chương trình

## 2. Cấp phát động

- malloc

```c
*ptr = (type *)malloc(byte_size);
```

- calloc: khởi tạo giá trị ban đầu bằng 0

```c
*ptr = (type *)calloc(n, size_of_an_element);
```

- realloc: resize và giữ nguyên data

```c
*ptr = (type *)realloc(ptr, new_size);
```

- free: tránh memory leak

## 3. Increasement và decreasement pointer

Ta có ptr++ và ptr--

ptr1 == ptr2 để check 2 pointer có cùng trỏ tới 1 vùng địa chỉ không

Con trỏ trong mảng đa chiều: ta có công thức tính vị trí của phần tử trong mảng đa chiều với pointer. vd mảng A[2][4] muốn truy xuất tới phần tử A[1][1]
thì sẽ tương đương 1\*4+1 = ptr+=5

Pointer to a structure

Function pointer và call backs: là 1 hàm với tham số truyền vào là function pointer

## 4. Advanced pointer topic

Void pointer: hold address of any data type

- VD: void \*ptr
- sử dụng khi kiểu dữ liệu không biết trước

pointer to const (hằng con trỏ): trỏ tới 1 const value (giá trị không đổi)

- VD const int \*ptr;

constant pointer (con trỏ hằng): 1 con trỏ có địa chỉ không đổi nhưng giá trị có thể thay đổi

- VD: int \*const ptr;

dangling pointer: tức là khi cấp phát động mà sau đó free() thì vẫn có 1 con trỏ trỏ tới vùng cấp phát động đó. Ngăn chặn bằng cách set pointer to NULL sau khi free.

Pointer casting: ép kiểu con trỏ

- 1 số rủi ro như miss data, gây một số lỗi runtime
