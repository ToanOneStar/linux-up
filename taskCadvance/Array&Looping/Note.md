I. Array

- Trong repo này tìm hiểu các vấn đề Array là gì, mảng đa chiều, Array in memory, how to declare an array, how works with array, when will using array?
- Đầu tiên array là tập hợp tuần tự các phần tử có cùng kiểu dữ liệu lưu trữ trong 1 dãy ô nhớ

* Độ dài của array được xác định trước và mỗi phần tử có một index xác định
* index là một số nguyên dương từ 0 đến n-1

- Mảng đa chiều thì thường làm việc với mảng 2 chiều có thể hiểu là 2 mảng một chiều biểu diễn bởi hàng và cột
- Mảng con trỏ *a = x[0] và *a+1 = x[1] khi kiểu dữ liệu con trỏ cùng kiểu dữ liệu array
- Cách array làm việc thường là:

* array elements and index
* insert
* find
* delete
* sort
  II. Looping

- Là 1 đoạn code mà chương trình thực hiện lặp đi lặp lại cho đến khi thỏa mãn điều kiện
- video nhắc lại phân biệt i++ và ++i
- trong lập trình nhúng thường dùng vòng lặp vô tận là while(1)
- do while thực hiện lệnh trước khi vào test condition
- Các key words hay dùng là: goto, continue, break, exit(), return

* goto: sẽ đi đến ngay một nhãn label nào đó được chỉ định (khó debug nên ít khi dùng)
* continue: bỏ qua các câu lệnh sau đó mà thực hiện lệnh của vòng lặp tiếp theo
* break: thoát khỏi vòng lặp ngay lập tức
* exit(): chương trình sẽ terminate và trả quyền control cho OS
