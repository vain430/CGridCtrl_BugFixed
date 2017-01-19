
// wowverygridView.cpp : CwowverygridView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CwowverygridView 생성/소멸

CwowverygridView::CwowverygridView()
	: CFormView(IDD_WOWVERYGRID_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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


// CwowverygridView 진단

#ifdef _DEBUG
void CwowverygridView::AssertValid() const
{
	CFormView::AssertValid();
}

void CwowverygridView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CwowverygridDoc* CwowverygridView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CwowverygridDoc)));
	return (CwowverygridDoc*)m_pDocument;
}
#endif //_DEBUG


// CwowverygridView 메시지 처리기
