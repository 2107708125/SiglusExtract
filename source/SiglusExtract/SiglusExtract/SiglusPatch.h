//	 kDays_supp.h�� ����ͷ�ļ�kDays.dll
//	 ���ߣ� DLL to Lib version 3.00
//	 ���ڣ� Saturday, June 03, 2017
//	 ������ kDays.dll����ڵ㺯����������
//	 ԭ�ͣ� BOOL WINAPI xxx_DllMain(HINSTANCE hinstance, DWORD fdwReason, LPVOID lpvReserved);
//	 ����: 
//		hinstance
//		 Ӧ�ó���ĵ�ǰʵ���ľ����ʹ�� AfxGetInstanceHandle()
//		 ��ȡʵ���ľ�������������Ŀ���� MFC ֧�֡�
//		fdwReason
//		 ָ��һ��ָʾΪʲô����Ϊ��ڵ㺯���ı�־��
//		lpvReserved 
//		 Ӧ������ʼ��������ָ��DLL
//		 ������Ϊ�գ�
//	 ע�ͣ� ��ڵ����ϸ��Ϣ����İ����ĵ�
//		 ����
//	 ��ҳ�� http://www.binary-soft.com
//	 Technical ֧�֣� support@binary-soft.com
/////////////////////////////////////////////////////////////////////

#if !defined(D2L_KDAYS_SUPP_H__643A694E_453C_1A1D_1112_521E393C1937__INCLUDED_)
#define D2L_KDAYS_SUPP_H__643A694E_453C_1A1D_1112_521E393C1937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef __cplusplus
extern "C" {
#endif


#include <windows.h>

	/* ����kDays.dll����ڵ㺯������Ӧ�ð�������Ҫ
	��ʼ������ֹ�� */

	BOOL WINAPI KDAYS_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved);


#ifdef __cplusplus
}
#endif

#endif // !defined(D2L_KDAYS_SUPP_H__643A694E_453C_1A1D_1112_521E393C1937__INCLUDED_)
