#pragma once

#include "resource.h"
#include "afxcmn.h"

// CSiglusExtractFeedbackDialog �Ի���

class CSiglusExtractFeedbackDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSiglusExtractFeedbackDialog)

public:
	CSiglusExtractFeedbackDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSiglusExtractFeedbackDialog();

// �Ի�������
	enum { IDD = IDD_FEEDBACK_DIALOG };

	BOOL m_IsInited;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CRichEditCtrl m_markEditNote;
};
