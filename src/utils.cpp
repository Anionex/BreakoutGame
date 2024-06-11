
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