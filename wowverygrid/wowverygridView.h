
// wowverygridView.h : CwowverygridView Ŭ������ �������̽�
//

#pragma once


class CwowverygridView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CwowverygridView();
	DECLARE_DYNCREATE(CwowverygridView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_WOWVERYGRID_FORM };
#endif

// Ư���Դϴ�.
public:
	CwowverygridDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CwowverygridView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CGridCtrl m_grid;
};

#ifndef _DEBUG  // wowverygridView.cpp�� ����� ����
inline CwowverygridDoc* CwowverygridView::GetDocument() const
   { return reinterpret_cast<CwowverygridDoc*>(m_pDocument); }
#endif

