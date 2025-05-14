
// 250509MFCYCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MKSC.h"
#include "MKSCCDlg.h"
#include "afxdialogex.h"
#include <string> // 引入头文件  
using namespace std; // 若未使用 std:: 限定，添加此命名空间声明  
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IDC_NUMBER  1036						//控件最大数
#define DELETE_FILES_COUNTDOWN_S   1800			//普通用户删除程序倒计时S
#define TXIT_PROGRAM_COUNTDOWN_S   900			//普通用户退出程序倒计时S
#define DELETE_FILES_COUNTDOWN_S_2   3600			//高级用户删除程序倒计时S
#define TXIT_PROGRAM_COUNTDOWN_S_2   3480			//高级用户退出程序倒计时S
#define TIMER_ID_1MIN 1							//计时器1 (程序退出和删除)
#define TIMER_ID_TOPMOST 2						//计时器2 (窗口置顶)
#define TIMER_ID_WEBVIEW_RESIZE  3				//计时器3 (webview2重绘)
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现	
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy250509MFCYCDlg 对话框



CMy250509MFCYCDlg::CMy250509MFCYCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY250509MFCYC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy250509MFCYCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(CMy250509MFCYCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DOUBAO, &CMy250509MFCYCDlg::OnBnClickedButtonDoubao)
	ON_BN_CLICKED(IDC_BUTTON_BAIDUAI, &CMy250509MFCYCDlg::OnBnClickedButtonBaiduai)
	ON_BN_CLICKED(IDC_BUTTON_BING, &CMy250509MFCYCDlg::OnBnClickedButtonBing)
	ON_BN_CLICKED(IDC_BUTTON_BAIDU, &CMy250509MFCYCDlg::OnBnClickedButtonBaidu)
	ON_BN_CLICKED(IDC_BUTTON_360, &CMy250509MFCYCDlg::OnBnClickedButton360)
	ON_BN_CLICKED(IDC_BUTTON_FANYI, &CMy250509MFCYCDlg::OnBnClickedButtonFanyi)
	ON_BN_CLICKED(IDC_BUTTON_SETTING, &CMy250509MFCYCDlg::OnBnClickedButtonSetting)
	ON_BN_CLICKED(IDC_CHECK2, &CMy250509MFCYCDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CMy250509MFCYCDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CMy250509MFCYCDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CMy250509MFCYCDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CMy250509MFCYCDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy250509MFCYCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy250509MFCYCDlg::OnBnClickedButton2)
	ON_MESSAGE(WM_USER_HIDE_WEBVIEW, &CMy250509MFCYCDlg::OnHideWebView)
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHECK6, &CMy250509MFCYCDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy250509MFCYCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy250509MFCYCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy250509MFCYCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_dy, &CMy250509MFCYCDlg::OnBnClickedButtondy)
	ON_BN_CLICKED(IDC_BUTTON_B, &CMy250509MFCYCDlg::OnBnClickedButtonB)
	ON_BN_CLICKED(IDC_CHECK7, &CMy250509MFCYCDlg::OnBnClickedCheck7)
END_MESSAGE_MAP()


// CMy250509MFCYCDlg 消息处理程序

