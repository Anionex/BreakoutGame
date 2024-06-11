
#include "utils.hpp"
using namespace sf;

void switchToEnglishInputMethod() {
    // 先加载英文键盘布局，语言编号+布局标志
    HKL hklEnglish = LoadKeyboardLayout("00000409", KLF_ACTIVATE);
    if (hklEnglish == NULL) return;


    // 获得当前窗口句柄
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) return;


    // 发送信息来改变布局为hkl...信息类型为WM_INPUTLANGCHANGEREQUEST（请求改变输入语言）
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