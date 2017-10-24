#pragma once

#include <atlimage.h>
#include "afxext.h"
#include "resource.h"

// CSiglusExtractAboutDialog �Ի���

class CSiglusExtractAboutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSiglusExtractAboutDialog)

public:
	CSiglusExtractAboutDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSiglusExtractAboutDialog();

// �Ի�������
	enum { IDD = IDD_ABOUT_DIALOG };

	CImage m_ImageBg;
	BOOL   m_IsInited;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��


	bool LoadImageFromResource(CImage* pImage, UINT nResID, LPCWSTR lpTyp);
	void CreateRgnByImage(CImage* pImage, CRgn &rgn);

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	CBitmapButton m_CloseBtn;
	afx_msg void OnBnClickedButton1();
};