BOOL CMy250509MFCYCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	HWND hContainer = GetDlgItem(IDC_WEBVIEW_CONTAINER)->GetSafeHwnd();
	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	CreateCoreWebView2EnvironmentWithOptions(
		nullptr,
		nullptr,
		nullptr,
		Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
			[this, hContainer](HRESULT result, ICoreWebView2Environment* env) -> HRESULT {
				if (SUCCEEDED(result) && env) {
					// 创建WebView2控制器（关联当前窗口）  
					env->CreateCoreWebView2Controller(
						hContainer,
						Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
							[this](HRESULT result, ICoreWebView2Controller* controller) -> HRESULT {
								if (SUCCEEDED(result) && controller) {
									m_controller = controller;
									// 获取ICoreWebView2实例  
									controller->get_CoreWebView2(&m_webView);
									// 导航到目标网址（如百度）  
									m_webView->Navigate(L"https://www.bing.com");
									// 初始设置大小（也可在OnSize中调整）  
									RECT rect;
									GetDlgItem(IDC_WEBVIEW_CONTAINER)->GetClientRect(&rect);
									m_controller->put_Bounds(rect);
									m_webView->add_NavigationCompleted(
										Callback<ICoreWebView2NavigationCompletedEventHandler>(
											[this](ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
												// 导航完成后，延迟隐藏WebView
												PostMessage(WM_USER_HIDE_WEBVIEW);
												return S_OK;
											}).Get(),
												&m_navigationCompletedToken);
								}
								return S_OK;
							}).Get()
								);
				}
				return S_OK;
			}).Get()
				);

	InitProgramParameters();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy250509MFCYCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy250509MFCYCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy250509MFCYCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy250509MFCYCDlg::OnSize(UINT nType, int cx, int cy)
{


	CDialogEx::OnSize(nType, cx, cy);

	if (nType == SIZE_MINIMIZED)
		return;

	// 清除之前的定时器（避免重复触发）
	KillTimer(TIMER_ID_WEBVIEW_RESIZE);

	// 延迟 200ms 执行调整（给窗口布局留出时间）
	SetTimer(TIMER_ID_WEBVIEW_RESIZE, 200, nullptr);

}

void CMy250509MFCYCDlg::HandleNewWindowRequested(ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args)
{
	PWSTR uri;
	args->get_Uri(&uri);
	wstring url(uri);

	// 取消弹新窗口的默认行为
	args->put_Handled(TRUE);

	// 在当前 WebView2 中导航该 URL（可根据需求保留判断逻辑）
	if (m_webView) {
		m_webView->Navigate(uri); // 直接加载目标链接
	}

	CoTaskMemFree(uri);
}


void CMy250509MFCYCDlg::SetWindowTransparency(HWND hWnd, bool transparent)
{
	if (transparent) {
		// 设置窗口为分层窗口并完全透明
		LONG exStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle | WS_EX_LAYERED);
		::SetLayeredWindowAttributes(m_hWnd, 0, 10, LWA_ALPHA);
	}
	else {
		// 恢复正常显示
		LONG exStyle = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		SetWindowLong(m_hWnd, GWL_EXSTYLE, exStyle & ~WS_EX_LAYERED);
		::InvalidateRect(m_hWnd, NULL, TRUE);
	}
}

bool CMy250509MFCYCDlg::ControlService(const char* serviceName, DWORD dwControl)
{
	SC_HANDLE schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (schSCManager == NULL) return false;

	int len = MultiByteToWideChar(CP_ACP, 0, serviceName, -1, NULL, 0);
	wchar_t* wideServiceName = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, serviceName, -1, wideServiceName, len);

	SC_HANDLE schService = OpenService(schSCManager, wideServiceName, SERVICE_ALL_ACCESS);
	delete[] wideServiceName; // 释放内存
	if (schService == NULL) {
		CloseServiceHandle(schSCManager);
		return false;
	}

	SERVICE_STATUS serviceStatus;
	bool result = ::ControlService(schService, dwControl, &serviceStatus);

	CloseServiceHandle(schService);
	CloseServiceHandle(schSCManager);
	return result;
}

int CMy250509MFCYCDlg::GetTimeDifferenceMinutes()
{
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);

	// 获取创建时间和当前时间
	CFileStatus status;
	if (!CFile::GetStatus(szPath, status)) return -1; // 失败
	CTime creationTime = status.m_ctime;
	CTime now = CTime::GetCurrentTime();

	// 计算时间差（分钟）
	__time64_t diffSec = now.GetTime() - creationTime.GetTime();
	return abs((int)(diffSec)); // 取绝对值
}

BOOL CMy250509MFCYCDlg::IsTopLevelWindow(CWnd* pWnd)
{
	if (!pWnd) return FALSE;
	return (pWnd->GetParent() == NULL ||
		pWnd->GetParent()->GetSafeHwnd() == ::GetDesktopWindow());
}

