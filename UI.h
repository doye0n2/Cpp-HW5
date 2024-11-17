// UI.h
#ifndef UI_H  // 헤더 파일이 여러 번 포함되는 것을 방지하기 위한 조건부 컴파일 시작
#define UI_H

// 사용자 인터페이스 관련 기능을 제공하는 UI 클래스 정의
class UI {
public:
    // 프로그램 메뉴를 출력하고 사용자가 선택한 메뉴 번호를 반환하는 정적 메서드
    static int getMenu();  // 메뉴 선택을 위해 사용자 입력을 받음

    // 추가할 도형의 타입을 입력받아 반환하는 정적 메서드
    static int getShapeTypeToInsert();  // 도형 타입(예: Line, Circle, Rectangle)을 선택

    // 삭제할 도형의 인덱스를 입력받아 반환하는 정적 메서드
    static int getShapeIndexToDelete();  // 도형 목록에서 삭제할 항목의 번호를 입력받음
};

// 헤더 파일의 끝, 조건부 컴파일 종료
#endif
