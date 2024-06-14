
#include "utils.hpp"
using namespace sf;

#define _USE_MATH_DEFINES
#include <math.h>

void switchToEnglishInputMethod() {
	// �ȼ���Ӣ�ļ��̲��֣����Ա��+���ֱ�־
	HKL hklEnglish = LoadKeyboardLayout("00000409", KLF_ACTIVATE);
	if (hklEnglish == NULL) return;


	// ��õ�ǰ���ھ��
	HWND hwnd = GetForegroundWindow();
	if (hwnd == NULL) return;


	// ������Ϣ���ı䲼��Ϊhkl...��Ϣ����ΪWM_INPUTLANGCHANGEREQUEST������ı��������ԣ�
	PostMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hklEnglish);
}
#define v2f Vector2f
void drawTextDefult(RenderWindow& window, ResourceManager& rm, const std::string& content, int size, v2f pos)
{
	Text text(content, rm.getFont("main"));
	text.setCharacterSize(size);
	FloatRect bounds = text.getLocalBounds();
	
	text.setPosition(v2f(pos.x - bounds.width / 2.0, pos.y - bounds.height));
	text.setFillColor(Color::Black);
	window.draw(text);
	return;
}
// A is a circle indeed 
int checkCollidType(FloatRect A, FloatRect B) {
	int HorizontalRebound = 0, VerticalRebound = 1, NoCollision = 2;
    v2f O = v2f(A.left + A.width / 2, A.top + A.height / 2);
    v2f P = v2f(B.left + B.width / 2, B.top + B.height / 2);
    float r = A.width / 2;

    // ���Բ���Ƿ��ھ����ڲ�
    if (O.x >= B.left && O.x <= B.left + B.width && O.y >= B.top && O.y <= B.top + B.height) {
        // Բ���ھ����ڲ���������Ҫ��������ı���������������
        float leftDist = O.x - B.left;
        float rightDist = B.left + B.width - O.x;
        float topDist = O.y - B.top;
        float bottomDist = B.top + B.height - O.y;
        float minDist = std::min({ leftDist, rightDist, topDist, bottomDist });

        if (minDist == leftDist || minDist == rightDist) {
            return HorizontalRebound;
        }
        else {
            return VerticalRebound;
        }
    }

    // ���Բ�;��ε���ײ
    float closestX = std::clamp(O.x, B.left, B.left + B.width);
    float closestY = std::clamp(O.y, B.top, B.top + B.height);
    float distanceX = O.x - closestX;
    float distanceY = O.y - closestY;
    float distanceSquared = distanceX * distanceX + distanceY * distanceY;

    if (distanceSquared > r * r) {
        return NoCollision;
    }

    // �жϷ�������
    if (std::abs(distanceX) > std::abs(distanceY)) {
        return HorizontalRebound;
    }
    else {
        return VerticalRebound;
    }
}

Text initText(const std::string& fontPath, const std::string& content, int size, const Color& color) {
	Font font;
	if (!font.loadFromFile(fontPath)) {
		std::cout << "Error loading font\n";
	}

	Text text;
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(size);
	text.setFillColor(color);

	return text;
}