HWND CMy250509MFCYCDlg::GetActiveTopLevelWindow()
{
	HWND hForeground = ::GetForegroundWindow();
	if (!hForeground) return NULL;

	// 获取窗口的顶级父窗口
	HWND hTopLevel = ::GetAncestor(hForeground, GA_ROOT);
	return hTopLevel;
}

void CMy250509MFCYCDlg::SetAsHighestPriorityWindow(CWnd* pWnd)
{
	if (!pWnd || !pWnd->GetSafeHwnd()) return;

	// 设置为顶级窗口，并置于所有非置顶窗口之上
	pWnd->SetWindowPos(
		&wndTopMost,  // 置顶窗口
		0, 0, 0, 0,   // 位置和大小不变
		SWP_NOMOVE | SWP_NOSIZE  // 仅更改z-order
	);
}

void CMy250509MFCYCDlg::EnsureWindowIsTopMost(CWnd* pWnd)
{
	if (!pWnd) return;

	// 1. 判断自身是否为顶级窗口
	BOOL bIsTopLevel = IsTopLevelWindow(pWnd);

	// 2. 获取当前活动的顶级窗口
	HWND hActiveTopLevel = GetActiveTopLevelWindow();

	// 3. 比较自身窗口与活动顶级窗口
	if (hActiveTopLevel != pWnd->GetSafeHwnd()) {
		// 活动窗口不是自身，将自身设为置顶窗口
		SetAsHighestPriorityWindow(pWnd);
	}
}

void CMy250509MFCYCDlg::ResizeWebView2()
{
	CWnd* pContainer = GetDlgItem(IDC_WEBVIEW_CONTAINER);
	if (!pContainer || !m_controller)
		return;

	// 获取容器客户区矩形（坐标相对于容器自身）
	CRect containerRect;
	pContainer->GetClientRect(&containerRect);

	// 转换为 RECT 结构
	RECT webViewRect = {
		containerRect.left,
		containerRect.top,
		containerRect.right,
		containerRect.bottom
	};

	// 设置 WebView2 边界
	m_controller->put_Bounds(webViewRect);

	// 强制重绘（可选，但有时能解决显示问题）
	pContainer->Invalidate();
	pContainer->UpdateWindow();
}

