// UI.cpp
#include "UI.h"
#include <iostream>
using namespace std;

// 사용자로부터 메뉴 선택을 입력받아 반환
int UI::getMenu() {
    int key; // 사용자가 입력할 메뉴 값을 저장할 변수
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>"; // 메뉴 옵션 출력
    cin >> key; // 사용자 입력 받기
    return key; // 입력된 값 반환
}

// 삽입할 도형의 타입을 사용자로부터 입력받아 반환
int UI::getShapeTypeToInsert() {
    int key; // 사용자가 입력할 도형 타입 값을 저장할 변수
    cout << "선:1, 원:2, 사각형:3 >>"; // 도형 타입 옵션 출력
    cin >> key; // 사용자 입력 받기
    return key; // 입력된 값 반환
}

// 삭제할 도형의 인덱스를 사용자로부터 입력받아 반환
int UI::getShapeIndexToDelete() {
    int key; // 사용자가 입력할 삭제할 도형의 인덱스를 저장할 변수
    cout << "삭제하고자 하는 도형의 인덱스 >>"; // 삭제할 도형의 인덱스 요청 메시지 출력
    cin >> key; // 사용자 입력 받기
    return key; // 입력된 값 반환
}
