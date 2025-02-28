I. C preprocessor overview: tiền xử lí

- Quá trình biên dịch code sẽ qua các khâu: đầu tiên sẽ tiến hành quá trình tiền xử lí để thay thế và define các thư viện, loại bỏ comment output là file .o sau đó qua linker kết hợp với các file .a bằng assembly để thành file .exe và được loader load lên CPU
- Quá trình tiền xử lí bao gồm:

* inclusion of header files
* macro expansion
* conditional compilation
* diagnostics directives

- Tiền xử lí bắt đầu với kí tự #

II. Macro

- Là đoạn mã được đặt tên bất cứ khi nào tên được sử dụng nó sẽ thay thế toàn bộ bằng nội dung của macro
- Sử dụng bằng #define
- Sử dụng khi biểu diễn số, chuỗi, biểu thức
- Chú ý sử dụng dấu ngoặc đơn cho từng tham số

III. Inclusion directive

- Có hai loại:

* #include <filename.h>: dùng để include system header files
* #include "filename": include user defined chú ý phải cùng một đường dẫn với C source file

IV. Conditional compilation

- #ifdef: check macro đã được defined chưa
- #ifndef: check macro không được defined
- #else: sử dụng với #if, #ifdef, #ifndef
- #elif
- #undef: undefined
- Toán tử 3 ngôi: <condition>?<express1>:<express2>

* VD: #define min(X,Y) ((X)<(Y))?(X):(Y)

- Toán tử tiền xử lí #: convert macro to string
- Toán tử token pasting ##: kết hợp hai chuỗi

V. Bit operation

- And, or, xor, not: Xor thì giống nhau = 0
- Shift bit <<, >>
- chú ý khi dùng các kiểu dữ liệu chỉ định giới hạn như uint8_t hay uint16_t thì có thể bị mất dữ liệu khi sử dụng shift bit
- Các phép toán thường dùng:

* set 1 bit lên 1: number |= (1<<position)
* clear 1 bit về 0: number &= ~(1<<position)
* reading 1 bit là 0 hay 1: bit (number >> position)&1
* đảo 1 bit (toggle): number ^= (1<<position)
