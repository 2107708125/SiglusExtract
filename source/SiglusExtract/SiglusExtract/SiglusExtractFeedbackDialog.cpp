// SiglusExtractFeedbackDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SiglusExtractFeedbackDialog.h"
#include "afxdialogex.h"
#include <vector>

// CSiglusExtractFeedbackDialog �Ի���

IMPLEMENT_DYNAMIC(CSiglusExtractFeedbackDialog, CDialogEx)

CSiglusExtractFeedbackDialog::CSiglusExtractFeedbackDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSiglusExtractFeedbackDialog::IDD, pParent)
{
	m_IsInited = FALSE;
}

CSiglusExtractFeedbackDialog::~CSiglusExtractFeedbackDialog()
{
}

void CSiglusExtractFeedbackDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_markEditNote);
}


BEGIN_MESSAGE_MAP(CSiglusExtractFeedbackDialog, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &CSiglusExtractFeedbackDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CSiglusExtractFeedbackDialog ��Ϣ�������


BOOL CSiglusExtractFeedbackDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	AfxInitRichEdit2();

	m_IsInited = TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CSiglusExtractFeedbackDialog::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();

	m_IsInited = FALSE;
}

//Send
void CSiglusExtractFeedbackDialog::OnBnClickedOk()
{
	CString Comment;

	m_markEditNote.GetWindowTextW(Comment);

	EndDialog(0);
}


BOOL CSiglusExtractFeedbackDialog::PreTranslateMessage(MSG* pMsg)
{
	//return CDialogEx::PreTranslateMessage(pMsg);

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			m_markEditNote.SetSel(-1, -1);
			m_markEditNote.ReplaceSel(_T("\n"));
			m_markEditNote.SetFocus();
			return true;
		}
	}
	return false;
}
