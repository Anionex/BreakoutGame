
#include "utils.hpp"
using namespace sf;

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
void showTextDefult(RenderWindow& window, ResourceManager& rm, const std::string content,int size, v2f pos)
{
	Text text(content, rm.getFont("main"));
	text.setPosition(pos);
	text.setFillColor(Color::Black);
	window.draw(text);
	window.display();
	return;
}

Text initText(const std::string &fontPath,const std::string &content, int size, const Color &color) {
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