// GraphicEditor.h
#ifndef GRAPHIC_EDITOR_H  // GraphicEditor.h ��� ������ �����ϴ� ���Ǻ� ������ ����
#define GRAPHIC_EDITOR_H

// Shape Ŭ������ UI Ŭ������ �����ϱ� ���� ��� ����
#include "Shape.h" // ���� ���� Ŭ���� ����
#include "UI.h"    // ����� �������̽� ���� Ŭ���� ����

// GraphicEditor Ŭ���� ����
class GraphicEditor {
    Shape* pStart;  // ���� ����Ʈ�� ù ��° ������ ����Ű�� ������
    Shape* pLast;   // ���� ����Ʈ�� ������ ������ ����Ű�� ������

public:
    // �⺻ ������
    GraphicEditor(); // GraphicEditor ��ü�� ������ �� pStart�� pLast �����͸� �ʱ�ȭ

    // �Ҹ���
    ~GraphicEditor(); // �������� �Ҵ�� �޸� ������ ó���ϱ� ���� �Ҹ���

    // ������ ����Ʈ�� �߰��ϴ� �޼���
    void insertItem(int type); // �Ű����� type�� ���� ������ �����ϰ� ����Ʈ�� �߰�

    // ������ ����Ʈ���� �����ϴ� �޼���
    void deleteItem(int index); // �Ű����� index�� �ش��ϴ� ������ ����Ʈ���� ����

    // ����Ʈ�� �ִ� ��� ������ ����ϴ� �޼���
    void show(); // ���� ����Ʈ�� ��� ������ ���

    // ���α׷� ������ ����ϴ� �޼���
    void run(); // ����� �Է��� ó���ϰ� ������ �߰�/�����ϴ� ���� �۾��� �����ϴ� �޼���
};

// ��� ������ ��, ���Ǻ� ������ ����
#endif
