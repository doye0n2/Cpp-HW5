// Shape.h
#ifndef SHAPE_H  // ��� ������ ���� �� ���ԵǴ� ���� �����ϱ� ���� ���Ǻ� ������ ����
#define SHAPE_H

// Shape Ŭ���� ���� (������ �⺻ Ŭ����)
class Shape {
    Shape* next;  // ���� ����Ʈ���� ���� ������ ����Ű�� ������

protected:
    // �� ������ ������ ����ϴ� ���� ���� �Լ� (��ӹ��� Ŭ�������� ����)
    virtual void draw() = 0;

public:
    // �⺻ ������
    Shape();  // Shape ��ü�� �ʱ�ȭ�ϰ� next �����͸� nullptr�� ����

    // ���� �Ҹ��� (��ӹ��� Ŭ�������� ���� �޸� ������ �� �� �ֵ���)
    virtual ~Shape();  // �������� �Ҵ�� �޸� ���� �� �ڿ� ����

    // ���ο� ������ ���� ������ �߰��ϴ� �޼���
    void add(Shape* p);  // �Ű������� ���� ������ ����Ʈ�� �߰� (���� ������ next�� ����)

    // ���� ������ ������ ����ϱ� ���� �޼��� (������ ����)
    void paint();  // draw() �޼��带 ȣ���Ͽ� ������ ������ ���

    // ���� ������ ��ȯ�ϴ� �޼��� (���� ����Ʈ ��ȸ��)
    Shape* getNext();  // next �����͸� ��ȯ�Ͽ� ����� �������� �̵�

};

// Line Ŭ������ Shape Ŭ�����κ��� ����Ͽ� ����
class Line : public Shape {
protected:
    // Line Ŭ������ ���� draw �޼��� ���� (������ ������ ���)
    virtual void draw();  // Line ������ ������ ����ϴ� ������ ����
};

// Circle Ŭ������ Shape Ŭ�����κ��� ����Ͽ� ����
class Circle : public Shape {
protected:
    // Circle Ŭ������ ���� draw �޼��� ���� (������ ������ ���)
    virtual void draw();  // Circle ������ ������ ����ϴ� ������ ����
};

// Rectangle Ŭ������ Shape Ŭ�����κ��� ����Ͽ� ����
class Rectangle : public Shape {
protected:
    // Rectangle Ŭ������ ���� draw �޼��� ���� (������ ������ ���)
    virtual void draw();  // Rectangle ������ ������ ����ϴ� ������ ����
};

// ��� ������ ��, ���Ǻ� ������ ����
#endif
