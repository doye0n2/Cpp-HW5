// Shape.cpp
#include "Shape.h"
#include <iostream>
using namespace std;

// 기본 생성자: next 포인터를 nullptr로 초기화하여 연결 리스트의 끝을 정의
Shape::Shape() {
    next = nullptr;
}

//가상 소멸자: 파생 클래스의 소멸자를 올바르게 호출하기 위해 필요
Shape::~Shape() {}

//도형 추가 메서드: 새로운 도형 객체를 현재 객체의 next로 설정
void Shape::add(Shape* p) {
    this->next = p; //현재 객체의 next를 전달받은 객체(p)로 설정
}

//도형 출력 메서드: 현재 도형을 그리고 paint()는 단순히 draw()만 호출
void Shape::paint() {
    draw(); // draw()는 각 파생 클래스에서 구현
}

//다음 도형 반환 메서드: 현재 객체의 next 포인터를 반환
Shape* Shape::getNext() {
    return next;
}

//Line 클래스의 draw() 메서드: 선(Line) 도형의 정보를 출력
void Line::draw() {
    cout << "Line" << endl; //"Line" 문자열 출력
}

//Circle 클래스의 draw() 메서드: 원(Circle) 도형의 정보를 출력
void Circle::draw() {
    cout << "Circle" << endl; //"Circle" 문자열 출력
}

//Rectangle 클래스의 draw() 메서드: 사각형(Rectangle) 도형의 정보를 출력
void Rectangle::draw() {
    cout << "Rectangle" << endl; //"Rectangle" 문자열 출력
}
