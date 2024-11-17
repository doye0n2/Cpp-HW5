// main.cpp
#include "GraphicEditor.h"  // GraphicEditor 클래스 정의를 포함하기 위해 헤더 파일을 포함

// 프로그램의 진입점인 main 함수
int main() {
    // GraphicEditor 클래스의 객체 graphicEditor를 생성
    GraphicEditor graphicEditor; // 도형을 관리하고 사용자와 상호작용하는 핵심 객체

    // graphicEditor 객체의 run() 메서드를 호출하여 프로그램 실행
    graphicEditor.run(); // 프로그램의 주요 로직 실행 (도형 추가, 삭제, 출력 등)

    // 프로그램이 정상적으로 종료되었음을 운영체제에 알림
    return 0; // 반환 값 0은 성공적인 종료를 의미
}
