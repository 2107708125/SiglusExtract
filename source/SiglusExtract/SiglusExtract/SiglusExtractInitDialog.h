#pragma once



#include "resource.h"

// CSiglusExtractInitDialog �Ի���

class CSiglusExtractInitDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSiglusExtractInitDialog)

public:
	CSiglusExtractInitDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSiglusExtractInitDialog();

// �Ի�������
	enum { IDD = IDD_INIT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

