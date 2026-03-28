## 개요

- 강의 제목: 리눅스 시스템 프로그래밍 - 이론과 실습
- 강의 링크: https://www.inflearn.com/course/리눅스-시스템-프로그래밍-이론과-실습

## 목차

### **파일 다루기 (High-level)**

- 파일 열기/닫기: **`fopen`**, **`fclose`**
    - section01/ex1.c
- 파일 포지션: **`ftell`**, **`fseek`**
    - section01/ex2.c
- 파일 읽고 쓰기: **`fread`**, **`fwrite`**
    - section01/ex3.c

### **파일 다루기 (Low-level)**

- 저수준 파일 열기/닫기, 스트림 포지션: **`open`**, **`close`**
    - section02/ex1.c
- 저수준 파일 문자/문자열 읽고 쓰기: **`read`**, **`write`**
    - section02/ex2.c
- 하드링크와 소프트링크: **`link`**, **`symlink`**, **`unlink`**
    - section02/ex3.c
- 파일 속성: **`stat`**, **`fstat`**
    - section02/ex4.c

### **파일 다루기 (Advanced)**

- Directory 다루기: **`opendir`**, **`readdir`**, **`closedir`**
    - section03/ex1.c
- Memory Map: **`mmap`**, **`munmap`**
    - section03/ex2.c
- 파일 락을 이용한 프로세스 간 동기화(제목 수정): **`flock`**
    - section03/ex3.c
- 파일 속성 제어
- 파일 이벤트
- I/O Multiplexing (select)
- I/O Multiplexing (epoll)

### **프로세스와 쓰레드**

- 프로세스 개념, 프로세스 생성
- 프로그램 실행과 종료 처리
- 프로세서 친화
- 쓰레드 개념, 쓰레드 생성/종료/조인/동기화

### **시그널, 시간**

- 기본 시그널 처리
- 고급 시그널 처리
- 시간과 타이머