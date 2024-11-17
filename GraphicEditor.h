// GraphicEditor.h
#ifndef GRAPHIC_EDITOR_H  // GraphicEditor.h 헤더 파일을 포함하는 조건부 컴파일 시작
#define GRAPHIC_EDITOR_H

// Shape 클래스와 UI 클래스를 포함하기 위한 헤더 파일
#include "Shape.h" // 도형 관련 클래스 포함
#include "UI.h"    // 사용자 인터페이스 관련 클래스 포함

// GraphicEditor 클래스 정의
class GraphicEditor {
    Shape* pStart;  // 도형 리스트의 첫 번째 도형을 가리키는 포인터
    Shape* pLast;   // 도형 리스트의 마지막 도형을 가리키는 포인터

public:
    // 기본 생성자
    GraphicEditor(); // GraphicEditor 객체를 생성할 때 pStart와 pLast 포인터를 초기화

    // 소멸자
    ~GraphicEditor(); // 동적으로 할당된 메모리 해제를 처리하기 위한 소멸자

    // 도형을 리스트에 추가하는 메서드
    void insertItem(int type); // 매개변수 type에 따라 도형을 생성하고 리스트에 추가

    // 도형을 리스트에서 삭제하는 메서드
    void deleteItem(int index); // 매개변수 index에 해당하는 도형을 리스트에서 삭제

    // 리스트에 있는 모든 도형을 출력하는 메서드
    void show(); // 도형 리스트의 모든 도형을 출력

    // 프로그램 실행을 담당하는 메서드
    void run(); // 사용자 입력을 처리하고 도형을 추가/삭제하는 등의 작업을 수행하는 메서드
};

// 헤더 파일의 끝, 조건부 컴파일 종료
#endif
