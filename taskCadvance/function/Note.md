- Hàm là 1 đoạn chương trình đọc lập thực hiện 1 nhiệm vụ cụ thể được xác định rõ
- Được dùng khi thực hiện nhiều lần 1 tính năng gì đó
- Việc gỡ lỗi trở nên dễ dàng hơn vì cấu trúc của chương trình rõ ràng hơn do dạng module của nó
- Quy chuẩn đặt tên hàm: prefix(tên cty) + vùng thực hiện source code + tính năng code
  VD: fptAppFrameworkGetValue()
- Trong C có hai khái niệm là truyền giá trị và truyền địa chỉ (không phải là tham trị và tham chiếu trong C++)
- return from function: chuyển quyền điều khiển từ hàm trở lại chương trình gọi ngay lập tức
- Dấu ngoặc đơn là bắt buộc
- Chỉ có 1 giá trị có thể được trả về
- function prototype: VD int sum (int a, int b)

* tương tự như định nghĩa hàm nhưng không có nội dung
* thông báo cho trình biên dịch nhận dạng và cách sử dụng
* để xem trong project đó có những hàm gì

- Variable

* biến cục bộ: được khai báo bên trong hàm, được tạo khi nhập vào 1 khối và bị hủy khi thoát khỏi hàm
* tham số chính thức(formal parameters): khai báo trong định nghĩa của hàm dưới dạng tham số, hoạt động giống như bất kì biến cục bộ nào bên trong 1 hàm
* biến toàn cục: khai báo ngoài hàm, giữ giá trị trong suốt quá trình thực thi

- Sử dụng truyền địa chỉ: hàm có thể thay đổi giá trị đối số, dùng cho hàm có nhiều đầu ra
- Keyword - static - inline
  +Khi sử dụng sẽ đề nghị trình biên dịch chèn toàn bộ mã của hàm vào vị trí mà hàm được gọi thay vì thực hiện 1 lời gọi hàm thông thường + Giảm thời gian thực thi chương trình vì loại bỏ chi phí gọi hàm (lưu địa chỉ, sao chép tham số, chuyền điều kiện) + Đổi lại size code sẽ lớn hơn
- Static inline function trong file .h để xử lí multi declare do các file .o sẽ không link với nhau
- function like macro: VD #define SQUARE(x) ((x)\*(x))
- Nhược điểm không xác định được kiểu dữ liệu trả về
- Đệ quy (Recursion)

* ưu điểm: thanh lịch, dễ hiểu
* nhược điểm: kém hiệu quả, chậm
