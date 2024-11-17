//GraphicEditor.cpp
#include "GraphicEditor.h"
#include <iostream>
using namespace std;

// GraphicEditor 생성자
// 연결 리스트의 시작과 끝을 나타내는 포인터를 초기화
GraphicEditor::GraphicEditor() {
    pStart = pLast = nullptr;
}

// GraphicEditor 소멸자
// 연결 리스트를 순회하며 동적으로 생성된 도형 객체들을 삭제
GraphicEditor::~GraphicEditor() {
    Shape* current = pStart; // 리스트의 시작부터 탐색
    while (current != nullptr) { // 리스트 끝까지 반복
        Shape* next = current->getNext(); // 다음 객체를 저장
        delete current; // 현재 객체 삭제
        current = next; // 다음 객체로 이동
    }
}

// 도형 삽입 메서드
void GraphicEditor::insertItem(int type) {
    Shape* p = nullptr; // 새로 생성할 도형 객체를 가리킬 포인터 초기화

    // 입력된 타입에 따라 도형 객체를 동적으로 생성
    switch (type) {
    case 1:
        p = new Line(); // 선 객체 생성
        break;
    case 2:
        p = new Circle(); // 원 객체 생성
        break;
    case 3:
        p = new Rectangle(); // 사각형 객체 생성
        break;
    default:
        break; // 잘못된 입력일 경우 아무 작업도 하지 않음
    }

    // 리스트가 비어 있는 경우
    if (pStart == nullptr) {
        pStart = p; // 첫 번째 도형으로 설정
        pLast = p;  // 마지막 도형도 동일
        return;
    }

    // 리스트가 비어 있지 않은 경우
    pLast->add(p);            // 현재 마지막 도형의 next에 새 도형 추가
    pLast = pLast->getNext(); // pLast를 새로 추가된 도형으로 갱신
}

// 도형 삭제 메서드
void GraphicEditor::deleteItem(int index) {
    // 리스트가 비어 있는 경우
    if (pStart == nullptr) {
        cout << "도형이 없습니다!" << endl; // 오류 메시지 출력
        return;
    }

    Shape* tmp = pStart; // 삭제할 도형을 탐색하기 위한 포인터
    Shape* pre = nullptr; // 삭제할 도형의 이전 도형을 가리킬 포인터

    // 첫 번째 도형 삭제 처리
    if (index == 0) {
        pStart = tmp->getNext(); // 시작 포인터를 다음 도형으로 이동
        delete tmp;              // 첫 번째 도형 삭제
        return;
    }

    // 입력된 인덱스까지 탐색
    for (int i = 0; i < index; i++) {
        pre = tmp;              // 현재 도형을 이전 도형으로 설정
        tmp = tmp->getNext();   // 다음 도형으로 이동
        if (tmp == nullptr) {   // 인덱스 범위를 초과한 경우
            cout << "잘못된 인덱스입니다!" << endl; // 오류 메시지 출력
            return;
        }
    }

    // 연결 리스트를 재구성하여 삭제
    pre->add(tmp->getNext()); // 이전 도형의 next를 삭제 대상의 next로 연결
    delete tmp;               // 삭제 대상 도형 삭제
}

// 도형 출력 메서드
void GraphicEditor::show() {
    Shape* tmp = pStart; // 리스트의 시작부터 탐색
    int i = 0;           // 출력용 인덱스
    while (tmp != nullptr) { // 리스트 끝까지 반복
        cout << i++ << ": "; // 현재 인덱스 출력
        tmp->paint();        // 현재 도형 출력
        tmp = tmp->getNext(); // 다음 도형으로 이동
    }
}

// 프로그램 실행 메서드
void GraphicEditor::run() {
    cout << "그래픽 에디터입니다." << endl; // 초기 메시지 출력
    int menu, index, type; // 메뉴, 인덱스, 타입 변수 초기화

    // 무한 반복하여 사용자 입력 처리
    while (true) {
        menu = UI::getMenu(); // 메뉴 선택 입력
        switch (menu) {
        case 1: // 도형 삽입
            type = UI::getShapeTypeToInsert(); // 삽입할 도형 타입 입력
            insertItem(type); // 도형 삽입 처리
            break;
        case 2: // 도형 삭제
            index = UI::getShapeIndexToDelete(); // 삭제할 도형 인덱스 입력
            deleteItem(index); // 도형 삭제 처리
            break;
        case 3: // 도형 출력
            show(); // 현재 리스트에 있는 도형 출력
            break;
        default: // 종료
            return;
        }
    }
}
