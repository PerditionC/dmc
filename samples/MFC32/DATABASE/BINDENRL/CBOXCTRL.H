#ifndef __CBOXCTRL_H__
#define __CBOXCTRL_H__

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CCbox1Ctrl wrapper class

class CCbox1Ctrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CCbox1Ctrl)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xfaeee760, 0x117e, 0x101b, { 0x89, 0x33, 0x8, 0x0, 0x2b, 0x2f, 0x4f, 0x5a } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	CString GetListField();
	void SetListField(LPCTSTR);
	CString GetBoundText();
	void SetBoundText(LPCTSTR);
	CString GetBoundColumn();
	void SetBoundColumn(LPCTSTR);
	long GetStyle();
	void SetStyle(long);
	long GetMousePointer();
	void SetMousePointer(long);
	BOOL GetLocked();
	void SetLocked(BOOL);
	LPDISPATCH GetMouseIcon();
	void SetMouseIcon(LPDISPATCH);
	BOOL GetIntegralHeight();
	void SetIntegralHeight(BOOL);
	long GetSelStart();
	void SetSelStart(long);
	long GetSelLength();
	void SetSelLength(long);
	CString GetSelText();
	void SetSelText(LPCTSTR);
	long GetMatchEntry();
	void SetMatchEntry(long);
	VARIANT GetSelectedItem();
	short GetVisibleCount();
	void SetVisibleCount(short);
	CString GetText();
	void SetText(LPCTSTR);
	LPUNKNOWN GetRowSource();
	void SetRowSource(LPUNKNOWN);
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	LPFONTDISP GetFont();
	void SetFont(LPFONTDISP);
	BOOL GetEnabled();
	void SetEnabled(BOOL);
	BOOL GetMatchedWithList();
	long GetAppearance();
	void SetAppearance(long);

// Operations
public:
	void ReFill();
	CString GetVisibleItems(short nIndex);
	void SetVisibleItems(short nIndex, LPCTSTR lpszNewValue);
	void AboutBox();
	void Refresh();
};

#endif // __CBOXCTRL_H__
