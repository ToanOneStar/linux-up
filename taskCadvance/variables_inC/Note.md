- Biến là gì? có thể hiểu biến là đại diện cho 1 vùng nhớ lưu trữ dữ liệu và giá trị có thể thay đổi được
- timelife của biến là thời gian biến có hiệu lực trong memory
- scope variable: vùng hoạt động của biến
- variable in memory: text code --> vùng nhớ khởi tạo hoặc không khởi tạo --> heap --> free memory --> stack
- Biến global và local:

* global: có memory tại vùng khởi tạo, khi sử dụng từ khóa extern sẽ hoạt động ở tất cả các file .o, sử dụng từ khóa static thì sẽ chỉ hoạt động ở file mà nó được khởi tạo
* local: vùng hoạt động chỉ trong hàm khởi tạo, timelife sẽ trong suốt thời gian chương trình hoạt động, memory là stack

- Các key words với biến:

* static: dùng để kiểm soát thời gian timelife, scope của một biến
  vd: static local variable sẽ đếm khả năng xuất hiện làm cho biến đó chạy trong suốt thời gian runtime file exe

- extern: khai báo global không cung cấp bộ nhớ cho nó, nó là tham chiếu 1 biến hàm cùng tên nào đó đã được định nghĩa bên ngoài. Nó chỉ khai báo chứ không định nghĩa (cấp phát bộ nhớ cho biến)
- biến được tham chiếu phải được khai báo ở mức độ cao nhất là global và có thể nằm trong tất cả các file .o
- register: lưu ở thanh ghi CPU thay vì memory làm truy cập nhanh hơn nhưng khó debug và không lấy được địa chỉ của biến
- volatile: load lại vùng nhớ của 1 biến có thể thay đổi giá trị sử dụng khi memory mapped peripheral register (thiết bị ngoại vi có ánh xạ đến ô nhớ) biến toàn cục được truy xuất từ các tiến trình con xử lý ngắt ISR biến toàn cục được truy xuất từ nhiều tác vụ trong ứng dụng điều khiển đa luồng multi threads
  --> thông báo cho compiler biến này có thể thay đổi

* pointer là một biến chứa địa chỉ của biến khác
  II struct datatype
* bao gồm struct, union, enum
* size of struct: CPU sẽ cấp phát cho struct các block để lưu địa chỉ của các member có trong struct đó

- OS 32 bit thì 1 block = 4 byte
- OS 64 bit thì 1 block = 8 byte

* union cho phép chứa nhiều kiểu dữ liệu khác nhau ở vùng bộ nhớ
* cấp phát union: size của union bằng kích thước lớn nhất của phần tử trong đó. Tại 1 thời điểm chỉ dùng 1 phần tử
* enum: thường dùng để assign mã lỗi
* size của enum bằng size của kiểu int
