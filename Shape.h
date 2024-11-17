// Shape.h
#ifndef SHAPE_H  // 헤더 파일이 여러 번 포함되는 것을 방지하기 위한 조건부 컴파일 시작
#define SHAPE_H

// Shape 클래스 정의 (도형의 기본 클래스)
class Shape {
    Shape* next;  // 연결 리스트에서 다음 도형을 가리키는 포인터

protected:
    // 각 도형의 정보를 출력하는 순수 가상 함수 (상속받은 클래스에서 구현)
    virtual void draw() = 0;

public:
    // 기본 생성자
    Shape();  // Shape 객체를 초기화하고 next 포인터를 nullptr로 설정

    // 가상 소멸자 (상속받은 클래스에서 동적 메모리 해제를 할 수 있도록)
    virtual ~Shape();  // 동적으로 할당된 메모리 해제 및 자원 정리

    // 새로운 도형을 현재 도형에 추가하는 메서드
    void add(Shape* p);  // 매개변수로 받은 도형을 리스트에 추가 (현재 도형의 next로 설정)

    // 현재 도형의 정보를 출력하기 위한 메서드 (다형성 제공)
    void paint();  // draw() 메서드를 호출하여 도형의 정보를 출력

    // 다음 도형을 반환하는 메서드 (연결 리스트 순회용)
    Shape* getNext();  // next 포인터를 반환하여 연결된 도형으로 이동

};

// Line 클래스를 Shape 클래스로부터 상속하여 정의
class Line : public Shape {
protected:
    // Line 클래스에 대한 draw 메서드 구현 (도형의 정보를 출력)
    virtual void draw();  // Line 도형의 정보를 출력하는 동작을 구현
};

// Circle 클래스를 Shape 클래스로부터 상속하여 정의
class Circle : public Shape {
protected:
    // Circle 클래스에 대한 draw 메서드 구현 (도형의 정보를 출력)
    virtual void draw();  // Circle 도형의 정보를 출력하는 동작을 구현
};

// Rectangle 클래스를 Shape 클래스로부터 상속하여 정의
class Rectangle : public Shape {
protected:
    // Rectangle 클래스에 대한 draw 메서드 구현 (도형의 정보를 출력)
    virtual void draw();  // Rectangle 도형의 정보를 출력하는 동작을 구현
};

// 헤더 파일의 끝, 조건부 컴파일 종료
#endif