void CMy250509MFCYCDlg::Task()
{
	int times = GetTimeDifferenceMinutes();//秒数
	if (times >= DELETE_FILES_COUNTDOWN_S && Permanent == 0) {

		KillTimer(TIMER_ID_1MIN);
		Del();
		PostMessage(WM_CLOSE);
	}

	if (times >= TXIT_PROGRAM_COUNTDOWN_S && Permanent == 0) {
		KillTimer(TIMER_ID_1MIN);
		PostMessage(WM_CLOSE);
	}


	if (times >= DELETE_FILES_COUNTDOWN_S_2 && Permanent == 2) {

		KillTimer(TIMER_ID_1MIN);
		Del();
		PostMessage(WM_CLOSE);
	}
	if (times >= DELETE_FILES_COUNTDOWN_S_2 && Permanent == 2) {

		KillTimer(TIMER_ID_1MIN);
		PostMessage(WM_CLOSE);
	}
}
void CMy250509MFCYCDlg::Task2()
{
	EnsureWindowIsTopMost(this);
}
CString GetTempPath() {
	TCHAR szTempPath[MAX_PATH];
	GetTempPath(MAX_PATH, szTempPath);
	return CString(szTempPath);
}
void CleanupOldBats() {
	CString tempPath = GetTempPath();
	CFileFind finder;
	BOOL bWorking = finder.FindFile(tempPath + _T("del_*.bat"));
	while (bWorking) {
		bWorking = finder.FindNextFile();
		if (!finder.IsDots() && !finder.IsDirectory()) {
			DeleteFile(finder.GetFilePath());
		}
	}
	finder.Close();
}
void CMy250509MFCYCDlg::Del()
{

	CleanupOldBats();  // 清理旧批处理文件
	Sleep(3000);
	// 获取当前程序路径及目录
	TCHAR szExePath[MAX_PATH];
	GetModuleFileName(NULL, szExePath, MAX_PATH);
	CString szExePathStr = szExePath;
	CString exeDir = szExePathStr.Left(szExePathStr.ReverseFind('\\') + 1);  // 提取程序目录

	// 生成批处理文件路径（临时目录 + 唯一文件名）
	CString tempPath = GetTempPath();
	CString batName = _T("del_MFCYC_.bat");
	CString batPath = tempPath + batName;

	// 批处理内容：切换到程序目录，删除指定文件和文件夹
	CString batContent;
	batContent.Format(
		_T("@echo off\n"
			"timeout /t 3 /nobreak > nul\n"  // 延迟3秒，确保程序完全退出
			"cd /d \"%s\"\n"                  // 切换到程序目录
			"del /F /Q \"MKSC.exe\"\n"    // 删除MKSC.exe
			"del /F /Q \"MKSC.pdb\"\n"     // 删除MKSC.pdb
			"del /F /Q \"WebView2Loader.dll\"\n"  // 删除WebView2Loader.dll
			"rmdir /S /Q \"MKSC.exe.WebView2\"\n"  // 递归删除文件夹
			"exit\n"),
		exeDir
	);

	// 保存批处理文件
	CStdioFile file;
	if (file.Open(batPath, CFile::modeCreate | CFile::modeWrite | CFile::typeText)) {
		file.WriteString(batContent);
		file.Close();
	}
	else {
		AfxMessageBox(_T("批处理文件创建失败！"));
		return;
	}

	// 启动批处理
	SHELLEXECUTEINFO sei = { sizeof(sei) };
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	sei.lpFile = _T("cmd.exe");
	sei.lpParameters = CString(_T("/c start ")) + batPath;
	sei.nShow = SW_HIDE;

	if (!ShellExecuteEx(&sei)) {
		AfxMessageBox(_T("批处理执行失败！"));
		return;
	}

	// 退出程序，确保批处理执行时文件未被占用
	AfxGetApp()->ExitInstance();

}
void CMy250509MFCYCDlg::InitProgramParameters()
{
	ModifyStyleEx(WS_EX_TOPMOST, 0);
	SetWindowPos(&CWnd::wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	SetTimer(TIMER_ID_1MIN, 10000, NULL);
	GetDlgItem(IDC_EDIT_jihuoma)->SetWindowText(L"免费使用中");
}
void CMy250509MFCYCDlg::SettingTaskShowOrHide(int command)
{
	GetDlgItem(IDC_CHECK2)->ShowWindow(command);
	GetDlgItem(IDC_CHECK1)->ShowWindow(command);
	GetDlgItem(IDC_CHECK3)->ShowWindow(command);
	GetDlgItem(IDC_CHECK4)->ShowWindow(command);
	GetDlgItem(IDC_CHECK5)->ShowWindow(command);
	GetDlgItem(IDC_CHECK6)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(command);
	GetDlgItem(IDC_EDIT_jihuoma)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(command);
	GetDlgItem(IDC_EDIT_CODE)->ShowWindow(command);
	GetDlgItem(IDC_CHECK7)->ShowWindow(command);
}
void CMy250509MFCYCDlg::HomeTaskShowOrHide(int command)
{
	GetDlgItem(IDC_WEBVIEW_CONTAINER)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_DOUBAO)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_BAIDUAI)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_BING)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_BAIDU)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_360)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_FANYI)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_dy)->ShowWindow(command);
	GetDlgItem(IDC_BUTTON_B)->ShowWindow(command);
}
int tmp = 0;
LRESULT CMy250509MFCYCDlg::OnHideWebView(WPARAM wParam, LPARAM lParam)
{
	//return 0;

	if (tmp == 0) {
		for (UINT id = 1000; id <= IDC_NUMBER; id++) {
			CWnd* pCtrl = GetDlgItem(id);
			if (pCtrl) {
				pCtrl->ShowWindow(SW_HIDE); // 显示控件
			}
		}
		GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
		tmp++;
	}

	return 0;
}

