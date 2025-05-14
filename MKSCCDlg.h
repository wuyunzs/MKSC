
// 250509MFCYCDlg.h: 头文件
//

#pragma once
#define WM_USER_HIDE_WEBVIEW (WM_USER + 1)

using namespace Microsoft::WRL;

// CMy250509MFCYCDlg 对话框
class CMy250509MFCYCDlg : public CDialogEx
{
	// 构造
public:
	CMy250509MFCYCDlg(CWnd* pParent = nullptr);	// 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY250509MFCYC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	ComPtr<ICoreWebView2> m_webView;         // WebView2实例  
	ComPtr<ICoreWebView2Controller> m_controller; // 控制器  
	afx_msg void OnSize(UINT nType, int cx, int cy); // 处理窗口大小变化  
	void HandleNewWindowRequested(ICoreWebView2* sender, ICoreWebView2NewWindowRequestedEventArgs* args);
	void SetWindowTransparency(HWND hWnd, bool transparent);
	bool ControlService(const char* serviceName, DWORD dwControl);
	int GetTimeDifferenceMinutes();
	BOOL IsTopLevelWindow(CWnd* pWnd);
	HWND GetActiveTopLevelWindow();
	void SetAsHighestPriorityWindow(CWnd* pWnd);
	void EnsureWindowIsTopMost(CWnd* pWnd);
	void ResizeWebView2();
	void Task();
	void Task2();
	void Del();
	void InitProgramParameters();
	void  SettingTaskShowOrHide(int command);
	void  HomeTaskShowOrHide(int command);
	DECLARE_MESSAGE_MAP()
public:
	EventRegistrationToken m_navigationCompletedToken;
	afx_msg LRESULT OnHideWebView(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonDoubao();
	afx_msg void OnBnClickedButtonBaiduai();
	afx_msg void OnBnClickedButtonBing();
	afx_msg void OnBnClickedButtonBaidu();
	afx_msg void OnBnClickedButton360();
	afx_msg void OnBnClickedButtonFanyi();
	afx_msg void OnBnClickedButtonSetting();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedButton1();
	CEdit CEdit_jihuoma;
	CHAR Permanent = 0;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButtondy();
	afx_msg void OnBnClickedButtonB();
	afx_msg void OnBnClickedCheck7();
};
