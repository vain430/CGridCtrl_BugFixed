
// wowverygrid.h : wowverygrid ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CwowverygridApp:
// �� Ŭ������ ������ ���ؼ��� wowverygrid.cpp�� �����Ͻʽÿ�.
//

class CwowverygridApp : public CWinApp
{
public:
	CwowverygridApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CwowverygridApp theApp;
