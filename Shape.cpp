//Shape.cpp
#include "Shape.h"
#include <iostream>
using namespace std;

// �⺻ ������: next �����͸� nullptr�� �ʱ�ȭ�Ͽ� ���� ����Ʈ�� ���� ����
Shape::Shape() {
    next = nullptr;
}

//���� �Ҹ���: �Ļ� Ŭ������ �Ҹ��ڸ� �ùٸ��� ȣ���ϱ� ���� �ʿ�
Shape::~Shape() {}

//���� �߰� �޼���: ���ο� ���� ��ü�� ���� ��ü�� next�� ����
void Shape::add(Shape* p) {
    this->next = p; //���� ��ü�� next�� ���޹��� ��ü(p)�� ����
}

//���� ��� �޼���: ���� ������ �׸��� paint()�� �ܼ��� draw()�� ȣ��
void Shape::paint() {
    draw(); // draw()�� �� �Ļ� Ŭ�������� ����
}

//���� ���� ��ȯ �޼���: ���� ��ü�� next �����͸� ��ȯ
Shape* Shape::getNext() {
    return next;
}

//Line Ŭ������ draw() �޼���: ��(Line) ������ ������ ���
void Line::draw() {
    cout << "Line" << endl; //"Line" ���ڿ� ���
}

//Circle Ŭ������ draw() �޼���: ��(Circle) ������ ������ ���
void Circle::draw() {
    cout << "Circle" << endl; //"Circle" ���ڿ� ���
}

//Rectangle Ŭ������ draw() �޼���: �簢��(Rectangle) ������ ������ ���
void Rectangle::draw() {
    cout << "Rectangle" << endl; //"Rectangle" ���ڿ� ���
}