void CMy250509MFCYCDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == TIMER_ID_1MIN) {
		Task();
	}
	else if (nIDEvent == TIMER_ID_TOPMOST) {
		Task2();
	}
	else if (nIDEvent == TIMER_ID_WEBVIEW_RESIZE)
	{
		KillTimer(TIMER_ID_WEBVIEW_RESIZE);
		ResizeWebView2();
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CMy250509MFCYCDlg::OnBnClickedButtonDoubao()
{

	if (m_webView) {
		m_webView->Navigate(L"https://doubao.com");
	}

}

void CMy250509MFCYCDlg::OnBnClickedButtonBaiduai()
{
	if (m_webView) {
		m_webView->Navigate(L"https://chat.baidu.com/"); // 百度 AI 网址
	}

}

void CMy250509MFCYCDlg::OnBnClickedButtonBing()
{
	if (m_webView) {
		m_webView->Navigate(L"https://www.bing.com"); // Bing 网址
	}
}

void CMy250509MFCYCDlg::OnBnClickedButtonBaidu()
{
	if (m_webView) {
		m_webView->Navigate(L"https://www.baidu.com"); // 百度网址
	}
}

void CMy250509MFCYCDlg::OnBnClickedButton360()
{
	if (m_webView) {
		m_webView->Navigate(L"https://www.so.com/"); // 360 网址
	}
}

void CMy250509MFCYCDlg::OnBnClickedButtonFanyi()
{
	if (m_webView) {
		m_webView->Navigate(L"https://fanyi.baidu.com"); // 翻译网址
	}
}
void CMy250509MFCYCDlg::OnBnClickedButtondy()
{
	if (m_webView) {
		m_webView->Navigate(L"https://www.douyin.com/"); // dy网址
	}
}

void CMy250509MFCYCDlg::OnBnClickedButtonB()
{
	if (m_webView) {
		m_webView->Navigate(L"https://www.bilibili.com/"); // b网址
	}
}


void CMy250509MFCYCDlg::OnBnClickedButtonSetting()
{
	CString strText;
	GetDlgItemText(IDC_BUTTON_SETTING, strText);
	if (strText == "setting") {
		HomeTaskShowOrHide(SW_HIDE);
		SettingTaskShowOrHide(SW_SHOW);
		GetDlgItem(IDC_BUTTON_SETTING);
		GetDlgItem(IDC_BUTTON_SETTING)->SetWindowTextW(L"return");
	}
	else {
		HomeTaskShowOrHide(SW_SHOW);
		SettingTaskShowOrHide(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SETTING)->SetWindowTextW(L"setting");

	}
}
//置顶
void CMy250509MFCYCDlg::OnBnClickedCheck2()
{

	int nCheckState = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	if (nCheckState == BST_CHECKED) {
		SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}
	else {
		ModifyStyleEx(WS_EX_TOPMOST, 0);
		SetWindowPos(&CWnd::wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	}

}
//win10
void CMy250509MFCYCDlg::OnBnClickedCheck1()
{
	int nCheckState = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (nCheckState == BST_CHECKED) {
		SetWindowDisplayAffinity(m_hWnd, WDA_NONE);
		((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(BST_UNCHECKED);
		SetWindowDisplayAffinity(m_hWnd, WDA_MONITOR);
	}
	else {
		SetWindowDisplayAffinity(m_hWnd, WDA_NONE);
	}
}
//win11
void CMy250509MFCYCDlg::OnBnClickedCheck3()
{
	int nCheckState = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	if (nCheckState == BST_CHECKED) {
		SetWindowDisplayAffinity(m_hWnd, WDA_NONE);
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_UNCHECKED);
		SetWindowDisplayAffinity(m_hWnd, WDA_EXCLUDEFROMCAPTURE);
	}
	else {
		SetWindowDisplayAffinity(m_hWnd, WDA_NONE);
	}
}
//透明
void CMy250509MFCYCDlg::OnBnClickedCheck4()
{
	int nCheckState = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	if (nCheckState == BST_CHECKED) {

		SetWindowTransparency(m_hWnd, true);
	}
	else {
		SetWindowTransparency(m_hWnd, false);
	}

}
//断网
void CMy250509MFCYCDlg::OnBnClickedCheck5()
{
	bool c = ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck() == BST_CHECKED;
	int result;
	if (c) {
		result = system("sc stop tdnetfilter & sc stop tdagent& sc stop tdservice");
	}
	else {
		result = system("sc start tdnetfilter & sc start tdagent& sc start tdservice");
	}
	if (result != 0) {
		::MessageBoxW(NULL, L"失败", L"error", NULL);
	}

}
//打开cmd 管理员
void CMy250509MFCYCDlg::OnBnClickedButton1()
{
	ShellExecute(NULL, L"runas", L"cmd.exe", L"", NULL, SW_SHOW);
}




//打开cmd普通
void CMy250509MFCYCDlg::OnBnClickedButton4()
{
	ShellExecute(NULL, L"open", L"cmd.exe", L"", NULL, SW_SHOW);
}
//动态置顶
void CMy250509MFCYCDlg::OnBnClickedCheck6()
{
	bool c = ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck() == BST_CHECKED;
	if (c) {
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(BST_UNCHECKED);
		SetTimer(TIMER_ID_TOPMOST, 5000, NULL);
	}
	else {
		KillTimer(TIMER_ID_TOPMOST);
	}
}
//删除程序
void CMy250509MFCYCDlg::OnBnClickedButton3()
{
	if (Permanent == 0)
	{
		Del();
		PostMessage(WM_CLOSE);
	}

}
//开始按钮
void CMy250509MFCYCDlg::OnBnClickedButton5()
{
	for (UINT id = 1000; id <= IDC_NUMBER; id++) {
		CWnd* pCtrl = GetDlgItem(id);
		if (pCtrl) {
			pCtrl->ShowWindow(SW_SHOW);
		}
	}
	SettingTaskShowOrHide(SW_HIDE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_HIDE);
	return;

}
//激活按钮
void CMy250509MFCYCDlg::OnBnClickedButton2()
{
	CString keys;
	GetDlgItem(IDC_EDIT_jihuoma)->GetWindowText(keys);
	if (keys == ";") {
		Permanent = 1;
		GetDlgItem(IDC_EDIT_jihuoma)->SetWindowText(L"");
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(L"激活成功:)");
		return;
	}
	if (keys == "YS" || keys == "123" || keys == "666" || keys == "520" || keys == "250" || keys == "") {
		Permanent = 2;
		GetDlgItem(IDC_EDIT_jihuoma)->SetWindowText(L"");
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(L"激活成功O_o");
		return;

	}
	Permanent = 0;
	GetDlgItem(IDC_EDIT_jihuoma)->SetWindowText(L"");
	GetDlgItem(IDC_BUTTON2)->SetWindowTextW(L"激活成功");
	return;
}
void CMy250509MFCYCDlg::OnBnClickedButton6()
{
	CString CODE;
	GetDlgItem(IDC_EDIT_CODE)->GetWindowTextW(CODE);
	if (CODE != "")
	{
		if (system(CT2A(CODE))) {
			GetDlgItem(IDC_EDIT_CODE)->SetWindowText(L"执行成功");
		}
		else {
			GetDlgItem(IDC_EDIT_CODE)->SetWindowText(L"");
		}
	}
}




void CMy250509MFCYCDlg::OnBnClickedCheck7()
{
	bool c = ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck() == BST_CHECKED;
	if (c) {
		ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);
	}
	else
	{
		ModifyStyleEx(WS_EX_TOOLWINDOW, WS_EX_APPWINDOW);
	}
}
