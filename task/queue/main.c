#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME "/student_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

struct sinhvien
{
    char hoten[50];
    int tuoi;
    char quequan[100];
    char sdt[100];
};

struct message
{
    long priority;
    struct sinhvien sv;
};

void input_student(mqd_t mq)
{
    struct message msg;
    printf("Nhập thông tin sinh viên:\n");

    // nhập tên sinh viên
    printf("Họ tên: ");
    fgets(msg.sv.hoten, 50, stdin);
    msg.sv.hoten[strcspn(msg.sv.hoten, "\n")] = 0;

    // nhập tuổi
    printf("Tuổi: ");
    scanf("%d", &msg.sv.tuoi);
    getchar();

    // nhập quê quán
    printf("Quê quán: ");
    fgets(msg.sv.quequan, 100, stdin);
    msg.sv.quequan[strcspn(msg.sv.quequan, "\n")] = 0;

    // nhập số điện thoại
    printf("Số điện thoại: ");
    fgets(msg.sv.sdt, 100, stdin);
    msg.sv.sdt[strcspn(msg.sv.sdt, "\n")] = 0;

    // tạo ID
    msg.priority = (long)(msg.sv.tuoi);

    if (mq_send(mq, (char *)&msg, sizeof(msg), 0) == -1)
    {
        perror("Lỗi khi gửi thông tin vào queue");
    }
}

void display_students(mqd_t mq)
{
    struct message msg;
    ssize_t bytes_read;

    printf("Danh sách sinh viên:\n");
    while ((bytes_read = mq_receive(mq, (char *)&msg, MAX_SIZE, NULL)) >= 0)
    {
        if (bytes_read > 0)
        {
            printf("ID: %ld\n", msg.priority);
            printf("Họ tên: %s\n", msg.sv.hoten);
            printf("Tuổi: %d\n", msg.sv.tuoi);
            printf("Quê quán: %s\n", msg.sv.quequan);
            printf("Số điện thoại: %s\n", msg.sv.sdt);
            printf("-------------------------\n");
        }
    }
}

void delete_student(mqd_t mq, long id)
{
    struct message msg;
    ssize_t bytes_read;

    while ((bytes_read = mq_receive(mq, (char *)&msg, MAX_SIZE, NULL)) >= 0)
    {
        if (msg.priority == id)
        {
            printf("Đã xóa sinh viên với ID: %ld\n", msg.priority);
            break;
        }
    }
}

void menu(mqd_t mq)
{
    int choice;
    long id;

    while (1)
    {
        printf("1. Nhập thông tin sinh viên\n");
        printf("2. Hiển thị danh sách sinh viên\n");
        printf("3. Xóa sinh viên\n");
        printf("4. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            input_student(mq);
            break;
        case 2:
            display_students(mq);
            break;
        case 3:
            printf("Nhập ID sinh viên cần xóa: ");
            scanf("%ld", &id);
            delete_student(mq, id);
            break;
        case 4:
            mq_close(mq);
            return;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    }
}
int main()
{
    mqd_t mq;
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(struct message);
    attr.mq_curmsgs = 0;

    // tạo message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == -1)
    {
        perror("Lỗi khi tạo message queue");
        return 1;
    }

    menu(mq);
    mq_unlink(QUEUE_NAME);

    return 0;
}
