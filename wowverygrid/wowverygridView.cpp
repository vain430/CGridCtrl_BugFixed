
// wowverygridView.cpp : CwowverygridView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "wowverygrid.h"
#endif

#include "wowverygridDoc.h"
#include "wowverygridView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CwowverygridView

IMPLEMENT_DYNCREATE(CwowverygridView, CFormView)

BEGIN_MESSAGE_MAP(CwowverygridView, CFormView)
END_MESSAGE_MAP()

// CwowverygridView ����/�Ҹ�

CwowverygridView::CwowverygridView()
	: CFormView(IDD_WOWVERYGRID_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CwowverygridView::~CwowverygridView()
{
}

void CwowverygridView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_grid);
}

BOOL CwowverygridView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CwowverygridView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	m_grid.SetRowCount(10);
	m_grid.SetColumnCount(10);

	DWORD dwTextStyle = DT_CENTER | DT_VCENTER | DT_SINGLELINE;    // Text Style
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			GV_ITEM Item;
			Item.mask = GVIF_TEXT | GVIF_FORMAT;
			Item.nFormat = dwTextStyle;
			Item.row = i;
			Item.col = j;

			Item.strText.Format(_T("DATA%d"), i - 1 * 2 + j);
			m_grid.SetItem(&Item); 
		}
	}
	m_grid.MergeCells(CCellRange(0, 0, 1, 1));
	m_grid.MergeCells(CCellRange(2, 2, 3, 3));
	m_grid.MergeCells(CCellRange(4, 4, 5, 5));
	m_grid.MergeCells(CCellRange(6, 6, 7, 7));
}


// CwowverygridView ����

#ifdef _DEBUG
void CwowverygridView::AssertValid() const
{
	CFormView::AssertValid();
}

void CwowverygridView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CwowverygridDoc* CwowverygridView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwowverygridDoc)));
	return (CwowverygridDoc*)m_pDocument;
}
#endif //_DEBUG


// CwowverygridView �޽��� ó����
